/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:44:26 by toshota           #+#    #+#             */
/*   Updated: 2024/06/05 16:43:20 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// コンストラクタ：インスタンスが生成されるときに呼び出されるもの
Zombie::Zombie(std::string name) : m_name(name) {}

// デストラクタ：インスタンスが破棄されるときに呼び出されるもの
Zombie::~Zombie()
{
	std::cout << "(destructor)" << this->m_name << " is destroyed" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->m_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
