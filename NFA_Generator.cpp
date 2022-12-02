//
// Created by rana_ on 11/30/2022.
//

#include "NFA_Generator.h"
#include "helper.h"
#include "State.h"

void NFA_Generator::GenerateNFA(string RE_expression,map<string,vector<char>>RE_definitions) {
    State start;
    vector<State>end_states={start};
    NFA total_NFA(start,end_states);
    string LHS=RE_expression.substr(0, RE_expression.find(':'));
    string RHS=RE_expression.substr(RE_expression.find(':')+1,RE_expression.size());
    vector<string>tokens=split_on_spacial_chars(RHS);
    vector<string>v=generate_infix(tokens);
    v= infixToPostfix(v);
    NFA result= postfix_eval(v,RE_definitions);
    this->NFAs.push_back(result);
}
NFA NFA_Generator::postfix_eval(vector<string>postfix,map<string,vector<char>>RE_definitions){
    stack<NFA>st;
     for(string s:postfix){
         if(!is_spacial_character(s)&&s!="`"){
            if(RE_definitions.find(s) != RE_definitions.end()){
                State state;
                State end_state;
                state.addNextState(end_state,RE_definitions.at(s));
                NFA currentNFA(state,vector<State>{end_state});
                st.push(currentNFA);
            }
            else{
                State state;
                State end_state;
                state.addNextState(end_state,vector<char>{s[0]});
                NFA currentNFA(state,vector<State>{end_state});
                st.push(currentNFA);
            }
         }
         else{
             if(s=="*"){
                st.top().closureNFA();
             }
             else if(s=="+"){
                 st.top().positive_closureNFA();
             }
             else if(s=="|"){
                 NFA NFA1=st.top();
                 st.pop();
                 NFA NFA2=st.top();
                 st.pop();
                 NFA1.ORNFA(NFA2);
                 st.push(NFA1);
             }
             else if(s=="`"){
                 NFA NFA1=st.top();
                 st.pop();
                 NFA NFA2=st.top();
                 st.pop();
                 NFA2.concatenateNFA(NFA1);
                 st.push(NFA2);
             }
         }
     }
    return st.top();
}
