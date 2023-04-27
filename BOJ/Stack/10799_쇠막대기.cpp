#include <iostream> 
#include <vector> 
#include <string>
#include <algorithm> 
#include <queue> 
#include <stack> 
using namespace std;

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);

	string s; 
	cin >> s;

	int sum = 0; 
	stack<char> st; 

	for(int i = 0; i < s.size(); i++){
		if(s[i] == '('){ 
			st.push(s[i]);
		}else{
			// () 레이저 
			if(s[i - 1] == '('){
				st.pop(); 
				sum += st.size(); 
			}else{
				// 막대기의 끝 
				st.pop(); 
				sum++; 
			}
		}
	}

	cout << sum; 
	
	return 0;
}
