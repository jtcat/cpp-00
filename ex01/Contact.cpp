/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoteix <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:52:21 by joaoteix          #+#    #+#             */
/*   Updated: 2024/05/14 11:33:50 by joaoteix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <cctype>
#include <cstddef>
#include <string>
#include <cwctype>

std::string	Contact::getFirstName(void) const
{
	return _firstName;
}

std::string	Contact::getLastName(void) const
{
	return _lastName;
}

std::string	Contact::getNickName(void) const
{
	return _nickName;
}

std::string	Contact::getPhoneNumb(void) const
{
	return _phoneNumb;
}

std::string	Contact::getSecret(void) const
{
	return _secret;
}

static bool	valField(const std::string &str, int (*charValidator)(int))
{
	std::size_t	i;

	if (str.empty())
		return false;
	if (!charValidator)
		return true;
	for (i = 0; i < str.length(); i++)
		if (!charValidator(static_cast<int>(str[i])))
			return false;
	return true;
}

bool	Contact::setFirstName(const std::string &firstName)
{
	if (!valField(firstName, std::isalpha))
		return false;
	_firstName = firstName;
	return true;
}

bool	Contact::setLastName(const std::string &lastName)
{
	if (!valField(lastName, std::isalpha))
		return false;
	_lastName = lastName;
	return true;
}

bool	Contact::setNickName(const std::string &nickName)
{
	if (!valField(nickName, std::isalpha))
		return false;
	_nickName = nickName;
	return true;
}

bool	Contact::setPhoneNumb(const std::string &phoneNumb)
{
	if (!valField(phoneNumb, isdigit))
		return false;
	_phoneNumb = phoneNumb;
	return true;
}

bool	Contact::setSecret(const std::string &secret)
{
	if (!valField(secret, NULL))
		return false;
	_secret = secret;
	return true;
}
