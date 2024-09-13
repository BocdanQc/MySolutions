/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Author: Daniel Emond
//
// Description: My C++ solution to the Nesting problem from Codility:
//              https://app.codility.com/programmers/lessons/7-stacks_and_queues/nesting/
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stack>

int solution(string &S) {
    stack<char> openBrackets;

    for (size_t i = 0; i < S.length(); i++) {
        if (S[i] == '(') {
            openBrackets.push('(');
        }
        else if (S[i] == ')') {
            if (openBrackets.top() == '(')
                openBrackets.pop();
            else
                return 0;
        }
    }
    return openBrackets.empty() ? 1 : 0;
}