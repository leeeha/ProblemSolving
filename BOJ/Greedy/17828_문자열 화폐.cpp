#include <iostream> 
#include <vector> 
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);

	int n, x; 
	cin >> n >> x; 

	// 불가능한 경우 예외 처리 
	if(x < 1 * n || x > 26 * n){
		cout << "!\n"; 
		return 0; 
	}

	string str = "";

	// 우선 A로 모두 채운다. 
	for(int i = 0; i < n; i++){
		str += 'A';
	}

	// x는 A로 채우고 나서 남아있는 수 (0으로 만들어야 함.)
	x -= n;

	// x가 0이 될 때까지 반복 
	for(int i = n - 1; i >= 0 && x > 0; i--){
		int temp = min(x, 25); // A + 25 == Z 
		str[i] += temp; // x 또는 25 중에 작은 수가 더해진다. (char로 암시적 형변환)
		x -= temp; // 남아있는 수 갱신 
	}

	// 모든 문자의 가치를 더해서 x가 되는 문자열 str 출력 
	cout << str;
	
	return 0;
}
