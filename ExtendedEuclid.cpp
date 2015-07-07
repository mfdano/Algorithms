#include <cstdio>
void extendedEuclid(int,int);
int x,y,d;
int main() {
	extendedEuclid(25,18);
	printf("%d %d %d\n",x,y,d);
	return 0;
}
void extendedEuclid(int a,int b) {
	if(b == 0) { x = 1 , y = 0 , d = a; return; }
	extendedEuclid(b,a%b);
	int x1 = y;
	int y1 = x - (a/b) * y;
	x = x1 , y = y1;
}
