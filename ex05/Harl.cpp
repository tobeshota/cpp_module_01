/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:54:27 by toshota           #+#    #+#             */
/*   Updated: 2024/06/10 18:25:17 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#define DEBUG_LOG                     \
  "I love having extra bacon for my " \
  "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
#define INFO_LOG                                                            \
  "I cannot believe adding extra bacon costs more money. You didn’t put " \
  "enough bacon in my burger! If you did, I wouldn’t be asking for more!"
#define WARNING_LOG                                                              \
  "I think I deserve to have some extra bacon for free. I’ve been coming for " \
  "years whereas you started working here since last month."
#define ERROR_LOG "This is unacceptable! I want to speak to the manager now."

void Harl::debug(void) { std::cout << DEBUG_LOG << std::endl; }

void Harl::info(void) { std::cout << INFO_LOG << std::endl; }

void Harl::warning(void) { std::cout << WARNING_LOG << std::endl; }

void Harl::error(void) { std::cout << ERROR_LOG << std::endl; }

/**関数ポインタ
 * return_type (*pointer_name)(parameter_types);
 */
void Harl::complain(std::string level) {
  void (Harl::*complain_action[])(void) = {&Harl::debug, &Harl::info,
                                           &Harl::warning, &Harl::error};
  std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
  std::size_t levels_size = sizeof(levels) / sizeof(levels[0]);

  for (std::size_t i = 0; i < levels_size; i++) {
    if (level == levels[i]) return (this->*complain_action[i])();
  }
  std::cerr << "complain supports following level: DEBUG, INFO, WARNING, ERROR"
            << std::endl;
}
