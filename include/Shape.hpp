/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shape.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 21:25:14 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/10/19 21:47:20 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <array>
#define COUNT_VERTEX 12

class Shape
{
	public:
		std::array<float, COUNT_VERTEX> arrayVertex;
		// void getVertexShape(void);
	Shape();
};
