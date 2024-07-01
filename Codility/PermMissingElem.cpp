#include <map>

int solution(vector<int> &A) {
    const int N = static_cast<int>(A.size());

    int missingElement = 0;
    map<int, bool> elements;

    for (auto ite = A.begin(); ite != A.end(); ++ite) {
        elements[*ite] = true;
    }

    for (int i = 1; i <= N + 1; ++i) {
        if (elements.find(i) == elements.end()) {
            missingElement = i;
            break;
        }
    }
    return missingElement;
}