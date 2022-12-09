#ifndef DFA_SETSTATES_H
#define DFA_SETSTATES_H

#include <bits/stdc++.h>
#include "State.h"
using namespace std;

class SetStates{
public:
    bool accepted;
    set<State*> states ;
    map<char,SetStates*> nextStates;

    SetStates(set<State*> states);
    SetStates();
    void Eclosure();
    SetStates* moveTo(char input);
    string getStatesIds();
    void insertStates(vector<State*> vector);
    void insertState(State* s);
};

#endif //DFA_SETSTATES_H
