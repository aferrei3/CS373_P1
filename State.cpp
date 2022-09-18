#include "State.h"
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>

#include <iterator>
#include <iomanip>
#include <algorithm>


using namespace std;


State::State(){
    stateNum = -1;
    isStart = false;
    isAccept = false;
}

State::State(int Num, bool Start, bool Accept){
    stateNum = Num;
    isStart = Start;
    isAccept = Accept;
}

void State::addTransition(vector<string> transition){
    transitions.push_back(transition);
    cout << "pair " << transition[0] << "," << transition[1] << " added" << endl;
}

bool State::checkStateNum(int num){
    if(num == stateNum) return true;
    return false;
}

void State::setStart(bool start){
    isStart = start;
}

void State::setAccept(bool accept){
    isAccept = accept;
}

void State::setNum(int num){
    stateNum = num;
}

void State::print(){
    cout << "( " << "State: " << stateNum << " | Start: " << isStart << " | Accept: " << isAccept << " |";
    for(int i = 0; i < transitions.size();i++){
        cout << "["  << transitions[i][0] << " -> " << transitions[i][1] << "] ";
    }
    cout << ")" << endl;
}

int State::getNum(){
    return stateNum;
}

bool State::getStart(){
    return isStart;
}

bool State::getAccept(){
    return isAccept;
}

// void State::getNextStates(string symbol, vector<int> &currStates){
//     for(int i = 0; i < transitions.size();i++){
//         if(transitions[i][0] == symbol) currStates.push_back(stoi(transitions[i][1]));
//     }
//     sort(currStates.begin(), currStates.end());
//     auto last = unique(currStates.begin(), currStates.end());
//     currStates.erase(last, currStates.end());


// }





//Rewrite this to make currStates a vector of states not int
//might have to create some new functions to make this work - we'll see...