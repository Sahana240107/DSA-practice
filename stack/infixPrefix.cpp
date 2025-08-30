/*Infix to postfix
Input: s = "a+b*(c^d-e)^(f+g*h)-i"
Output: abcd^e-fgh*+^*+i-  */
#include <bits/stdc++.h>
using namespace std;

// Function to return precedence of operators
int precedence(char c) {
    if(c == '^')
        return 3;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// Function to check if character is operand
bool isOperand(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (isdigit(c));
}

// Function to convert infix to postfix
string infixToPostfix(string s) {
    stack<char> st;
    string result;
    for(int i=0; i<s.length(); i++) {
        char c = s[i];
        // If operand, add to result
        if(isOperand(c))
            result += c;
        // If '(', push to stack
        else if(c == '(')
            st.push('(');
        // If ')', pop until '('
        else if(c == ')') {
            while(!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            if(!st.empty())
                st.pop(); // remove '('
        }

        // Operator
        else {
            while(!st.empty() && precedence(s[i]) <= precedence(st.top())) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop all operators
    while(!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}

// Function to convert infix to prefix
string infixToPrefix(string infix) {
    // Reverse infix
    reverse(infix.begin(), infix.end());

    // Replace '(' with ')' and vice versa
    for(int i=0; i<infix.length(); i++) {
        if(infix[i] == '(') infix[i] = ')';
        else if(infix[i] == ')') infix[i] = '(';
    }

    // Get postfix of modified expression
    string postfix = infixToPostfix(infix);

    // Reverse postfix to get prefix
    reverse(postfix.begin(), postfix.end());

    return postfix;
}