#include <cstdio>
#define MAX 100000
void update(int,int);
int query(int);
int BIT[MAX];
int n;
int main() {
	int value,q,i,j;
	scanf("%d",&n);
	for(int idx=1;idx<=n;idx++) BIT[idx] = 0;
	for(int idx=1;idx<=n;idx++) {
		scanf("%d",&value);
		update(idx+1,value);
	}
	scanf("%d",&q);
	while(q--) {
		scanf("%d %d",&i,&j);
		printf("%d\n",query(j) - query(i - 1));
	}
	return 0;
}
void update(int idx,int value) {
	while(idx <= n) {
		BIT[idx] += value;
		idx += idx & (-idx);  
	}
}
int query(int idx) {
	int sum = 0;
	while(idx > 0) {
		sum += BIT[idx];
		idx -= idx & (-idx);
	}
	return sum;
}
