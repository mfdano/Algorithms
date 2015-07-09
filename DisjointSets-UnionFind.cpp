#include <cstdio>
void init(int);
int find(int);
bool joined(int, int);
void join(int, int);
int root[100005];
int members[100005];
int main() {
	return 0;
}
void init(int n) {
	for(int i=0;i<n;i++) {
		root[i] = i;
        	members[i] = 0;
    	}
}
int find(int a) {
    	if(a != root[a]) return root[a] = find(root[a]);
    	return a;
}
bool joined(int a, int b) {
    	return find(a) == find(b);
}
void join(int a, int b) {
	if(joined(a,b)) return;
    	root[find(a)] = find(b);
    	members[b] += members[a];
}
