#include "../include/cub3d.h"

void    allocate_map(t_window *ups)
{
    ups->map = malloc(sizeof(t_map));
    if (!ups->map)
    {
        ft_putstr_fd("Failed to allocate mem for map struct", 1);
        exit(1);
    }
    parse_map("map.txt", ups->map);
}