#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

const int MAX = 10;
int freq[MAX]; 

int main(void) {
	ios::sync_with_stdio(0);
    cin.tie(0);

	string s; 
	cin >> s; 

	int ans = -1; 
	for(auto ch: s){
		int num = ch - '0';
		freq[num]++;

		// 문자의 최대 빈도수 -> 필요한 세트 개수
		if(num != 6 && num != 9){
			ans = max(ans, freq[num]);
		}
	}

	// 6과 9는 교차되기 때문에 필요한 세트 개수는 
	// 두 숫자의 빈도수 합을 2로 나누고 반올림 한 값이다. 
	// ex) 666666 -> 696969 (3), 66666 -> 69696 (3) 
	ans = max(ans, (freq[6] + freq[9] + 1) / 2); 

	cout << ans; 
	
	return 0;
}