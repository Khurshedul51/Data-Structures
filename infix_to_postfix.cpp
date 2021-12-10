#include <bits/stdc++.h>
using namespace std;

int precidency(char c){
    if(c == '^') return 3;
    else if(c == '*' || c == '/') return 2;
    else if(c == '+' || c == '-') return 1;
    else return -1;
}
void infix_to_postfix(string s){
    stack<char> st;
    string result;
    // scanning expression
    for(int i = 0; i< s.length(); i++){
        char c = s[i];

        // if scanned char is an operand add it to result string
        if((c>='A'&&c<='Z') || (c>='a'&&c<='z') || (c>='0'&&c<='9')){
            result += c;
        }
        //if the scanned char is an '(' push it to the stack.
        else if(c == '('){
            st.push(c);
        }
        // If the scanned character is an ‘)’,
        // pop and to output string from the stack
        // until an ‘(‘ is encountered.
        else if(c == ')'){
            while(st.top() != '('){
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        // if an operator is scanned 
        else{
            while(!st.empty() && precidency(c) <= precidency(st.top())){
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    // pop all remaining elements from the stack
    while(!st.empty()){
        result += st.top();
        st.pop();
    }

    cout << "postfix expression: " << result << "\n";
}
int main(){

    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    infix_to_postfix(exp);// abcd^e-fgh*+^*+i-
    return 0;
}