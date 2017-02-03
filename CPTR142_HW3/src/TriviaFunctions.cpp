/*
 * TriviaFunctions.cpp
 *
 *  Created on: Feb 2, 2017
 *      Author: aaron
 */

#include <vector>
#include <string>
#include <iostream>

#include <stdlib.h>
#include <time.h>
#include "TriviaFunctions.h"
#include "Trivia.h"
#include "User.h"

int randomizeQ(std::vector <Trivia> &question_list){
	int status = 1;
	srand (time(NULL)); // initialize seed
	int size = question_list.size();

	Trivia temp("blah", "blah", 0); // temporary trivia object

	// Shuffling components
	for(int i = 0;  i < size; i++){
		//int swap_Q = rand() size + 1;
		int swap_Q = rand() & size;
		temp = question_list[i];question_list[i] = question_list[swap_Q];
		question_list[swap_Q] = temp;
	}
	status = 0;
	return(status);
}

int loadQuestions(std::vector <Trivia> &question_list){
	int status = 1;
	Trivia q0("In What year did the Titanic sink?", "1912", 200);
	question_list.push_back(q0);
	Trivia q1("Which famous singer appeared in the movie Mad Max: Beyond Thunderdome?", "Tina Turner", 400);
	question_list.push_back(q1);
	Trivia q2("What do the letters HTML, a markup language used to create web pages, stand for?", "Hypertext Markup Language", 300);
	question_list.push_back(q2);
	Trivia q3("Madeira, an archipelago located in the Atlantic Ocean, is an autonomous region of which country?", "Portugal", 600);
	question_list.push_back(q3);
	Trivia q4("Which five-times Grand Slam tennis champion tested positive for a banned substance at the 2016 Australian Open?", "Maria Sharapova", 500);
	question_list.push_back(q4);
	Trivia q5("The art of paper folding is known as what?", "Origami", 100);
	question_list.push_back(q5);

	status = 0;
	return(status);
}

//int askQuestion(std::vector <Trivia> &question_list, int &current_num, std::vector <User> &players, int &player_num){
int askQuestion(std::vector <Trivia> &question_list, int &current_num, std::vector <User> &players, const int &player_num){
	int status = 1;
	std::string input;
	std::cout << "The question is: " << question_list[current_num].getQuestion() << std::endl;
	std::cout << "Enter your answer: ";
	getline(std::cin, input);
	std::cout << input << std::endl;
	if(input == question_list[current_num].getAnswer()){
		std::cout << "Congradulations, that answer is correct!" << std::endl;
		int value = question_list[current_num].getValue();
		std::cout << "You have earned: $" << value << std::endl;
		players[player_num].addPoints(value);
	}
	else{
		std::cout << "The correct answer is: " << question_list[current_num].getAnswer() << std::endl;
		std::cout << "The question was worth: " << question_list[current_num].getValue() << std::endl;
	}
	current_num++;	//incrementing to the next question

	status = 0;
	return(status);
}

int createUsers(std::vector <User> &player){
	int status = 1;
	bool loop = true;
	std::string input;
	char ch;
	while(loop){
		std::cout << "Enter Player name: ";
		getline(std::cin, input);
		User player0(input);
		player.push_back(player0);
		std::cout << "Would you like to add another player? (y/N): ";
		std::cin >> ch;
		std::cin.ignore();
		if(ch == 'Y' || ch == 'y'){
			loop = true;
		}
		else{
			loop = false;
		}
	}
	status = 0;
	return(status);
}

int selectUser(std::vector <User> &players, int &player_number){
	int status = 1;
	std::cout << "It is " << players[player_number].getName() << "'s turn";
	status = 0;
	return(status);
}

void setSessionCount(int &count){
	count = 0;
	std::cout << "Please enter how many sessions you would like (how many questions will each person answer?)?: ";
	std::cin >> count;
	std::cin.ignore();
}

void pointsLeader(std::vector <User> &players, User &leader, bool &tie){
	tie = false;
	int highScore = 0;
	int leader_num = -1;
	for(int i = 0; i < players.size(); i++){
		int present_score = players[i].getScore();
		if(present_score > highScore){
			highScore = present_score;
			leader_num = i;
		}
	}
	if(leader_num >= 0){
		leader = players[leader_num];
	}
	else{
		tie = true;
	}
}
void GameOver(std::vector <User> &players){
	User winner("The Awesome One");
	bool tie = false;
	pointsLeader(players, winner, tie);
	std::cout << "----------------------------------------------------------------------------------" << std::endl;
	std::cout << "----------------------------------------------------------------------------------" << std::endl;
	std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! GAME OVER !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
	if(tie == false){
		std::cout << std::endl;
		std::cout << "Congradulations: " << winner.getName() << " You Won!!!!!!!!" << std::endl;
		std::cout << "Your Awesome Score was: " << winner.getScore() << std::endl;
		std::cout << std::endl;
	}
	else{
		std::cout <<"BOOOOO!!!!!!!!!!!!!!!! You tied" << std::endl;
	}
	std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! GAME OVER !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
	std::cout << "----------------------------------------------------------------------------------" << std::endl;
	std::cout << "----------------------------------------------------------------------------------" << std::endl;
}
