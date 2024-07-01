#include <vector>
#include <algorithm>

int solution(vector<int> &A) {
    const int N =  static_cast<int>(A.size());

    int hasTriangularTriplet = 0;

    if (N >= 3) {
        sort(A.begin(), A.end());

        long long int ap, aq, ar;
        for (int i = 0; i < N - 2; i++) {
            //  * A[P] + A[Q] > A[R],
            //  * A[Q] + A[R] > A[P],
            //  * A[R] + A[P] > A[Q].
            ap = A[i]; aq = A[i + 1]; ar = A[i + 2];
            if ((ap + aq) > ar && (aq + ar) > ap && (ar + ap) > aq) {
                hasTriangularTriplet = 1;
                break;
            }

        }
    }

    return hasTriangularTriplet;
}