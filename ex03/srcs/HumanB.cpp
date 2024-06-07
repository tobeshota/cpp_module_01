/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:47:51 by toshota           #+#    #+#             */
/*   Updated: 2024/06/07 15:26:06 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : m_name(name) {}

void HumanB::setWeapon(Weapon& weapon)
{
	this->m_weapon = &weapon;
	nullptr;
}

void HumanB::attack(void) const
{
	if (this->m_weapon)
		std::cout << this->m_name << " attacks with their " << this->m_weapon->getType() << std::endl;
	else
		std::cout << this->m_name << " has no weapon!" << std::endl;
}
