#include <iostream>
#include <cstdlib>
#include <unistd.h>

#include "getch.h"

int snake_x = 10;
int snake_y = 10;

int snake_body_x[100];
int snake_body_y[100];

int snake_length = 1;

int food_x;
int food_y;

int check = 0;

char map[20][20];

void snake_long()
{
    for(int i = 99; i >= 1; i--)
    {
        snake_body_x[i] = snake_body_x[i - 1];
        snake_body_y[i] = snake_body_y[i - 1];
    }
}

void spawn_food()
{
    food_y = rand() % 18 + 1;
    food_x = rand() % 18 + 1;

    map[food_y][food_x] = 'X';

}

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
    snake_body_x[0] = snake_x;
    snake_body_y[0] = snake_y;

    map[snake_y][snake_x] = 'O';

    for(int i = 0; i < snake_length; i++)
    {
        map[snake_body_y[i]][snake_body_x[i]] = 'O';
    }
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
    spawn_food();

    char new_cordinate;

    char old_press = 'd';

    int quit_menu_helper = 1;

    while(quit_menu_helper)
    {
        system("clear");
        clear_map();
        map[food_y][food_x] = 'X';

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
                snake_long();
                snake_y -= 1;
                snake_body_x[0] = snake_x;
                snake_body_y[0] = snake_y;
                map[snake_y][snake_x] = 'O';
            }
        }
        else if(old_press == 's')
        {
            if(snake_y + 1 != 19)
            {
                map[snake_y][snake_x] = ' ';
                snake_long();
                snake_y += 1;
                snake_body_x[0] = snake_x;
                snake_body_y[0] = snake_y;
                map[snake_y][snake_x] = 'O';
            }
        }
        else if(old_press == 'a')
        {
            if(snake_x - 1 != 0)
            {
                map[snake_y][snake_x] = ' ';
                snake_long();
                snake_x -= 1;
                snake_body_x[0] = snake_x;
                snake_body_y[0] = snake_y;
                map[snake_y][snake_x] = 'O';
            }
        }
        else if(old_press == 'd')
        {
            if(snake_x + 1 != 19)
            {
                map[snake_y][snake_x] = ' ';
                snake_long();
                snake_x += 1;
                snake_body_x[0] = snake_x;
                snake_body_y[0] = snake_y;
                map[snake_y][snake_x] = 'O';
            }
        }

        if(snake_x == food_x && snake_y == food_y)
        {
            map[snake_y][snake_x] = ' ';
            usleep(1000);
            map[snake_y][snake_x] = 'O';
            usleep(1000);
            map[snake_y][snake_x] = ' ';
            usleep(1000);
            check += 1;
            snake_length += 1;
            spawn_food();

        }
        std::cout << check << '\n';
        show_snake();
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
