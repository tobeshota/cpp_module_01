/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:29:39 by toshota           #+#    #+#             */
/*   Updated: 2024/06/05 16:45:35 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


/** ヒープとスタックの使い分け
 * ■ヒープ
 * 関数のスコープ外でもゾンビを使用する場合，そのゾンビはヒープ領域で確保しなければならない．ヒープに作成したゾンビは明示的に削除する必要がある．
 *
 * ■スタック
 * 関数のスコープ内のみゾンビを使用する場合，そのゾンビはスタック領域で確保してよい．スタックに作成したゾンビは関数の終わりとともに自動的に削除される．
 */
int main(void)
{
	Zombie *zombie_heap = newZombile("zombie_heap");
	zombie_heap->announce();
	delete zombie_heap;

	randomChump("zombie_stack");
}

__attribute__((destructor)) static void destructor()
{
	system("leaks -q a.out");
}
