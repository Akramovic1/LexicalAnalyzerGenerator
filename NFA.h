//
// Created by mrrad on 11/29/2022.
//

#ifndef PHASE_1__NFA_H
#define PHASE_1__NFA_H


#include "State.h"

class NFA {
public:
    State start_state;
    vector<State>end_states;
    NFA(State s,vector<State> v);
    void closureNFA();
    void concatenateNFA(NFA concatenatedNFA);
    void ORNFA(NFA paralleledNFA);
    void positive_closureNFA();
};


#endif //PHASE_1__NFA_H
