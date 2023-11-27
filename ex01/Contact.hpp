/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoteix <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:47:10 by joaoteix          #+#    #+#             */
/*   Updated: 2023/11/22 13:43:19 by joaoteix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

class Contact {
	private:
		std::string	_firstName;

		std::string	_lastName;

		std::string	_nickName;

		std::string	_phoneNumb;

		std::string	_secret;

	public:
		Contact();

		~Contact();

		std::string	getFirstName();

		std::string	getLastName();

		std::string	getPhoneNumb();

#endif
