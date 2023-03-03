#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring> 
#include <queue> 
using namespace std; 

int n; 
vector<int> nums; 
vector<int> oper; 
int minVal = 1e9, maxVal = -1e9; 

void input(){
	cin >> n; 

	// 피연산자 
	for(int i = 0; i < n; i++){
		int x; 
		cin >> x; 
		nums.push_back(x); 
	}

	// 연산자 개수 
	for(int i = 0; i < 4; i++){
		int x; 
		cin >> x; 
		oper.push_back(x); 
	}
}

void updateMaxMin(int result){ 
	if(result > maxVal){
		maxVal = result; 
	}
	if(result < minVal){
		minVal = result; 
	}
}

void dfs(int result, int idx){ 
	// n개의 피연산자에 대한 한가지 연산 결과가 나오면 
	// 최소, 최대 값 업데이트 
	if(idx == n){ 
		updateMaxMin(result); 
		return; 
	} 

	for(int i = 0; i < 4; i++){ 
		if(oper[i] <= 0) continue; 

		oper[i]--; // 상태 변화 (연산자 사용)
		
		switch(i){ // 재귀 호출 
			case 0: 
				dfs(result + nums[idx], idx + 1); 
				break; 
			case 1: 
				dfs(result - nums[idx], idx + 1); 
				break; 
			case 2: 
				dfs(result * nums[idx], idx + 1); 
				break;
			case 3: 
				dfs(result / nums[idx], idx + 1); 
				break; 
		}

		oper[i]++; // 상태 복구 (다른 연산자 사용)  
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	input(); 

	// 현재까지의 연산 결과, 다음으로 연산할 숫자의 인덱스 
	dfs(nums[0], 1); 

	cout << maxVal << "\n" << minVal; 
	
    return 0;
}