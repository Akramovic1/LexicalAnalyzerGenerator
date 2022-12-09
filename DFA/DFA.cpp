#include "DFA.h"
#include "SetStates.h"

string inputs = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!#$%&'(){}[]*/+-|"


void DFA::generateDFA(NFA *NFAfinal){

    //first get the starting state of the NFA to be the starting state of the DFA
    this->startingState->insertState(NFAfinal->start_state);
    this->startingState->Eclosure();

    queue<SetStates*> Dstates ;
    Dstates.push(this->startingState);

    while (!Dstates.empty()){
        T = Dstates.front();
        Dstates.pop();

        string Ids = T.getStatesIds();
        this->transitions.insert(pair<string,SetStates*>(Ids,T))


        //for each input get the output of T
        for (char input  : inputs){
            U = T->moveTo(input);

            //check if we have this state before in the transition table or U is empty state
            if (this->transitions.find(U->getStatesIds())!=this->transitions.end() || U->states.empty()){
                continue ;
            }

            Dstates.push(U);
            T->nextStates.insert(pair<char,SetStates*>(input,U));
        }

    }


}

vector<SetStates*> DFA::remainingStates() {
    vector<SetStates*> answer ;

    for (pair<string,SetStates*> a : this->transitions){
        if (!a.second->accepted) {
            answer.push_back(a.second);
            cout << a.second->getStatesIds() << "\n";
        }
    }
    return answer ;
}

vector<SetStates*> DFA::acceptingStates() {
    vector<SetStates*> answer ;

    for (pair<string,SetStates*> a : this->transitions){
        if (a.second->accepted) {
            answer.push_back(a.second);
            cout << a.second->getStatesIds() << "\n";
        }
    }
    return answer ;
}
