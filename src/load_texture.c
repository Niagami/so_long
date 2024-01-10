/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:58:25 by jteste            #+#    #+#             */
/*   Updated: 2024/01/10 15:59:14 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
