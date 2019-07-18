/*
Atta Saleh
EMPL ID 14187529
Prof. Ligorio
Project 4

City  class interface
*/

#ifndef CITY_
#define CITY_

#include <string>
#include <vector>

class City
{
public:
	City(std::string name); 				//Parameterized constructor
	bool getVisited() const; 				//Returns bool visited
	void setVisited();						//Sets visited to true
	std::vector<City*> getAdjacent(); 		//returns adjacent_cities
	std::string getName() const;			//Returns city_name	
	void addAdjacent(City* city); 			//Adds adjacent city to adjacent_to

private:
	bool visited; 							//Whether the city was already visited. Default to false
	std::string city_name; 					//Name of the city
	std::vector<City*> adjacent_cities; 	//Vector of pointers to cities adjacent to this city
};

#endif