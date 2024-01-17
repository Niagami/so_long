/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:39:08 by jteste            #+#    #+#             */
/*   Updated: 2024/01/17 13:38:16 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_message(char *message)
{
	ft_printf("Error\n");
	if (message != NULL)
		ft_printf("%s\n", message);
	exit(0);
}
