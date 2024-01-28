/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoteix <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:52:21 by joaoteix          #+#    #+#             */
/*   Updated: 2024/01/28 11:43:42 by joaoteix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <cctype>
#include <cstddef>
#include <string>

const std::string	&Contact::getFirstName(void){
	return _firstName;
}

const std::string	&Contact::getLastName(void){
	return _lastName;
}

const std::string	&Contact::getNickName(void){
	return _nickName;
}

const std::string	&Contact::getPhoneNumb(void){
	return _phoneNumb;
}

const std::string	&Contact::getSecret(void){
	return _secret;
}

static bool	valField(const std::string &str, int (*charValidator)(int)) {
	std::size_t	i;

	if (str.empty())
		return false;
	for (i = 0; i < str.length() && charValidator(str[i]); i++)
		;
	return i == str.length();
}

bool	Contact::setFirstName(const std::string &firstName) {
	if (!valField(firstName, isalpha))
		return false;
	_firstName = firstName;
	return true;
}

bool	Contact::setLastName(const std::string &lastName) {
	if (!valField(lastName, isalpha))
		return false;
	_lastName = lastName;
	return true;
}

bool	Contact::setNickName(const std::string &nickName) {
	if (!valField(nickName, isalpha))
		return false;
	_nickName = nickName;
	return true;
}

bool	Contact::setPhoneNumb(const std::string &phoneNumb) {
	if (!valField(phoneNumb, isdigit))
		return false;
	_phoneNumb = phoneNumb;
	return true;
}

bool	Contact::setSecret(const std::string &secret) {
	_secret = secret;
	return true;
}
