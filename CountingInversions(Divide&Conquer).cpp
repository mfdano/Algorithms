O (n Log n)
#include <cstdio>
#include <queue>
using namespace std;
int count(int[],int,int);
int countSplitInversions(int[],int,int,int);
int main() {
	int array[] = {1,3,5,2,4,6};
	int size = sizeof(array) / sizeof(array[0]);
	printf("%d\n",count(array,0,size-1));
	return 0;
}
int count(int array[],int low, int high) {
	int middle, x = 0, y = 0, z = 0;
	if(high == 0) return 0;
	else {
		if(low < high) {
			middle = ((low + high) / 2);
			x = count(array,low,middle);
			y = count(array,middle+1,high);
			z = countSplitInversions(array,low,middle,high);
		}
	}
	return x + y + z;
}
int countSplitInversions(int array[],int low, int middle, int high) {
	queue<int> q1;
	queue<int> q2;
	int contInversions = 0;
	for(int i=low;i<=middle;i++)  q1.push(array[i]);
	for(int i=middle+1;i<=high;i++) q2.push(array[i]);
	int i = low;
	while(!(q1.empty() || q2.empty())) {
		if(q1.front() <= q2.front()) {
			array[i++] = q1.front();
			q1.pop();
		} else {
			array[i++] = q2.front();
			q2.pop();
			contInversions += q1.size();
		}
	}
	while(!q1.empty()) {
		array[i++] = q1.front();
		q1.pop();
	}
	while(!q2.empty()) {
		array[i++] = q2.front();
		q2.pop();
		contInversions += q1.size();
	}
	return contInversions;
}
