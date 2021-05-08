/*
** EPITECH PROJECT, 2021
** prints
** File description:
** prints everything
*/

#include <matchstick.h>
#include <unistd.h>
#include <stdlib.h>
#include "ib.h"

bool print_end(bool **grid, int size, bool end)
{
    print_grid(grid, size);
    for (int i = 0; i < size; i++)
        free(grid[i]);
    free(grid);
    if (!end)
        ib_putstr("I lost... snif... but I'll get you next time!!\n");
    else
        ib_putstr("You lost, too bad...\n");
    return (end);
}

void print_turn(char *player, int match, int line)
{
    ib_putstr(player);
    ib_putstr(" removed ");
    ib_putnbr(match);
    ib_putstr(" match(es) from line ");
    ib_putnbr(line);
    ib_putstr("\n");
}

void print_grid(bool **grid, int size)
{
    for (int i = 0; i < 2 * size + 1; i++)
        write(1, "*", 1);
    write(1, "\n", 1);
    for (int i = 0; i < size; i++) {
        write(1, "*", 1);
        for (int j = 0; j < 2 * size - 1; j++)
            (grid[i][j])?(write(1, "|", 1)):(write(1, " ", 1));
        write(1, "*\n", 2);
    }
    for (int i = 0; i < 2 * size + 1; i++)
        write(1, "*", 1);
    write(1, "\n", 1);
}

int get_error(int error, int moves)
{
    if (error == 1)
        ib_putstr("Error: invalid input (positive number expected)\n");
    if (error == 2)
        ib_putstr("Error: you have to remove at least one match\n");
    if (error == 3)
        ib_putstr("Error: not enough matches on this line\n");
    if (error == 4) {
        ib_putstr("Error: you cannot remove more than ");
        ib_putnbr(moves);
        ib_putstr(" matches per turn\n");
    }
    if (error == 5)
        ib_putstr("Error: this line is out of range\n");
    return (-1);
}