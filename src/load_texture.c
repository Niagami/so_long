/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:58:25 by jteste            #+#    #+#             */
/*   Updated: 2024/01/23 16:26:34 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_load_image(t_main *mainstruct)
{
	mainstruct->map_size = ft_map_size(mainstruct);
	mainstruct->image_bg = ft_calloc((mainstruct->map_size), sizeof(mlx_image_t));
	if (mainstruct->image_bg == NULL)
		ft_free_all(mainstruct, "Malloc error", 1);
	mainstruct->image_collectible = ft_calloc((mainstruct->collectible_count), sizeof(mlx_image_t));
	if (mainstruct->image_collectible == NULL)
		ft_free_all(mainstruct, "Malloc error", 1);
	mainstruct->image_player = ft_calloc(1, sizeof(mlx_image_t));
	if (mainstruct->image_player == NULL)
		ft_free_all(mainstruct, "Malloc error", 1);
	mainstruct->image_exit = ft_calloc(1, sizeof(mlx_image_t));
	if (mainstruct->image_exit == NULL)
		ft_free_all(mainstruct, "Malloc error", 1);
	mainstruct->image_wall = ft_calloc(mainstruct->wall_count, sizeof(mlx_image_t));
	if (mainstruct->image_exit == NULL)
		ft_free_all(mainstruct, "Malloc error", 1);
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
	mainstruct->texture_bg = ft_calloc(1, sizeof(mlx_texture_t));
	if (mainstruct->texture_bg == NULL)
		ft_free_all(mainstruct, "Malloc error", 1);
	mainstruct->texture_collectible = ft_calloc(1, sizeof(mlx_texture_t));
	if (mainstruct->texture_collectible == NULL)
		ft_free_all(mainstruct, "Malloc error", 1);
	mainstruct->texture_exit = ft_calloc(1, sizeof(mlx_texture_t));
	if (mainstruct->texture_exit == NULL)
		ft_free_all(mainstruct, "Malloc error", 1);
	mainstruct->texture_player = ft_calloc(1, sizeof(mlx_texture_t));
	if (mainstruct->texture_player == NULL)
		ft_free_all(mainstruct, "Malloc error", 1);
	mainstruct->texture_wall = ft_calloc(1, sizeof(mlx_texture_t));
	if (mainstruct->texture_wall == NULL)
		ft_free_all(mainstruct, "Malloc error", 1);
	ft_load_png(mainstruct);
	return (0);
}

int	ft_load_png(t_main *mainstruct)
{
	mainstruct->texture_bg[0] = mlx_load_png("./img/bg.png");
	if (mainstruct->texture_bg[0] == NULL)
		ft_free_all(mainstruct, "Error loading background texture", 1);
	mainstruct->texture_collectible[0] = mlx_load_png("./img/collectible.png");
	if (mainstruct->texture_collectible[0] == NULL)
		ft_free_all(mainstruct, "Error loading collectible texture", 1);
	mainstruct->texture_exit[0] = mlx_load_png("./img/exit.png");
	if (mainstruct->texture_exit[0] == NULL)
		ft_free_all(mainstruct, "Error loading exit texture", 1);
	mainstruct->texture_player[0] = mlx_load_png("./img/player.png");
	if (mainstruct->texture_player[0] == NULL)
		ft_free_all(mainstruct, "Error loading player texture", 1);
	mainstruct->texture_wall[0] = mlx_load_png("./img/wall.png");
	if (mainstruct->texture_wall[0] == NULL)
		ft_free_all(mainstruct, "Error loading wall texture", 1);
	return (0);
}
