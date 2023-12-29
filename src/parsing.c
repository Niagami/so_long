/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:25:12 by jteste            #+#    #+#             */
/*   Updated: 2023/12/29 14:54:09 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_map(t_main *mainstruct)
{
	if (ft_check_sign(mainstruct) == 1)
		ft_error_message("Wrong charactere in map\n");
	if (ft_check_size(mainstruct) == 1)
		ft_error_message("Map is not a rectangle\n");
	if (ft_check_count(mainstruct) == 1)
		ft_error_message("Wrong number of Start, Exit or collectible\n");
	if (ft_check_walls(mainstruct) == 1)
		ft_error_message("Map not surrounded by walls\n");
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
			return (1);
		i++;
	}
	return (0);
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
			&& (mainstruct->map[i][j] != '\n'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
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
				mainstruct->start_pos++;
			if (mainstruct->map[i][j] == 'C')
				mainstruct->collectible++;
			j++;
		}
		i++;
	}
	if ((mainstruct->map_exit == 1) && (mainstruct->start_pos == 1)
		&& (mainstruct->collectible > 0))
		return (0);
	else
		return (1);
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
			return (1);
		i++;
	}
	i = 0;
	while (i < mainstruct->count_line)
	{
		if ((mainstruct->map[i][0] != '1')
			|| (mainstruct->map[i][line_lenght - 1] != '1'))
			return (1);
		i++;
	}	
	return (0);
}
