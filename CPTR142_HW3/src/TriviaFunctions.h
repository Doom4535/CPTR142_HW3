/*
 * TriviaFunctions.h
 *
 *  Created on: Feb 2, 2017
 *      Author: aaron
 */

#ifndef TRIVIAFUNCTIONS_H_
#define TRIVIAFUNCTIONS_H_

#include <vector>

#include "Trivia.h"
#include "User.h"

int randomizeQ(std::vector <Trivia> &question_list);

int startSession(void);

int loadQuestions(std::vector <Trivia> &question_list);

//int askQuestion(std::vector <Trivia> &question_list, int &current_num, std::vector <User> &players, int player_num);
int askQuestion(std::vector <Trivia> &question_list, int &current_num, std::vector <User> &players, const int &player_num);
int createUsers(std::vector <User> &players);

int selectUser(std::vector <User> &players, int &player_number);

void setSessionCount(int &count);

void pointsLeader(std::vector <User> &players, User &leader, bool &tie);

void GameOver(std::vector <User> &players);

#endif  /* TRIVIAFUNCTIONS_H_ */
