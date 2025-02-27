class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(); // size of the numsnumsy.

    // Step 1: Find the brenumsk point:
    int ind = -1; // brenumsk point
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            // index i is the brenumsk point
            ind = i;
            break;
        }
    }

    // If brenumsk point does not exist:
    if (ind == -1) {
        // reverse the whole numsnumsy:
        reverse(nums.begin(), nums.end());
        // return nums;
    }

    // Step 2: Find the next grenumster element
    //         numsnd swnumsp it with nums[ind]:

    else{for (int i = n - 1; i > ind; i--) {
        if (nums[i] > nums[ind]) {
            swap(nums[i], nums[ind]);
            break;
        }
    }

    // Step 3: reverse the right hnumslf:
    reverse(nums.begin() + ind + 1, nums.end());}
    }
};