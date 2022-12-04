//
// Created by mrrad on 11/29/2022.
//
#include <bits/stdc++.h>
#ifndef PHASE_1__HELPER_H
#define PHASE_1__HELPER_H
static int id_generator=0;
static string remove_spaces(string input){
    input.erase(remove(input.begin(), input.end(), ' '), input.end());
    return input;
}
static bool isBothSpace(char const &lhs, char const &rhs) {
    return lhs == rhs && iswspace(lhs);
}
static string remove_duplicate_spaces(string str) {
    auto it = unique(str.begin(), str.end(), isBothSpace);
    str.erase(it, str.end());
    return str;
}
static  string remove_first_last_space(string str){
    if(str.at(0)==' ') str = str.substr(1,str.length()-1);
    if(str.at(str.length()-1)==' ') str = str.substr(0,str.length()-1);
    return str;
}
static vector<string> split_on_spacial_chars(string str) {
    vector<string> result;
    regex rgx(R"([+()*\|\-,:?\s\\]+)");
//    sregex_token_iterator iter(str.begin(), str.end(), rgx, -1);
//    sregex_token_iterator end;
//    for (; iter != end; ++iter){
//        result.push_back(*iter);
//    }
    string current_string="";
    for(char c:str){
        if(regex_match(string(1,c),rgx)){
            if(!current_string.empty()){
                result.push_back(current_string);
            }
            if(c!=' '){
                result.push_back(string(1, c));
            }
           current_string="";
        }
        else{
            current_string.append(string(1,c));
        }
    }
    if(!current_string.empty())result.push_back(current_string);
    return result;
}
static bool is_spacial_character(string c){
    regex rgx(R"([+()*\|\-?\s\\]+)");
    return regex_match(c,rgx);
}
static vector<string> generate_infix(vector<string>RE_expression_tokens) {
    for (int i = 1; i < RE_expression_tokens.size(); i++) {
        if(RE_expression_tokens.at(i)=="\\"){
            i++;
        }
        else if (RE_expression_tokens.at(i) == "(" && RE_expression_tokens.at(i-1)!="|") {
            RE_expression_tokens.insert(RE_expression_tokens.begin() + i, string(1,'`'));
            i+=1;
        } else if (!is_spacial_character(RE_expression_tokens.at(i)) &&
                   (RE_expression_tokens.at(i - 1) == "*" || RE_expression_tokens.at(i - 1) == "+" || !is_spacial_character(RE_expression_tokens.at(i - 1)) || RE_expression_tokens.at(i - 1) == ")")) {
            RE_expression_tokens.insert(RE_expression_tokens.begin() + i, string(1,'`'));
            i+=1;
        }
    }
    return RE_expression_tokens;
}
static string surround_parentheses(string input){
    if(is_spacial_character(input)) return input;
    for(int i = 0; i < input.size(); i++) {
        input.insert(i, "(");
        input.insert(i + 2, ")");
        i += 2;
    }
    return input;
}

//Function to return precedence of operators
static int prec(string c)
{
    if (c == "*"|| c=="+")
        return 3;
    else if (c == "`" )
        return 2;
    else if (c == "|" )
        return 1;
    else
        return -1;
}

 //The main function to convert infix expression
 //to postfix expression
static vector<string> infixToPostfix(vector<string>RE_expression_tokens)
{
    stack<string> st; // For stack operations, we are using
    // C++ built in stack
     vector<string>postfix;

    for (int i = 0; i < RE_expression_tokens.size(); i++) {
        string c = RE_expression_tokens.at(i);
        if(c=="\\"){
            postfix.push_back(c);
            i++;
            postfix.push_back(RE_expression_tokens.at(i));
        }
        // If the scanned character is
        // an operand, add it to output string.
       else if (!is_spacial_character(c) && c!="`")
            postfix.push_back(c);
            // If the scanned character is an
            // ‘(‘, push it to the stack.
        else if (c == "(")
            st.push("(");
            // If the scanned character is an ‘)’,
            // pop and to output string from the stack
            // until an ‘(‘ is encountered.
        else if (c == ")") {
            while (st.top() != "(") {
                postfix.push_back(st.top());
                st.pop();
            }
            st.pop();
        }
            // If an operator is scanned
        else {
            while (!st.empty()
                   && prec(RE_expression_tokens[i]) <= prec(st.top())) {
                postfix.push_back(st.top());
                st.pop();
            }
            st.push(c);
        }
    }
    // Pop all the remaining elements from the stack
    while (!st.empty()) {
        postfix.push_back(st.top());
        st.pop();
    }
    return postfix;
}

static vector<char> expandDashes(string in) {
    char x,y;
    vector<char> temp,tempo;
    for(int i=0;i<in.length();++i){
        temp.clear();
        if(in[i]=='-'&&in[i-1]!='\\'&&in[i-1]<in[i+1]){
            x=in[i-1];
            y=in[i+1];
            while(x<=y)
                temp.push_back(x++);
            tempo.push_back(temp[0]);
            for(int j=1;j<temp.size();j++){
//                tempo+='|';
                tempo.push_back(temp[j]);
            }
//            in.replace(i-1,3,tempo);
        }
    }
    return tempo;
}
#endif //PHASE_1__HELPER_H
