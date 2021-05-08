/*
** EPITECH PROJECT, 2021
** grid_gestion
** File description:
** manages grid inputs
*/

#include <matchstick.h>
#include <stdlib.h>
#include <unistd.h>

int get_sticks(bool **grid, int size, int pos)
{
    int sticks = 0;

    if (pos < 1)
        return (0);
    pos -= 1;
    for (int j = 0; j < 2 * size; j++)
        sticks += grid[pos][j];
    return (sticks);
}

bool remove_stick(bool **grid, int size, int pos, int sticks)
{
    int end = 2 * size;

    for (; end > 0 && !grid[pos - 1][end]; end--);
    for (int i = 0; i < sticks; i++)
        grid[pos - 1][end - i] = 0;
    if (end_game(grid, size))
        return (1);
    return (0);
}

bool **make_stick_grid(int size)
{
    bool **grid = malloc(sizeof(bool *) * (size * 2 + 1));
    int p_size = (size + size - 2) / 2;

    for (int i = 0; i < 2 * size; i++)
        grid[i] = malloc(sizeof(bool) * (size * 2 + 1));
    for (int i = 0; i < size; i++)
        for (int j = 0; j < 2 * size - 1; j++)
            grid[i][j] = ((j > p_size - (i + 1)) && (p_size + (i + 1) > j));
    return (grid);
}