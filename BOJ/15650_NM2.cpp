#include <iostream>
#define MAX 8  
using namespace std;

int n, r; 
int arr[MAX]; // 0으로 초기화 
bool selected[MAX]; // false로 초기화 

void printArray(){
	for(int i = 0; i < n; i++){
		if(selected[i]){
			cout << arr[i] << " ";
		}
	}
	cout << "\n";
}

void dfs(int idx, int cnt){
	if(cnt == r){
		printArray();
		return;
	}

	// idx 이전의 원소는 이미 선택했으므로 그 이후의 원소들 중에서만 뽑는다. 
	for(int i = idx; i < n; i++){
		if(!selected[i]){
			selected[i] = true; 
			dfs(i, cnt + 1); 
			selected[i] = false; 
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> n >> r;
	
	for(int i = 0; i < n; i++){
		arr[i] = i + 1;
	}

	dfs(0, 0);
	
	return 0;
}