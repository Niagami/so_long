/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:08:12 by jteste            #+#    #+#             */
/*   Updated: 2024/01/17 13:41:28 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_display_image(t_main *mainstruct)
{
	ft_display_bg(mainstruct);
	ft_display_collectible(mainstruct);
	ft_display_exit(mainstruct);
	mlx_image_to_window(mainstruct->mlx_ptr, mainstruct->image_player[0],
		mainstruct->player_pos_x * 64, mainstruct->player_pos_y * 64);
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

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_main	*mainstruct;

	mainstruct = param;
	if (keydata.key == MLX_KEY_W && ((keydata.action == MLX_PRESS)
			|| (keydata.action == MLX_REPEAT)))
		ft_player_up(mainstruct);
	if (keydata.key == MLX_KEY_S && ((keydata.action == MLX_PRESS)
			|| (keydata.action == MLX_REPEAT)))
		ft_player_down(mainstruct);
	if (keydata.key == MLX_KEY_D && ((keydata.action == MLX_PRESS)
			|| (keydata.action == MLX_REPEAT)))
		ft_player_right(mainstruct);
	if (keydata.key == MLX_KEY_A && ((keydata.action == MLX_PRESS)
			|| (keydata.action == MLX_REPEAT)))
		ft_player_left(mainstruct);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(mainstruct->mlx_ptr);
}
