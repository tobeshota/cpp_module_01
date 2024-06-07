/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOUtils.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:33:00 by toshota           #+#    #+#             */
/*   Updated: 2024/06/07 22:37:20 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IOUTILS_HPP
# define IOUTILS_HPP

#include <iostream>

class IOUtils
{
public:
	typedef enum s_exit_status
	{
		NORMAL,
		ERROR
	}		t_exit_status;
	static void exit_with_msg(const std::string msg, const IOUtils::s_exit_status exit_status);
};

#endif
