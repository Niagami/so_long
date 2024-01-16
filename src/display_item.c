/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_item.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:06:55 by jteste            #+#    #+#             */
/*   Updated: 2024/01/16 17:07:52 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_display_item(void *param)
{
	t_main	*mainstruct;
	int		i;

	mainstruct = param;
	i = 0;
	while (i < mainstruct->collectible_count)
	{
		if ((mainstruct->player_pos_x == mainstruct->collectible[i].x) && (mainstruct->player_pos_y == mainstruct->collectible[i].y))
		{
			mlx_delete_image(mainstruct->mlx_ptr, mainstruct->image_collectible[i]);
			mainstruct->collected++;
			return ;
		}
		i++;
	}
}
