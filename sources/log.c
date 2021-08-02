/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:41:37 by cvernius          #+#    #+#             */
/*   Updated: 2021/07/14 18:43:31 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "log_scop.h"
#include "../libft/libft.h"

void	log_scop(const char *error, enum errors code)
{
	ft_putstr_fd(error, 2);
	exit(code);
}
