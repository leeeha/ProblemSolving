#include <iostream>
#include <vector> 
#define MAX 8 
using namespace std; 

int n, r; 
int arr[MAX]; // 0으로 초기화 
bool selected[MAX]; // false로 초기화 
vector<int> v; 

void printArray(){
	for(int i = 0; i < v.size(); i++){
		cout << v[i] << " "; 
	}
	cout << "\n";
}

void dfs(int cnt){
	if(cnt == r){
		printArray();
		return;
	}

	for(int i = 0; i < n; i++){
		if(!selected[i]){
			selected[i] = true; 
			v.push_back(arr[i]);
			
			dfs(cnt + 1); 
			
			v.pop_back(); 
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
	
	dfs(0);
	
	return 0;
}
