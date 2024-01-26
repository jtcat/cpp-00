/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookApp.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcat <joaoteix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:39:58 by jcat              #+#    #+#             */
/*   Updated: 2024/01/26 09:44:18 by jcat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <exception>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <ostream>
#include <string>

const std::string	readValidInput(void)
{
	std::string	input;

	if (!std::cin)
		std::terminate();
	std::cin >> input;
	return input;
}

void	add_prompt(PhoneBook &pb)
{
	Contact		newContact;

	std::cout << "*** Adding new contact ***\n" << std::endl;
	std::cout << "Insert first name: ";
	while (!newContact.setFirstName(readValidInput()))
		std::cout << std::endl << "Invalid name, try again: ";
	std::cout << std::endl << "Insert last name: ";
	while (!newContact.setLastName(readValidInput()))
		std::cout << std::endl <<  "Invalid name, try again: ";
	std::cout << std::endl << "Insert nickname: ";
	while (!newContact.setNickName(readValidInput()))
		std::cout << std::endl <<  "Invalid name, try again: ";
	std::cout << std::endl << "Insert phone number: ";
	while (!newContact.setPhoneNumb(readValidInput()))
		std::cout << std::endl <<  "Invalid phone number, try again: ";
	std::cout << std::endl << "Insert secret: ";
	newContact.setSecret(readValidInput());
	pb.addContact(newContact);
}

void	printContact(Contact &contact) {
	std::cout << "First name: " << contact.getFirstName()
		<< "\nLast name: " << contact.getLastName()
		<< "\nNickname: " << contact.getNickName()
		<< "\nPhone number: " << contact.getPhoneNumb()
		<< "\nSecret: " << contact.getSecret() << std::endl;;
}

void	search_prompt(PhoneBook &pb)
{
	int		i;
	Contact	&contact = pb.getContact(0);

	if (pb.getContactNum() == 0)
	{
		std::cout << "No contacts present" << std::endl;
		return ;
	}
	std::cout << "INDEX | FIRST NAME | LAST NAME | NICKNAME" << std::endl;
	for (i = 0; i < pb.getContactNum(); ++i)
	{
		contact = pb.getContact(i);
		std::cout << std::setw(10) << i << '|';
		std::cout << std::setw(10) << contact.getFirstName() << '|';
		std::cout << std::setw(10) << contact.getLastName() << '|';
		std::cout << std::setw(10) << contact.getNickName();
		std::cout << std::endl;
	}
	std::cout << std::endl << "Select contact index: ";
	while (std::cin)
	{
		std::cin >> i;
		if (i >= 0 && i < pb.getContactNum())
			break;
		std::cout << std::endl << "Invalid index, try again: ";
	}
	contact = pb.getContact(i);
	printContact(contact);
}

void	main_prompt(PhoneBook &pb)
{
	std::string	input;

	while (std::cin)
	{
		std::cout << "Insert a command: ";
		std::cin >> input;
		if (input == "EXIT")
			return ; 
		else if (input == "ADD")
			add_prompt(pb);
		else if (input == "SEARCH")
			search_prompt(pb);
	}
}

int	main(void)
{
	PhoneBook	pb;

	std::cout << "*** 42 Phonebook Manager ***\n" << std::endl;
	main_prompt(pb);
	return 0;
}
