#include <bits/stdc++.h>
#ifndef PHASE_1__HELPER_H
#define PHASE_1__HELPER_H
static int id_generator=0;
static string remove_spaces(string input){
    input.erase(remove(input.begin(), input.end(), ' '), input.end());
    return input;
}
static string remove_leading_spaces(string str){
    int i;
    for(i=0;i<str.size();i++){
          if(str[i]!=' ') break;
    }
    return str.substr(i,str.size());
}

static vector<string> split_on_spacial_chars(string str,regex rgx=regex(R"([+()*\|\-,:?\s\\]+)")) {
    vector<string> result;
    string current_string="";
    for(char c:str){
        if(regex_match(string(1,c),rgx)){
            if(!current_string.empty()){
                result.push_back(remove_leading_spaces(current_string));
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
    if(!current_string.empty())result.push_back(remove_leading_spaces(current_string));
    return result;
}
static bool is_spacial_character(string c){
    regex rgx(R"([+()*\|\?\s\\]+)");
    return regex_match(c,rgx);
}
static vector<string> generate_infix(vector<string>RE_expression_tokens) {
    for (int i = 1; i < RE_expression_tokens.size(); i++) {
        if(RE_expression_tokens.at(i)=="\\"){
            i++;
        }
        else if (RE_expression_tokens.at(i) == "(" && RE_expression_tokens.at(i-1)!="|" && RE_expression_tokens.at(i-1)!="(") {
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

//return precedence of operators
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

//convert infix expression to postfix expression
static vector<string> infixToPostfix(vector<string>RE_expression_tokens)
{
    stack<string> st;
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

static vector<char> get_ranges(string range) {
    range=remove_spaces(range);
    vector<char>result;
    while(range.find('-') != string::npos){
        int pos=range.find('-');
        int before=min(range[pos-1],range[pos+1]);
        int after=max(range[pos-1],range[pos+1]);
        range=range.substr(pos+1);
        for(int i=before;i<=after;i++){
            result.push_back(i);
        }
    }
    return result;
}
static string accumlator(vector<string>input,string delimter){
    string result="";
    for(string s:input){
        result.append(s+delimter);
    }
    return result.substr(0,result.size()-1);

}
static vector<string> subvector(vector<string>v, int m, int n) {
    vector<string>result;
    for(int i=m;i<n;i++){
        result.emplace_back(v[i]);
    }
    return result;
}
#endif //PHASE_1__HELPER_H
