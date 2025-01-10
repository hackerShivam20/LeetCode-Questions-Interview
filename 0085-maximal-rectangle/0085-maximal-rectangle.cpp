class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        stack<int> s;

        for(int i=0;i<=n;i++){
            while(!s.empty() && (i == n || heights[s.top()] >= heights[i])){
                int height = heights[s.top()];
                s.pop();

                int width;

                if(s.empty()){
                    width = i;
                }
                else{
                    width = i - s.top() - 1;
                }
                maxArea = max(maxArea, height*width);
            }
            s.push(i);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int maxArea = 0;
        vector<vector<int>> prev(n, vector<int>(m, 0));

        for(int j=0;j<m;j++){
            int sum = 0;
            for(int i=0;i<n;i++){
                sum += matrix[i][j] - '0';
                if(matrix[i][j] == '0') sum = 0;
                prev[i][j] = sum;
            }
        }

        for(int i=0;i<n;i++){
            maxArea = max(maxArea, largestRectangleArea(prev[i]));
        }
        return maxArea;
    }
};