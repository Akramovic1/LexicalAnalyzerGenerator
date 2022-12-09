#ifndef DFA_STATE_H
#define DFA_STATE_H

#include <bits/stdc++.h>
using namespace std;

class State {
public:
    int id;
    bool accepted;
    map<char,vector<State*>> nextStates;
    string tokenType;
    State();
    void addNextState(State* next, vector<char>input);
    bool check(string input);


};

#endif //DFA_STATE_H
