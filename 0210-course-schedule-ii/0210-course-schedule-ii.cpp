class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];

        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        vector<int> inDegree(numCourses, 0);
        
        for(int i=0;i<numCourses;i++){
            for(auto it:adj[i]){
                inDegree[it]++;
            }
        }
        
        queue<int> q;
        vector<int> topo;
        
        for(int i=0;i<numCourses;i++){
            if(inDegree[i] == 0) q.push(i);
        }
        
        while(!q.empty()){
            int ele = q.front();
            q.pop();
            topo.push_back(ele);
            
            for(auto it:adj[ele]){
                inDegree[it]--;
                if(inDegree[it] == 0) q.push(it);
            }
        }
        if(topo.size() == numCourses) return topo;
        return {};
    }
};