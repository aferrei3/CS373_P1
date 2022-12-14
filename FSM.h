#ifndef FSM_H
#define FSM_H

#include <vector>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "State.h"

using namespace std;

class FSM{
    private:
        vector<State *> stateVec;
        vector<State *> currentStates;

    public:
        FSM();
        FSM(vector<State *> inputStates);
        bool run(string input);
};

    



#endif