//
// Created by rana_ on 11/30/2022.
//

#ifndef PHASE_1__NFA_GENERATOR_H
#define PHASE_1__NFA_GENERATOR_H
#include "NFA.h"


class NFA_Generator {
public:
    vector<NFA*>NFAs;
    void GenerateNFA(pair<string,string> RE_expression_pair,map<string,vector<char>>RE_definitions);
    NFA* postfix_eval(vector<string>postfix,map<string,vector<char>>RE_definitions,string accepted_type);
};


#endif //PHASE_1__NFA_GENERATOR_H
