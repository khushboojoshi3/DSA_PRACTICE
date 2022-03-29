// https://www.youtube.com/watch?v=CrxG4WJotgg&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=17
// See by normal bfs also we can update distances and get the shortest path ,
// but we might have to visit some vertex again from some other vertexes path to get a shorter distance through it ,
// but this degrades complexity , so topological sort gives us a order to visit vertexes so that the vertex you're currently visiting ,
// you can be sure the vertexes before it would have shortest path on them and you Haven't to visit them again ,
// as we see topological order moves that way , least directed edged vertex to most directed edge vertex(sorry for this layman explanation) , 
// so we now visit every vertex only once , hence we have complexity of visiting every node i.e. V+E .
#include<bits/stdc++.h>
using namespace std;
void findTopoSort(int node,int vis[],stack<int> &st,vector<pair<int,int>> adj[]){
    vis[node]=1;
    for(auto it: adj[node]){
        if(vis[it.first]==false) findTopoSort(it.first,vis,st,adj);
    }
    st.push(node);
}

void shortestPath(int src,int N,vector<pair<int,int>> adj[]){
    int vis[N]={0};
    stack<int> st;
    for(int i=0;i<N;i++){
        if(vis[i]==false){
            findTopoSort(i,vis,st,adj);
        }
    }
    int dist[N];
    for(int i=0;i<N;i++){
        dist[i]=INT_MAX;
    }
    dist[src]=0;
    while(!st.empty()){
        int node=st.top();
        st.pop();
        //if the node has been found previously 
        if(dist[src]!=INT_MAX){
            for(auto nbr:adj[node]){
                if(dist[node] + nbr.second<dist[nbr.first]){
                    dist[nbr.first]=dist[node]+nbr.second;
                }
            }
        }
    }
    for(int i=0;i<N;i++){
        if(dist[i]==INT_MAX){
            cout<<"INFINTIY ";
        }
        else{
            cout<<dist[i]<<" ";
        }
    }
}
int main() {
    int n=6;
    vector<pair<int,int>> adj[n];
    adj[0].push_back({1,2});
    adj[0].push_back({4,1});
    adj[1].push_back({2,3});
    adj[2].push_back({3,6});
    adj[4].push_back({2,2});
    adj[4].push_back({5,4});
    adj[5].push_back({3,1});
    shortestPath(0,n,adj);
    return 0;
}
