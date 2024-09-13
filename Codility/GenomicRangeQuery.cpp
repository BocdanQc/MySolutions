/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Author: Daniel Emond
//
// Description: My C++ solutions to the GenomicRangeQuery problem from Codility:
//              https://app.codility.com/programmers/lessons/5-prefix_sums/genomic_range_query/
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <vector>
#include <unordered_map>

#define IMPACT_FACTOR_A 1
#define IMPACT_FACTOR_C 2
#define IMPACT_FACTOR_G 3
#define IMPACT_FACTOR_T 4

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {

    const int N = static_cast<int>(S.length());
    const int M = static_cast<int>(min(P.size(), Q.size()));

    vector<int> queriesResults;

    unordered_map<char, int> counters({{'A', 0}, {'C', 0}, {'G', 0}, {'T', 0}});
    vector<unordered_map<char, int>> countersAtPosition(1, counters);
    for (int i = 0; i < N; i++) {
        counters[S[i]]++;
        countersAtPosition.push_back(counters);
    }

    for (int k = 0; k < M; k++) {
        int fromIdx = P[k], toIdx = Q[k] + 1;
        if (countersAtPosition[toIdx]['A'] - countersAtPosition[fromIdx]['A'] > 0) {
            queriesResults.push_back(IMPACT_FACTOR_A);
        }
        else if (countersAtPosition[toIdx]['C'] - countersAtPosition[fromIdx]['C'] > 0) {
            queriesResults.push_back(IMPACT_FACTOR_C);
        }
        else if (countersAtPosition[toIdx]['G'] - countersAtPosition[fromIdx]['G'] > 0) {
            queriesResults.push_back(IMPACT_FACTOR_G);
        }
        else if (countersAtPosition[toIdx]['T'] - countersAtPosition[fromIdx]['T'] > 0) {
            queriesResults.push_back(IMPACT_FACTOR_T);
        }
        else {
            queriesResults.push_back(0);
        }
    }
    
    return queriesResults;
}
