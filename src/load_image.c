/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:40:12 by jteste            #+#    #+#             */
/*   Updated: 2024/01/15 13:40:39 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_texture_to_image(t_main *mainstruct)
{
	ft_bg_image(mainstruct);
	ft_collectible_image(mainstruct);
	ft_exit_image(mainstruct);
	ft_player_image(mainstruct);
	return (0);
}

int	ft_bg_image(t_main *smain)
{
	int	j;
	int	k;

	j = 0;
	while (smain->count < smain->map_size)
	{
		k = 0;
		while (smain->map[j][k] != '\0' && smain->map[j][k] != '\n')
		{
			if (smain->map[j][k] == '1')
				smain->image_bg[smain->count] = mlx_texture_to_image
					(smain->mlx_ptr, smain->texture_bg[1]);
			if (!smain->image_bg)
				ft_error_message("Error loading texture to image");
			else if (smain->map[j][k] != '1')
				smain->image_bg[smain->count] = mlx_texture_to_image
					(smain->mlx_ptr, smain->texture_bg[0]);
			if (!smain->image_bg)
				ft_error_message("Error loading texture to image");
			smain->count++;
			k++;
		}
		j++;
	}
	return (0);
}

int	ft_collectible_image(t_main *mainstruct)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (i < mainstruct->collectible_count)
	{
		k = 0;
		while (mainstruct->map[j][k] != '\0' && mainstruct->map[j][k] != '\n')
		{
			if (mainstruct->map[j][k] == 'C')
			{
				mainstruct->image_collectible[i] = mlx_texture_to_image
					(mainstruct->mlx_ptr, mainstruct->texture_collectible[0]);
				if (!mainstruct->image_collectible)
					ft_error_message("Error loading texture to image");
				i++;
			}
			k++;
		}
		j++;
	}
	return (0);
}

int	ft_exit_image(t_main *mainstruct)
{
	mainstruct->image_exit[0] = mlx_texture_to_image
		(mainstruct->mlx_ptr, mainstruct->texture_exit[0]);
	if (!mainstruct->image_exit)
		ft_error_message("Error loading texture to image");
	return (0);
}

int	ft_player_image(t_main *mainstruct)
{
	mainstruct->image_player[0] = mlx_texture_to_image
		(mainstruct->mlx_ptr, mainstruct->texture_player[0]);
	if (!mainstruct->image_player)
		ft_error_message("Error loading texture to image");
	return (0);
}
