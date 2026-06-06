class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int i=0,j=n-1;
        int mini = INT_MAX;

        while(i <= j){
            int mid = (i+j)/2;

            if(nums[mid] >= nums[i]){
                mini = min(mini, nums[i]);
                i = mid+1;
            }
            else{
                mini = min(mini, nums[mid]);
                j = mid-1;
            }
        }
                cout<<mini<<endl;
        if(mini == INT_MAX) return -1;
        else return mini;
    }
};