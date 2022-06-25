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

	// �����ʿ��� �������� �̵� 
	for (int i = n - 1; i >= 0; i--){
		while (!s.empty() && (s.top() <= arr[i])){
			s.pop();
		}

		if(s.empty()){
			ans[i] = -1; 
		}else{
			// s.top() > arr[i] 
			ans[i] = s.top(); // top ������ ���� ���� 
		}

		// ������ bottom->top (��������)
		s.push(arr[i]); 
	}
	
	for (int i = 0; i < n; i++)
		cout << ans[i] << " ";
}