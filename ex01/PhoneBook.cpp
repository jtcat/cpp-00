/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoteix <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:54:59 by joaoteix          #+#    #+#             */
/*   Updated: 2023/11/22 13:48:47 by joaoteix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

class PhoneBook {
	public:
		~PhoneBook() {
			while (--_contact_n)
				delete _contacts[_contact_n];
		}

		void	addContact(Contact contact) {
			if (_contact_n == 8) {	
				delete _contacts[_contact_n - 1];
				_contacts[_contact_n] = contact;
			}
			else {
				_contacts[_contact_n] = contact;
				_contact_n++;
			}
		}

		const Contact	*getContacts(void) {
			return _contacts;
		}
}
