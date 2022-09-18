#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <sstream>

#include "State.h"
#include "FSM.h"

using namespace std;

State getState(int num, vector<State> stateVec){
	for(int i = 0; i < stateVec.size(); i++){
		if(stateVec[i].getNum() == num){
			return stateVec[i];
		}
	}
	return State();
}

int main(int argc, char * argv[]){
	//Take in file and input
	fstream inputFile;
	string inputString = argv[2];
	//initialize the mega array of states its gonna have 1001 entries
	vector<State> stateArr;
	
	inputFile.open(argv[1], ios::in);

	//Figure out how to store data
	
	

	if(inputFile.is_open()){
		string tp;
		while(getline(inputFile, tp)){
			stringstream s(tp);

			State newState;

			if(tp.find("transition") == string::npos){
				int stateNum;
				string tmp;
				bool startState = false;
				bool acceptState = false;

				s >> tmp >> stateNum;
				
				newState.setNum(stateNum);
				
				if(tp.find("start") != string::npos) newState.setStart(true);
				if(tp.find("accept") != string::npos) newState.setAccept(true);

			}else{
				
				string temp_str;
				string tmp, from, symbol, to;
				// pair<string, State> transition;

				vector<string> transition;

				s >> tmp >> from >> symbol >> to;

				transition.push_back(temp_str + symbol);
				State transitionState;

				
				if(getState(stoi(from), stateArr).getNum() == -1){
					newState.setNum(stoi(from));
					//LOOKS THROUGH STATE ARR TO CHECK IF FROM STATE EXISTS INSIDE OF IT
				}

				
				if(getState(stoi(to), stateArr).getNum() == -1){
					transitionState.setNum(stoi(to));
					stateArr.push_back(transitionState);
				}
				transition.push_back(temp_str + to);

				getState(stoi(from), stateArr).transitions.push_back(transition);
				// getState(stoi(from), stateArr).transitions.push_back(transition);
				//Should this be by pointer?

				cout << from << " -> " << transition[0] << " -> " << transition[1] << endl;
				
				

				



			
			}
			
			if(newState.getNum() != -1){
				stateArr.push_back(newState);
			}

		}
	
	}
	for(int i = 0; i < stateArr.size();i++){
		stateArr[i].print();
	}
	inputFile.close();
	cout << getState(1, stateArr).transitions.size() << endl;

	
}

	/*
	Gonna make it into an array containing arrays of each individual state, containing arrays of valid transitions from those states and where they go from there
	sort of like 
	[
		[1,[0,3],[1,1]],
		[2,[0,4],[1,6]],
				.
				.
				.
		[90,[0,103],[1,86]]
	]
	Pretty sure this is possible. Will just operate under the assumption it is until it succeeds or fails. Godspeed.
	*/
	/*
	I could reasonably do it by indexing if i wanted to since the states are from 0-1000
	...Yeah I'm gonna do it by index
	*/



	

	//gonna have to rewrite getNextState() function check the State.cpp and State.h files 
	

	

	



