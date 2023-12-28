/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 12:45:34 by jteste            #+#    #+#             */
/*   Updated: 2023/12/28 15:50:06 by jteste           ###   ########.fr       */
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

typedef struct s_main
{
	char	**map;
	int		count_line;
}				t_main;

int	ft_open_map(t_main *mainstruct);
int	ft_copy_map(t_main *mainstruct);
int	ft_checkmap(t_main *mainstruct);
int	ft_checksize(t_main *mainstruct);

#endif
