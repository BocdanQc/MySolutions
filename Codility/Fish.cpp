/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Author: Daniel Emond
//
// Description: My C++ solutions to the Fish problem from Codility:
//              https://app.codility.com/programmers/lessons/7-stacks_and_queues/fish/
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stack>

int solution(vector<int> &A, vector<int> &B) {
    if (A.size() != B.size())
        return A.size();

    int nbFishAlive = 0;
    stack<int> opposingFishes;
    for (size_t i = 0; i < A.size(); i++) {
        // Going downstream
        if (B[i] == 1) {
            opposingFishes.push(A[i]);
            nbFishAlive++;
        }
        // Going upstream
        else {
            while (!opposingFishes.empty() && A[i] > opposingFishes.top()) {
                if (A[i] > opposingFishes.top()) {
                    opposingFishes.pop();
                    nbFishAlive--;
                }
            }
            if (opposingFishes.empty()){
                nbFishAlive++;
            }
        }
    }
    return nbFishAlive;
}
