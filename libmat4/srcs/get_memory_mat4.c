/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_memory_mat4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 19:26:43 by cvernius          #+#    #+#             */
/*   Updated: 2021/03/14 19:28:48 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat4.h"

void	get_memory_mat4(float *mat)
{
	mat = malloc(sizeof(float) * 16);
	if (!mat)
		exit(0);
}
