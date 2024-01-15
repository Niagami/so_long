/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:08:12 by jteste            #+#    #+#             */
/*   Updated: 2024/01/15 13:35:20 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_display_image(t_main *mainstruct)
{
	ft_display_bg(mainstruct);
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
			mlx_image_to_window(smain->mlx_ptr, smain->image_bg[i], k * 64, j * 64);
			i++;
			k++;
		}
		j++;
	}
	return (0);
}
