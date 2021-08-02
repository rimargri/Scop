/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 18:29:52 by cvernius          #+#    #+#             */
/*   Updated: 2020/10/16 23:06:15 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	error_processing(int code, void *param)
{
	if (code == 0)
		printf("mlx was destroyed\n");
	if (code == 1)
		printf("init gl error\n");
	if (code == 2)
		printf("failed to inicialize glfw!\n");
	if (code == 3)
		printf("Failed to open GLFW opengl window.\n");
	if (code == 4)
		printf("ERROR: vertex shader index %u did not compile\n", *(GLuint*)(param));
	if (code == 5)
		printf("ERROR: fragment shader index %u did not compile\n", *(GLuint*)(param));
	if (code == 6)
		printf("ERROR: could not link shader program GL index %u\n", *(GLuint*)(param));
	
	
	exit (0);
}
