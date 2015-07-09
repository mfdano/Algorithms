#include <iostream>
#include <algorithm>
#define MAX 100000
using namespace std;
int array[MAX];
int main() {
	int n,maxfinal,current_max;
	cin >> n;
	for(int i=0;i<n;i++) cin >> array[i];
	maxfinal = current_max = array[0];
	for(int i=1;i<n;i++) {
		current_max = max(current_max+array[i],array[i]);
		maxfinal = max(current_max,maxfinal);
	}
	cout << maxfinal << "\n";
}
