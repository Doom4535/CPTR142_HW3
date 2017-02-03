/*
 * TriviaGame.cpp
 *
 *  Created on: Feb 3, 2017
 *      Author: aaron.covrig
 */

#include <iostream>
#include <vector>
#include <string>

#include <stdlib.h>
#include <time.h>
#include "Trivia.h"
#include "User.h"
#include <unistd.h>
#include "TriviaGame.h"

// Trivia Game function calls


int triviaGame(void){
	int k = 0; // used to know which question to ask next
	int max_count = 1;
	std::vector <Trivia> current_session;
	std::vector <User> players;
	createUsers(players);
	loadQuestions(current_session);
	randomizeQ(current_session); // shuffling the questions
	setSessionCount(max_count);
	int count = 0;
	while(count < max_count){
		for(unsigned int b = 0; b < players.size(); b++){
			selectUser(players, b);
			std::cout << std::endl;	// Adding in an extra space
			//askQuestion(current_session, k, players, b);
			askQuestion(current_session, k, players, b);
			k++;	//incrementing to the next question
			std::cout << std::endl; // adding in an extra space for readability
			if(k >= current_session.size()){ // checking to see if we have reached the end of the question pool
				randomizeQ(current_session); // shuffling the questions
				k = 0; // resetting the question counter/incrementer
			}
		}
		count++;
	}
	GameOver(players);


	return(0);
}

/*! Randomizing order of questions */
int randomizeQ(std::vector <Trivia> &question_list){
	int status = 1;
	srand (time(NULL)); // initialize seed
	int size = question_list.size();

	//Trivia temp("!!!!!!! Error !!!!!!!", "error", 0); // temporary trivia object
	Trivia temp = question_list[0];

	// Shuffling components
	for(int i = 0;  i < size; i++){
		//int swap_Q = rand() size + 1;
		int swap_Q = rand() & (size -1);
		temp = question_list[i];
		question_list[i] = question_list[swap_Q];
		question_list[swap_Q] = temp;
	}

	questionCheck(question_list);

	status = 0;
	return(status);
}

/*! Loading questions */
int loadQuestions(std::vector <Trivia> &question_list){
	int status = 1;
	//question_list.pop_back(); // removing mysterious first element
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
	Trivia q6("Who plays the terminator model T-800?", "Arnold Schwarzenegger", 100);
	question_list.push_back(q6);
	Trivia q7("What color was the original Oscar the Grouch in Sesame Street?", "Orange", 600);
	question_list.push_back(q7);
	Trivia q8("Who invented the Pringles can?", "Fredric Baur", 600);
	question_list.push_back(q8);
	Trivia q9("Is Reno farther east than Los Angeles? (True/False)", "False", 400);
	question_list.push_back(q9);
	Trivia q10("Were Furbies banned from the NSA headquarters at one point? (Yes/No)", "Yes", 300);
	question_list.push_back(q10);
	Trivia q11("Which U.S. president signed Father's Day into Law?", "Lyndon B. Johnson", 300);
	question_list.push_back(q11);
	Trivia q12("Catalonia is a region of what country?", "Spain", 400);
	question_list.push_back(q12);
	Trivia q13("Which team won the 2016 Super Bowl? (Region Name)", "Denver Broncos", 200);
	question_list.push_back(q13);
	Trivia q14("Which actor was the voice of Darth Vader in the original Star Wars films? (first middle last)", "James Earl Jones", 600);
	question_list.push_back(q14);
	Trivia q15("In the world of video games, what does NES stand for?", "Nintendo Entertainment System", 400);
	question_list.push_back(q15);
	Trivia q16("Who painted the famous Dutch Golden age painting 'The Night Watch'", "Rembrant", 500);
	question_list.push_back(q16);
	Trivia q17("Taylor Swift fans are known as what?", "Swifties", 100);
	question_list.push_back(q17);
	Trivia q18("The writer Eric Blair went by what pen name?", "George Orwell", 250);
	question_list.push_back(q18);
	Trivia q19("The Alaskan Malamute is a type of what?", "Dog", 150);
	question_list.push_back(q19);
	Trivia q20("In what type of restaurant would you typically find the condiment wasabi?", "Japanese", 150);
	question_list.push_back(q20);

	/*! Verifying questions */
	questionCheck(question_list);

	status = 0;
	return(status);
}

/*! Performing a quick check to try and make sure there are no erronious elements.
 *  Assuming that no entry is to have a cash value of $0, and that no string field
 *  is to be blank.
 */
void questionCheck(std::vector <Trivia> &question_list){
	for(unsigned int i = 0; i < question_list.size(); i++){
		bool erase = false;
		if(question_list[i].getValue() == 0){
			std::cout << "Error in value field discoverd in element: " << i << std::endl;
			erase = true;
		}
		if(question_list[i].getQuestion() == ""){
			std::cout << "Error in question field discoverd in element: " << i << std::endl;
			erase = true;
		}
		if(question_list[i].getAnswer() == ""){
			std::cout << "Error in answer field discoverd in element: " << i << std::endl;
			erase = true;
		}
		if(erase){
			sleep(1);
			question_list.erase(question_list.begin()+i);
		}
	}
}

//int askQuestion(std::vector <Trivia> &question_list, int &current_num, std::vector <User> &players, int &player_num){
int askQuestion(std::vector <Trivia> &question_list, const int &current_num, std::vector <User> &players, const int &player_num){
	int status = 1;
	std::string input;
	std::cout << "The question is: " << question_list[current_num].getQuestion() << std::endl;
	std::cout << "Enter your answer: ";
	getline(std::cin, input);
	std::cout << input << std::endl;
	if(input == question_list[current_num].getAnswer()){
		std::cout << "Congratulations, that answer is correct!" << std::endl;
		int value = question_list[current_num].getValue();
		std::cout << "You have earned: $" << value << std::endl;
		players[player_num].addPoints(value);
	}
	else{
		std::cout << "The correct answer is: " << question_list[current_num].getAnswer() << std::endl;
		std::cout << "The question was worth: $" << question_list[current_num].getValue() << std::endl;
	}
	//current_num++;

	status = 0;
	return(status);
}

/* Creating the users */
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

/*! Choosing the next user */
int selectUser(std::vector <User> &players, unsigned int &player_number){
	int status = 1;
	std::cout << "It is " << players[player_number].getName() << "'s turn";
	status = 0;
	return(status);
}

/*! Enterying the number of questions to be answered by each user */
void setSessionCount(int &count){
	count = 1;
	std::cout << "Please enter how many sessions you would like (how many questions will each person answer?)?: ";
	std::cin >> count;
	if(!std::cin){
		std::cin.clear();
		fflush(stdin);
		count = 4;
		std::cout << "Ignoring bad input, defaulting to 4" << std::endl;
	}
	std::cin.ignore();
}

/*! Find the user with the most points or set tie to true if all tied */
void pointsLeader(std::vector <User> &players, User &leader, bool &tie){
	tie = false;
	int highScore = 0;
	int leader_num = -1;
	for(unsigned int i = 0; i < players.size(); i++){
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

/*! Finishing the game and outputing the ending stuff */
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


