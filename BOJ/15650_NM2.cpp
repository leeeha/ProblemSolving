#include <iostream>
#define MAX 8  
using namespace std;

int n, r; 
int arr[MAX]; // 0���� �ʱ�ȭ 
bool selected[MAX]; // false�� �ʱ�ȭ 

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

	// idx ������ ���Ҵ� �̹� ���������Ƿ� �� ������ ���ҵ� �߿����� �̴´�. 
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