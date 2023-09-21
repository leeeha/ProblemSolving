#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int arr[26]; 

bool possible(string a, string b) { 
	if(a.size() != b.size()) return false;

	for(int i = 0; i < a.size(); i++){
		arr[a[i] - 'a']++; 
		arr[b[i] - 'a']--; 
	}

	// 두 문자열에서 각 문자의 빈도 수가 일치하지 않는 경우 
	// 일치한다면 arr 배열에는 0이 저장되어야 한다. 
	for(int i = 0; i < 26; i++){ 
		if(arr[i] != 0) return false; 
	}

	return true; 
}

int main(void) {
	ios::sync_with_stdio(0);
    cin.tie(0);

	int n; 
	cin >> n; 

	while(n--){
		string a, b;
		cin >> a >> b;

		if(possible(a, b)) cout << "Possible\n";
		else cout << "Impossible\n";

		// 각 테스트 케이스마다 배열 초기화 해주기!!
		fill(arr, arr + 26, 0);
	}

	return 0;
}
	