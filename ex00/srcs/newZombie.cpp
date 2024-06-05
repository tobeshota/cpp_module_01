/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:53:19 by toshota           #+#    #+#             */
/*   Updated: 2024/06/05 16:39:09 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// 関数の外で使用するメモリはヒープ領域で確保する
// ヒープに作成したゾンビは明示的に削除する必要がある
Zombie *newZombile(std::string name)
{
	Zombie *zombie_heap;
	zombie_heap = new Zombie(name);
	return zombie_heap;
}
