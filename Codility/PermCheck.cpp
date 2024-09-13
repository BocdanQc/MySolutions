/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Author: Daniel Emond
//
// Description: My C++ solution to the PermCheck problem from Codility:
//              https://app.codility.com/programmers/lessons/4-counting_elements/perm_check/
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <set>

int solution(vector<int> &A) {
    const int N = static_cast<int>(A.size());

    multiset<int> sequence;
    for (auto ite = A.begin(); ite != A.end(); ++ite) {
        sequence.insert(*ite);
    }

    for (int i = 1; i <= N; ++i) {
        if (sequence.count(i) != 1) {
            return 0;
        }
    }
    return 1;
}
