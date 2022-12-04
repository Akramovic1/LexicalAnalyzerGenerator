//
// Created by rana_ on 11/30/2022.
//

#include "NFA_Generator.h"
#include "helper.h"
#include "State.h"

void NFA_Generator::GenerateNFA(pair<string,string> RE_expression_pair,map<string,vector<char>>raw_RE_definitions) {
    string LHS=RE_expression_pair.first;
    string RHS=RE_expression_pair.second;
    vector<string>tokens=split_on_spacial_chars(RHS);
    vector<string>v=generate_infix(tokens);
    v= infixToPostfix(v);
    NFA* result= postfix_eval(v,raw_RE_definitions, LHS);
    this->NFAs.push_back(result);
}
NFA* NFA_Generator::postfix_eval(vector<string>postfix,map<string,vector<char>>RE_definitions,string accepted_type){
    stack<NFA*>st;
     for(string s:postfix){
         if(!is_spacial_character(s)&&s!="`"){
            if(RE_definitions.find(s) != RE_definitions.end()){
                State* state = new State();
                State* end_state = new State();
                state->addNextState(end_state,RE_definitions.at(s));
                NFA* currentNFA=new NFA(state,vector<State*>{end_state});
                st.push(currentNFA);
            }
            else{
                State* state = new State();
                State* end_state = new State();
                state->addNextState(end_state,vector<char>{s[0]});
                NFA* currentNFA=new NFA(state,vector<State*>{end_state});
                st.push(currentNFA);
            }
         }
         else{
             if(s=="*"){
                st.top()->closureNFA();
             }
             else if(s=="+"){
                 st.top()->positive_closureNFA();
             }
             else if(s=="|"){
                 NFA* NFA1=st.top();
                 st.pop();
                 NFA* NFA2=st.top();
                 st.pop();
                 NFA1->ORNFA(NFA2);
                 st.push(NFA1);
             }
             else if(s=="`"){
                 NFA* NFA1=st.top();
                 st.pop();
                 NFA* NFA2=st.top();
                 st.pop();
                 NFA2->concatenateNFA(NFA1);
                 st.push(NFA2);
             }
         }
     }
     NFA* accepted_NFA=st.top();
     State* accpeting_state=new State();
     accpeting_state->accepted = true;
     accpeting_state->tokenType= accepted_type;
     accepted_NFA->combine_end_states(accpeting_state);
     return accepted_NFA;
}
