/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOUtils.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:33:00 by toshota           #+#    #+#             */
/*   Updated: 2024/06/10 19:18:14 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IOUtils.hpp"

void IOUtils::exit_with_msg(const std::string msg, const int exit_status)
{
	std::cout << msg << std::endl;
	std::exit(exit_status);
}
