class Solution {
public:
    vector<int> prevSmallest(vector<int> &arr){
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            ans[i] = st.empty()?-1:st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> nextSmallest(vector<int> &arr){
        int n = arr.size();
        vector<int> ans(n, n);
        stack<int> st;

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            ans[i] = st.empty()?n:st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> prevGreatest(vector<int> &arr){
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] < arr[i]) st.pop();
            ans[i] = st.empty()?-1:st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> nextGreatest(vector<int> &arr){
        int n = arr.size();
        vector<int> ans(n, n);
        stack<int> st;

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            ans[i] = st.empty()?n:st.top();
            st.push(i);
        }
        return ans;
    }
    long long sumSubarrayMins(vector<int>& arr){
        long long ans = 0;
        long long ans1 = 0;
        int n = arr.size();
        vector<int> left = prevSmallest(arr);
        vector<int> right = nextSmallest(arr);
        vector<int> left1 = prevGreatest(arr);
        vector<int> right1 = nextGreatest(arr);

        for(int i=0;i<n;i++){
            long long l = i - left[i];
            long long r = right[i] - i;
            long long l1 = i - left1[i];
            long long r1 = right1[i] - i;

            ans += l*r*arr[i];
            ans1 += l1*r1*arr[i];
        }
        return ans1 - ans;
    }

    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMins(nums);
    }
};