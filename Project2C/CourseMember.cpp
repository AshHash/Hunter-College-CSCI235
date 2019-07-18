/**
//	
//	Atta Saleh
//	EMPLID 14187529
//	3/15/19
//	Project 2C	
//
//	Definitions of member functions of the class CourseMember
*/

#include "CourseMember.hpp"

//Default constructor
CourseMember::CourseMember()
{
	id_ = 0;
	first_name_ = "";
	last_name_ = "";
}
//Parameterized constructor
CourseMember::CourseMember(int id, std::string first, std::string last)
{
		id_ = id;				//Student's unique ID
		first_name_ = first;	//First name
		last_name_ = last;		//Last name 
}

int CourseMember::getID() const
{
	return id_;
}

std::string CourseMember::getFirstName() const
{
	return first_name_;
}

std::string CourseMember::getLastName() const
{
	return last_name_;
}

