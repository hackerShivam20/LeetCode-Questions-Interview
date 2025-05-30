class Solution {
public:

    void reverse(vector<int>&nums, int i , int j ){
        while( i < j){
            swap(nums[i++] , nums[j--] );
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size() ;
        k = k %n;
//  Reverse the whole Array 
        reverse(nums, 0 , n-1 );
//  Reverse the array from k index to n-1 index
        reverse(nums, k, n-1 );
//  Reverse the array from 0 to k-1 index 
        reverse(nums, 0, k-1);
    }
};