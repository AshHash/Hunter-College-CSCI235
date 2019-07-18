/**
//	
//	Atta Saleh
//	EMPLID 14187529
//	2/15/19
//	Project 1B	
//
//	Instructor class implementation 
*/

#include "Instructor.hpp"

//Parameterized constructor for Instructor class
Instructor::Instructor(int id, std::string first, std::string last):
CourseMember(0, "test", "test")
{
	id_ = id;				//Instructor's unique ID
	first_name_ = first;	//First name
	last_name_ = last;		//Last name 
}

//Returns office_
std::string Instructor::getOffice() const
{
	return office_;
}

//Returns contact_
std::string Instructor::getContact() const
{
	return contact_;
}

//Sets office_
void Instructor::setOffice(const std::string office)
{
	office_ = office;
}

//Sets contact_
void Instructor::setContact(const std::string contact)
{
	contact_ = contact;
}



