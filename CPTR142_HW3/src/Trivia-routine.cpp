/*
 * Trivia-routine.cpp
 *
 *  Created on: Feb 2, 2017
 *      Author: aaron
 */

#include <iostream>
#include <vector>
#include <string>

#include "Trivia-routine.h"
#include "TriviaFunctions.h"
#include "Trivia.h"
#include "User.h"


int triviaGame(void){
	int k = 0; // used to know which question to ask next
	int max_count = 1;
	std::vector <Trivia> current_session;
	std::vector <User> players;
	createUsers(players);
	loadQuestions(current_session);
	setSessionCount(max_count);
	int count = 0;
	while(count < max_count){
		for(int b = 0; b < players.size(); b++){
			selectUser(players, b);
			std::cout << std::endl;	// Adding in an extra space
			//askQuestion(current_session, k, players, b);
			askQuestion(current_session, k, players, b);
			std::cout << std::endl; // adding in an extra space for readability
			if(k > current_session.size()){ // checking to see if we have reached the end of the question pool
				randomizeQ(current_session); // shuffling the questions
				k = 0; // resetting the question counter/incrementer
			}
		}
		count++;
	}
	GameOver(players);


	return(0);
}

