/**
//	
//	Atta Saleh
//	EMPLID 14187529
//	2/15/19
//	Project 1B	
//
//	TeachingAssistant class implementation 
*/

#include "TeachingAssistant.hpp"

//Parameterized constructor for TeachingAssistant class
TeachingAssistant::TeachingAssistant(int id, std::string first, std::string last):
Student(0, "test", "test")
{
	id_ = id;				//Student's unique ID
	first_name_ = first;	//First name
	last_name_ = last;		//Last name 
	role_ = LAB_ASSISTANT;
}

//Returns hours_per_week
int TeachingAssistant::getHours() const
{
	return hours_per_week;
}

//Returns role_ enum
ta_role TeachingAssistant::getRole() const
{
	return role_;
}

//Sets hours_per_week
void TeachingAssistant::setHours(const int hours)
{
	hours_per_week = hours;
}

//Sets role_, defaults to LAB_ASSISTANT, or 0;
void TeachingAssistant::setRole(const ta_role role)
{
		role_ = role;
}


