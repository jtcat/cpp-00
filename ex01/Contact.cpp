/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoteix <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:52:21 by joaoteix          #+#    #+#             */
/*   Updated: 2024/05/11 18:49:31 by joaoteix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <cctype>
#include <cstddef>
#include <string>
#include <cwctype>

std::wstring	Contact::getFirstName(void) const
{
	return _firstName;
}

std::wstring	Contact::getLastName(void) const
{
	return _lastName;
}

std::wstring	Contact::getNickName(void) const
{
	return _nickName;
}

std::wstring	Contact::getPhoneNumb(void) const
{
	return _phoneNumb;
}

std::wstring	Contact::getSecret(void) const
{
	return _secret;
}

static bool	valField(const std::wstring &str, int (*charValidator)(std::wint_t))
{
	std::size_t	i;

	if (str.empty())
		return false;
	if (!charValidator)
		return true;
	for (i = 0; i < str.length(); i++)
		if (!charValidator(static_cast<wchar_t>(str[i])))
			return false;
	return true;
}

bool	Contact::setFirstName(const std::wstring &firstName)
{
	if (!valField(firstName, std::iswalpha))
		return false;
	_firstName = firstName;
	return true;
}

bool	Contact::setLastName(const std::wstring &lastName)
{
	if (!valField(lastName, std::iswalpha))
		return false;
	_lastName = lastName;
	return true;
}

bool	Contact::setNickName(const std::wstring &nickName)
{
	if (!valField(nickName, std::iswalpha))
		return false;
	_nickName = nickName;
	return true;
}

bool	Contact::setPhoneNumb(const std::wstring &phoneNumb)
{
	if (!valField(phoneNumb, iswdigit))
		return false;
	_phoneNumb = phoneNumb;
	return true;
}

bool	Contact::setSecret(const std::wstring &secret)
{
	if (!valField(secret, NULL))
		return false;
	_secret = secret;
	return true;
}
