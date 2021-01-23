/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_model_view_projection_mat.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 21:41:33 by cvernius          #+#    #+#             */
/*   Updated: 2021/01/23 21:45:54 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include <stdio.h>

// void	translate_mat4_arr(t_scop *s, t_mat4 mvp)
// {

// 	s->opengl.mvp[0][0] = mvp.a;
// 	s->opengl.mvp[0][1] = mvp.b;
// 	s->opengl.mvp[0][2] = mvp.c;
// 	s->opengl.mvp[0][3] = mvp.d;

// 	s->opengl.mvp[1][0] = mvp.e;
// 	s->opengl.mvp[1][1] = mvp.f;
// 	s->opengl.mvp[1][2] = mvp.g;
// 	s->opengl.mvp[1][3] = mvp.h;

// 	s->opengl.mvp[2][0] = mvp.i;
// 	s->opengl.mvp[2][1] = mvp.j;
// 	s->opengl.mvp[2][2] = mvp.k;
// 	s->opengl.mvp[2][3] = mvp.l;

// 	s->opengl.mvp[3][0] = mvp.m;
// 	s->opengl.mvp[3][1] = mvp.n;
// 	s->opengl.mvp[3][2] = mvp.o;
// 	s->opengl.mvp[3][3] = mvp.p;
// }

// void	perspective_projection_check(t_opengl *ogl, float camera_distance)
// {
// 	ogl->mvp[0] = 1.0f;
// 	ogl->mvp[1] = 0.0f;
// 	ogl->mvp[2] = 0.0f;
// 	ogl->mvp[3] = 0.0f;

// 	ogl->mvp[4] = 0.0f;
// 	ogl->mvp[5] = 1.0f;
// 	ogl->mvp[6] = 0.0f;
// 	ogl->mvp[7] = 0.0f;

// 	ogl->mvp[8] = 0.0f;
// 	ogl->mvp[9] = 0.0f;
// 	ogl->mvp[10] = 1.0f;
// 	ogl->mvp[11] = 0.0f;

// 	ogl->mvp[12] = 0.0f;
// 	ogl->mvp[13] = 0.0f;
// 	ogl->mvp[14] = -1.0f / camera_distance;
// 	ogl->mvp[15] = 1.0f;

// }



void ComputeFOVProjection(t_scop *s, float fov, float aspect, float nearDist, float farDist, int leftHanded /* = true */ )
{
    //
    // General form of the Projection Matrix
    //
    // uh = Cot( fov/2 ) == 1/Tan(fov/2)
    // uw / uh = 1/aspect
    // 
    //   uw         0       0       0
    //    0        uh       0       0
    //    0         0      f/(f-n)  1
    //    0         0    -fn/(f-n)  0
    //
    // Make result to be identity first

    // check for bad parameters to avoid divide by zero:
    // if found, assert and return an identity matrix.
    if ( fov <= 0 || aspect == 0 )
    {
        // Assert( fov > 0 && aspect != 0 );
        return;
    }

    float frustumDepth = farDist - nearDist;
    float oneOverDepth = 1 / frustumDepth;

    // result[1][1] = 1 / tan(0.5f * fov);
    // result[0][0] = (leftHanded ? 1 : -1 ) * result[1][1] / aspect;
    // result[2][2] = farDist * oneOverDepth;
    // result[3][2] = (-farDist * nearDist) * oneOverDepth;
    // result[2][3] = 1;
    // result[3][3] = 0;


	s->opengl.mvp[4] = 0.0f;
	s->opengl.mvp[5] = 1 / tan(0.5f * fov);
	s->opengl.mvp[6] = 0.0f;
	s->opengl.mvp[7] = 0.0f;

	s->opengl.mvp[0] = (leftHanded ? 1 : -1 ) * s->opengl.mvp[5] / aspect;
	s->opengl.mvp[1] = 0.0f;
	s->opengl.mvp[2] = 0.0f;
	s->opengl.mvp[3] = 0.0f;

	s->opengl.mvp[8] = 0.0f;
	s->opengl.mvp[9] = 0.0f;
	s->opengl.mvp[10] = farDist * oneOverDepth;
	s->opengl.mvp[11] = 1.0f;

	s->opengl.mvp[12] = 0.0f;
	s->opengl.mvp[13] = 0.0f;
	s->opengl.mvp[14] = (-farDist * nearDist) * oneOverDepth;
	s->opengl.mvp[15] = 0.0f;

}


void	create_model_view_projection_mat(t_scop *s)
{
	t_mat mat;
	float camera_distance = 0.5f;

	s->opengl.mvp = (float*)(malloc(sizeof(float) * 16));
	(s->opengl.mvp == NULL ? exit(99) : 1);

	// float farDist = 100.0f;
	// float nearDist = 0.1f;

	float farDist = 100.0f;
	float nearDist = 1.0f;

	// float S = 1.0f / (tan((FOV / 2) * M_PI / 180));
	// float f = - (farDist / (farDist - nearDist));
	// float f2 = - (farDist * nearDist / (farDist - nearDist));

	float first_arg = 1.0f / tan(FOV / 2);
	float t_arg = (- nearDist - farDist) / (nearDist - farDist);
	float f_arg = (2 * farDist * nearDist) / (nearDist - farDist);

	s->opengl.mvp[0] = first_arg;
	s->opengl.mvp[1] = 0.0f;
	s->opengl.mvp[2] = 0.0f;
	s->opengl.mvp[3] = 0.0f;

	s->opengl.mvp[4] = 0.0f;
	s->opengl.mvp[5] = first_arg;
	s->opengl.mvp[6] = 0.0f;
	s->opengl.mvp[7] = 0.0f;

	s->opengl.mvp[8] = 0.0f;
	s->opengl.mvp[9] = 0.0f;
	s->opengl.mvp[10] = t_arg;
	s->opengl.mvp[11] = f_arg;

	s->opengl.mvp[12] = 0.0f;
	s->opengl.mvp[13] = 0.0f;
	s->opengl.mvp[14] = 1.0f;
	s->opengl.mvp[15] = 0.0f;



	// s->opengl.mvp[0] = -1.0f;
	// s->opengl.mvp[1] = 0.0f;
	// s->opengl.mvp[2] = 0.0f;
	// s->opengl.mvp[3] = 0.0f;

	// s->opengl.mvp[4] = -1.0f;
	// s->opengl.mvp[5] = 1.0f;
	// s->opengl.mvp[6] = 0.0f;
	// s->opengl.mvp[7] = 0.0f;

	// s->opengl.mvp[8] = -1.0f;
	// s->opengl.mvp[9] = 0.0f;
	// s->opengl.mvp[10] = 1.0f;
	// s->opengl.mvp[11] = 0.0f;

	// s->opengl.mvp[12] = 0.0f;
	// s->opengl.mvp[13] = 0.0f;
	// s->opengl.mvp[14] = 0.0f;
	// s->opengl.mvp[15] = 1.0f;


	// ComputeFOVProjection(s, FOV, 1.0f, 0.1f, 100.0f, 1);


	// 	1.0f, 0.0f, 0.0f, 0.0f,
	// 	0.0f, 1.0f, 0.0f, 0.0f,
	// 	0.0f, 0.0f, 1.0f, 0.0f,
	// 	0.0f, 0.0f, 0.0f, 1.0f		
	// };

	// mat.projection = build_perspective_projection(s);
	// perspective_projection_check(&s->opengl, camera_distance);

	// for (int i = 0; i < 16; i++)
	// 	printf("%f\n", s->opengl.mvp[i]);

	s->opengl.matrix_id = glGetUniformLocation(s->opengl.program_id, "mvp");

	// mat.view = create_view_mat((t_vec3){4, 3, 3},
	// 							(t_vec3){0, 0, 0},
	// 							(t_vec3){0, 1, 0});
	// mat.model = create_model_mat();
	// mat.mvp = mult_matrix(
	// 							mult_matrix(mat.projection, mat.view), mat.model);
	
	// translate_mat4_arr(s, mat.mvp);
	// return (mat.transform);
}
