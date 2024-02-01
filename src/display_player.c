/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:30:50 by jteste            #+#    #+#             */
/*   Updated: 2024/02/01 16:52:07 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_player_up(t_main *s)
{
	s->index = 0;
	while (s->index < s->wall_count)
	{	
		if (((s->player_pos_y - 1) == s->wall[s->index].y)
			&& (s->player_pos_x == s->wall[s->index].x))
			return ;
		s->index++;
	}
	s->image_player[0]->instances[0].y -= 64;
	s->player_pos_y--;
	ft_printf("you mooved %d times\n", s->moove_count++);
	ft_display_item(s);
	return ;
}

void	ft_player_down(t_main *s)
{
	s->index = 0;
	while (s->index < s->wall_count)
	{	
		if (((s->player_pos_y + 1) == s->wall[s->index].y)
			&& (s->player_pos_x == s->wall[s->index].x))
		{
			return ;
		}
		s->index++;
	}
	s->image_player[0]->instances[0].y += 64;
	s->player_pos_y++;
	ft_printf("you mooved %d times\n", s->moove_count++);
	ft_display_item(s);
	return ;
}

void	ft_player_right(t_main *s)
{
	s->index = 0;
	while (s->index < s->wall_count)
	{	
		if (((s->player_pos_x + 1) == s->wall[s->index].x)
			&& (s->player_pos_y == s->wall[s->index].y))
		{
			return ;
		}
		s->index++;
	}
	s->image_player[0]->instances[0].x += 64;
	s->player_pos_x++;
	ft_printf("you mooved %d times\n", s->moove_count++);
	ft_display_item(s);
	return ;
}

void	ft_player_left(t_main *s)
{
	s->index = 0;
	while (s->index < s->wall_count)
	{	
		if (((s->player_pos_x - 1) == s->wall[s->index].x)
			&& (s->player_pos_y == s->wall[s->index].y))
		{
			return ;
		}
		s->index++;
	}
	s->image_player[0]->instances[0].x -= 64;
	s->player_pos_x--;
	ft_printf("you mooved %d times\n", s->moove_count++);
	ft_display_item(s);
	return ;
}
