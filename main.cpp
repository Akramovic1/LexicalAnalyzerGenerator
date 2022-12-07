#include <iostream>
#include "Parser.h"
#include "State.h"
#include "helper.h"
#include "NFA.h"
#include "NFA_Generator.h"
#include "Identifier.h"
int main(){
    Parser p;
    p.parseFile(R"(----------!!!! Input file path !!!!! ----------------)");
    NFA_Generator g;
    g.generate_all_NFAs(Parser::RE_expressions,p.raw_RE_definitions);
    Identifier i;
    i.parse_string(R"(----------!!!!! Grammar file path !!!!! ----------------)");
        for(pair<string,string> pair:i.acceptedTokens){
        cout<<pair.first<<":"<<pair.second<<endl;
    }
}
