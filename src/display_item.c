/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_item.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:06:55 by jteste            #+#    #+#             */
/*   Updated: 2024/01/22 13:03:53 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_display_item(void *param)
{
	t_main	*s;
	int		i;

	s = param;
	i = 0;
	while (i < s->collectible_count)
	{
		if ((s->player_pos_x == s->collectible[i].x) && (s->player_pos_y
				== s->collectible[i].y) && s->collectible[i].collected == false)
		{
			s->image_collectible[i]->enabled = false;
			s->collectible[i].collected = true;
			s->collected++;
			return ;
		}
		i++;
	}
	if ((s->player_pos_x == s->exit[0].x) && (s->player_pos_y
			== s->exit[0].y) && (s->collected == s->collectible_count))
	{
		ft_free_all(s, "\n\n\nYou won the game in %d mooves, Congrats !! :D\n\n\n", 0);
	}
}
