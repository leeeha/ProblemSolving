#include <iostream>
#define MAX 9 
using namespace std; 

int n, m; 
int arr[MAX]; 
bool selected[MAX];

// 선택된 m개를 출력한다. 
void printArray(){ 
	for(int i = 0; i < m; i++){ 
		cout << arr[i] << " "; 
	}
	cout << "\n"; 
}

void dfs(int num, int cnt){ // 숫자 번호, 뽑은 개수 
	if(cnt == m){
		printArray(); 
		return; 
	}

	for(int i = num; i <= n; i++){ // num부터 시작 
		if(!selected[i]){ 
			selected[i] = true; 
			arr[cnt] = i; // 선택된 값을 저장한다. 
			dfs(i, cnt + 1); 
			selected[i] = false; 
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m; 
	
	dfs(1, 0); 
	
    return 0;
}