#include <vector>
#include <map>

int solution(int X, vector<int> &A) {
    const int N = static_cast<int>(A.size());

    int earliestTime = -1;

    map<int, int> leaves;
    for (int i = N - 1; i >= 0; i--) {
        leaves[A[i]] = i;
    }
    for (int i = 1; i <= X; i++) {
        if (leaves.find(i) != leaves.end()) {
            if (leaves[i] > earliestTime){
                earliestTime = leaves[i];
            }
        }
        else {
            earliestTime = -1;
            break;
        }
    }
    return earliestTime;
}