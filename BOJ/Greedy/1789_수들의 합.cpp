#include <iostream> 
#include <vector> 
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);

	long long S; 
	cin >> S; 

	long long sum = 0; // ������ ���� �� Ȯ���ϱ�!!! 
	int n = 1; // ���ϴ� �� ��ü 
	int cnt = 0; // ���� ���� 
	
	while(sum < S){ 
		sum += n; 

		if(sum > S) break; 
		
		cnt++; 
		n += 1; 
	}

	cout << cnt; 
	
	return 0;
}
