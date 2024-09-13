/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Author: Daniel Emond
//
// Description: My C++ solution to the LaserShooter2D problem from a Evident Scientific / Olympus (Montreal) interview
//              question using Codility (https://app.codility.com/).
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <set>

int FindGCD(int a, int b) {
    return (b == 0) ? a : FindGCD(b, a % b);
}

pair<int, int> MakeReducedSlope(int dY, int dX) {
    pair<int, int> slope;

    int gcd = FindGCD(abs(dY), abs(dX));

    return make_pair(dY / gcd, dX / gcd);
}

int solution(vector<Point2D> &A) {
    const int NB_STATUES = static_cast<int>(A.size());

    int minRays = 0;

    set<pair<int, int>> rays;
    pair<int, int> currRay;

    for (int i = 0; i < NB_STATUES; ++i) {
        currRay = MakeReducedSlope(A[i].y, A[i].x);

        if (rays.find(currRay) == rays.end()) {
            rays.insert(currRay);
            minRays++;
        }
    }

    return minRays;
}
