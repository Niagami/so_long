/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:39:08 by jteste            #+#    #+#             */
/*   Updated: 2023/12/29 15:30:28 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_message(char *message)
{
	write(2, "Error\n", 7);
	if (message != NULL)
		write(2, message, ft_strlen(message));
	exit(0);
}
