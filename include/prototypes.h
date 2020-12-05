/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 20:05:07 by cvernius          #+#    #+#             */
/*   Updated: 2020/10/17 19:24:11 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	init_gl(t_opengl *opengl);
void	create_shaders(t_scop *scop);
void	scp_gl_loop(t_scop *scop);
void	create_shape(t_scop *s);

void	error_processing(int code, void *param);