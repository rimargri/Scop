/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 18:29:52 by cvernius          #+#    #+#             */
/*   Updated: 2020/10/05 19:13:00 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	error_processing(int code)
{
	if (code == 0)
		printf("mlx was destroyed\n");
	if (code == 1)
		printf("init gl error\n");
	if (code == 2)
		printf("failed to inicialize glfw!\n");
	if (code == 3)
		printf("Failed to open GLFW opengl window.\n");
	exit (0);
}
