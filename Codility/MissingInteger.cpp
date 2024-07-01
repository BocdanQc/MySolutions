// Using map
#include <map>

int solution(vector<int> &A) {

    int smallest = 1;

    map<int,bool> integers;

    for (auto ite = A.begin(); ite != A.end(); ++ite) {
        integers[*ite] = true;
    }

    const int biggest = integers.rbegin()->first;

    for (int i = 1; i <= biggest + 1; i++) {
        if (integers.find(i) == integers.end()) {
            smallest = i;
            break;
        }
    }
    return smallest;
}

// Using set
#include <set>

int solution(vector<int> &A) {
    int smallest = 1;

    set<int> integers;
    for (auto ite = A.begin(); ite != A.end(); ++ite) {
        integers.insert(*ite);
    }

    int biggest = *(integers.rbegin());

    for (int i = 1; i <= biggest + 1; i++) {
        if (integers.find(i) == integers.end()) {
            smallest = i;
            break;
        }
    }

    return smallest;
}
