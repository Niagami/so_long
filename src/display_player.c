/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:30:50 by jteste            #+#    #+#             */
/*   Updated: 2024/01/16 15:44:08 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_player_up(t_main *mainstruct)
{
	mainstruct->index = 0;
	while (mainstruct->index < mainstruct->wall_count)
	{	
		if (((mainstruct->player_pos_y - 1) == mainstruct->wall[mainstruct->index].y)
			&& (mainstruct->player_pos_x == mainstruct->wall[mainstruct->index].x))
		{
			return ;
		}
		mainstruct->index++;
	}
	mainstruct->image_player[0]->instances[0].y -= 64;
	mainstruct->player_pos_y--;
	ft_printf("you mooved %d times\n", mainstruct->moove_count++);
	return ;
}

void	ft_player_down(t_main *mainstruct)
{
	mainstruct->index = 0;
	while (mainstruct->index < mainstruct->wall_count)
	{	
		if (((mainstruct->player_pos_y + 1) == mainstruct->wall[mainstruct->index].y)
			&& (mainstruct->player_pos_x == mainstruct->wall[mainstruct->index].x))
		{
			return ;
		}
		mainstruct->index++;
	}
	mainstruct->image_player[0]->instances[0].y += 64;
	mainstruct->player_pos_y++;
	ft_printf("you mooved %d times\n", mainstruct->moove_count++);
	return ;
}

void	ft_player_right(t_main *mainstruct)
{
	mainstruct->index = 0;
	while (mainstruct->index < mainstruct->wall_count)
	{	
		if (((mainstruct->player_pos_x + 1) == mainstruct->wall[mainstruct->index].x) 
			&& (mainstruct->player_pos_y == mainstruct->wall[mainstruct->index].y))
		{
			return ;
		}
		mainstruct->index++;
	}
	mainstruct->image_player[0]->instances[0].x += 64;
	mainstruct->player_pos_x++;
	ft_printf("you mooved %d times\n", mainstruct->moove_count++);
	return ;
}

void	ft_player_left(t_main *mainstruct)
{
	mainstruct->index = 0;
	while (mainstruct->index < mainstruct->wall_count)
	{	
		if (((mainstruct->player_pos_x - 1) == mainstruct->wall[mainstruct->index].x)
			&& (mainstruct->player_pos_y == mainstruct->wall[mainstruct->index].y))
		{
			return ;
		}
		mainstruct->index++;
	}
	mainstruct->image_player[0]->instances[0].x -= 64;
	mainstruct->player_pos_x--;
	ft_printf("you mooved %d times\n", mainstruct->moove_count++);
	return ;
}
