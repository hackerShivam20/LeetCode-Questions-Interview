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
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        vector<int> left = prevSmallest(heights);
        vector<int> right = nextSmallest(heights);

        for(int i=0;i<n;i++){
            int area = (right[i] - left[i] - 1) * heights[i];
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};