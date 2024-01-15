/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:58:25 by jteste            #+#    #+#             */
/*   Updated: 2024/01/15 12:55:04 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_load_image(t_main *mainstruct)
{
	mainstruct->map_size = ft_map_size(mainstruct);
	mainstruct->image_bg = malloc((mainstruct->map_size)
			* sizeof(mlx_image_t));
	if (mainstruct->image_bg == NULL)
		ft_error_message("Malloc Error");
	mainstruct->image_collectible = malloc((mainstruct->collectible_count)
			* sizeof(mlx_image_t));
	if (mainstruct->image_collectible == NULL)
		ft_error_message("Malloc Error");
	mainstruct->image_player = malloc(4 * sizeof(mlx_image_t));
	if (mainstruct->image_player == NULL)
		ft_error_message("Malloc Error");
	mainstruct->image_exit = malloc(sizeof(mlx_image_t));
	if (mainstruct->image_exit == NULL)
		ft_error_message("Malloc Error");
	ft_load_texture(mainstruct);
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

int	ft_load_texture(t_main *mainstruct)
{
	mainstruct->texture_bg = malloc(2 * sizeof(mlx_texture_t));
	if (mainstruct->texture_bg == NULL)
		ft_error_message("Malloc Error");
	mainstruct->texture_collectible = malloc(sizeof(mlx_texture_t));
	if (mainstruct->texture_collectible == NULL)
		ft_error_message("Malloc Error");
	mainstruct->texture_exit = malloc(sizeof(mlx_texture_t));
	if (mainstruct->texture_exit == NULL)
		ft_error_message("Malloc Error");
	mainstruct->texture_player = malloc(sizeof(mlx_texture_t)); // malloc de 4 si 4 textures player
	if (mainstruct->texture_player == NULL)
		ft_error_message("Malloc Error");
	ft_load_png(mainstruct);
	return (0);
}

int	ft_load_png(t_main *mainstruct)
{
	mainstruct->texture_bg[0] = mlx_load_png("./img/bg.png");
	if (mainstruct->texture_bg[0] == NULL)
		ft_error_message("Error loading background texture");
	mainstruct->texture_bg[1] = mlx_load_png("./img/wall.png");
	if (mainstruct->texture_bg[1] == NULL)
		ft_error_message("Error loading wall texture");
	mainstruct->texture_collectible[0] = mlx_load_png("./img/collectible.png");
	if (mainstruct->texture_collectible[0] == NULL)
		ft_error_message("Error loading collectible texture");
	mainstruct->texture_exit[0] = mlx_load_png("./img/exit.png");
	if (mainstruct->texture_exit[0] == NULL)
		ft_error_message("Error loading exit texture");
	mainstruct->texture_player[0] = mlx_load_png("./img/player.png");
	if (mainstruct->texture_player[0] == NULL)
		ft_error_message("Error loading player texture");
	return (0);
}
