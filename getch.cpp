#include "getch.h"

#include <termios.h>
#include <unistd.h>

char _getch()
{
    termios old_settings;
    termios new_settings;

    // Получаем текущие настройки терминала
    tcgetattr(STDIN_FILENO, &old_settings);

    // Делаем копию
    new_settings = old_settings;

    // Выключаем ожидание Enter и отображение символа
    new_settings.c_lflag &= ~(ICANON | ECHO);

    // Применяем новые настройки
    tcsetattr(STDIN_FILENO, TCSANOW, &new_settings);

    // Читаем один символ
    char key;
    read(STDIN_FILENO, &key, 1);

    // Возвращаем старые настройки
    tcsetattr(STDIN_FILENO, TCSANOW, &old_settings);

    return key;
}
