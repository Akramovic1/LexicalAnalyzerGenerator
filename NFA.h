//
// Created by mrrad on 11/29/2022.
//

#ifndef PHASE_1__NFA_H
#define PHASE_1__NFA_H


#include "State.h"

class NFA {
public:
    State* start_state;
    vector<State*>end_states;
    NFA(State* s,vector<State*> v);
    NFA();
    void closureNFA();
    void concatenateNFA(NFA* concatenatedNFA);
    void ORNFA(NFA* paralleledNFA);
    void positive_closureNFA();
    void combine_end_states(State* combined_state);
};


#endif //PHASE_1__NFA_H
