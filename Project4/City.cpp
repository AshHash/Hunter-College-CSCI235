/*
Atta Saleh
EMPL ID 14187529
Prof. Ligorio
Project 4

City  class implementation
*/

#include "City.hpp"

City::City(std::string name)
{
	city_name = name;
	visited = false;
}

bool City::getVisited() const
{
	return visited;
}

void City::setVisited()
{
	visited = true;
}

std::vector<City*> City::getAdjacent()
{
	return adjacent_cities;
}

std::string City::getName() const
{
	return city_name;
}

void City::addAdjacent(City* city)
{
	adjacent_cities.push_back(city);
}