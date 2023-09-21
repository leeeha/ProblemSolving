#include <iostream> 
#include <vector> 
#include <string>
#include <algorithm> 
#include <queue> 
using namespace std;

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);

	int n;
	cin >> n; // 최대 1500 

	priority_queue<int, vector<int>, greater<int>> pq; // 최소 힙 
	
	for(int i = 0; i < n * n; i++){
		int e; 
		cin >> e; 
		pq.push(e); 
		if(pq.size() > n) pq.pop(); // 작은 수부터 pop 되도록 
	}

	// 남아있는 원소: 35 41 48 49 52 
	// while(!pq.empty()){
	// 	cout << pq.top() << " ";
	// 	pq.pop(); 
	// }

	// N번째로 큰 수 출력 
	cout << pq.top() << endl; 
	
	return 0;
}