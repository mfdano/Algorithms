#include <cstdio>
#include <vector>
#include <queue>
#define INF (1<<30)
using namespace std;
int main() {
    int v,e,a,b,init;
    queue<int> q;
    scanf("%d %d %d",&v, &e, &init);
    vector<int> graph[v+1];
    int distance[v+1];
    while(e--) {
        scanf("%d %d",&a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=0;i<=v;i++) distance[i] = INF;
    q.push(init);
    distance[init] = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i=0;i<graph[u].size();i++) {
            int v = graph[u][i];
            if(distance[u] + 1 < distance[v]) {
                q.push(v);
                distance[v] = distance[u] + 1;
            }
        }
    }
    for(int i=1;i<=v;i++) printf("%d\n",distance[i]);
    return 0;
}
