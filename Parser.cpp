#include "Parser.h"
#include <bits/stdc++.h>
#include "helper.h"
using namespace std;
void Parser::parseFile(string filepath){
    ifstream inFile;
    inFile.open(filepath);
    string str;
    while (std::getline(inFile, str)) {
        str= remove_duplicate_spaces(str);
        if (str.find(":") != std::string::npos) {
            str=remove_spaces(str);
            RE_expressions.push_back(str);
        } else if (str[0] == '{') {
            str = str.substr(1,str.length()-2);
            str=remove_first_last_space(str);
            int pos = 0;
            while ((pos = str.find(' ')) != string::npos) {
                keywords.push_back(str.substr(0, pos));
                str.erase(0, pos + 1);
            }
            pos = str.find(' ') != string::npos?str.find(' '):str.size();
            keywords.push_back(str.substr(0, pos));
        } else if (str[0] == '[') {
            str = str.substr(1,str.length()-2);
            str=remove_first_last_space(str);
            int pos = 0;
            while ((pos = str.find(' ')) != string::npos) {
                punctuation.push_back(str.substr(0, pos));
                str.erase(0, pos + 1);
            }
            pos = str.find(' ') != string::npos?str.find(' '):str.size();
            punctuation.push_back(str.substr(0, pos));
        } else if (str.find("=") != std::string::npos) {
            str=remove_spaces(str);
            int index = str.find('=');
            string temp =  str.substr(index+1, str.size());
            RE_definitions.insert({str.substr(0,index), expandDashes(temp)});
        }else{
            cout<<"Invalid Input";
        }
    }}
regex Parser::generateRegex(string str){
    std::regex re("["+str+"]");
    return re;
};