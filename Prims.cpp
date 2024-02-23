class Solution
{
	public:
    int spanningTree(int v, vector<vector<int>> adj[]){
        //Prims Algorithm
        int c=0,node,w;
        vector<bool> vis(v,false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            node=pq.top().second;
            w=pq.top().first;
            pq.pop();
            if(!vis[node]){
                vis[node]=true;
                c+=w;
                for(auto it:adj[node]){
                    pq.push({it[1],it[0]});
                }
            }
        }
        return c;
    }
};
