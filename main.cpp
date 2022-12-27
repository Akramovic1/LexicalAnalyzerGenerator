#include <iostream>
#include "Parser.h"
#include "State.h"
#include "helper.h"
#include "NFA.h"
#include "NFA_Generator.h"
#include "Identifier.h"
#include "parser_generator.h"
int main(){
//    State* s=new State();
//    Parser p;
//    p.parseFile(R"(C:\Users\mrrad\OneDrive\Documents\GitHub\LexicalAnalyzerGenerator\grammar.txt)");
//    NFA_Generator g;
//    g.generate_all_NFAs(Parser::RE_expressions,p.raw_RE_definitions);
//    Identifier i;
//    i.parse_string(R"(C:\Users\mrrad\OneDrive\Documents\GitHub\LexicalAnalyzerGenerator\test.txt)");
//        for(pair<string,string> pair:i.acceptedTokens){
//        cout<<pair.first<<":"<<pair.second<<endl;
//    }
    parser_generator pg;
    pg.read_file(R"(C:\Users\rana_\Documents\GitHub\LexicalAnalyzerGenerator\test.txt)");
    pg.get_parsing_table();
//    set<string>s={};
//    vector<string>vec={"a","b","c"};
//    s.insert(vec.begin(),vec.end());
//    for (string st:s){
//        cout<<st<<endl;
//    }
//    pg.removeLR();
//    cout<<"Finished!"<<endl;
//    vector<string> vec = {"rana","radwan","radwanon"};
//    vec = subvector(vec,1,vec.size());
//    string s = accumlator(vec,",");
//    cout<<s<<endl;





    //Parser p;
//    p.parseFile(R"(----------!!!!! Grammar file path !!!!! ----------------)");
//    NFA_Generator g;
//    g.generate_all_NFAs(Parser::RE_expressions,p.raw_RE_definitions);
//    Identifier i;
//    i.parse_string(R"(----------!!!! Input file path !!!!! ----------------)");
//        for(pair<string,string> pair:i.acceptedTokens){
//        cout<<pair.first<<":"<<pair.second<<endl;
//    }

//    string s="fg|abB | aB | cdg | cdeB | cfB";
//    pg.left_factor(0);
//    cout<<"......"<<endl;

    //cout<<remove_leading_spaces("   aaa")<<endl;
//    regex terminal(R"('.*')");
//    cout<<regex_match("'a'",terminal)<<endl;
//map<string,vector<string>>graph;
//graph.insert({"E",vector<string>{"E_dash","T"}});
//graph.insert({"E_dash",vector<string>{"T"}});
//graph.insert({"T",vector<string>{"F","T_dash"}});
//graph.insert({"T_dash",vector<string>{"F"}});
//graph.insert({"F",vector<string>{}});
//
//vector<string>sorted= topologicalSort(graph);
//for(string s:sorted) {
//    cout << s << endl;
//}

}
