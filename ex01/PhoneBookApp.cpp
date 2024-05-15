/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookApp.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcat <joaoteix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:39:58 by jcat              #+#    #+#             */
/*   Updated: 2024/05/15 09:26:55 by joaoteix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <string>
#include <sstream>
#include <limits>
#include <csignal>

enum e_inputType
{
	INPUT_TYPE_STRING,
	INPUT_TYPE_LINE
};

const std::string	readValidInput(enum e_inputType inputType)
{
	std::string			line;
	std::string			tok;
	std::string			next_tok;

	std::getline(std::cin, line);

	if (!std::cin)
		return std::string();

	if (inputType == INPUT_TYPE_LINE) {
		return line;
	}

	std::stringstream	s(line);

	s >> tok;
	if (s >> next_tok)
		return std::string();

	return tok;
}

void	addContactPrompt(PhoneBook &pb)
{
	Contact		newContact;

	std::cout << "*** Adding new contact ***\n" << std::endl;
	std::cout << "Insert first name: ";
	while (!newContact.setFirstName(readValidInput(INPUT_TYPE_STRING))) {
		if (std::cin.eof())
			return ;
		std::cout << std::endl << "Invalid name, try again: ";
	}
	std::cout << std::endl << "Insert last name: ";
	while (!newContact.setLastName(readValidInput(INPUT_TYPE_STRING))) {
		if (std::cin.eof())
			return ;
		std::cout << std::endl <<  "Invalid name, try again: ";
	}
	std::cout << std::endl << "Insert nickname: ";
	while (!newContact.setNickName(readValidInput(INPUT_TYPE_STRING))) {
		if (std::cin.eof())
			return ;
		std::cout << std::endl <<  "Invalid name, try again: ";
	}
	std::cout << std::endl << "Insert phone number: ";
	while (!newContact.setPhoneNumb(readValidInput(INPUT_TYPE_STRING))) {
		if (std::cin.eof())
			return ;
		std::cout << std::endl <<  "Invalid phone number, try again: ";
	}
	std::cout << std::endl << "Insert secret: ";
	newContact.setSecret(readValidInput(INPUT_TYPE_LINE));
	if (std::cin.eof())
		return ;
	pb.addContact(newContact);
}

static void	printContact(const Contact &contact)
{
	std::cout << "First name: " << contact.getFirstName()
		<< "\nLast name: " << contact.getLastName()
		<< "\nNickname: " << contact.getNickName()
		<< "\nPhone number: " << contact.getPhoneNumb()
		<< "\nSecret: " << contact.getSecret() << std::endl;;
}

void	printTrunc(std::string str, size_t len) {
	if (str.length() > len)
		std::cout << std::right << std::setw(len) << str.substr(0, len - 1) + '.';
	else
		std::cout << std::right << std::setw(len) << str;
}

void	searchContactPrompt(PhoneBook &pb)
{
	int				i;
	const Contact*	contact;

	if (pb.getContactNum() == 0)
	{
		std::cout << "No contacts present" << std::endl;
		return ;
	}
	std::cout << "     INDEX|FIRST NAME| LAST NAME|  NICKNAME" << std::endl;
	for (i = 0; i < pb.getContactNum(); ++i)
	{
		contact = pb.getContact(i);
		std::cout << std::right << std::setw(10) << i << '|';
		printTrunc(contact->getFirstName(), 10);
		std::cout << '|';
		printTrunc(contact->getLastName(), 10);
		std::cout << '|';
		printTrunc(contact->getNickName(), 10);
		std::cout << std::endl;
	}
	std::cout << std::endl << "Select contact index: ";
	while (std::cin)
	{
		std::cin >> i;
		if (!std::cin)
		{
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << std::endl << "Invalid index, try again: ";
			continue;
		}
		if (i >= 0 && i < pb.getContactNum())
			break;
		std::cout << std::endl << "Invalid index, try again: ";
	}
	contact = pb.getContact(i);
	printContact(*contact);
}

void	mainPrompt(PhoneBook &pb)
{
	std::string	input;

	while (std::cin)
	{
		std::cout << "Insert a command: ";
		input = readValidInput(INPUT_TYPE_STRING);
		if (!std::cin || input == "EXIT")
			return ; 
		else if (input == "ADD")
			addContactPrompt(pb);
		else if (input == "SEARCH")
			searchContactPrompt(pb);
		else
		 	std::cout << "Unrecognized command. Try again" << std::endl;
		//std::cin.clear();
		//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

void	sig_handler(int signal)
{
	if (signal == SIGINT)
	{
		std::cout << "SIGINT" << std::endl;
		exit(1);
	}
}

int	main(void)
{
	PhoneBook	pb;

	//std::locale::global(std::locale(""));
//	std::locale	l("C.UTF-8");
//
//	std::setlocale(LC_ALL, "C.UTF-8");
//	std::cout.imbue(l);

//	std::cout.imbue(std::locale(""));
//	std::cin.imbue(std::locale(""));
	std::signal(SIGINT, sig_handler);

	std::cout << "*** 42 Phonebook Manager ***\n" << std::endl;
	mainPrompt(pb);
	return 0;
}
