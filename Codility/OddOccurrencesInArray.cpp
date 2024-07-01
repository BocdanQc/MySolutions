#include <unordered_map>

int solution(vector<int> &A) {
    const size_t N = A.size();
    int unpairedElement = 0;
    unordered_map<int, int> elements;
    for (size_t i = 0; i < N; i++) {
        ++elements[A[i]];
    }
    for (auto& e : elements) {
        if (e.second % 2 != 0) {
            unpairedElement = e.first;
            break;
        }
    }
    return unpairedElement;
}
