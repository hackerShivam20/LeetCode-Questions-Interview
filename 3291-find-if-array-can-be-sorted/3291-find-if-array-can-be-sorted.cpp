class Solution {
public:
    int cntBits(int n){
        int cnt = 0;

        while(n>0){
            cnt += (n&1);
            n >>= 1;
        }
        return cnt;
    }

    bool canSortArray(vector<int>& nums) {
        vector<int> numBit;

        for(int i=0;i<nums.size();i++){
            numBit.push_back(cntBits(nums[i]));
        }

        for(int i=0;i<nums.size();i++){
            int j=i;

            while(j>0 && nums[j] < nums[j-1] && numBit[j] == numBit[j-1]){
                int temp = nums[j-1];
                nums[j-1] = nums[j];
                nums[j] = temp;
                j--;
            }
        }
        for(int i=1;i<nums.size();i++){
            if(nums[i] < nums[i-1]) return false;
        }
        return true;
    }
};