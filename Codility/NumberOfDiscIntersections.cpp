#include <vector>

int solution(vector<int> &A) {
    const int N = static_cast<int>(A.size());
    const int MAX_INTERSECTIONS = 10000000;

    int nbIntersections = 0;

    vector<int> nbDiscsStarts(N, 0);
    vector<int> nbDiscsEnds(N, 0);

    int currStart = 0, currEnd = 0;
    for (int i = 0; i < N; i++) {
        // currStart = (i - A[i] > 0 ? i + A[i] : 0); <-- possible arithmetic overflow
        currStart = (i > A[i] ? i - A[i] : 0);
        // currEnd = (i + A[i] < N ? i + A[i] : N - 1); <-- possible arithmetic overflow
        currEnd = (N - i > A[i] ? i + A[i] : N - 1);

        nbDiscsStarts[currStart]++;
        nbDiscsEnds[currEnd]++;
    }

    int nbActiveDiscs = 0;
    for (int i = 0; i < N; i++)
    {
        if (nbDiscsStarts[i] > 0)
        {
            nbIntersections += nbActiveDiscs * nbDiscsStarts[i];
            // e.g.: if nbDiscsStarts[i] is 3, then the number of intersections is 3 + 2 + 1 => 3 x (3 - 1) / 2
            // i.e.: Sum(1, 2, ..., n) = n x (n - 1) / 2
            nbIntersections += nbDiscsStarts[i] * (nbDiscsStarts[i] - 1) / 2;

            if (nbIntersections > MAX_INTERSECTIONS) {
                nbIntersections = -1;
                break;
            } 
            nbActiveDiscs += nbDiscsStarts[i];
        }
        nbActiveDiscs -= nbDiscsEnds[i];
    }

    return nbIntersections;
}