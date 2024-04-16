/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 19:47:08 by melanieyane       #+#    #+#             */
/*   Updated: 2024/04/16 15:35:26 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {
	
	return ;
}

Contact::~Contact(void) {

	return ;
}

void	Contact::set_info(std::string What, std::string Value) {
	if (What == "FirstName")
		this->_FirstName = Value;
	else if (What == "LastName")
		this->_LastName = Value;
	else if (What == "NickName")
		this->_NickName = Value;
	else if (What == "PhoneNumber")
		this->_PhoneNumber = Value;
	else if (What == "DarkestSecret")
		this->_DarkestSecret = Value;
}

std::string	Contact::get_info(std::string What) {
	if (What == "FirstName")
		return this->_FirstName;
	else if (What == "LastName")
		return this->_LastName;
	else if (What == "NickName")
		return this->_NickName;
	else if (What == "PhoneNumber")
		return this->_PhoneNumber;
	else if (What == "DarkestSecret")
		return this->_DarkestSecret;
	return "NULL";
}