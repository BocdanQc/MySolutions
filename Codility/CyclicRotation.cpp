vector<int> solution(vector<int> &A, int K) {
    const int N = static_cast<int>(A.size());
    vector<int> rotA = A;
    if (N > 0) {
        int nbRot = K % N;
        if (nbRot > 0) {
            for (int i = 0; i < N; ++i) {
                rotA[(i + nbRot) % N] = A[i];
            }
        }
    }
    return rotA;
}