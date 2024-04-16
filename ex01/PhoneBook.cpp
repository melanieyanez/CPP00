/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 19:42:24 by melanieyane       #+#    #+#             */
/*   Updated: 2024/04/16 15:50:04 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int PhoneBook::_ContactCount = 0;
int PhoneBook::_ContactTotal = 0;

PhoneBook::PhoneBook(void) {
	
	std::cout << "Welcome into the best phonebook in the universe!" << std::endl;
	return ;
}

PhoneBook::~PhoneBook(void){
	
	std::cout << "You have successfully left the best phonebook in the universe." << std::endl;
	return ;
}

void PhoneBook::_CheckData(std::string text, std::string field) {
	std::string	prompt;
	
	std::cout << "Enter the " << text << ":" << std::endl;
	std::getline(std::cin, prompt);
	while (prompt.empty()) {
		std::cout << "Error! Field cannot be empty." << std::endl;
		std::cout << "Enter the " << text << ":" << std::endl;
		std::getline(std::cin, prompt);
	}
	if (prompt == "EXIT")
	{
		std::cout << "You have successfully left the best phonebook in the universe." << std::endl;
		exit (0);
	}
	this->_Contacts[PhoneBook::_ContactCount].set_info(field, prompt);
}

void	PhoneBook::AddContact(void) {
	
	std::string prompt;
	
	std::cin.ignore();
	while (42)
	{
		if (PhoneBook::_ContactTotal == 8){
			std::cout << "Limit reached! A contact will be replaced. Do you want to continue? (Y/N)?" << std::endl;
			std::getline(std::cin, prompt);
			while (prompt != "Y" && prompt != "N"){
				std::cout << "Invalid entry. Please enter Y or N:" << std::endl;
				std::getline(std::cin, prompt);
			}
			if (prompt == "N") {
				std::cout << "Contact addition cancelled." << std::endl;
				return;
			}
		}
		PhoneBook::_CheckData("first name", "FirstName");
		PhoneBook::_CheckData("last name", "LastName");
		PhoneBook::_CheckData("nickname", "NickName");
		PhoneBook::_CheckData("phone number", "PhoneNumber");
		PhoneBook::_CheckData("darkest secret", "DarkestSecret");
		break;
	}
	if (PhoneBook::_ContactTotal == 8)
		std::cout << "Contact replaced." << std::endl;
	else
		std::cout << "Contact added." << std::endl;
	PhoneBook::_ContactCount ++;
	PhoneBook::_ContactCount %= 8;
	if (PhoneBook::_ContactTotal < 8)
		PhoneBook::_ContactTotal++;
	return ;
}

void PhoneBook::SearchContact(void) {
	std::string prompt;
	int			index;
	
	std::cin.ignore();
	if (PhoneBook::_ContactTotal){
		PhoneBook::_DisplayList();
		while (42){
			if (PhoneBook::_ContactTotal == 1)
				std::cout << "Enter the index of the contact whose details you want to see (1):" << std::endl;
			else
				std::cout << "Enter the index of the contact whose details you want to see (1->" << PhoneBook::_ContactTotal << "):" << std::endl;
			std::getline(std::cin, prompt);
			if (prompt == "EXIT"){
				std::cout << "You have successfully left the best phonebook in the universe." << std::endl;
				exit(0);
			}
			try {
            	index = std::stoi(prompt);
                if (index >= 1 && index <= PhoneBook::_ContactTotal) {
                	break ;
                }
				else if (index > 8)
					 std::cout << "The phonebook cannot hold more than 8 contacts." << std::endl;
				else
                	std::cout << "No entry for this index." << std::endl;
                } catch (const std::invalid_argument&) {
                    std::cout << "Error! Invalid input." << std::endl;
                } catch (const std::out_of_range&) {
                    std::cout << "Error! Invalid input." << std::endl;
                }
		}
		PhoneBook::_DisplayContact(index);
	}
	else {
		std::cout << "The phonebook is empty." << std::endl;
		return;
	}
}

void	PhoneBook::_DisplayList(void){
	std::cout << "     Index|First Name| Last Name|  Nickname|" << std::endl;
	for(int i = 0; i < _ContactTotal; i++){
		std::cout << std::setw(10) << std::setfill(' ') << std::right << i + 1 << "|";
		if (PhoneBook::_Contacts[i].get_info("FirstName").length() > 10)
			std::cout << std::setw(10) << std::setfill(' ') << std::right << PhoneBook::_Contacts[i].get_info("FirstName").substr(0, 9) + "." << "|";
		else
			std::cout << std::setw(10) << std::setfill(' ') << std::right << PhoneBook::_Contacts[i].get_info("FirstName") << "|";
		if (PhoneBook::_Contacts[i].get_info("LastName").length() > 10)
			std::cout << std::setw(10) << std::setfill(' ') << std::right << PhoneBook::_Contacts[i].get_info("LastName").substr(0, 9) + "." << "|";
		else
			std::cout << std::setw(10) << std::setfill(' ') << std::right << PhoneBook::_Contacts[i].get_info("LastName") << "|";
		if (PhoneBook::_Contacts[i].get_info("NickName").length() > 10)
			std::cout << std::setw(10) << std::setfill(' ') << std::right << PhoneBook::_Contacts[i].get_info("NickName").substr(0, 9) + "." << "|";
		else
			std::cout << std::setw(10) << std::setfill(' ') << std::right << PhoneBook::_Contacts[i].get_info("NickName") << "|";
		std::cout << std::endl;
  	}
}

void	PhoneBook::_DisplayContact(int index){
	std::cout << "First Name: " << _Contacts[index - 1].get_info("FirstName") << std::endl;
	std::cout << "Last Name: " << _Contacts[index - 1].get_info("LastName") << std::endl;
	std::cout << "Nickname: " << _Contacts[index - 1].get_info("NickName") << std::endl;
	std::cout << "Phone number: " << _Contacts[index - 1].get_info("PhoneNumber") << std::endl;
	std::cout << "Darkest secret: " << _Contacts[index - 1].get_info("DarkestSecret") << std::endl;
}

