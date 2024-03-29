/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:25:12 by jteste            #+#    #+#             */
/*   Updated: 2024/01/24 16:08:30 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_map(t_main *mainstruct)
{
	int	items;

	if (ft_check_sign(mainstruct) == false)
		ft_free_all(mainstruct, "Wrong caractere in map\n", 1);
	if (ft_check_size(mainstruct) == false)
		ft_free_all(mainstruct, "Map is not a rectangle\n", 1);
	if (ft_check_count(mainstruct) == false)
		ft_free_all(mainstruct,
			"Wrong number of Start, Exit or collectible\n", 1);
	if (ft_check_walls(mainstruct) == false)
		ft_free_all(mainstruct, "Map not surrounded by walls\n", 1);
	items = mainstruct->collectible_count + mainstruct->map_exit;
	if ((ft_flood_fill(mainstruct->map, mainstruct->player_pos_x,
				mainstruct->player_pos_y, &items)) == false)
		ft_free_all(mainstruct, "No valid path in map\n", 1);
	ft_free_map(mainstruct);
	ft_open_map(mainstruct);
	ft_save_collectible_pos(mainstruct);
	ft_save_wall_pos(mainstruct);
	ft_save_exit_pos(mainstruct);
	return (0);
}

int	ft_check_size(t_main *mainstruct)
{
	int		i;
	size_t	first_line_lenght;
	size_t	next_line_lenght;

	i = 0;
	first_line_lenght = ft_strlen(mainstruct->map[i]) - 1;
	while (mainstruct->map[i] != NULL)
	{
		if (ft_strchr(mainstruct->map[i], '\n'))
			next_line_lenght = ft_strlen(mainstruct->map[i]) - 1;
		else
			next_line_lenght = ft_strlen(mainstruct->map[i]);
		if (next_line_lenght != first_line_lenght)
			return (false);
		i++;
	}
	return (true);
}

int	ft_check_sign(t_main *mainstruct)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mainstruct->map[i] != NULL)
	{
		j = 0;
		while (mainstruct->map[i][j] != '\0')
		{
			if ((mainstruct->map[i][j] != '0')
			&& (mainstruct->map[i][j] != '1')
			&& (mainstruct->map[i][j] != 'C')
			&& (mainstruct->map[i][j] != 'P')
			&& (mainstruct->map[i][j] != 'E')
			&& (mainstruct->map[i][j] != '\r')
			&& (mainstruct->map[i][j] != '\n'))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

int	ft_check_count(t_main *mainstruct)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mainstruct->map[i] != NULL)
	{
		j = 0;
		while (mainstruct->map[i][j] != '\0')
		{
			if (mainstruct->map[i][j] == 'E')
				mainstruct->map_exit++;
			if (mainstruct->map[i][j] == 'P')
				ft_save_player_pos(mainstruct, i, j);
			if (mainstruct->map[i][j] == 'C')
				mainstruct->collectible_count++;
			j++;
		}
		i++;
	}
	if ((mainstruct->map_exit == 1) && (mainstruct->start_pos == 1)
		&& (mainstruct->collectible_count > 0))
		return (true);
	else
		return (false);
}

int	ft_check_walls(t_main *mainstruct)
{
	int	line_lenght;
	int	i;

	i = 0;
	line_lenght = ft_strlen(mainstruct->map[0]) - 1;
	while (i < line_lenght)
	{
		if ((mainstruct->map[0][i] != '1')
			|| (mainstruct->map[mainstruct->count_line - 1][i] != '1'))
			return (false);
		i++;
	}
	i = 0;
	while (i < mainstruct->count_line)
	{
		if ((mainstruct->map[i][0] != '1')
			|| (mainstruct->map[i][line_lenght - 1] != '1'))
			return (false);
		i++;
	}	
	return (true);
}
