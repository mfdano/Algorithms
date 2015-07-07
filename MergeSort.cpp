#include <cstdio>
#include <queue>
using namespace std;
void merge(int[],int,int,int);
void mergeSort(int[],int,int);
int main() {
	int array[] = {1,5,8,7,4,9,3,6,8};
	int size = sizeof(array) / sizeof(array[0]);
	mergeSort(array,0,size-1);
	for(int i=0;i<size;i++) printf("%d ",array[i]);
	printf("\n");
	return 0;
}
void mergeSort(int array[],int low, int high) {
	int middle;
	if(low < high) {
		middle = ((low + high) / 2);
		mergeSort(array,low,middle);
		mergeSort(array,middle+1,high);
		merge(array,low,middle,high);
	}
}
void merge(int array[],int low, int middle, int high) {
	queue<int> q1;
	queue<int> q2;
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
		}
	}
	while(!q1.empty()) {
		array[i++] = q1.front();
		q1.pop();
	}
	while(!q2.empty()) {
		array[i++] = q2.front();
		q2.pop();
	}
}
