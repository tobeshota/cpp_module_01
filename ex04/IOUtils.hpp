/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOUtils.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:33:00 by toshota           #+#    #+#             */
/*   Updated: 2024/06/10 19:16:43 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IOUTILS_HPP
# define IOUTILS_HPP

#include <iostream>

namespace IOUtils
{
	void exit_with_msg(const std::string msg, const int exit_status);
}

#endif
