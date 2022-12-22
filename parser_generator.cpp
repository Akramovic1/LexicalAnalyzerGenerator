

#include "parser_generator.h"
#include "helper.h"
void parser_generator::read_file(string filepath) {
    ifstream inFile;
    inFile.open(filepath);
    string str;
    regex new_rule(R"([\s]*[a-zA-z]*[\s]*=.*)");
    string LHS;
    while(getline(inFile, str)){
        if(regex_match(str,new_rule)){
            int pos=str.find('=');
            LHS = remove_spaces(str.substr(0,pos));
            string RHS=  str.substr(pos+1,str.size());
            this->grammer_rules.emplace_back(make_pair(LHS,RHS));
        }
        else{
            this->grammer_rules.back().second.append(str);
        }
    }
}

void parser_generator::removeLR() {
    for(int i = 0; i<grammer_rules.size(); i++){
        for(int j=0; j<i; j++){
            substitute(i,j);
        }
        eliminate_immediate_LR(i);
    }
}
void  parser_generator::eliminate_immediate_LR(int rule_index){
    pair<string,string> rule=grammer_rules[rule_index];
    vector<string> productions = split_on_spacial_chars(rule.second, regex(R"([\|])"));
    pair<string,string>dash= make_pair(rule.first+"_dash","");
    string temp;
     for(int i=0;i<productions.size();i++){
         if(productions[i]=="|")continue;
         vector<string> prod_parts = split_on_spacial_chars(productions[i],regex(R"([\s]+)"));
         if(prod_parts[0]==rule.first){
             string accu=accumlator(subvector(prod_parts,1,prod_parts.size()), " ");
             dash.second.append(accu.append(" "+dash.first+" |"));
         }else{
             string accu=accumlator(prod_parts, " ");
             temp.append(accu+" "+dash.first+" |");
         }
     }
     if(!dash.second.empty()){
        grammer_rules.at(rule_index).second=temp.substr(0,temp.size()-1);
        dash.second.append(" epsilon");
        grammer_rules.emplace_back(dash);
     }
}

void parser_generator::left_factor(int index) {
    for (index = 0; index < grammer_rules.size(); index++) {
        string RHS = grammer_rules[index].second;
        vector <string> productions = split_on_spacial_chars(RHS, regex(R"([\|])"));
        sort(productions.begin(), productions.end());
        map <string, vector<string>> groups;
        int group_index = -1;
        string group = productions[0];
        int current = -1;
        string refactored;
        for (string p: productions) {
            if (p == "|")continue;
            string substr = get_match_substr(group, p);
            if (substr.size() == 0) {
                if (group_index < current - 1) {
                    vector <string> group_str = remove_substr(subvector(productions, group_index + 1, current + 1),group);
                    groups.insert({group, group_str});
                } else {
                    refactored.append(group + " |");
                }
                group = p;
                group_index = current;
            } else {
                group = substr;
            }
            current++;
        }
        if (group_index < current - 1) {
            vector <string> group_str = remove_substr(subvector(productions, group_index + 1, current + 1), group);
            groups.insert({group, group_str});
        } else {
            refactored.append(group + " |");
        }
        for (auto const&[key, val]: groups) {
            refactored.append(key + " " + key + "_dash " + "|");
            grammer_rules.push_back({key + "_dash", accumlator(val, "|")});
        }
        grammer_rules[index].second = refactored.substr(0, refactored.size() - 1);
    }
}

string parser_generator::get_match_substr(string group,string p){
    for(int i=0;i<min(p.size(),group.size());i++){
        if(group[i]!=p[i]){
           return p.substr(0,i);
        }
    }
    if(p.size()<group.size()) return p;
    return group;
}
vector<string> parser_generator::remove_substr(vector<string>vec,string str){
    vector<string>result;
    for(int i=0;i<vec.size();i++){
        result.emplace_back(vec[i].substr(str.size(),vec[i].size()));
    }
    return result;
}
void parser_generator::get_parsing_table() {

}

void parser_generator::substitute(int i,int j){
    pair<string,string> rule_i=grammer_rules[i];
    pair<string,string> rule_j=grammer_rules[j];
vector<string>rule_i_productions= split_on_spacial_chars(rule_i.second, regex(R"([\|])"));
    for(int i=0; i < rule_i_productions.size(); i++){
        string rule_i_prod=rule_i_productions[i];
        vector<string> rule_i_prod_part= split_on_spacial_chars(rule_i_prod,regex(R"([\s]+)"));
        if(rule_i_prod_part[0]==rule_j.first){
            string accu=accumlator(subvector(rule_i_prod_part,1,rule_i_prod_part.size()), " ");
            vector<string>rule_j_productions=split_on_spacial_chars(rule_j.second, regex(R"([\|])"));
            for(int j=0;j<rule_j_productions.size();j++){
                if(rule_j_productions[j]!="|")
                rule_j_productions[j].append(" "+accu);
            }
            string rule_j_substitution=accumlator(rule_j_productions, " ");
            rule_i_productions[i]=rule_j_substitution;
        }
    }
    string rule_i_prod_final=accumlator(rule_i_productions, " ");
    grammer_rules.at(i).second=rule_i_prod_final;
}