#include <iostream>
#include <cstdlib>
#include <unistd.h>

#include "getch.h"

int snake_x = 10;
int snake_y = 10;

char map[20][20];

void clear_map()
{
    for(int y = 0; y < 20; y++)
    {
        for(int x = 0; x < 20; x++)
        {
            if(y == 0)
            {
                map[y][x] = '#';
            }
            else if(x == 0)
            {
                map[y][x] = '#';
            }
            else if(y == 19)
            {
                map[y][x] = '#';
            }
            else if(x == 19)
            {
                map[y][x] = '#';
            }
            else
            {
                map[y][x] = ' ';
            }
        }
    }
}

void show_snake()
{
    map[snake_y][snake_x] = 'O';
}

void show_map()
{
    for(int y = 0; y < 20; y++)
    {
        for(int x = 0; x < 20; x++)
        {
            std::cout << map[y][x];
        }

        std::cout << "\n";
    }
}

void player_move()
{
    char new_cordinate;

    char old_press = 'd';

    int quit_menu_helper = 1;

    while(quit_menu_helper)
    {
        system("clear");

        new_cordinate = _getch();

        if(new_cordinate == 'w')
        {
            old_press = 'w';
        }
        else if(new_cordinate == 's')
        {
            old_press = 's';
        }
        else if(new_cordinate == 'a')
        {
            old_press = 'a';
        }
        else if(new_cordinate == 'd')
        {
            old_press = 'd';
        }
        else if(new_cordinate == 'q')
        {
            quit_menu_helper = 0;
            continue;
        }

        if(old_press == 'w')
        {
            if(snake_y - 1 != 0)
            {
                map[snake_y][snake_x] = ' ';
                snake_y -= 1;
                map[snake_y][snake_x] = 'O';
            }
        }
        else if(old_press == 's')
        {
            if(snake_y + 1 != 19)
            {
                map[snake_y][snake_x] = ' ';
                snake_y += 1;
                map[snake_y][snake_x] = 'O';
            }
        }
        else if(old_press == 'a')
        {
            if(snake_x - 1 != 0)
            {
                map[snake_y][snake_x] = ' ';
                snake_x -= 1;
                map[snake_y][snake_x] = 'O';
            }
        }
        else if(old_press == 'd')
        {
            if(snake_x + 1 != 19)
            {
                map[snake_y][snake_x] = ' ';
                snake_x += 1;
                map[snake_y][snake_x] = 'O';
            }
        }

        show_map();

        usleep(150000);
    }
}

int main()
{
    clear_map();

    show_snake();

    player_move();

    return 0;
}
