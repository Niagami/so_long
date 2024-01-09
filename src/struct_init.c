/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:16:57 by jteste            #+#    #+#             */
/*   Updated: 2024/01/09 16:39:57 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_struct_init(t_main *mainstruct)
{
	mainstruct->count_line = 0;
	mainstruct->map_exit = 0;
	mainstruct->collectible_count = 0;
	mainstruct->start_pos = 0;
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
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	mainstruct->collectible = malloc((mainstruct->collectible_count)
			* sizeof(t_collectible));
	while (mainstruct->map[i] != NULL)
	{
		j = 0;
		while (mainstruct->map[i][j] != '\0')
		{
			if (mainstruct->map[i][j] == 'C')
			{
				mainstruct->collectible[k].x = j;
				mainstruct->collectible[k].y = i;
				mainstruct->collectible[k].collected = false;
				k++;
			}
			j++;
		}
		i++;
	}
}
