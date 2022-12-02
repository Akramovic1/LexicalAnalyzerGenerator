#include <iostream>
#include "Parser.h"
#include "State.h"
#include "helper.h"
#include "NFA.h"
#include "NFA_Generator.h"
int main(){
//    Parser p;
//    p.parseFile(R"(E:\CSED23\year_(4)four_1st term\Compilers\Project\Phase(1)\test.txt)");
//    State s;
//    regex r("[0-9]");
//    s.checker=p.RE_definitions.at("digit");
//    cout<<s.check("6")<<endl;
//    std::string s = "who,li\\ves:in-a,pineapple    under-the+sea?";
    std::string s = "a-z 1-9";
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
    p.parseFile(R"(C:\Users\rana_\Downloads\Phase(1)\test.txt)");
    NFA_Generator g;
//    g.GenerateNFA(p.RE_expressions[0],p.RE_definitions);
    g.GenerateNFA("mulop: \\* | /",p.RE_definitions);

}
