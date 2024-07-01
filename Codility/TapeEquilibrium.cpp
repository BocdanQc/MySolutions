#include <unordered_map>
#include <limits>

int solution(vector<int> &A) {
    const int N = static_cast<int>(A.size());

    int minDiff = numeric_limits<int>::max();
    int diff = 0;
    int s = 0;
    unordered_map<int,int> sumAfterP;
    for (int p = N - 1; p > 0; --p) {
        s += A[p];
        sumAfterP[p] = s;
    }

    s = 0;
    for (int p = 1; p < N; ++p) {
        s += A[p-1];
        diff = abs(s - sumAfterP[p]);
        if (diff < minDiff) {
            minDiff = diff;
        }
    }

    return minDiff;
}