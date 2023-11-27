/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoteix <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:52:21 by joaoteix          #+#    #+#             */
/*   Updated: 2023/11/11 14:52:54 by joaoteix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

class Contact {
	public:
		std::string	getFirstName(){
			return firstName;
		}

		std::string	getLastName(){
			return lastName;
		}

		std::string	getPhoneNumb(){
			return phoneNumb;
		}
}
