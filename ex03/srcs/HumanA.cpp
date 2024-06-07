/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:27:30 by toshota           #+#    #+#             */
/*   Updated: 2024/06/06 17:04:27 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : m_weapon(weapon) , m_name(name){}

void HumanA::attack(void) const
{
	std::cout << this->m_name << " attacks with their " << this->m_weapon.getType() << std::endl;
}
