/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:08:54 by jteste            #+#    #+#             */
/*   Updated: 2024/01/23 17:04:36 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_save_exit_pos(t_main *mainstruct)
{
	int	j;

	mainstruct->index = 0;
	mainstruct->exit = ft_calloc(1, sizeof(t_exit));
	if (mainstruct->exit == NULL)
		ft_free_all(mainstruct, "Malloc error", 1);
	while (mainstruct->map[mainstruct->index] != NULL)
	{
		j = 0;
		while (mainstruct->map[mainstruct->index][j] != '\0')
		{
			if (mainstruct->map[mainstruct->index][j] == 'E')
			{
				mainstruct->exit[0].x = j;
				mainstruct->exit[0].y = mainstruct->index;
			}
			j++;
		}
		mainstruct->index++;
	}
}
int	ft_wall_image(t_main *mainstruct)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (i < mainstruct->wall_count)
	{
		k = 0;
		while (mainstruct->map[j][k] != '\0' && mainstruct->map[j][k] != '\n')
		{
			if (mainstruct->map[j][k] == '1')
			{
				mainstruct->image_wall[i] = mlx_texture_to_image
					(mainstruct->mlx_ptr, mainstruct->texture_wall[0]);
				if (!mainstruct->image_wall)
					ft_free_all(mainstruct, "Error loading texture to image", 1);
				i++;
			}
			k++;
		}
		j++;
	}
	return (0);
}
int	ft_display_wall(t_main *smain)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (i < smain->wall_count)
	{
		k = 0;
		while (smain->map[j][k] != '\0' && smain->map[j][k] != '\n')
		{
			if (smain->map[j][k] == '1')
			{
				mlx_image_to_window(smain->mlx_ptr,
					smain->image_wall[i], k * 64, j * 64);
				i++;
			}
			k++;
		}
		j++;
	}
	return (0);
}
void	ft_free_wall(t_main *mainstruct)
{
	int	i;

	i = 0;
	while (mainstruct->image_wall && i < mainstruct->wall_count)
	{
		mlx_delete_image(mainstruct->mlx_ptr, mainstruct->image_wall[i]);
		i++;
	}
	free(mainstruct->image_wall);
}
