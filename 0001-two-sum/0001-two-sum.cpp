class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for(int i=0;i<n;i++){
            int num = nums[i];
            int left = target - num;

            if(mp.find(left) == mp.end()){
                mp[nums[i]] = i;
            }
            else{
                return {mp[left], i};
            }
        }
        return {-1, -1};
    }
};