//
// Created by mrrad on 11/28/2022.
//

#include "State.h"
#include "helper.h"
State::State(int id){
    this->id = id;
}
State::State(){
    this->id=id_generator++;
}
void State::addNextState(State next, vector<char> input) {
    for(char i : input) {
        if (this->nextStates.count(i) != 0) {
            this->nextStates.at(i).push_back(next);
        }
        else {
            this->nextStates.insert({i, vector<State>{next}});
        }
    }
}
vector<State> State::goToNextState(char input){
    if(this->nextStates.count(input)!=0){
        return this->nextStates.at(input);
    }
    return vector<State>{};
}