/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:16:57 by jteste            #+#    #+#             */
/*   Updated: 2024/01/10 15:55:18 by jteste           ###   ########.fr       */
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
	int	j;
	int	k;

	mainstruct->index = 0;
	k = 0;
	mainstruct->collectible = malloc((mainstruct->collectible_count)
			* sizeof(t_collectible));
	if (mainstruct->collectible == NULL)
		ft_error_message("Malloc error");
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

int	ft_load_texture(t_main *mainstruct)
{
	int	map_size;

	map_size = ft_map_size(mainstruct);
	mainstruct->image_bg = malloc(map_size + 1 * sizeof(mlx_image_t));
	if (mainstruct->image_bg == NULL)
		ft_error_message("Malloc Error");
	mainstruct->image_bg[map_size] = NULL;
	mainstruct->image_collectible = malloc(mainstruct->collectible_count + 1
			* sizeof(mlx_image_t));
	if (mainstruct->image_collectible == NULL)
		ft_error_message("Malloc Error");
	mainstruct->image_collectible[mainstruct->collectible_count] = NULL;
	mainstruct->image_player = malloc(5 * sizeof(mlx_image_t));
	if (mainstruct->image_player == NULL)
		ft_error_message("Malloc Error");
	mainstruct->image_player[4] = NULL;
	return (0);
}

int	ft_map_size(t_main *mainstruct)
{
	int	map_x;
	int	map_size;

	map_x = ft_strlen(mainstruct->map[0]) - 1;
	map_size = map_x * mainstruct->count_line;
	return (map_size);
}
