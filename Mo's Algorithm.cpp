#include <iostream>
#include <algorithm>
#define N 30005
#define Q 200005
#define NUM 1000005
#define R 550 // Sqrt(N)
using namespace std;
struct node {
    int a, b, index;
} query[Q];
bool operator < (node first, node second) {
    return (first.a/R != second.a/R) ? first.a/R < second.a/R : first.b < second.b;
}
int numbers[N];
int different[Q];
int repeated[NUM];
int answer;
void add(int);
void remove(int);
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n,q,l,r;
    cin >> n;
    for(int i=0;i<n;i++) cin >> numbers[i];
    cin >> q;
    for(int i=0;i<q;i++) {
        cin >> query[i].a >> query[i].b;
        query[i].a--;
        query[i].b--;
        query[i].index = i;
    }
    sort(query,query+q);
    l = r = answer = 0;
    for(int i=0;i<q;i++)  {
        while(l < query[i].a) remove(l), l++; 
        while(l > query[i].a) add(l-1), l--; 
        while(r <= query[i].b) add(r), r++; 
        while(r > query[i].b+1) remove(r-1), r--; 
        different[query[i].index] = answer;
    }
    for(int i=0;i<q;i++)  cout << different[i] << "\n";
    return 0;
}
void add(int idx) {
    repeated[numbers[idx]]++;
    if(repeated[numbers[idx]] == 1) answer++;
}
void remove(int idx) {
    repeated[numbers[idx]]--;
    if(repeated[numbers[idx]] == 0) answer--;
}
