
#ifndef PHASE_1__PARSER_GENERATOR_H
#define PHASE_1__PARSER_GENERATOR_H
using namespace std;
#include <bits/stdc++.h>


class parser_generator {
public:
vector<pair<string,string>>grammer_rules;
void read_file(string filepath);
void removeLR();
void left_factor(int index);
void get_parsing_table();
void substitute(int i,int j);
void eliminate_immediate_LR(int rule_index);
string get_match_substr(string group, string p);
vector <string> remove_substr(vector <string> vec, string str);

};


#endif //PHASE_1__PARSER_GENERATOR_H
