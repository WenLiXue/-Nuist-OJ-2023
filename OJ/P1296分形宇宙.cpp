
#include<bits/stdc++.h>
using namespace std;
int const NN=10000;
char Array[NN][NN];
int const t =2;
void dfs_search_fun(int n,int x,int y)
{
    if(n<t)
        Array[x][y]='X';
    else{
        int size=pow(3,n-2);
        dfs_search_fun(n-1,x,y);
        dfs_search_fun(n-1,x,y+2*size);
        dfs_search_fun(n-1,x+size,y+size);
        dfs_search_fun(n-1,x+2*size,y);
        dfs_search_fun(n-1,x+2*size,y+2*size);
    }
    return;
}
int main()
{
    int n;
    while(cin>>n)
    {
        int size=pow(3,n-1);
        for(int i=0;i<=size;i++)
            for(int j=0;j<=size;j++)
            {
                Array[i][j]=' ';
            }
        dfs_search_fun(n,1,1);
        for(int i=1;i<=size;i++)
        {
            for(int j=1;j<=size;j++)
            {
                cout<<Array[i][j];
            }
            cout<<endl;
        }
        cout<<"-"<<endl;
    }
 
}
