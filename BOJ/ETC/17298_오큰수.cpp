#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

stack<int> s;
int ans[100'0001];
int arr[100'0001];

int main(){
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	// 오른쪽에서 왼쪽으로 이동 
	for (int i = n - 1; i >= 0; i--){
		while (!s.empty() && (s.top() <= arr[i])){
			s.pop();
		}

		if(s.empty()){
			ans[i] = -1; 
		}else{
			// s.top() > arr[i] 
			ans[i] = s.top(); // top 원소의 값을 저장 
		}

		// 스택의 bottom->top (내림차순)
		s.push(arr[i]); 
	}
	
	for (int i = 0; i < n; i++)
		cout << ans[i] << " ";
}