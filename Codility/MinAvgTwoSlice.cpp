/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Author: Daniel Emond
//
// Description: My C++ solution to the MinAvgTwoSlice problem from Codility:
//              https://app.codility.com/programmers/lessons/5-prefix_sums/min_avg_two_slice/
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <limits>

int solution(vector<int> &A) {
    const int N = static_cast<int>(A.size());

    int minIdxP = 0;
    double minAvg = numeric_limits<double>::max();
    int sum = 0;
    double avg = 0.;
    for (int i = 0; i < N - 1; i++) {
        // Smallest Slice (P, Q) where Q = P + 1 (size of 2) 
        sum = A[i] + A[i + 1];
        avg = static_cast<double>(sum) / 2.;
        if (avg < minAvg) {
            minAvg = avg;
            minIdxP = i;
        }
        // Slice (P, Q) where Q = P + 2 (size of 3)
        if (i + 2 < N) {
            sum += A[i + 2];
            avg = static_cast<double>(sum) / 3.;
            if (avg < minAvg) {
                minAvg = avg;
                minIdxP = i;
            }
        }
        // Why not consider bigger slices?
    }

    return minIdxP;
}
