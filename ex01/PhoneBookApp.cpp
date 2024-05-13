/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookApp.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcat <joaoteix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:39:58 by jcat              #+#    #+#             */
/*   Updated: 2024/05/13 15:09:37 by joaoteix         ###   ########.fr       */
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
#include <locale>
#include <limits>

enum e_inputType
{
	INPUT_TYPE_STRING,
	INPUT_TYPE_LINE
};

const std::wstring	readValidInput(enum e_inputType inputType)
{
	std::wstring	input;

	if (inputType == INPUT_TYPE_STRING) {

		std::wcin >> input;
		std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	else if (inputType == INPUT_TYPE_LINE)
		std::getline(std::wcin, input);
	if (!std::wcin)
		return std::wstring();
	return input;
}

void	add_prompt(PhoneBook &pb)
{
	Contact		newContact;

	std::wcout << "*** Adding new contact ***\n" << std::endl;
	std::wcout << "Insert first name: ";
	while (!newContact.setFirstName(readValidInput(INPUT_TYPE_STRING))) {
		if (std::wcin.eof())
			return ;
		std::wcout << std::endl << "Invalid name, try again: ";
	}
	std::wcout << std::endl << "Insert last name: ";
	while (!newContact.setLastName(readValidInput(INPUT_TYPE_STRING))) {
		if (std::wcin.eof())
			return ;
		std::wcout << std::endl <<  "Invalid name, try again: ";
	}
	std::wcout << std::endl << "Insert nickname: ";
	while (!newContact.setNickName(readValidInput(INPUT_TYPE_STRING))) {
		if (std::wcin.eof())
			return ;
		std::wcout << std::endl <<  "Invalid name, try again: ";
	}
	std::wcout << std::endl << "Insert phone number: ";
	while (!newContact.setPhoneNumb(readValidInput(INPUT_TYPE_STRING))) {
		if (std::wcin.eof())
			return ;
		std::wcout << std::endl <<  "Invalid phone number, try again: ";
	}
	std::wcout << std::endl << "Insert secret: ";
	newContact.setSecret(readValidInput(INPUT_TYPE_LINE));
	if (std::wcin.eof())
		return ;
	pb.addContact(newContact);
}

static void	printContact(const Contact &contact)
{
	std::wcout << "First name: " << contact.getFirstName()
		<< "\nLast name: " << contact.getLastName()
		<< "\nNickname: " << contact.getNickName()
		<< "\nPhone number: " << contact.getPhoneNumb()
		<< "\nSecret: " << contact.getSecret() << std::endl;;
}

void	printTrunc(std::wstring str, size_t len) {
	if (str.length() > len)
		std::wcout << std::right << std::setw(len) << str.substr(0, len - 1) + L'.';
	else
		std::wcout << std::right << std::setw(len) << str;
}

void	search_prompt(PhoneBook &pb)
{
	int				i;
	const Contact*	contact;

	if (pb.getContactNum() == 0)
	{
		std::wcout << L"No contacts present" << std::endl;
		return ;
	}
	std::wcout << "     INDEX|FIRST NAME| LAST NAME|  NICKNAME" << std::endl;
	for (i = 0; i < pb.getContactNum(); ++i)
	{
		contact = pb.getContact(i);
		std::wcout << std::right << std::setw(10) << i << '|';
		printTrunc(contact->getFirstName(), 10);
		std::wcout << '|';
		printTrunc(contact->getLastName(), 10);
		std::wcout << '|';
		printTrunc(contact->getNickName(), 10);
		std::wcout << std::endl;
	}
	std::wcout << std::endl << "Select contact index: ";
	while (std::wcin)
	{
		std::wcin >> i;
		if (!std::wcin)
		{
			std::wcin.clear();
			std::wcin.ignore(10000, '\n');
			std::wcout << std::endl << L"Invalid index, try again: ";
			continue;
		}
		if (i >= 0 && i < pb.getContactNum())
			break;
		std::wcout << std::endl << L"Invalid index, try again: ";
	}
	contact = pb.getContact(i);
	printContact(*contact);
}

void	main_prompt(PhoneBook &pb)
{
	std::wstring	input;

	while (std::wcin)
	{
		std::wcout << L"Insert a command: ";
		std::wcin >> input;
		if (!std::wcin || input == L"EXIT")
			return ; 
		else if (input == L"ADD")
			add_prompt(pb);
		else if (input == L"SEARCH")
			search_prompt(pb);
		else
		 	std::wcout << L"Unrecognized command. Try again" << std::endl;
	}
}

int	main(void)
{
	PhoneBook	pb;

	//std::locale::global(std::locale(""));

	std::setlocale(LC_ALL, "C.UTF-8");
	std::wcout.imbue(std::locale("C.UTF-8"));

//	std::wcout.imbue(std::locale(""));
//	std::wcin.imbue(std::locale(""));
	std::wcout << L"*** 42 Phonebook Manager ***\n" << std::endl;
	main_prompt(pb);
	return 0;
}
