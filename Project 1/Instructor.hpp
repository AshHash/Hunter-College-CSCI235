/**
//	
//	Atta Saleh
//	EMPLID 14187529
//	2/15/19
//	Project 1B	
//
//	Instructor.hpp 
*/
#include "CourseMember.hpp"
#include <string>

class Instructor: public CourseMember
{
public:
	
	//Parameterized constructor for Instructor class
	Instructor(int id, std::string first, std::string last);

	//Returns office_
	std::string getOffice() const;

	//Returns contact_
 	std::string getContact() const;

 	//Sets office_
 	void setOffice(const std::string office);

 	//Sets contact_
 	void setContact(const std::string contact);

private:

	std::string office_;
 	std::string contact_;
 };