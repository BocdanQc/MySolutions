/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Author: Daniel Emond
//
// Description: My C++ solution to the PassingCars problem from Codility:
//              https://app.codility.com/programmers/lessons/5-prefix_sums/passing_cars/
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define GOING_EAST 0
#define GOING_WEST 1

int solution(vector<int> &A) {
    const int N = static_cast<int>(A.size());

    const int MAX_PASSING_CARS = 1000000000;

    int nbPassingCars = 0, nbCarsGoingEast = 0;

    for (int i = 0; i < N; ++i) {
        if (A[i] == GOING_EAST) {
            nbCarsGoingEast++;
        }
        else { // A[i] == GOING_WEST
            nbPassingCars += nbCarsGoingEast;
        }

        if (nbPassingCars > MAX_PASSING_CARS) {
            nbPassingCars = -1;
            break;
        }
    }

    return nbPassingCars;
}