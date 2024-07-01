class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        const int M = min(static_cast<int>(nums1.size()), m);
        const int N = min(static_cast<int>(nums2.size()), n);

        std::vector<int> merged;
        merged.reserve(M + N);

        int i = 0, j = 0;
        while (i < M && j < N) {
            if (nums1[i] < nums2[j]) {
                merged.push_back(nums1[i++]);
            } else {
                merged.push_back(nums2[j++]);
            }
        }
        while (i < M) {
            merged.push_back(nums1[i++]);
        }
        while (j < N) {
            merged.push_back(nums2[j++]);
        }

        nums1 = merged;
    }
};
