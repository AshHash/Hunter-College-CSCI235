/**
//	
//	Atta Saleh
//	EMPLID 14187529
//	3/15/19
//	Project 2C	
//
//	Definitions of member functions of the class Student
*/

#include "Student.hpp"

//Parameterized constructor
Student::Student(int id, std::string first, std::string last):
CourseMember(0, "test", "test")
{
	id_ = id;				//Student's unique ID
	first_name_ = first;	//First name
	last_name_ = last;		//Last name 
}
//Returns Student major_
std::string Student::getMajor() const
{
	return major_;
}
 	
//Returns student gpa_
double Student::getGpa() const
{
	return gpa_;
}
 	
//Sets major_
void Student::setMajor(const std::string major)
{
	major_ = major;
}

//Sets gpa_
void Student::setGpa(const double gpa)
{
	gpa_ = gpa;
}

void Student::displayMember() const
{
	std::cout << getFirstName() << " " << getLastName() << " majors in " << major_ << " with gpa: " << gpa_;
}

