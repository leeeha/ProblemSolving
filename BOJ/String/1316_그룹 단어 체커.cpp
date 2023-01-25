#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; 
	cin >> n; 
	
	int cnt = n; 
	while(n--){
		string s; 
		cin >> s; 

		bool appeared[26] {false}; 

		// 첫번째 알파벳 문자에 대한 출현 유무 처리 
		int index = s[0] - 'a'; 
		appeared[index] = true; 

		for(int i = 1; i < s.size(); i++){ 
			int index = s[i] - 'a'; 
			
			// 이전 문자와 같지 않은데, 전에 나왔던 문자인 경우 
			if(s[i] != s[i - 1] && appeared[index]){
				cnt--; // 그룹 단어 X 
				break; // 다음 케이스로 이동 
			}

			if(!appeared[index]){ 
				appeared[index] = true; 
			}
		}
	}

	cout << cnt; 
	
	return 0; 
}