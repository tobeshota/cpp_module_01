/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:22:35 by toshota           #+#    #+#             */
/*   Updated: 2024/06/07 15:53:31 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB
{
private:
	// HumanBが保持するWeaponが参照型でなくポインタ型である理由は
	// HumanBは武器を必ずしも持たないため
		// ・参照型の変数はポインタ型のそれとは異なり，nullptr(何も指さない)を代入できない
	Weapon *m_weapon;
	std::string m_name;
public:
	HumanB(std::string name);
	void setWeapon(Weapon& weapon);	//	中でアドレスを参照する場合には，同じアドレスを共有する参照を用いたい
	void attack(void) const;
};

#endif
