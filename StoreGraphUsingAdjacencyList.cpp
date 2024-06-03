#include<iostream>
#include<map>
#include<iterator>
#include<vector>
using namespace std;
int main(){
    int n;
    cout<<"Enter Number of Vertices"<<" ";
    cin>>n;
    map<int,vector<int>>m;
    int u,v,ch;
    while(1){
        cout<<"Enter nodes which has an edge"<<" ";
        cin>>u;
        cin>>v;
        m[u].push_back(v);
        cout<<"To add more edges";
        cin>>ch;
        if(ch!=1){
            break;
        }
    }
    for(auto it=m.begin();it!=m.end();it++){
        int x=it->first;
        for(auto it1=it->second.begin();it1!=it->second.end();it1++){
            cout<<"There is an edge between "<<x<<"and"<<*it1<<endl;
        }
    }
    return 0;
}