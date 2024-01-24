/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:16:57 by jteste            #+#    #+#             */
/*   Updated: 2024/01/24 14:32:18 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_struct_init(t_main *mainstruct)
{
	mainstruct->count_line = 0;
	mainstruct->map_exit = 0;
	mainstruct->collectible_count = 0;
	mainstruct->start_pos = 0;
	mainstruct->map_size = 0;
	mainstruct->count = 0;
	mainstruct->wall_count = 0;
	mainstruct->moove_count = 1;
	mainstruct->collected = 0;
	return (0);
}

void	ft_save_player_pos(t_main *mainstruct, int i, int j)
{
	mainstruct->start_pos++;
	mainstruct->player_pos_y = i;
	mainstruct->player_pos_x = j;
}

void	ft_save_collectible_pos(t_main *mainstruct)
{
	int	j;
	int	k;

	mainstruct->index = 0;
	k = 0;
	mainstruct->collectible = ft_calloc((mainstruct->collectible_count),
			sizeof(t_collectible));
	if (mainstruct->collectible == NULL)
		ft_free_all(mainstruct, "Malloc error", 1);
	while (mainstruct->map[mainstruct->index] != NULL)
	{
		j = 0;
		while (mainstruct->map[mainstruct->index][j] != '\0')
		{
			if (mainstruct->map[mainstruct->index][j] == 'C')
			{
				mainstruct->collectible[k].x = j;
				mainstruct->collectible[k].y = mainstruct->index;
				mainstruct->collectible[k].collected = false;
				k++;
			}
			j++;
		}
		mainstruct->index++;
	}
}

void	ft_count_wall(t_main *mainstruct)
{
	int	i;
	int	j;

	i = 0;
	while (mainstruct->map[i] != NULL)
	{
		j = 0;
		while (mainstruct->map[i][j] != '\0')
		{
			if (mainstruct->map[i][j] == '1')
				mainstruct->wall_count++;
			j++;
		}
		i++;
	}
}

void	ft_save_wall_pos(t_main *mainstruct)
{
	int	j;
	int	k;

	ft_count_wall(mainstruct);
	mainstruct->index = 0;
	k = 0;
	mainstruct->wall = ft_calloc(mainstruct->wall_count, sizeof(t_wall));
	if (mainstruct->wall == NULL)
		ft_free_all(mainstruct, "Malloc error", 1);
	while (mainstruct->map[mainstruct->index] != NULL)
	{
		j = 0;
		while (mainstruct->map[mainstruct->index][j] != '\0')
		{
			if (mainstruct->map[mainstruct->index][j] == '1')
			{
				mainstruct->wall[k].x = j;
				mainstruct->wall[k].y = mainstruct->index;
				k++;
			}
			j++;
		}
		mainstruct->index++;
	}
}
