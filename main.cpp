#include <iostream>
#include <string>
#include <cstdlib>
#include <termios.h>
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
            else if (x == 0)
            {
                map[y][x] = '#';
            }
            else if (y == 19)
            {
                map[y][x] = '#';
            }
            else if (x == 19)
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

    int quit_menu_helper = 1;

while(quit_menu_helper)
{
    system("clear");
    map[snake_y][snake_x] = 'O';
    show_map();

    new_cordinate = _getch();

        if (new_cordinate == 'w')
        {
            if(snake_y - 1 == 0)
            {
                std::cout << "Error cordinate" << "\n";
            }
            else
            {
                map[snake_y][snake_x] = ' ';
                snake_y -= 1;
                map[snake_y][snake_x] = 'O';
            }
        }
        else if(new_cordinate == 's')
        {
            if(snake_y + 1 == 19)
            {
                std::cout << "Error cordinate" << "\n";
            }
            else
            {
                map[snake_y][snake_x] = ' ';
                snake_y += 1;
                map[snake_y][snake_x] = 'O';
            }
        }
        else if (new_cordinate == 'a')
        {
            if(snake_x - 1 == 0)
            {
                std::cout << "Error cordinate" << "\n";
            }
            else
            {
                map[snake_y][snake_x] = ' ';
                snake_x -= 1;
                map[snake_y][snake_x] = 'O';
            }
        }
        else if (new_cordinate == 'd')
        {
            if(snake_x + 1 == 19)
            {
                std::cout << "Error cordinate" << "\n";
            }
            else
            {
                map[snake_y][snake_x] = ' ';
                snake_x += 1;
                map[snake_y][snake_x] = 'O';
            }
        }
        else if (new_cordinate == 'q')
        {
            quit_menu_helper = 0;
        }
        else
        {
            std::cout << "Error" << "\n";
        }
    }
}

int main()
{
    clear_map();
    show_snake();
    show_map();
    player_move();

    return 0;
}
