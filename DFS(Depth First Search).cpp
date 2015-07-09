// O(V + E)
#include <cstdio>
#include <cstring>
#include <vector>
#define MAX 100000
using namespace std;
void dfs(int);
vector <int> graph[MAX];
int visited[MAX];
int components;
int main() {
    int v,e,a,b;
    components = 0;
    scanf("%d %d",&v, &e);
    while(e--) {
        scanf("%d %d",&a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1;i<=v;i++) visited[i] = 0;
    for(int i=1;i<=v;i++) {
        if(visited[i] == 0) {
            dfs(i);
            components++;
        }
    }
    for(int i=1;i<=i;i++) printf("%d ",visited[i]);
    printf("\nComponents: %d\n",components);
    return 0;
}
void dfs(int u) {
    visited[u]++;
    for(int i=0;i<graph[u].size();i++) {
        int v = graph[u][i];
        if(visited[v] == 0) dfs(v);
    }
}
