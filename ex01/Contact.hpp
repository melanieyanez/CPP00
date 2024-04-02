#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact 
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
	public:
		Contact(void);
		void set_firstname();
		void set_lastname();
		void set_nickname();
		void set_phonenumber();
		void set_darkestsecret();

};

#endif