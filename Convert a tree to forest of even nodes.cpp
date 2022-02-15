// Convert a tree to forest of even nodes
// https://www.geeksforgeeks.org/convert-tree-forest-even-nodes/
// Given a tree of n even nodes. 
// The task is to find the maximum number of edges to be removed from the given tree to obtain forest of trees having even number of nodes. 
// This problem is always solvable as given graph has even nodes.
#include<bits/stdc++.h>
#define N 12
using namespace std;
int dfs(vector<int> tree[N],int vis[N],int &ans,int node){
    int count=0;
    int temp;
    vis[node]=1;
    for(int i=0;i<tree[node].size();i++){
        int nbr=tree[node][i];
        if(vis[nbr]==0){
            temp=dfs(tree,vis,ans,nbr); //length of child chain 
            if(temp%2==0){
                ans++;
            }
            else{
                count=count+temp;
            }
        }
    }
    return count+1;//return length of current chain including the current node
}

int minEdge(vector<int> tree[N], int n)
{
    int visit[n+2];
    int ans = 0;
    memset(visit, 0, sizeof visit);
 
    dfs(tree, visit, ans, 1);
 
    return ans;
}
int main()
{
    int n = 10;
 
    vector<int> tree[n+2];
    tree[1].push_back(3);
    tree[3].push_back(1);
 
    tree[1].push_back(6);
    tree[6].push_back(1);
 
    tree[1].push_back(2);
    tree[2].push_back(1);
 
    tree[3].push_back(4);
    tree[4].push_back(3);
 
    tree[6].push_back(8);
    tree[8].push_back(6);
 
    tree[2].push_back(7);
    tree[7].push_back(2);
 
    tree[2].push_back(5);
    tree[5].push_back(2);
 
    tree[4].push_back(9);
    tree[9].push_back(4);
 
    tree[4].push_back(10);
    tree[10].push_back(4);
 
    cout << minEdge(tree, n) << endl;
    return 0;
}
