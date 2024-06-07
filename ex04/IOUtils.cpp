/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOUtils.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:33:00 by toshota           #+#    #+#             */
/*   Updated: 2024/06/07 17:45:38 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IOUtils.hpp"

void IOUtils::exit_with_msg(const std::string msg, const IOUtils::s_exit_status exit_status)
{
	std::cout << msg << std::endl;
	std::exit(exit_status);
}
