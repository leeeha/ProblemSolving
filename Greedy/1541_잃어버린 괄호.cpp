#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;

	string tmp = ""; // 숫자 하나를 임시 저장하는 변수
	int ans = 0; 
	bool minus = false;

	// [] 연산자는 배열 인덱스 범위 넘어도 예외 발생x
	for(int i = 0; i <= s.length(); i++){
		if(s.at(i) == '+' || s[i] == '-' || i == s.length()){
			if(minus){
				ans -= stoi(tmp); // 50 40 
			}else{
				ans += stoi(tmp); // 55
			}
			tmp = ""; // 임시 변수 초기화

			// - 문자가 한번이라도 나오면 그 뒤의 숫자들은 모두 뺄셈 연산 
			if(s[i] == '-'){
				minus = true;
			}
		}
		else{ // tmp 문자열에 숫자 한자리씩 붙이기
			tmp += s[i];
		}
	}

	cout << ans << "\n";
	
	return 0;
}
