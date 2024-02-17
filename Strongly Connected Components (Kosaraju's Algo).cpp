void dfs(int x,int node,vector<bool>& vis,stack<int>& order,vector<vector<int>>& adj){
  vis[node]=true;
  for(auto it:adj[node]){
      if(!vis[it]) dfs(x,it,vis,order,adj);
  }
  if(x) order.push(node);
}
int kosaraju(int n, vector<vector<int>>& adj){
    int c=0;
    vector<vector<int>> revadj(n,vector<int>());
    stack<int> order;
    vector<bool> vis(n,false);
    vector<bool> fr(n,false);
    for(int i=0;i<adj.size();i++){
        for(int j=0;j<adj[i].size();j++) revadj[adj[i][j]].push_back(i);
    }
    for(int i=0;i<n;i++){
        if(!vis[i]) dfs(1,i,vis,order,adj);
    }
    while(!order.empty()){
        if(!fr[order.top()]){
            c++;
            dfs(0,order.top(),fr,order,revadj);
        }
        order.pop();
    }
    return c;
}
