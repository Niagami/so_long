/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:40:12 by jteste            #+#    #+#             */
/*   Updated: 2024/01/11 17:03:45 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_texture_to_image(t_main *mainstruct)
{
	ft_bg_image(mainstruct);
	ft_collectible_image(mainstruct);
	ft_exit_image(mainstruct);
	return (0);
}

int	ft_bg_image(t_main *mainstruct)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (i < mainstruct->map_size)
	{
		k = 0;
		while (mainstruct->map[j][k] != '\0' && mainstruct->map[j][k] != '\n')
		{
			if (mainstruct->map[j][k] == '1')
				mainstruct->image_bg[i] = mlx_texture_to_image
					(mainstruct->mlx_ptr, mainstruct->texture_bg[1]);
			else
				mainstruct->image_bg[i] = mlx_texture_to_image
					(mainstruct->mlx_ptr, mainstruct->texture_bg[0]);
			i++;
			k++;
		}
		j++;
	}
	printf("Taille de la map :%d\n", mainstruct->map_size);
	printf("nb d'image de bg :%d\n", i);
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
				i++;
			}
			k++;
		}
		j++;
	}
	printf("nb de collectible :%d\n", mainstruct->collectible_count);
	printf("nb d'image de collectible :%d\n", i);
	return (0);
}

int	ft_exit_image(t_main *mainstruct)
{
	mainstruct->image_exit[0] = mlx_texture_to_image
		(mainstruct->mlx_ptr, mainstruct->texture_exit[0]);
	return (0);
}
