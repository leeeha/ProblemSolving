#include <iostream>
#include <vector>
#include <algorithm>
#include <utility> 
#include <cstring> 
#include <queue> 
#define MAX 9 
using namespace std; 

int n, m; 
int arr[MAX]; 

// 선택된 m개를 출력한다. 
void printArray(){ 
	for(int i = 0; i < m; i++){ 
		cout << arr[i] << " "; 
	}
	cout << "\n"; 
}

void dfs(int cnt){ // 뽑은 개수 
	if(cnt == m){
		printArray(); 
		return; 
	}

	for(int i = 1; i <= n; i++){ 
		arr[cnt] = i; // 선택된 값을 저장한다. 
		dfs(cnt + 1); 
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m; 
	
	dfs(0); 
	
    return 0;
}