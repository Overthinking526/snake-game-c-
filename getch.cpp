#include "getch.h"

#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

char _getch()
{
    termios old_settings;
    termios new_settings;

    tcgetattr(STDIN_FILENO, &old_settings);

    new_settings = old_settings;
    new_settings.c_lflag &= ~(ICANON | ECHO);

    tcsetattr(STDIN_FILENO, TCSANOW, &new_settings);

    int old_flags = fcntl(STDIN_FILENO, F_GETFL, 0);

    fcntl(STDIN_FILENO, F_SETFL, old_flags | O_NONBLOCK);

    char key;

    int result = read(STDIN_FILENO, &key, 1);

    fcntl(STDIN_FILENO, F_SETFL, old_flags);

    tcsetattr(STDIN_FILENO, TCSANOW, &old_settings);

    if(result == 1)
    {
        return key;
    }

    return '\0';
}
