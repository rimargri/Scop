/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shape.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 21:26:23 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/10/21 18:46:11 by f0rsunka         ###   ########.fr       */
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

	arrayColors[0] = 1.0f;
	arrayColors[1] = 0.0f;
	arrayColors[2] = 0.0f;

	arrayColors[3] = 0.0f;
	arrayColors[4] = 1.0f;
	arrayColors[5] = 0.0f;

	arrayColors[6] = 0.0f;
	arrayColors[7] = 0.0f;
	arrayColors[8] = 1.0f;

	arrayColors[9] = 0.5f;
	arrayColors[10] = 0.5f;
	arrayColors[11] = 0.0f;

}
