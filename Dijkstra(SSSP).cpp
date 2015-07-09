#include <cstdio>
#include <vector>
#include <queue>
#define INF (1<<30)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int main(){
    	vector<vii>graph;
    	int V,e,init,a,b,w;
    	scanf("%d %d %d",&V,&e,&init);
    	graph.assign(V+1, vii());
    	while(e--) {
        	scanf("%d %d %d",&a,&b,&w);
        	graph[a].push_back(ii(b,w));
    	}
    	vi distance(V+1, INF); distance[init]=0;
    	priority_queue<ii, vector<ii>, greater<ii> > pq;
    	pq.push(ii(0,init));
    	while(!pq.empty()){
        	ii front = pq.top(); pq.pop();
        	int d  = front.first; 
        	int u = front.second;
        	if(d == distance[u]) {
        		for(int  i=0;i<graph[u].size();i++) {
	            		ii v = graph[u][i];
	            		if(distance[u]+v.second< distance[v.first]) {
	                		distance[v.first] = distance[u]+v.second;
	                		pq.push(ii(distance[v.first],v.first));
	            		}
	       	        }
        	}
    	}
    	for (int i=1;i<=V;i++) printf("%d -> %d : %d\n",init,i,distance[i]);
    	return 0;
}
