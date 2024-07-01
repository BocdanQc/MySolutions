#include <cmath>

int solution(int X, int Y, int D) {
    int nbJumps = 0;
    if (D > 0) {
        nbJumps = static_cast<int>(ceil(abs(Y - X) / static_cast<double>(D)));
    }
    return nbJumps;
}