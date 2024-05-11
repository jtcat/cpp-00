/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoteix <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:54:59 by joaoteix          #+#    #+#             */
/*   Updated: 2024/05/11 20:23:50 by joaoteix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook(void) : _contacts_n(0), _contacts_i(0) {}

void	PhoneBook::addContact(const Contact &contact)
{
	_contacts[_contacts_i] = contact;
	_contacts_i = (_contacts_i + 1) % MAX_CONTACTS;
	_contacts_n += _contacts_n < MAX_CONTACTS;
}

const Contact*	PhoneBook::getContact(int index)
{
	return _contacts + index;
}

int		PhoneBook::getContactNum(void)
{
	return _contacts_n;
}

const Contact	*PhoneBook::getContacts(void)
{
	return _contacts;
}
