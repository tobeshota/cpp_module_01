/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:54:17 by toshota           #+#    #+#             */
/*   Updated: 2024/06/10 18:27:30 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#ifndef TEST

int main(int argc, char **argv)
{
	Harl harl;
	if (argc == 2)
		harl.filter(argv[1]);
}

#else

int main(int argc, char **argv)
{
	Harl harl;
	std::string test_param[] = {"DEBUG", "INFO", "WARNING", "ERROR", "hoge"};
	std::size_t test_param_size = sizeof(test_param) / sizeof(test_param[0]);

	(void)argc;
	for (std::size_t i = 0; i < test_param_size; i++)
	{
		std::cout << "- " << i << " -----" << std::endl;
		std::cout << argv[0] << " " + test_param[i] << std::endl;
		harl.filter(test_param[i]);
	}
}

#endif

#ifdef DEBUG

__attribute__((destructor)) static void destructor()
{
	system("leaks -q ft_sed");
}

#endif
