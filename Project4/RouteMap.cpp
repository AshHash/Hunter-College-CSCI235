/*
Atta Saleh
EMPL ID 14187529
Prof. Ligorio
Project 4

RouteMap class implementation
*/

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <stack>

#include "RouteMap.hpp"
#include "City.hpp"

bool RouteMap::readMap(std::string input_file_name)
{
	std::fstream input;
	input.open(input_file_name.c_str());

	std::string city_list;
	getline(input, city_list);

	std::string city_list_delimiter = ",";

	size_t pos = 0;
	std::string token;


	while((pos = city_list.find(city_list_delimiter)) != std::string::npos) 
	{
    	token = city_list.substr(0, pos);
    	City current_city(token);
    	cities_.push_back(current_city);
    	city_list.erase(0, pos + city_list_delimiter.length());
	}
	City last_city(city_list);
	cities_.push_back(last_city);


	while(!input.eof())
	{
		std::string origin;
		std::string adjacent;
		City* adjacentPtr;
		getline(input, origin, '-');
		getline(input, adjacent, ',');

		for(int i = 0; i<cities_.size(); i++)
		{
			if(adjacent == cities_[i].getName())
			{
				adjacentPtr = &cities_[i];
			}
		}

		for(int i = 0; i<cities_.size(); i++)
		{
			if(origin == cities_[i].getName())
			{
				cities_[i].addAdjacent(adjacentPtr);
			}
		}
	}

	//Close filestream
	input.close();

	return true;
}

City* RouteMap::getCity(size_t position)
{
	City* output = &cities_[position];
	return output;
}

bool RouteMap::isRoute(City* origin, City* destination)
{
	std::stack <City*> city_stack;
	City* current = origin;
	bool deadEnd = false;

	while(current != destination && !deadEnd)
	{
		bool hasUnvisited = false;

		current->setVisited();

		std::vector<City*> adjacentCities = current->getAdjacent();

		int i = 0;

		while(i < adjacentCities.size() && hasUnvisited == false)
		{
			if(!adjacentCities[i]->getVisited())
			{
				city_stack.push(adjacentCities[i]);
				adjacentCities[i]->setVisited();
				hasUnvisited = true;
			}
			i++;
		}

		if(hasUnvisited == false)
			city_stack.pop();

		current = city_stack.top();

		if(city_stack.empty())
		{
			deadEnd = true;
			return false;
		}

	}

	if(current == destination)
	{
		return true;
		std::stack <City*> outputStack;
		while(!city_stack.empty()) 
		{
			outputStack.push(city_stack.top());
			city_stack.pop();
		}
		outputStack.push(origin);
		while(!outputStack.empty())
		{
			if(outputStack.size() > 1)
				std::cout << outputStack.top()->getName() << "\n";
			else
				std::cout << outputStack.top()->getName() << " -> ";
			outputStack.pop();
		}
	}
}
