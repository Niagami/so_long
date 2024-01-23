/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 12:45:34 by jteste            #+#    #+#             */
/*   Updated: 2024/01/23 16:32:34 by jteste           ###   ########.fr       */
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

# define WIDTH 2560
# define HEIGHT 1440

typedef struct s_collectible
{
	int		x;
	int		y;
	bool	collected;
}	t_collectible;

typedef struct s_wall
{
	int		x;
	int		y;
}	t_wall;

typedef struct s_exit
{
	int		x;
	int		y;
}	t_exit;

typedef struct s_main
{
	char			*mapname;
	char			**map;
	int				map_size;
	int				count_line;
	int				map_exit;
	int				collectible_count;
	int				wall_count;
	int				start_pos;
	int				player_pos_x;
	int				player_pos_y;
	void			*mlx_ptr;
	void			*win_ptr;
	mlx_image_t		**image_bg;
	mlx_image_t		**image_wall;
	mlx_image_t		**image_collectible;
	mlx_image_t		**image_player;
	mlx_image_t		**image_exit;
	mlx_texture_t	**texture_player;
	mlx_texture_t	**texture_bg;
	mlx_texture_t	**texture_exit;
	mlx_texture_t	**texture_collectible;
	mlx_texture_t	**texture_wall;
	t_collectible	*collectible;
	t_wall			*wall;
	t_exit			*exit;
	int				index;
	int				count;
	int				moove_count;
	int				collected;
}				t_main;

int		ft_struct_init(t_main *mainstruct);
int		ft_open_map(t_main *mainstruct);
void	ft_copy_map(t_main *mainstruct);
int		ft_check_map(t_main *mainstruct);
int		ft_check_size(t_main *mainstruct);
int		ft_check_sign(t_main *mainstruct);
int		ft_check_count(t_main *mainstruct);
int		ft_check_walls(t_main *mainstruct);
int		ft_check_format(t_main *mainstruct);
void	ft_save_player_pos(t_main *mainstruct, int i, int j);
void	ft_save_collectible_pos(t_main *mainstruct);
int		ft_flood_fill(char	**map, int x, int y, int *items);
void	ft_error_message(char *message, int boolean);
int		ft_load_texture(t_main *mainstruct);
int		ft_load_image(t_main *mainstruct);
int		ft_map_size(t_main *mainstruct);
int		ft_load_png(t_main *mainstruct);
int		ft_texture_to_image(t_main *mainstruct);
int		ft_bg_image(t_main *mainstruct);
int		ft_collectible_image(t_main *mainstruct);
int		ft_wall_image(t_main *mainstruct);
int		ft_exit_image(t_main *mainstruct);
int		ft_player_image(t_main *mainstruct);
int		ft_display_image(t_main *mainstruct);
void	ft_count_wall(t_main *mainstruct);
void	ft_save_wall_pos(t_main *mainstruct);
void	ft_save_exit_pos(t_main *mainstruct);
int		ft_display_bg(t_main *smain);
int		ft_display_collectible(t_main *smain);
int		ft_display_exit(t_main *smain);
int		ft_display_wall(t_main *smain);
void	my_keyhook(mlx_key_data_t keydata, void *param);
void	ft_player_up(t_main *mainstruct);
void	ft_player_down(t_main *mainstruct);
void	ft_player_left(t_main *mainstruct);
void	ft_player_right(t_main *mainstruct);
void	ft_display_item(void *param);
void	ft_free_all(t_main *mainstruct, char *message, int boolean);
void	ft_free_map(t_main *mainstruct);
void	ft_free_image(t_main *mainstruct);
void	ft_free_texture(t_main *mainstruct);
void	ft_free_wall(t_main *mainstruct);
#endif
