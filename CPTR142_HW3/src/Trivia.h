/*
 * Trivia.h
 *
 *  Created on: Feb 2, 2017
 *      Author: aaron
 */

#ifndef TRIVIA_H_
#define TRIVIA_H_

#include <string>

class Trivia{
	private:
		/*! The trivia question */
		std::string Question;
		/*! The correct answer */
		std::string Answer;
		/*! The value in dollars (whole) if answered correctly */
		int value;

	public:
		//Trivia();
		Trivia(std::string Q, std::string A, int v);
		std::string getQuestion(void);
		std::string getAnswer(void);
		int getValue(void);
};



#endif /* TRIVIA_H_ */
