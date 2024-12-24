class Solution {
public:

    double sol(vector<int> arr, int n)
    {
    
        // If length of array is even
        if (n % 2 == 0) {
            double z = n / 2;
            double e = arr[z];
            double q = arr[z - 1];
            double ans = (e + q) / 2;
            return ans;
        }
    
        // If length if array is odd
        else {
            int z = round(n / 2);
            double ans = arr[z];
            return ans;
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> nums3;

        for(int i=0;i<m;i++){
            nums3.push_back(nums1[i]);
        }

        for(int i=0;i<n;i++){
            nums3.push_back(nums2[i]);
        }
    
        // Sort the merged array
        sort(nums3.begin(), nums3.end());
        double ans = sol(nums3, m+n);
        return ans;
    }
};