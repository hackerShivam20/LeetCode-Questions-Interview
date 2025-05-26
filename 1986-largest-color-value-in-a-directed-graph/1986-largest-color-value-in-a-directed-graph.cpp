class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
            int n = colors.size();
    vector<vector<int>> graph(n);
    vector<int> indegree(n, 0);

    // Build graph and indegree
    for (auto& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        indegree[edge[1]]++;
    }

    // 26 colors, one row for each node
    vector<vector<int>> colorCount(n, vector<int>(26, 0));
    queue<int> q;

    // Start with nodes having 0 indegree
    for (int i = 0; i < n; ++i) {
        if (indegree[i] == 0) q.push(i);
        colorCount[i][colors[i] - 'a'] = 1;
    }

    int processed = 0, maxColorValue = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        processed++;

        for (int v : graph[u]) {
            for (int c = 0; c < 26; ++c) {
                int add = (colors[v] - 'a' == c) ? 1 : 0;
                colorCount[v][c] = max(colorCount[v][c], colorCount[u][c] + add);
            }
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }

        maxColorValue = max(maxColorValue, *max_element(colorCount[u].begin(), colorCount[u].end()));
    }

    return processed == n ? maxColorValue : -1;
    }
};