// https://chanhuiseok.github.io/posts/baek-31/
// ���� Ÿ���� ll���� �����ؾ� �ð��ʰ��� ���� �ʴ´�. 

#include <iostream>
using namespace std; 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long S;
	cin >> S;

	long long sum = 0, num = 1; 
	int cnt = 0; 

	while(true) {
		sum += num; 
		cnt++;
		if(sum > S){
			cnt--;
			break;
		}
		num++;
	}

	cout << cnt; 
	
	return 0; 
}