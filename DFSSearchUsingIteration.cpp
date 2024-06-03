#include<iostream>
#include<stack>
int n;
int a[20][20],visited[20];
using namespace std;
void dfs(int v) {
    stack<int> st;
    st.push(v);
    visited[v] = 1; 
    while (!st.empty()) {
        int s = st.top();
        st.pop();
        cout << s << " ";
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0 && a[s][i] == 1) {
                visited[i] = 1; 
                st.push(i);
            }
        }
    }
}
int main(){
    cout<<"Enter the number of vertices:";
    cin>>n;
    cout<<"Enter Adjacency matrix:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    int v;
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    cout<<"Enter start vertex:";
    cin>>v;
    dfs(v);
    return 0;
}