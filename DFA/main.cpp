#include "SetStates.h"
#include "State.h"
#include "NFA.h"
#include "DFA.h"

int main() {
    State* state1 ;
    state1->id = 1 ;
    State* state2 ;
    state2->id = 2 ;
    State* state3 ;
    state3->id = 3 ;
    State* state4 ;
    state4->id = 4 ;
    State* state5 ;
    state5->id = 5 ;
    State* state6 ;
    state6->id = 6 ;
    State* state7 ;
    state7->id = 7 ;
    State* state8 ;
    state8->id = 8 ;
    State* state9 ;
    state9->id = 9 ;
    State* state10 ;
    state10->id = 10 ;
    state10->accepted = true ;
    State* state0 ;
    state0->id = 0 ;

    state0->nextStates.insert({'\0',vector<State*>{state1,state7}});
    state1->nextStates.insert({'\0',vector<State*>{state4,state2}});
    state2->nextStates.insert({'a',vector<State*>{state3}});
    state3->nextStates.insert({'\0',vector<State*>{state6}});
    state4->nextStates.insert({'b',vector<State*>{state5}});
    state5->nextStates.insert({'\0',vector<State*>{state6}});
    state6->nextStates.insert({'\0',vector<State*>{state1,state7}});
    state7->nextStates.insert({'a',vector<State*>{state8}});
    state8->nextStates.insert({'b',vector<State*>{state9}});
    state9->nextStates.insert({'b',vector<State*>{state10}});


    NFA finalNFA = NFA(state0, vector<State*>{state10});


    DFA finalDFA = DFA();

    finalDFA.generateDFA(&finalNFA);

    cout << "accepting States\n";
    finalDFA.acceptingStates();


    cout << "remaining States\n";
    finalDFA.remainingStates();





}
