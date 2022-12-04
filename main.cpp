#include <iostream>
#include "Parser.h"
#include "State.h"
#include "helper.h"
#include "NFA.h"
#include "NFA_Generator.h"
#include "Identifier.h"
int main(){
//    Parser p;
//    p.parseFile(R"(E:\CSED23\year_(4)four_1st term\Compilers\Project\Phase(1)\grammar.txt)");
//    State s;
//    regex r("[0-9]");
//    s.checker=p.RE_definitions.at("digit");
//    cout<<s.check("6")<<endl;
//    std::string s = "who,li\\ves:in-a,pineapple    under-the+sea?";
//    std::string s = "letter | digit  +";
//    vector<string>r=split_on_spacial_chars(s);
//    for(string s:r){
//        cout<<s<<" ";
//    }
//    cout<<endl;
//    r=generate_infix(r);
//    for(string s:r){
//        cout<<s<<" ";
//    }
//    cout<<endl;
//
//    vector<string> test = infixToPostfix(r);
//    for(string s:test){
//        cout<<s<<" ";
//    }
//    cout<<endl;
    Parser p;
    p.parseFile(R"(C:\Users\rana_\Documents\GitHub\LexicalAnalyzerGenerator\grammar.txt)");
    NFA_Generator g;
    g.generate_all_NFAs(Parser::RE_expressions,p.raw_RE_definitions);
    Identifier i;
    i.parse_string(R"(C:\Users\rana_\Documents\GitHub\LexicalAnalyzerGenerator\test.txt)");
        for(pair<string,string> pair:i.acceptedTokens){
        cout<<pair.first<<":"<<pair.second<<endl;
    }
//    g.GenerateNFA("mulop: \\* | /",p.RE_definitions);
//    cout<<surround_parentheses("Rana")<<endl;


}
