//
// Created by mrrad on 11/29/2022.
//

#include "NFA.h"

NFA::NFA(State* s, vector<State*> v) {
    this->start_state = s;
    this->end_states = v;
}
void NFA::closureNFA(){
    // Combine all end states to only one state
   State* combined = new State();
   for(State* s:this->end_states){
       s->addNextState(combined, vector<char>{' '});
   }
   this->end_states.clear();
   this->end_states.push_back(combined);
   // put new start state at the beginning
   State* new_start_state = new State();
   new_start_state->addNextState(this->start_state,vector<char>{' '});
   // do closure
   combined->addNextState(this->start_state,vector<char>{' '});
   this->start_state=new_start_state;
   this->start_state->addNextState(combined,vector<char>{' '});
}
void NFA::positive_closureNFA(){
    // Combine all end states to only one state
    State* combined = new State();
    for(State* s:this->end_states){
        s->addNextState(combined, vector<char>{' '});
    }
    this->end_states.clear();
    this->end_states.push_back(combined);
    // put new start state at the beginning
    State* new_start_state = new State();
    new_start_state->addNextState(this->start_state,vector<char>{' '});
    // do closure
    combined->addNextState(this->start_state,vector<char>{' '});
    this->start_state=new_start_state;
}
void NFA::concatenateNFA(NFA* concatenatedNFA){
    for(State* s:this->end_states){
        s->addNextState(concatenatedNFA->start_state,vector<char>{' '});
    }
    this->end_states.clear();
    for(State* s:concatenatedNFA->end_states){
        this->end_states.push_back(s);
    }
}
void NFA::ORNFA(NFA* paralleledNFA){
    State* start = new State();
    start->addNextState(this->start_state,vector<char>{' '});
    start->addNextState(paralleledNFA->start_state,vector<char>{' '});
    vector<State*> newVector;
    newVector.reserve( this->end_states.size() + paralleledNFA->end_states.size() );
    newVector.insert( newVector.end(), this->end_states.begin(), this->end_states.end() );
    newVector.insert( newVector.end(), paralleledNFA->end_states.begin(), paralleledNFA->end_states.end());
    this->end_states=newVector;
    this->start_state=start;
}
void NFA::combine_end_states(State* combined_end_state){
    for(State* s:this->end_states){
        s->addNextState(combined_end_state, vector<char>{' '});
    }
    this->end_states.clear();
    this->end_states.push_back(combined_end_state);
}

NFA::NFA() {

}

