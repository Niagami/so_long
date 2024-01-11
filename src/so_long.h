/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 12:45:34 by jteste            #+#    #+#             */
/*   Updated: 2024/01/11 16:58:58 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/stat.h>
# include <fcntl.h>

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_collectible
{
	int		x;
	int		y;
	bool	collected;
}	t_collectible;

typedef struct s_main
{
	char			*mapname;
	char			**map;
	int				map_size;
	int				count_line;
	int				map_exit;
	int				collectible_count;
	int				start_pos;
	int				player_pos_x;
	int				player_pos_y;
	void			*mlx_ptr;
	void			*win_ptr;
	mlx_image_t		**image_bg;
	mlx_image_t		**image_collectible;
	mlx_image_t		**image_player;
	mlx_image_t		**image_exit;
	mlx_texture_t	**texture_player;
	mlx_texture_t	**texture_bg;
	mlx_texture_t	**texture_exit;
	mlx_texture_t	**texture_collectible;
	t_collectible	*collectible;
	int				index;
}				t_main;

int		ft_struct_init(t_main *mainstruct);
int		ft_open_map(t_main *mainstruct);
int		ft_copy_map(t_main *mainstruct);
int		ft_check_map(t_main *mainstruct);
int		ft_check_size(t_main *mainstruct);
int		ft_check_sign(t_main *mainstruct);
int		ft_check_count(t_main *mainstruct);
int		ft_check_walls(t_main *mainstruct);
int		ft_check_format(t_main *mainstruct);
void	ft_save_player_pos(t_main *mainstruct, int i, int j);
void	ft_save_collectible_pos(t_main *mainstruct);
int		ft_flood_fill(char	**map, int x, int y, int *items);
void	ft_error_message(char *message);
int		ft_load_texture(t_main *mainstruct);
int		ft_load_image(t_main *mainstruct);
int		ft_map_size(t_main *mainstruct);
int		ft_load_png(t_main *mainstruct);
int		ft_texture_to_image(t_main *mainstruct);
int		ft_bg_image(t_main *mainstruct);
int		ft_collectible_image(t_main *mainstruct);
int		ft_exit_image(t_main *mainstruct);

#endif
