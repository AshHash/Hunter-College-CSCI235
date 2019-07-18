/*
 Atta Saleh
 EMPLID 14187529
 Project 2C
 Polytest implementation
*/

#include "polytest.hpp"
#include "List.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <cstdlib>

void populateCmList(List<CourseMember*>& cm_list, std::string input_file)
{
	std::ifstream input;
	input.open(input_file.c_str());
	std::string title; 						//placeholder for titles
	std::string first_name_, last_name_; 	//placeholder for first and last names
	std::string holdInt; 					//Holds string int to be converted to int;
	int id;
	while(!input.eof())
	{
		getline (input,holdInt,',');
		std::stringstream convert(holdInt);
		if (!(convert >> id))
		{
			id = 0;
		}
		getline (input,first_name_,',');
		getline (input,last_name_,',');
		getline (input,title, '\n');
		if(!input.eof())
			title.pop_back();
		addMemberToList(cm_list, id, first_name_, last_name_, title);
	}
	input.close();

}
void addMemberToList(List<CourseMember*>& cm_list, int id, const std::string&
first_name, const std::string& last_name, const std::string& title)
{
	if(title == "Student")
	{
		Student* s_ptr = new Student(id, first_name, last_name);
		s_ptr->setGpa(randGpa());
		s_ptr->setMajor(randMajor());
		CourseMember* c_ptr = s_ptr;
		cm_list.insert(cm_list.getLength(), c_ptr);
		s_ptr = nullptr;
	}
	else if(title == "Teaching Assistant")
	{	
		TeachingAssistant* t_ptr = new TeachingAssistant(id, first_name, last_name);
		t_ptr->setGpa(randGpa());
		t_ptr->setMajor(randMajor());
		t_ptr->setRole(randRole());
		CourseMember* c_ptr = t_ptr;
		cm_list.insert(cm_list.getLength(), c_ptr);
		t_ptr = nullptr;
	}
	else if(title == "Instructor")
	{	
		Instructor* i_ptr = new Instructor(id, first_name, last_name);
		i_ptr->setOffice("1000C");
		i_ptr->setContact("235Instructors@hunter.cuny.edu");
		CourseMember* c_ptr = i_ptr;
		cm_list.insert(cm_list.getLength(), c_ptr);
		i_ptr = nullptr;
	}
}
double randGpa()
{
	double gpa = 4.0;
	std::vector<double> gpavector;
	for (int i=0; i<8; i++)
	{
		gpavector.push_back(gpa);
		gpa = gpa - 0.25;
	}
	
	int random = rand() % 8;
	
	return gpavector[random];
}

std::string randMajor()
{
	std::vector<std::string> majorvector;
	majorvector.push_back("Computer Science");
	majorvector.push_back("Literature");
	majorvector.push_back("Music");
	majorvector.push_back("Philosophy");
	majorvector.push_back("Physics");
	majorvector.push_back("Theatre");
	majorvector.push_back("Computational Biology");
	majorvector.push_back("Mathematics");
	majorvector.push_back("Geography");
	majorvector.push_back("Linguistics");
	
	int random = rand() % 9;
	
	return majorvector[random];	
}

ta_role randRole()
{
	std::vector<ta_role> rolevector;
	rolevector.push_back(LAB_ASSISTANT);
	rolevector.push_back(LECTURE_ASSISTANT);
	rolevector.push_back(FULL_ASSISTANT);
	
	int random = rand() % 2;
	
	return rolevector[random];
}
