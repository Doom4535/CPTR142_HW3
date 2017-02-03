/*
 * User.h
 *
 *  Created on: Feb 2, 2017
 *      Author: aaron
 */


/*!	UML Diagram
 * 		class User
 * 			private
 * 				ID#
 * 				name
 * 				PortOfCall (home, ect.)
 * 				score
 * 				teamID
 * 				team name
 *
 * 			public
 * 				User()
 * 				getID
 * 				setID
 * 				getName
 * 				setName
 * 				getPoC (used to get the Port of Call)
 * 				getScore
 * 				clearScore
 * 				addPoints
 * 				getTeamID
 * 				setTeamID
 * 				getTeam (team name)
 * 				setTeam (set team name)
 */

#ifndef USER_H_
#define USER_H_

#include <string>

class User{
	private:
		static int playerID;
		int ID;
		std::string name;
		std::string PortOfCall;
		int score;
		int teamID;
		std::string team;
	public:
		User(std::string name);
		int getID(void);
		void setID(int id);
		std::string getName(void);
		void setName(std::string name);
		std::string getPoC(void);
		void setPoC(std::string PoF);
		int getScore(void);
		void clearScore(void);
		void addPoints(int points);
		int getTeamID(void);
		void setTeamID(int id);
		std::string getTeam(void);
		void setTeam(std::string team);
};



#endif /* USER_H_ */
