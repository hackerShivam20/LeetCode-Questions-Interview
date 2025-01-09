class Solution {
public:
int mod = 1000000007;
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
    int sumSubarrayMins(vector<int>& arr){
        int ans = 0;
        int n = arr.size();
        vector<int> left = prevSmallest(arr);
        vector<int> right = nextSmallest(arr);

        for(int i=0;i<n;i++){
            int l = i - left[i];
            int r = right[i] - i;

            ans = (ans + (l*r*1LL*arr[i])%mod)%mod;
        }
        return ans;
    }
};