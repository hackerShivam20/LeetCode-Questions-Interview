class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph){

        int m = graph.size();
        vector<vector<int>> adj(m);
        vector<int> indegree(m, 0);
        queue<int> q;
	    vector<int> topo;

        for(int i=0;i<m;i++){
            for(auto it:graph[i]){
                adj[it].push_back(i);
                indegree[i]++;
            }
        }

        for(int i=0;i<m;i++){
	        if(indegree[i] == 0){
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        topo.push_back(node);
	        
	        for(auto it:adj[node]){
	            indegree[it]--;
	            
	            if(indegree[it] == 0) q.push(it);
	        }
	    }
        sort(topo.begin(), topo.end());
        return topo;
    }
};