/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 12:39:50 by jteste            #+#    #+#             */
/*   Updated: 2024/01/15 14:49:13 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_main	mainstruct;

	if (argc != 2)
	{
		ft_error_message("Wrong number of arguments");
		return (1);
	}
	mainstruct.mapname = ft_strdup(argv[1]);
	ft_struct_init(&mainstruct);
	ft_open_map(&mainstruct);
	ft_check_map(&mainstruct);
	mainstruct.mlx_ptr = mlx_init(WIDTH, HEIGHT, "So_long", false);
	if (mainstruct.mlx_ptr == NULL)
		return (1);
	ft_load_image(&mainstruct);
	ft_texture_to_image(&mainstruct);
	ft_display_image(&mainstruct);
	mlx_loop_hook(mainstruct.mlx_ptr, ft_hook, &mainstruct);
	mlx_loop(mainstruct.mlx_ptr);
	free(mainstruct.mlx_ptr);
	return (0);
}
