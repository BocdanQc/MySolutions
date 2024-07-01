// Brute Force
int solution(int A, int B, int K) {
    int nbDivisors = 0;

    for (int i = A; i <= B; i++) {
        if (i % K == 0) {
            nbDivisors++;
        }
    }

    return nbDivisors;
}

// Better using equation
int solution(int A, int B, int K) {
    int nbDivisors = 0;

    int AmodK = A % K;
 
    // Is A a factor of K then the number of factors of K in the range A to B is:
    //     rangeAtoB / K + 1
    if (AmodK == 0) {
        nbDivisors = (B - A) / K + 1;
    }
    // Otherwise, the number of factors of K in the range A to B is:
    //     rangeA-A%KtoB / K
    else {
        nbDivisors = (B - A + AmodK) / K;
    }

    return nbDivisors;
}
