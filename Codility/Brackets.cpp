/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Author: Daniel Emond
//
// Description: My C++ solution to the Brackets problem from Codility:
//              https://app.codility.com/programmers/lessons/7-stacks_and_queues/brackets/
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stack>
bool IsOpenBracket(char c) {
    return (c == '(' || c == '[' || c == '{');
}
bool IsCloseBracket(char c) {
    return (c == ')' || c == ']' || c == '}');
}

char MatchingBracket(char c) {
    switch (c) {
        case '(': return ')';
        case ')': return '(';
        case '[': return ']';
        case ']': return '[';
        case '{': return '}';
        case '}': return '{';
    }
    return ' ';
}

int solution(string &S) {
    stack<char> openBrackets;

    for (size_t i = 0; i < S.length(); i++) {
        // Parathesis
        if (IsOpenBracket(S[i])) {
            openBrackets.push(S[i]);
        }
        else if (IsCloseBracket(S[i])) {
            if (openBrackets.top() == MatchingBracket(S[i]))
                openBrackets.pop();
            else
                return 0;
        }
    }
    return openBrackets.empty() ? 1 : 0;
}