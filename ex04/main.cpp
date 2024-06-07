/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:57:30 by toshota           #+#    #+#             */
/*   Updated: 2024/06/07 20:29:55 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IOUtils.hpp"
#include "Sed.hpp"
#define ARGC_ERRMSG "usage:\n ft_sed <filename> <s1> <s2>"

int	main(int argc, char **argv)
{
	if (argc != 4)
		IOUtils::exit_with_msg(ARGC_ERRMSG, IOUtils::ERROR);
	Sed(argv[1], argv[2], argv[3]);
}

#ifdef DEBUG

__attribute__((destructor)) static void destructor()
{
	system("leaks -q ft_sed");
}

#endif
