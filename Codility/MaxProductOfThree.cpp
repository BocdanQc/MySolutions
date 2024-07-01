// Greatest will always be: (X*Z > Y*Z ? X*Z : Y*Z) where
//   There are at least 5 elements
//   X = biggest two negative numbers (or first two elements of array)
//   Z = largest number (last element of array)
//   Y = second and third largest number (N-1 and N-2, respectively)
// Edge cases:
//   3 elements - just return A[P]*A[Q]*A[R]
//   4 elements - [a b c d] - return greater of abd or bcd

#include <vector>
#include <algorithm>

int solution(vector<int> &A) {
    const int N = static_cast<int>(A.size());

    long long int maxProduct = 0;
    if (N == 3) {
        maxProduct = A[0] * A[1] * A[2];
    }
    else if (N >= 4) {
        sort(A.begin(), A.end());
        maxProduct = max(A[0] * A[1] * A[N-1], A[N-3] * A[N-2] * A[N-1]);
    }

    return static_cast<int>(maxProduct);
}


