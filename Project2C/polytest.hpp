/*
 Atta Saleh
 EMPLID 14187529
 Project 2C
 Polytest interface
*/
#include "TeachingAssistant.hpp"
#include "Instructor.hpp"
#include "List.hpp"
#include <string>
#include <iostream>


void populateCmList(List<CourseMember*>& cm_list, std::string input_file);

void addMemberToList(List<CourseMember*>& cm_list, int id, const std::string&
first_name, const std::string& last_name, const std::string& title);

double randGpa();

std::string randMajor();

ta_role randRole(); 

