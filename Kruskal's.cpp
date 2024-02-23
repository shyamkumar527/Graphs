class Solution
{
	public:
	int findParent(int node,vector<int>& parent){
	    if(parent[node]==node) return node;
	    return parent[node]=findParent(parent[node],parent);
	}
    int spanningTree(int v, vector<vector<int>> adj[]){
        //Kruskal's Algorithm
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<v;i++){
            for(auto it:adj[i]) edges.push_back({it[1],{i,it[0]}});
        }
        sort(edges.begin(),edges.end());
        int val=0,px,py;
        vector<int> parent(v);
        for(int i=0;i<v;i++) parent[i]=i;
        for(int i=0;i<edges.size();i++){
            px=findParent(edges[i].second.first,parent);
            py=findParent(edges[i].second.second,parent);
            if(px!=py){
                val+=edges[i].first;
                parent[py]=px;
            }
        }
        return val;
    }
};
