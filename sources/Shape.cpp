/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shape.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 21:26:23 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/10/19 21:30:07 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Shape.hpp"

Shape::Shape() {
	arrayVertex[0] = -0.5f;
	arrayVertex[1] = -0.5f;
	arrayVertex[2] = 0.0f;

	arrayVertex[3] = 0.5f;
	arrayVertex[4] = -0.5f;
	arrayVertex[5] = 0.0f;

	arrayVertex[6] = -0.5f;
	arrayVertex[7] = 0.5f;
	arrayVertex[8] = 0.0f;

	arrayVertex[9] = 0.5f;
	arrayVertex[10] = 0.5f;
	arrayVertex[11] = 0.0f;
}
