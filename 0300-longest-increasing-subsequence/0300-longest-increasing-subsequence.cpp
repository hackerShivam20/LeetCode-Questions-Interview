class Solution {
public:
    int lengthOfLIS(vector<int>& nums){
        vector<int> temp;
        temp.push_back(nums[0]);

        int len = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > temp.back()) {
                // If arr[i] is greater than the last element of temp, extend the subsequence
                temp.push_back(nums[i]);
                len++;
            } else {
                // If arr[i] is not greater, replace the element in temp with arr[i]
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }

        return len;
    }
};




// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums){
//         int n = nums.size();
//         vector<int> dp(n,1);
//        for(int i=0; i<=n-1; i++){
//             for(int prev_index = 0; prev_index <=i-1; prev_index ++){
                
//                 if(nums[prev_index]<nums[i]){
//                     dp[i] = max(dp[i], 1 + dp[prev_index]);
//                 }
//             }
//         }

//         int ans = 0;
//         int index = -1;

//         for(int i=0;i<dp.size();i++){
//             ans = max(ans, dp[i]);
//         }

//         return ans;
//     }
// };





// class Solution {
// public:
//     // int f(vector<int>& nums, int index, int prev, vector<vector<int>> &dp){
//     //     if(index == nums.size()) return 0;
//     //     if(dp[index][prev+1] != -1) return dp[index][prev+1];

//     //     int notTake = 0 + f(nums,index+1,prev, dp);
//     //     int take = 0;
//     //     if(prev == -1 || nums[index] > nums[prev]){
//     //         take = 1 + f(nums, index+1, index, dp);
//     //     }

//     //     return dp[index][prev+1] = max(take, notTake);
//     // }

//     int lengthOfLIS(vector<int>& nums){
//         // vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1, 0));
//         vector<int> next(nums.size()+1, 0);
//         int n = nums.size();


//         for(int index = n-1;index>=0;index--){
//             vector<int> curr(nums.size()+1, 0);
//             for(int prev = index-1;prev>=-1;prev--){
//                 int notTake = 0 + next[prev+1];
//                 int take = 0;
//                 if(prev == -1 || nums[index] > nums[prev]){
//                     take = 1 + next[index+1];
//                 }

//                 // dp[index][prev+1] = 
//                  curr[prev+1] = max(take, notTake);
//             }
//             next = curr;
//         }
//         return next[0];
//     }
// };