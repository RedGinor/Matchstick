/*
** EPITECH PROJECT, 2021
** launch_game
** File description:
** launches game
*/

#include <matchstick.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "ib.h"

int get_line(int size)
{
    char *buf = NULL;
    size_t len = 0;
    int lines = 0;

    while (lines < 1 || lines > size || !ib_isnum(buf)) {
        ib_putstr("Line: ");
        if (getline(&buf, &len, stdin) == -1) {
            free(buf);
            return (-84);
        }
        buf[ib_strlen(buf) - 1] = '\0';
        lines = (ib_isnum(buf) && ib_strlen(buf) > 0)?(ib_atoi(buf)):(-1);
        if (lines < 0) {
            get_error(1, 0);
            lines = 0;
        } else if (lines > size || lines == 0)
            get_error(5, 0);
    }
    free(buf);
    return (lines);
}

int get_matches(bool **grid, int size, int pos, int moves)
{
    char *buf = NULL;
    size_t len = 0;
    int matches = 0;
    int sticks = get_sticks(grid, size, pos);

    ib_putstr("Matches: ");
    if (getline(&buf, &len, stdin) == -1) {
        free(buf);
        return (-84);
    }
    buf[ib_strlen(buf) - 1] = '\0';
    matches = (ib_isnum(buf) && ib_strlen(buf) > 0)?(ib_atoi(buf)):(-1);
    if (matches < 0)
        matches = get_error(1, 0);
    else if (matches == 0)
        matches = get_error(2, 0);
    else if (matches > sticks || matches > moves)
        matches = get_error(3 + (matches > moves), moves);
    free(buf);
    return (matches);
}

bool end_game(bool **grid, int size)
{
    for (int i = 0; i <= size; i++)
        if (get_sticks(grid, size, i) > 0)
            return (0);
    return (1);
}

int launch_game(int size, int moves)
{
    bool **grid = make_stick_grid(size);

    for (int sticks = 0, pos = 0; !end_game(grid, size); sticks = 0, pos = 0) {
        print_grid(grid, size);
        ib_putstr("\nYour turn:\n");
        while (sticks <= 0) {
            pos = get_line(size);
            if (pos == -84)
                return (0);
            sticks = get_matches(grid, size, pos, moves);
            if (sticks == -84)
                return (0);
        }
        print_turn("Player", sticks, pos);
        if (remove_stick(grid, size, pos, sticks) || ia_move(grid, size, moves))
            return (print_end(grid, size, true) + 1);
    }
    return (print_end(grid, size, false) + 1);
}