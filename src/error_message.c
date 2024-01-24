/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:39:08 by jteste            #+#    #+#             */
/*   Updated: 2024/01/24 15:17:51 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error_message(char *message, int boolean)
{
	if (boolean == 1)
		ft_printf("Error\n");
	if (message != NULL)
		ft_printf("%s\n", message);
	return (0);
}

void	ft_free_all(t_main *mainstruct, char *message, int boolean)
{
	free(mainstruct->mapname);
	ft_free_map(mainstruct);
	ft_free_texture(mainstruct);
	ft_free_image(mainstruct);
	if (mainstruct->collectible)
		free(mainstruct->collectible);
	if (mainstruct->wall)
		free(mainstruct->wall);
	if (mainstruct->exit)
		free(mainstruct->exit);
	if (mainstruct->mlx_ptr)
		mlx_terminate(mainstruct->mlx_ptr);
	ft_error_message(message, boolean);
	exit(0);
}

void	ft_free_map(t_main *mainstruct)
{
	int	i;

	i = 0;
	if (mainstruct->map)
	{
		while (i <= mainstruct->count_line)
		{
			free(mainstruct->map[i]);
			i++;
		}
		free(mainstruct->map);
	}
}

void	ft_free_image(t_main *mainstruct)
{
	int	i;

	i = 0;
	while (mainstruct->image_bg && i < mainstruct->map_size)
	{
		mlx_delete_image(mainstruct->mlx_ptr, mainstruct->image_bg[i]);
		i++;
	}
	free(mainstruct->image_bg);
	i = 0;
	while (mainstruct->image_collectible && i < mainstruct->collectible_count)
	{
		mlx_delete_image(mainstruct->mlx_ptr, mainstruct->image_collectible[i]);
		i++;
	}
	free(mainstruct->image_collectible);
	if (mainstruct->image_exit)
		mlx_delete_image(mainstruct->mlx_ptr, mainstruct->image_exit[0]);
	free(mainstruct->image_exit);
	if (mainstruct->image_player)
		mlx_delete_image(mainstruct->mlx_ptr, mainstruct->image_player[0]);
	free(mainstruct->image_player);
	ft_free_wall(mainstruct);
}

void	ft_free_texture(t_main *mainstruct)
{
	if (mainstruct->texture_bg)
	{
		mlx_delete_texture(mainstruct->texture_bg[0]);
		free(mainstruct->texture_bg);
	}
	if (mainstruct->texture_collectible)
	{
		mlx_delete_texture(mainstruct->texture_collectible[0]);
		free(mainstruct->texture_collectible);
	}
	if (mainstruct->texture_exit)
	{
		mlx_delete_texture(mainstruct->texture_exit[0]);
		free(mainstruct->texture_exit);
	}
	if (mainstruct->texture_player)
	{
		mlx_delete_texture(mainstruct->texture_player[0]);
		free(mainstruct->texture_player);
	}
	if (mainstruct->texture_wall)
	{
		mlx_delete_texture(mainstruct->texture_wall[0]);
		free(mainstruct->texture_wall);
	}
}
