/*
 Atta Saleh
 EMPLID 14187529
 Project 3
 
	WordLadder class implementation
 */

#include "WordLadder.hpp"
#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>

WordLadder::WordLadder()
{
	
}

void WordLadder::readLexicon(std::string input_file)
{
    //Opens the file stream. 
    std::fstream file;
    file.open(input_file.c_str());

    // This loop adds every word in the document to a private string vector.
    while(!file.eof())
    {
        std::string currentword;
        getline (file,currentword);
        if (currentword == "")
        {
            continue;
        }
        wordslist_.push_back(currentword);
    }

    // Closes the file stream
    file.close();
}

std::vector<std::string> WordLadder::findShortestLadder(std::string start_word, std::string end_word)
{
	
	//creates a queue for ladders
	std::queue<std::vector<std::string> > ladderQueue;

	//adds the starting word to initial ladder and the queue
	std::vector<std::string> startLadder;
	startLadder.push_back(start_word);
	ladderQueue.push(startLadder);


	//adds the start word to list of used words
	used_.push_back(start_word);

	bool ladderExists = false;

	while(!ladderQueue.empty())
	{
		//stores the first ladder in the queue in a vector currentLadder
		std::vector<std::string> currentLadder = ladderQueue.front();
		ladderQueue.pop();

		//if the currentLadder's last element is the end_word, return true 
		if(currentLadder.back() == end_word)
		{
			return currentLadder;
		}
		std::vector<std::string> nextWords = oneLetterDiff(currentLadder.back());

		//placeholder ladder
		std::vector<std::string> tempLadder;
		for(int i = 0; i < nextWords.size(); i++)
		{
		//sets tempLadder to the input ladder
		tempLadder = currentLadder;
		//appends word i of newWords to tempLadder
		tempLadder.push_back(nextWords[i]);
		//adds tempLadder to the back of the queue
		ladderQueue.push(tempLadder);
		}
	}
	//empty ladder to return if there was no ladder found
	std::vector<std::string> emptyLadder;
	return emptyLadder;
	//If there is no ladder, outputs that there is none

}

std::vector<std::string> WordLadder::oneLetterDiff(std::string word)
{
	std::vector<std::string> oneDiffVector;
	std::string changedWord;
	//iterates over each character of the word we are starting with
	for(int j = 0; j < 4; j++)
	{
		//creates a copy of the word we are starting with
		changedWord = word;
		//changes the current letter of the copied word to each letter in the alphabet
  		for(int i = 97; i < 123; i++)
    	{
        	changedWord[j] = i;
        	//if the word is in the lexicon and hasn't been used, add it to our output vector
        	if(isInList(changedWord, wordslist_) && !isInList(changedWord, used_))
        	{
        		oneDiffVector.push_back(changedWord);
        		used_.push_back(changedWord);
        	}
    	}
	}
	return oneDiffVector;
}

bool WordLadder::isInList(std::string word, std::vector<std::string> list)
{
	bool output = false;
	if(binary_search(list.begin(), list.end(), word))
	{
		output = true;
	}
	return output;
}