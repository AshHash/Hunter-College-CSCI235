/**
//	
//	Atta Saleh
//	EMPLID 14187529
//	3/15/19
//	Project 2C	
//
//	Instructor.hpp 
*/


#ifndef Instructor_hpp
#define Instructor_hpp

#include "CourseMember.hpp"
#include <string>
#include <iostream>

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

 	virtual void displayMember() const override;

private:

	std::string office_;
 	std::string contact_;
 };
#endif