/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 12:39:50 by jteste            #+#    #+#             */
/*   Updated: 2024/02/01 16:55:24 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_main	mainstruct;

	if (argc != 2)
		return (ft_error_message("Wrong number of arguments", 1));
	ft_bzero(&mainstruct, sizeof(t_main));
	mainstruct.mapname = ft_strdup(argv[1]);
	if (!mainstruct.mapname)
		ft_free_all(&mainstruct, "Malloc error", 1);
	if alse)
		ft_free_all(&mainstruct, "Wrong map for(ft_check_format(&mainstruct) == fmat\n", 1);
	mainstruct.moove_count = 1;
	ft_open_map(&mainstruct);
	ft_check_map(&mainstruct);
	mainstruct.mlx_ptr = mlx_init((ft_strlen(mainstruct.map[0]) - 1) * 64,
			mainstruct.count_line * 64, "so_long", false);
	if (mainstruct.mlx_ptr == NULL)
		return (1);
	ft_load_image(&mainstruct);
	ft_texture_to_image(&mainstruct);
	ft_display_image(&mainstruct);
	mlx_key_hook(mainstruct.mlx_ptr, &my_keyhook, &mainstruct);
	mlx_close_hook(mainstruct.mlx_ptr, &my_close_hook, &mainstruct);
	mlx_loop(mainstruct.mlx_ptr);
	return (0);
}
