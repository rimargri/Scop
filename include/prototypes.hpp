/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 20:05:07 by cvernius          #+#    #+#             */
/*   Updated: 2020/10/05 18:44:47 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	init_gl(t_opengl *opengl);
void	create_shaders(t_scop *scop);
void	sc_gl_loop(t_scop *scop);
void	create_shape(t_scop *s);

void	error_processing(int code, void *param);