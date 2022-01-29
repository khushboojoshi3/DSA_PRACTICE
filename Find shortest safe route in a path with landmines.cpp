// Find shortest safe route in a path with landmines
// https://www.geeksforgeeks.org/find-shortest-safe-route-in-a-path-with-landmines/
#include <bits/stdc++.h>
using namespace std;
 
#define R 12
#define C 10

// int dir[4][2]={{-1,0},{0,-1},{0,1},{1,0}};
int rowNum[] = { -1, 0, 0, 1 };
int colNum[] = { 0, -1, 1, 0 };
void findShortestPath(int mat[R][C]){
    // int i,j;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(mat[i][j]==0){
                for(int d=0;d<4;d++){
                    int ni=i+rowNum[d];
                    int nj=j+colNum[d];
                    if(ni>=0 && nj>=0 && ni<R && nj<C){
                        mat[ni][nj]=-1;
                    }
                }
            }
        }
    }

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(mat[i][j]==-1){
                mat[i][j]=0;
            }
        }
    }

    queue<pair<int,int>> q;
    int dist[R][C];
    memset(dist,-1,sizeof(dist));
    for(int i=0;i<R;i++){
        if(mat[i][0]==1){
            q.push({i,0});
            dist[i][0]=0;
        } 
    }

    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        int d=dist[x][y];
        for(int k=0;k<4;k++){
            int nx=x+rowNum[k];
            int ny=y+colNum[k];
            if(nx>=0 && ny>=0 && nx<R && ny<C && dist[nx][ny]==-1 && mat[nx][ny]==1){
                q.push({nx,ny});
                dist[nx][ny]=d+1;
            }
        }
    }


    // for(int i=0;i<R;i++){
    //     for(int j=0;j<C;j++){
    //         cout<<dist[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

    int ans=INT_MAX;
    for(int i=0;i<R;i++){
        if(mat[i][C-1]==1 && dist[i][C-1]!=-1){
            ans=min(ans,dist[i][C-1]);
        }
    }

    if(ans==INT_MAX){
        cout<<"NOT POSSIBLE\n";
    }
    else{
        cout<<"Length of shortest safe route is "<<ans<<"\n";
    }
}
int main(){
     
    // input matrix with landmines shown with number 0
    int mat[R][C] =
    {
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 1, 0, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 }
    };
     
    // find shortest path
    findShortestPath(mat);
    return 0;
}
