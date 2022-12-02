//
// Created by mrrad on 11/28/2022.
//
#include <bits/stdc++.h>
using namespace std;
#ifndef PHASE_1__PARSER_H
#define PHASE_1__PARSER_H


class Parser {
public:
    map<string,vector<char>>RE_definitions;
    vector<string>RE_expressions;
    vector<string>keywords;
    vector<string>punctuation;
    vector<string>restrictedSymbols;

    void parseFile(string filepath);
    regex generateRegex(string str);
};


#endif //PHASE_1__PARSER_H
