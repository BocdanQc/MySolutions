/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Author: Daniel Emond
//
// Description: My C++ solutions to the Distinct problem from Codility:
//              https://app.codility.com/programmers/lessons/6-sorting/distinct/
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <set>

int solution(vector<int> &A) {
    
    set<int> distinctValues;
    
    for (auto ite = A.begin(); ite != A.end(); ++ite) {
        distinctValues.insert(*ite);
    }

    return distinctValues.size();
}