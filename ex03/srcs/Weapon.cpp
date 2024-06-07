/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:16:33 by toshota           #+#    #+#             */
/*   Updated: 2024/06/07 15:34:14 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : m_type(type) {}

std::string const& Weapon::getType() const
{
	return this->m_type;
}

void Weapon::setType(std::string type)
{
	this->m_type = type;
}
