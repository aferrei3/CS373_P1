#ifndef STATE
#define STATE

#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class State{
    private:
        int stateNum;
        // vector<vector<string>> transitions;
        
        bool isStart = false;
        bool isAccept = false;

    public:
        vector<pair<string, State *>> transitions;
        State();
        State(int Num, bool Start, bool Accept);

        void addTransition(pair<string, State *> transition);
        bool checkStateNum(int num);
        void setStart(bool start);
        void setAccept(bool accept);
        void setNum(int num);
        int getNum();
        bool getStart();
        bool getAccept();
        void getNextStates(string symbol, vector<int> &currStates);
        
        // Have to find a way to get the state by number - don't know if it would necessarily be a good idea for this file.


        void print();

        


};



#endif