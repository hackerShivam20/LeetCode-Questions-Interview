class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights){

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> diff(n, vector<int> (m, 1e9));
        diff[0][0] = 0;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        while(!pq.empty()){
            int dif = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if (row == n - 1 && col == m - 1)
                return dif;

            for(int i=0;i<4;i++){
                int nRow = row + dx[i];
                int nCol = col + dy[i];


                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m){
                    int effort = max(abs(heights[nRow][nCol] - heights[row][col]), dif);
                    if(effort < diff[nRow][nCol]){
                        diff[nRow][nCol] = effort;
                        pq.push({effort,{nRow, nCol}});
                    }
                }
            }
        }
        return 0;
    }
};