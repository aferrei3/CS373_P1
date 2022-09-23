#include "FSM.h"
#include "State.h"
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

FSM::FSM(){
      
}

FSM::FSM(vector<State *> inputStates){
    stateVec = inputStates;
}

bool FSM::run(string input){
    vector<State *> currStates;
    stateVec[0]->getNextStates(input[0], currStates);
    for(int i = 1; i < input.size(); i++){
        int size = currStates.size();
        for(int j = 0; j < size; j++){
            currStates[j]->getNextStates(input[i], currStates);
            currStates.erase(currStates.begin() + j);
        }
        
    }
    string acceptedString = "reject";
    for(int i = 0; i < currStates.size(); i++){
        if(currStates[i]->getAccept() == true){
            acceptedString = "accept";
        }
    }
    cout << acceptedString << " ";
    
    for(int i = 0; i < currStates.size(); i++){
        cout << currStates[i]->getNum() << " ";
    }
    cout << endl;

    return true;
}