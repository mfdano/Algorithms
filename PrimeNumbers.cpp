#include <cstdio>
void primeFactors(int);
bool isPrime(int);
bool isPrime2(int);
int main() {
	int n;
	scanf("%d",&n);
	if(isPrime(n)) printf("1\n");
        else printf("0\n");
	return 0;
}
void primeFactors(int n) {
    	while (n%2 == 0) {
 		printf("%d ", 2);
        	n = n/2;
    	}
    	for (int i=3;i<=sqrt(n);i+=2) {
        	while (n%i == 0) {
            		printf("%d ", i);
            		n = n/i;
        	}
    	}
    	if (n > 2) printf ("%d ", n);
}
bool isPrime(int n) {
	if(n < 2) return false;
	for(int i=2;i*i<=n;i++) {
		if(n%i == 0) return false;
	}
	return true;
}
bool isPrime(int n) {
    for(int i=2;i<=(sqrt(n));i++){
        if(n%i == 0) return true;
    }
    return false;
}
