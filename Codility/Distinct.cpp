#include <set>

int solution(vector<int> &A) {
    
    set<int> distinctValues;
    
    for (auto ite = A.begin(); ite != A.end(); ++ite) {
        distinctValues.insert(*ite);
    }

    return distinctValues.size();
}