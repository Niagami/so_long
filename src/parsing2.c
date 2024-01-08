/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:11:00 by jteste            #+#    #+#             */
/*   Updated: 2024/01/08 16:13:20 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_format(t_main *mainstruct)
{
	size_t	i;

	i = ft_strlen(mainstruct->mapname);
	if ((mainstruct->mapname[i - 1] == 'r')
		&& (mainstruct->mapname[i - 2] == 'e')
		&& (mainstruct->mapname[i - 3] == 'b')
		&& (mainstruct->mapname[i - 4] == '.'))
		return (true);
	else
		return (false);
}

int	ft_flood_fill(char	**map, int x, int y, int *items)
{
	if (map[y][x] == '1')
		return (false);
	if (map[y][x] == 'C' || map[y][x] == 'E')
		*items -= 1;
	map[y][x] = '1';
	ft_flood_fill(map, x - 1, y, items);
	ft_flood_fill(map, x + 1, y, items);
	ft_flood_fill(map, x, y - 1, items);
	ft_flood_fill(map, x, y + 1, items);
	if (*items == 0)
		return (true);
	return (false);
}
