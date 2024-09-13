/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Author: Daniel Emond
//
// Description: My C++ solution to the MaxCounters problem from Codility:
//              https://app.codility.com/programmers/lessons/4-counting_elements/max_counters/
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

vector<int> solution(int N, vector<int> &A) {
    const int M = static_cast<int>(A.size());

    vector<int> counters;
    int counterMaximum = 0, currMax = 0, currIdx = 0;
    
    if (N > 0) {
        counters.resize(N, 0);
        for (int k = 0; k < M; k++) {
            if (A[k] == N + 1) {
                counterMaximum = currMax;
            }
            else if (1 <= A[k] && A[k] <= N) {
                currIdx = A[k] - 1;
                counters[currIdx] = (counterMaximum > counters[currIdx] ? counterMaximum + 1 : counters[currIdx] + 1);

                if (counters[currIdx] > currMax) {
                    currMax = counters[currIdx];
                }
            }
        }
        for(int i = 0; i < N; i++) {
            if (counterMaximum > counters[i]) {
                counters[i] = counterMaximum;
            }
        }
    }
    return counters;
}