#include <iostream>
#include "Parser.h"
#include "State.h"
#include "helper.h"
#include "NFA.h"
#include "NFA_Generator.h"
#include "Identifier.h"
#include "parser_generator.h"

int main(){
//    Parser p;
//    p.parseFile(R"(----------!!!!! Grammar file path !!!!! ----------------)");
//    NFA_Generator g;
//    g.generate_all_NFAs(Parser::RE_expressions,p.raw_RE_definitions);
//    Identifier i;


//    i.parse_string(R"(----------!!!! Input file path !!!!! ----------------)");
//        for(pair<string,string> pair:i.acceptedTokens){
//        cout<<pair.first<<":"<<pair.second<<endl;
//    }

    parser_generator pg;
    pg.read_file(R"(C:\Users\mrrad\OneDrive\Documents\GitHub\LexicalAnalyzerGenerator\test.txt)");
    pg.removeLR();
    pg.left_factor();
    pg.get_parsing_table();

}
