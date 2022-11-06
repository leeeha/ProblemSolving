#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;

	int origin = n;
	int cnt = 0;
	do{
		int l = n / 10, r = n % 10;
		int sum = l + r;
		cnt++;
		n = (r * 10) + (sum % 10);
	}while(n != origin);

	cout << cnt << '\n';

    return 0;
}