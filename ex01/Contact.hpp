/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoteix <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:47:10 by joaoteix          #+#    #+#             */
/*   Updated: 2024/05/11 17:48:06 by joaoteix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact {
	private:
		std::wstring	_firstName;

		std::wstring	_lastName;

		std::wstring	_nickName;

		std::wstring	_phoneNumb;

		std::wstring	_secret;

	public:
//		Contact();
//
//		~Contact();
		bool		valName(const std::wstring &str);

		std::wstring	getFirstName(void) const;
		std::wstring	getLastName(void) const;
		std::wstring	getNickName(void) const;
		std::wstring	getPhoneNumb(void) const;
		std::wstring	getSecret(void) const;

		bool	setFirstName(const std::wstring &firstName);
		bool	setLastName(const std::wstring &lastName);
		bool	setNickName(const std::wstring &nickName);
		bool	setPhoneNumb(const std::wstring &phoneNumb);
		bool	setSecret(const std::wstring &secret);
};
#endif
