#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter Number of Vertices"<<" ";
    cin>>n;
    int a[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            a[i][j] = 0;
        }
    }    int u,v,ch;
    while(1){
        cout<<"Enter nodes which has an edge"<<" ";
        cin>>u;
        cin>>v;
        a[u][v]=1;
        cout<<"To add more edges";
        cin>>ch;
        if(ch!=1){
            break;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==1){
                cout<<"There is an edge between"<<i<<"and"<<j<<endl;
            }

        }
    }
    return 0;
}