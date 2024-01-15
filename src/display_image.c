/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:08:12 by jteste            #+#    #+#             */
/*   Updated: 2024/01/15 15:08:22 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_display_image(t_main *mainstruct)
{
	ft_display_bg(mainstruct);
	ft_display_collectible(mainstruct);
	ft_display_exit(mainstruct);
	mlx_image_to_window(mainstruct->mlx_ptr, mainstruct->image_player[0], mainstruct->player_pos_x * 64, mainstruct->player_pos_y * 64);
	return (0);
}

int	ft_display_bg(t_main *smain)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (i < smain->map_size)
	{
		k = 0;
		while (smain->map[j][k] != '\0' && smain->map[j][k] != '\n')
		{
			mlx_image_to_window(smain->mlx_ptr,
				smain->image_bg[i], k * 64, j * 64);
			i++;
			k++;
		}
		j++;
	}
	return (0);
}

int	ft_display_collectible(t_main *smain)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (i < smain->collectible_count)
	{
		k = 0;
		while (smain->map[j][k] != '\0' && smain->map[j][k] != '\n')
		{
			if (smain->map[j][k] == 'C')
			{
				mlx_image_to_window(smain->mlx_ptr,
					smain->image_collectible[i], k * 64, j * 64);
				i++;
			}
			k++;
		}
		j++;
	}
	return (0);
}

int	ft_display_exit(t_main *smain)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (i < 1)
	{
		k = 0;
		while (smain->map[j][k] != '\0' && smain->map[j][k] != '\n')
		{
			if (smain->map[j][k] == 'E')
			{
				mlx_image_to_window(smain->mlx_ptr,
					smain->image_exit[i], k * 64, j * 64);
				i++;
			}
			k++;
		}
		j++;
	}
	return (0);
}

void	ft_hook(void *param)
{
	t_main	*mainstruct;

	mainstruct = param;
	if (mlx_is_key_down(mainstruct->mlx_ptr, MLX_KEY_ESCAPE))
		mlx_close_window(mainstruct->mlx_ptr);
	if (mlx_is_key_down(mainstruct->mlx_ptr, MLX_KEY_UP))
		mainstruct->image_player[0]->instances[0].y -= 64;
	if (mlx_is_key_down(mainstruct->mlx_ptr, MLX_KEY_DOWN))
		mainstruct->image_player[0]->instances[0].y += 64;
	if (mlx_is_key_down(mainstruct->mlx_ptr, MLX_KEY_LEFT))
		mainstruct->image_player[0]->instances[0].x -= 64;
	if (mlx_is_key_down(mainstruct->mlx_ptr, MLX_KEY_RIGHT))
		mainstruct->image_player[0]->instances[0].x += 64;
}
