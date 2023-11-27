/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookApp.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoteix <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:50:09 by joaoteix          #+#    #+#             */
/*   Updated: 2023/11/27 16:46:53 by joaoteix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include <iomanip>

std::view

void	add_prompt(void)
{
}

void	search_prompt(void)
{
	std::cout << std::setiosflags(std::ios::right) << std::setw(10);
	std::cout << "     INDEX    |FIRST NAME| LAST NAME| nickname " << std::endl;
	std::cout << "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" << std::endl;
}

void	main_prompt(void)
{
	std::string	input;

	do {
		std::cout << "Insert a command: ";
		std::cin >> input;
		if (input == "ADD")
			add_prompt();
		else if (input == "SEARCH")
			search_prompt();
	}
	while (std::cin && input != "EXIT");
}

int	main(int argc, char **argv) {
	std::cout << "*** Phonebook Manager ***" << std::endl;
	main_prompt();
}
