/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_model_view_projection_mat.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 21:41:33 by cvernius          #+#    #+#             */
/*   Updated: 2020/12/09 20:09:19 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include <stdio.h>

void	translate_mat4_arr(t_scop *s, t_mat4 mvp)
{

	s->opengl.mvp[0][0] = mvp.a;
	s->opengl.mvp[0][1] = mvp.b;
	s->opengl.mvp[0][2] = mvp.c;
	s->opengl.mvp[0][3] = mvp.d;

	s->opengl.mvp[1][0] = mvp.e;
	s->opengl.mvp[1][1] = mvp.f;
	s->opengl.mvp[1][2] = mvp.g;
	s->opengl.mvp[1][3] = mvp.h;

	s->opengl.mvp[2][0] = mvp.i;
	s->opengl.mvp[2][1] = mvp.j;
	s->opengl.mvp[2][2] = mvp.k;
	s->opengl.mvp[2][3] = mvp.l;

	s->opengl.mvp[3][0] = mvp.m;
	s->opengl.mvp[3][1] = mvp.n;
	s->opengl.mvp[3][2] = mvp.o;
	s->opengl.mvp[3][3] = mvp.p;
}

void	perspective_projection_check(t_opengl *ogl, float camera_distance)
{
	ogl->mvp[0][0] = 1.0f;
	ogl->mvp[0][1] = 0.0f;
	ogl->mvp[0][2] = 0.0f;
	ogl->mvp[0][3] = 0.0f;

	ogl->mvp[1][0] = 0.0f;
	ogl->mvp[1][1] = 1.0f;
	ogl->mvp[1][2] = 0.0f;
	ogl->mvp[1][3] = 0.0f;

	ogl->mvp[2][0] = 0.0f;
	ogl->mvp[2][1] = 0.0f;
	ogl->mvp[2][2] = 1.0f;
	ogl->mvp[2][3] = 0.0f;

	ogl->mvp[3][0] = 0.0f;
	ogl->mvp[3][1] = 0.0f;
	ogl->mvp[3][2] = -1.0f / camera_distance;
	ogl->mvp[3][3] = 1.0f;

}

void	create_model_view_projection_mat(t_scop *s)
{
	t_mat mat;
	float camera_distance = 0.5f;

	int i;

	i = 0;
	s->opengl.mvp = malloc(sizeof(float) * 4);
	if (!(s->opengl.mvp))
		exit(99);
	while (i < 4)
	{
		s->opengl.mvp[i] = malloc(sizeof(float) * 4);
		if (!(s->opengl.mvp[i]))
			exit(11);
		i++;
	}


	// mat.projection = build_perspective_projection(s);
	perspective_projection_check(&s->opengl, camera_distance);
	// mat.view = create_view_mat((t_vec3){4, 3, 3},
	// 							(t_vec3){0, 0, 0},
	// 							(t_vec3){0, 1, 0});
	// mat.model = create_model_mat();
	// mat.mvp = mult_matrix(
	// 							mult_matrix(mat.projection, mat.view), mat.model);
	
	// translate_mat4_arr(s, mat.mvp);
	// printf("%f\n", s->opengl.mvp[0][1]);
	// return (mat.transform);
}
