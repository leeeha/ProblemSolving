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
bool selected[MAX];

// ���õ� m���� ����Ѵ�. 
void printArray(){
	for(int i = 0; i < m; i++){
		cout << arr[i] << " "; 
	}
	cout << "\n"; 
}

void dfs(int cnt){ // ���� ���� 
	if(cnt == m){
		printArray(); 
		return; 
	}

	for(int i = 1; i <= n; i++){
		if(!selected[i]){ 
			selected[i] = true; 
			arr[cnt] = i; // ���õ� ���� �����Ѵ�. 
			dfs(cnt + 1); 
			selected[i] = false; 
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m; 
	
	dfs(0); 
	
    return 0;
}