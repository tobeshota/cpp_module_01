/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:57:01 by toshota           #+#    #+#             */
/*   Updated: 2024/06/05 16:40:45 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
  private:
	std::string m_name;
	/* data */
  public:
	Zombie(std::string name);
	~Zombie();
	void announce(void);
};

Zombie *newZombile(std::string name);
void randomChump(std::string name);

#endif
