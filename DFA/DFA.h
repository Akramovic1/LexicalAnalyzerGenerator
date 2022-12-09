#ifndef DFA_DFA_H
#define DFA_DFA_H

#include <bits/stdc++.h>
#include "SetStates.h"
#include "NFA.h"

using namespace std;

class DFA {
public:
    SetStates *startingState;
    map<string ,SetStates*> transitions;

    DFA();
    void generateDFA(NFA* NFAfinal);
    vector<SetStates*> remainingStates();
    vector<SetStates*> acceptingStates();
};



#endif //DFA_DFA_H
