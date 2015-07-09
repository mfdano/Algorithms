// O(Log n)
#include <cstdio>
typedef long long ll;
ll power(ll,ll);
int main() {
	printf("%lld\n",power(2,50));
    	return 0;
}
ll power(ll n, ll k) {
	if(k == 1) return n;
	if(k%2 == 0) return power(n,k/2) * power(n,k/2);
	return n * power(n,k-1);
}
