#include <bitset>
#include <cstdio>
#include <vector>
using namespace std;
void sieve(long long);
bool isPrime(long long);
void primeFactors(long long);
long long EulerPhi(long long);
long long sieveSize;
bitset <10000005> bit;
vector <int> primes;
vector <int> factors;
int main() {
	sieve(1000);
	primeFactors(345);
	for(int i=0;i<factors.size();i++) printf("%d ",factors[i]);
	factors.clear();
	printf("\n%lld\n",EulerPhi(6));
	return 0;
}
void sieve(long long upperbound) {
	sieveSize = upperbound + 1;
	bit.reset(); bit.flip();
	bit.set(0,false); bit.set(1,false);
	for(long long i=2;i<=sieveSize;i++) {
		if(bit.test((size_t)i)) {
			for(long long j=i*i;j<=sieveSize;j+=i) {
				bit.set((size_t)j,false);
			}
			primes.push_back((int)i);
		}
	}
}
bool isPrime(long long n) {
	if(n < sieveSize) return bit.test(n);
	for(long long i=0;i<sieveSize;i++) if(n % primes[i] == 0) return false;
	return true;
}
void primeFactors(long long n) {
	int primefactor_idx = 0;
	int primefactor = primes[primefactor_idx];
	while((n != 1) && ((primefactor * primefactor) <= n)) {
		while(n % primefactor == 0) {
			n /= primefactor;
			factors.push_back(primefactor);
		}
		primefactor = primes[++primefactor_idx];
	}
	if(n != 1) factors.push_back(n);
}
long long EulerPhi(long long n) {
	long long phi = n;
	primeFactors(n);
	for(long long i=0;i<factors.size();i++) phi = phi - (phi/factors[i]);
	return phi;
}
