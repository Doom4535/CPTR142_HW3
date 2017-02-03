/*
 * User.cpp
 *
 *  Created on: Feb 2, 2017
 *      Author: aaron
 */

#include <iostream>
#include "User.h"

int User::playerID = 0;

User::User(std::string n){
	name = n;
	ID = playerID;
	PortOfCall = "Unknown";
	score = 0;
	teamID = 0;
	team = "none";
	playerID++;
}

int User::getID(void){
	return(ID);
}

void User::setID(int num){
	ID = num;
}

std::string User::getName(void){
	return(name);
}
void User::setName(std::string n){
	name = n;
}
std::string User::getPoC(void){
	return(PortOfCall);
}
void User::setPoC(std::string PoF){
	PortOfCall = PoF;
}
int User::getScore(void){
	return(score);
}
void User::clearScore(void){
	score = 0;
}
void User::addPoints(int points){
	score += points;
}
int User::getTeamID(void){
	return(teamID);
}
void User::setTeamID(int id){
	teamID = id;
}
std::string User::getTeam(void){
	return(team);
}
void User::setTeam(std::string t){
	team = t;
};
