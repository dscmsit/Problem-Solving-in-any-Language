/* 
Those edges on whose removal the graph is broken into two or more components are bridges
Using two arrays to find bridges
Intime -> time of insertion of a node, stores the time at which we enter a node
Lowtime -> lowest time of insertion around all its adjacent nodes, stores the intime of lowest ancestor directly reachable by that node
*/

#include <bits/stdc++.h>
using namespace std;
int timer=1;
// intime can directly be used as vis array
void DFS(int node,int par,vector<vector<int>>&adjL,vector<int>&vis,vector<int>&low,vector<int>&intime){
    vis[node]=1;
    low[node]=intime[node]=timer;
    timer++;
    for(int ajn:adjL[node]){
        if(ajn==par) continue;  // case 1
        if(vis[ajn]==1){  // already vis ajn // case 2
            // edge node to ajn is a back edge (in pic 1 N-B edge)
            low[node]=min(low[node],intime[ajn]);
        }
        else{  // edge node to ajn is forward edge // not vis ajn yet // case 3
            // in pic 1 root - B edge
           DFS(ajn,node,adjL,vis,low,intime);
           if(low[ajn]>intime[node]){
               // bridge between node and ajn 
               cout<<node<<"-"<<ajn<<endl;
           }
           low[node]=min(low[node],low[ajn]); 
           // so that node can minimize its low time
        }
    }
}

int main(){
    int n,e;
    cin>>n>>e;
    vector<vector<int>>adjL(n+1); // 1 to n nodes 
    for(int i=1;i<=e;i++){
       int u,v;
       cin>>u>>v;
       adjL[u].push_back(v);
       adjL[v].push_back(u);
    }
    vector<int>vis(n+1,0);
    vector<int>low(n+1,INT_MAX);
    vector<int>intime(n+1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i]{
            DFS(i,-1,adjL,vis,low,intime);
        }
    }
}
