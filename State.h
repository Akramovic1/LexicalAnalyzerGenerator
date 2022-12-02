//
// Created by mrrad on 11/28/2022.
//

#ifndef PHASE_1__STATE_H
#define PHASE_1__STATE_H
#include <bits/stdc++.h>
using namespace std;

class State {
public:
    int id;
    bool accepted;
    map<char,vector<State>> nextStates;
    string tokenType;
    State(int id);
    State();
    void addNextState(State next, vector<char>input);
    vector<State> goToNextState(char input);
    bool check(string input);


};


#endif //PHASE_1__STATE_H
