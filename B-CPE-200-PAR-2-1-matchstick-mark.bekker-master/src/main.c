/*
** EPITECH PROJECT, 2021
** main
** File description:
** main file
*/

#include <matchstick.h>
#include "ib.h"

bool error_handler(int ac, char **av)
{
    if (ac != 3)
        return (true);
    if (!ib_isnum(av[1]) || !ib_isnum(av[2]))
        return (true);
    if (ib_atoi(av[1]) > 99 || ib_atoi(av[1]) < 2)
        return (true);
    if (ib_atoi(av[2]) < 1)
        return (true);
    return (false);
}

int main(int ac, char **av)
{
    if (error_handler(ac, av))
        return (84);
    return (launch_game(ib_atoi(av[1]), ib_atoi(av[2])));
}