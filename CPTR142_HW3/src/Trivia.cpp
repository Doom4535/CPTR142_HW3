/*
 * Trivia.cpp
 *
 *  Created on: Feb 2, 2017
 *      Author: aaron
 */

#include <string>

#include "Trivia.h"

Trivia::Trivia(std::string Q, std::string A, int v){
	Question = Q;
	Answer = A;
	value = v;
}

std::string Trivia::getQuestion(void){
	return(Question);
}

std::string  Trivia::getAnswer(void){
	return(Answer);
}

int Trivia::getValue(void){
	return(value);
}
