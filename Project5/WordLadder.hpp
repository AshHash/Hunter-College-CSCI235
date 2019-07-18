/*
 Atta Saleh
 EMPLID 14187529
 Project 3

	WordLadder interface
*/

#ifndef WordLadder_hpp
#define WordLadder_hpp

#include <string>
#include <vector>
#include <queue>

class WordLadder
{
public:
	/** default constructor**/
	WordLadder();
	
	/**
	@post reads lexicon words from the input file and stores them for
	 later use
	 **/
	void readLexicon(std::string input_file);
	
	/**
	@param start_word is the first word in the ladder
	@param end_word is the last word in the ladder
	@return a vector containing words s.t. the first word is start_word,
	 the last word is end_word, and all words in between differ by
	 only one character from the preceding and following words, in
	 the shortest such transformation found in the current lexicon.
	 If no transformation is found between start_word and end_word,
	 returns an empty vector.
	 **/
	std::vector<std::string> findShortestLadder(std::string start_word, std::string end_word);

	/**
	@param word is the last word in the current Ladder
	@return a vector including each unused word in the lexicon that
	 differs from word by one letter.
	**/
	std::vector<std::string> oneLetterDiff(std::string word);

	/**
	@param word is the word we are checking for in a list
	@param list is the list that we are checking for the word
	@return true if the word is in the list, false if it isn't.
	**/
	bool isInList(std::string word, std::vector<std::string> list);

	    
private:
	std::vector<std::string> wordslist_;
	//list of words that have already been used
	std::vector<std::string> used_;
    
    
}; //end WordLadder

#endif /* WordLadder_hpp */
