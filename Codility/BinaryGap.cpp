int solution(int N) {
    int gap = 0, longestGap = 0;
    bool startGapCount = false;
    while (N > 0){
        if (N & 1) {
            startGapCount = true;
            gap = 0;
        }
        else if (startGapCount) {
            ++gap;
        }
        if (gap > longestGap) {
            longestGap = gap;
        }
        N = N >> 1;
    }
    return longestGap;
}