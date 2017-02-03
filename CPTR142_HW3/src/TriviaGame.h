/*
 * TriviaGame.h
 *
 *  Created on: Feb 3, 2017
 *      Author: aaron.covrig
 */

#ifndef TRIVIAGAME_H_
#define TRIVIAGAME_H_

#include <vector>
#include "Trivia.h"
#include "User.h"

// Trivia Game function call definitions

int triviaGame(void);

int randomizeQ(std::vector <Trivia> &question_list);

int startSession(void);

int loadQuestions(std::vector <Trivia> &question_list);

void questionCheck(std::vector <Trivia> &question_list);

//int askQuestion(std::vector <Trivia> &question_list, int &current_num, std::vector <User> &players, int player_num);
int askQuestion(std::vector <Trivia> &question_list,const int &current_num, std::vector <User> &players, const int &player_num);

int createUsers(std::vector <User> &players);

int selectUser(std::vector <User> &players, unsigned int &player_number);

void setSessionCount(int &count);

void pointsLeader(std::vector <User> &players, User &leader, bool &tie);

void GameOver(std::vector <User> &players);



#endif /* TRIVIAGAME_H_ */
