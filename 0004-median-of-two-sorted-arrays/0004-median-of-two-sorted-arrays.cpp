class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
    int n = nums2.size();

    // Ensure that nums1 is the shorter array
    if (m > n) {
        swap(nums1, nums2);
        swap(m, n);
    }

    int low = 0, high = m;
    int i, j;
    while (low <= high) {
        i = low + (high - low) / 2;
        j = (m + n + 1) / 2 - i;

        if (j > 0 && i < m && nums2[j - 1] > nums1[i]) {
            low = i + 1;
        }
        else if (i > 0 && j < n && nums1[i - 1] > nums2[j]) {
            high = i - 1;
        }
        else {
            // i is perfect
            int max_of_left;
            if (i == 0) {
                max_of_left = nums2[j - 1];
            }
            else if (j == 0) {
                max_of_left = nums1[i - 1];
            }
            else {
                max_of_left = max(nums1[i - 1], nums2[j - 1]);
            }

            if ((m + n) % 2 == 1) {
                return max_of_left;
            }

            int min_of_right;
            if (i == m) {
                min_of_right = nums2[j];
            }
            else if (j == n) {
                min_of_right = nums1[i];
            }
            else {
                min_of_right = min(nums1[i], nums2[j]);
            }

            return (max_of_left + min_of_right) / 2.0;
        }
    }

    return 0;   
    }
};