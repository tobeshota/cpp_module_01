/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:57:01 by toshota           #+#    #+#             */
/*   Updated: 2024/06/05 18:32:19 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
  private:
	std::string m_name;
  public:
	Zombie();
	~Zombie();
	void set_name(std::string name);
	void announce(void);
};

Zombie *zombieHorde(int N, std::string name);

#endif
