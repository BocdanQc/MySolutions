/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Author: Daniel Emond
//
// Description: My C++ solution to the IncreaseTheDigits problem from a Evident Scientific / Olympus (Montreal) interview
//              question using Codility (https://app.codility.com/).
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// You are given two strings, 𝑆 ﻿and 𝑇, ﻿both of length 𝑁. ﻿Both strings are made up of digits.
// In a single move, you can select an index 𝐾 ﻿within the range [0..N-2] and increase the digits 𝑆[𝐾] ﻿and 𝑆[𝐾+1] ﻿by 1. ﻿If a digit 9 ﻿is increased, it becomes 0.
//
// Is it possible to transform 𝑆 ﻿into 𝑇 ﻿by performing some (possibly zero) number of such moves? If so, ﻿what is the minimum number of moves needed?
//
// Write a function:
//     int solution(string &S, ﻿string &T);
// that, given strings 𝑆 ﻿and 𝑇, ﻿each of length 𝑁, ﻿returns the minimum number of moves needed to transform 𝑆 ﻿into 𝑇. ﻿If it is not possible to obtain 𝑇 ﻿in this way, return -1.
//
// Examples:
// 1. For 𝑆 = "13471" ﻿and 𝑇 = "59604", ﻿the function should return 9.
// A valid sequence of moves could be as follows:
//   * choose index 1 ﻿and increase S[1] ﻿and S[2] ﻿two times.   After these moves, S becomes "1 56 71".
//   * choose index 3 ﻿and increase S[3] ﻿and S[4] ﻿three times. After these moves, S becomes "156 04".
//   * choose index 0 ﻿and increase S[0] ﻿and S[1] four times.  After these moves, S becomes "59 604".
// In the end, 𝑆 is equal to 𝑇. It took nine moves in total.
// 2. For 𝑆 = "557" ﻿and 𝑇 = "403", ﻿the function should return 15.
// 3. For 𝑆 = "557" ﻿and 𝑇 = "403", ﻿the function should return -1.
// 4. For 𝑆 = "1343" ﻿and 𝑇 = "1343", ﻿the function should return 0. 𝑆 is already equal to 𝑇, so there is no need to perform any moves.
//

// From the web
int get(int x, int last, int y) {
    return (y - x - last + 100) % 10;
}

int solution(string S, string T) {
    const int N = S.length();

    int r = 0, last = 0;
    for (int i = 0; i < N - 1; i++) {
        last = get(S[i], last, T[i]);
        r += last;
    }

    return get(S[N - 1], last, T[N - 1]) == 0 ? r : -1;
}

// OR Mine
int GetNbMoves(int source, int target, int previousNbMoves) {
    return (100000000 + target - source - previousNbMoves) % 10;
}

int solution(string S, string T) {
    int nbMoves = 0;
    if (S.length() == T.length()) {
        const int N = static_cast<int>(S.length());
        int previousNbMoves = 0;
        for (int i = 0; i < N - 1; i++) {
            previousNbMoves = GetNbMoves(S[i], T[i], previousNbMoves);
            nbMoves += previousNbMoves;
        }
        if (GetNbMoves(S[N - 1], T[N - 1], previousNbMoves) != 0) {
            nbMoves = -1;
        }
    }
    else {
        nbMoves = -1;
    }
        
    return nbMoves;
}

int main()
{
    cout << solution("13471", "59604") << endl;
    cout << solution("557", "403") << endl;
    cout << solution("115", "116") << endl;
    cout << solution("1343", "1343") << endl;
    cout << solution("1", "1") << endl;
    cout << solution("1", "9") << endl;

    return 0;
}

// To solve this problem, we need to carefully analyze how the operation of increasing digits affects the transformation from string S to string T. Let's break down the solution into steps:
// ### Step 1: Understand the Problem First, ensure you understand the problem correctly.
//             You are given two strings, S and T, both of the same length and composed of digits.
//             You can select any index K (from 0 to N-2) and increase the digits at S[K] and S[K+1] by 1, with the digit 9 rolling over to 0.
//             The goal is to determine if it's possible to transform S into T using this operation and, if so, find the minimum number of moves required.
// ### Step 2: Analyze the Operation's Effect.
//             Notice that each operation affects two adjacent digits.
//             This means the transformation from S to T depends on the relative differences between corresponding digits in S and T.
//             Also, since the operation increases digits, if T has a digit that is less than the corresponding digit in S (without considering rollover from 9 to 0), direct transformation is impossible.
// ### Step 3: Calculate the Differences.
//             For each pair of corresponding digits in S and T (S[i] and T[i]), calculate the difference (T[i] - S[i]).
//             If the difference is negative, add 10 to it to account for the rollover.
//             This gives you the minimum number of increases needed for each digit to match, considering rollovers.
// ### Step 4: Check for Adjacent Differences.
//             Since each operation increases two adjacent digits, the differences calculated in Step 3 for adjacent digits in S and T must be the same or differ by at most 1.
//             If there's a pair of adjacent digits where the difference is more than 1, transforming S into T is impossible.
// ### Step 5: Calculate the Minimum Number of Moves If the transformation is possible, the minimum number of moves required is the maximum difference found in Step 3.
//             This is because, in the best-case scenario, you are performing operations that simultaneously satisfy the increase needed for two adjacent digits. 
// ### Step 6: Implement the Solution:
//             1. Initialize a variable to keep track of the maximum difference found.
//             2. Loop through the digits of S and T, calculating the difference for each pair of digits as described in Step 3.
//             3. As you calculate differences, check the condition described in Step 4. If any pair of adjacent digits violates this condition, conclude that the transformation is impossible.
//     Answer  4. If all pairs of adjacent digits satisfy the condition, the transformation is possible, and the maximum difference calculated is the minimum number of moves required.
// ### Example Let's apply these steps to a small example: - S = "129" - T = "231"
//             Step 3: Calculate differences (considering rollover):
//                      - For S[0] to T[0]: 2 - 1 = 1
//                      - For S[1] to T[1]: 3 - 2 = 1
//                      - For S[2] to T[2]: 1 - 9 + 10 = 2 (9 rolls over to 0, so add 10: 3 - 9 + 10 = 4)
//             Step 4: Check for adjacent differences:
//                      - Differences are [1, 4, 2]. The differences between adjacent digits are more than 1, so direct transformation is not possible in this case.
//             This example demonstrates the steps but also highlights the importance of carefully checking the conditions in Step 4.
//             Adjust the example as needed to fit scenarios where transformation is possible to better understand the calculation of the minimum number of moves.





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Other example
//
// Minimum number of increment operations required to make two Strings equal
//
// Given two strings S1 and S2 of the same length containing characters ranging from ‘0’ to ‘9’,
// the task is to return the minimum number of operations required to make two strings equal by following the below operations:
//  * Increment any two characters from the string by 1.
//  * If it is not possible to make two strings equal with above condition then return -1.
//
// Examples:
// 
// Input : S1 = “12”, S2 = “21”
// Output : 1
// Explanation: Operation 1: Increment first index of S1 and 
// second index of S2, new S1 = “22”, S2 = “22”
// 
// Input : “123”, S2 = “015”
// Output : 2
// Explanation: Operation 1: Increment third index of S1 and 
// first index of S2, new S1 = “124”, S2 = “115”
// Operation 2: Increment third index of S1 and second index of S2.
// New S1 = “125”, S2 = “125”
// 
// Input: S1 = “19”, S2 = “24”
// Output: -1
// Explanation: There is no such valid operation exists through which 
// we can make two strings equal.
// 
// Approach: To solve the problem follow the below observations:
// 
// Observations:
// We are incrementing 1 to both the characters of strings to perform valid operation. So, if initially S1 and S2 have different sums, they can never be made equal (since they must have the same sum when they are equal). Now let, Sum(S1) = Sum(S2). Lets see for a specific index  0 ? i ? N – 1(N is length of either string S1 or S2).
//  * If S1[ i ] == s2[ i ], no operation will be needed
//  * If s1[ i ] > S2[ i ], then we need to add S1[ i ] – S2[ i ] in S2 to make S1[ i ] and S2[ i ] equal.
//  * If S1[ i ] < S2[ i ], then we need to add S2[ i ] – S1[ i ] in S1 to make S1[ i ] and S2[ i ] equal.
// Let x is summation of S1[ i ] – S2[ i ] for all indices where S1[ i ] > S2[ i ]. As noted above, x is the minimum number of operations we need to perform on indices of S2.
// 
// Let y is summation of S2[ i ] – S1[ i ] for all indices where S1[ i ] < S2[ i ]. As noted above, y is the minimum number of operations we need to perform on indices of S1.
// 
// We will find the total summation of operations needed on both the strings i.e (x+y) and we will divide it by 2 because in every single operation we need to increase any character from both the strings.

// C++ code for the above approach:

int solution(string S1, string S2)
{
    // To store sum of all digits
    // in S1 and S2
    int sum1 = 0, sum2 = 0;

    // Traversing on string and
    // finding sum of both strings
    for (int i = 0; i < S1.size(); i++) {
        sum1 += (S1[i] - '0');
        sum2 += (S2[i] - '0');
    }
 
    // If sum1 != sum2 they can
    // never be equal, then return -1
    if (sum1 != sum2)
        return -1;

    // To find count of valid operations
    int count = 0;
    for (int i = 0; i < S1.size(); i++) {
        if (S1[i] > S2[i]) {

            // Operations on S2 to make
            // S1 and S2 equal
            count += (S1[i] - S2[i]);
        }
        else {
            // Operations on S1 to make
            // S1 and S2 equal
            count += (S2[i] - S1[i]);
        }
    }

    return count / 2;
}

int main()
{
    string S1 = "123";
    string S2 = "015";

    // Function call
    cout << solution(S1, S2);

    return 0;
}

