#include "FSM.h"
#include "State.h"
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

FSM::FSM(){
    vector<State> stateVec;
   
}

FSM::FSM(vector<State> inputStates){
    stateVec = inputStates;
}

bool FSM::run(){
    vector<State> currStates;
    
    return true;
}