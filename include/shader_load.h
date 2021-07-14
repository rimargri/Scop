/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader_load.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 18:31:20 by cvernius          #+#    #+#             */
/*   Updated: 2021/07/14 16:55:46 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADER_LOAD_H
#define SHADER_LOAD_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
#define MAX_SHADER 1000000

char	*read_shader(const char *filename);

#endif
