#include<iostream>
#include<map>
#include<stack>
#include<list>
using namespace std;

class Graph{
public:
    map<int, bool> visited;  
    map<int, list<int>> adj;

    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    void dfs(int v) {
        stack<int> st;
        st.push(v);
        visited[v] = true; 
        while (!st.empty()) {
            int s = st.top();
            st.pop();
            cout << s << " ";
            for(auto i = adj[s].begin(); i != adj[s].end(); ++i) {
                if(!visited[*i]) {
                    st.push(*i);
                    visited[*i] = true;
                }
            }
        }
    }
};

int main() {
    Graph g;
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter edges:\n";
    int s, w;
    for(int i = 0; i < n; i++) {
        cin >> s >> w;
        g.addEdge(s, w);
    }
    int v;
    cout << "Enter starting vertex: ";
    cin >> v;
    g.dfs(v);
    return 0;
}