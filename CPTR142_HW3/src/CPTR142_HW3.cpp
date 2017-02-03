//============================================================================
// Name        		: CPTR142_HW3.cpp
// Author      		: Aaron Covrig
// Version     		:
// Copyright   		: Your copyright notice
// Description 		: Hello World in C++, Ansi-style
// Acknowledgment	: http://stackoverflow.com/questions/14818084/what-is-the-proper-include-for-the-function-sleep-in-c \
//			  http://stackoverflow.com/questions/38430267/sleep-in-infinite-while-loop-not-printing-value-if-not-ended-with-n
//============================================================================

#include <iostream>
#include "Trivia-routine.h"
#include <unistd.h>
#include <string>

int main() {
	std::cout << "!!!Hello World!!!" << std::endl; // prints !!!Hello World!!!
	std::cout << "Loading SkyNet";
	int loading = 15;
	for(int i = 0; i < loading; i++){
		sleep(1);
		std::cout << ".";
		fflush(stdout);
	}
	std::cout << std::endl;
	std::cout << "Conquering the World";

	int conquer = 8;
	for(int i = 0; i < conquer; i++){
		sleep(1);
		std::cout << ".";
		fflush(stdout);
	}
	std::cout << std::endl;
	std::cout << "You may now play: 'Trivia with SkyNet'" << std::endl;
	std::cout << "How long would you like to play? (Number) ";
	std::string input;
	std::cin >> input;
	std::cin.ignore();
	bool playing = true;
	std::cout << "You entered: Eternity" << std::endl;
	std::cout << "Loading Game";
	loading = 7;
	for(int i = 0; i < loading; i++){
		sleep(1);
		std::cout << ".";
		fflush(stdout);
	}
	std::cout << std::endl;
	fflush(stdin);
	while(playing){
		triviaGame();
		sleep(1);
		std::cout << std::endl;
		std::cout << "You thought you were done?" << std::endl;
		std::cout << "Starting next game..." << std::endl;
	}

	return 0;
}
