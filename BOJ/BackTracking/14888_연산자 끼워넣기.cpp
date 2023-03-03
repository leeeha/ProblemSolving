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

	// �ǿ����� 
	for(int i = 0; i < n; i++){
		int x; 
		cin >> x; 
		nums.push_back(x); 
	}

	// ������ ���� 
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
	// n���� �ǿ����ڿ� ���� �Ѱ��� ���� ����� ������ 
	// �ּ�, �ִ� �� ������Ʈ 
	if(idx == n){ 
		updateMaxMin(result); 
		return; 
	} 

	for(int i = 0; i < 4; i++){ 
		if(oper[i] <= 0) continue; 

		oper[i]--; // ���� ��ȭ (������ ���)
		
		switch(i){ // ��� ȣ�� 
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

		oper[i]++; // ���� ���� (�ٸ� ������ ���)  
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	input(); 

	// ��������� ���� ���, �������� ������ ������ �ε��� 
	dfs(nums[0], 1); 

	cout << maxVal << "\n" << minVal; 
	
    return 0;
}