#include <bits/stdc++.h>
using namespace std;

int FindParent(int a,vector<int>& Parent){
    if(Parent[a]==a) return a;
    return Parent[a]=FindParent(Parent[a],Parent);
}

void Union(int x,int y,vector<int>& Parent,vector<int>& Rank){
    int px=FindParent(x,Parent);
    int py=FindParent(y,Parent);
    if(px==py){
        Parent[py]=px;
        Rank[px]++;
    }
    else if(py<px) Parent[py]=px;
    else Parent[px]=py;
}

int main() {
    int n;
    cin>>n;
    vector<int> Parent(n);
    vector<int> Rank(n,0);
    for(int i=0;i<n;i++) Parent[i]=i;
    int q;
    cin>>q;
    while(q--){
        int act,v1,v2;
        cin>>act>>v1>>v2;
        if(act==1) Union(v1,v2,Parent,Rank);
        else{
            if(FindParent(v1,Parent)==FindParent(v2,Parent)) cout<<"Same";
            else cout<<"Not Same";
        }
    }
}
