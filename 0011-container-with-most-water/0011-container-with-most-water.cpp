class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int area = 0;
        int i=0, j=n-1;
        while(i<j){
            int l = min(height[i], height[j]);
            int b = j-i;
            area = max(area, l*b);
            if(height[i] < height[j]) i++;
            else j--;
        }
        return area;
    }
};