#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
#include <stack> 
#include <utility> 
#include <set> 
using namespace std;

vector<pair<int, int>> paren; 
set<string> result; 

void saveParenthesesPosition(string input) {
	stack<pair<char, int>> st;
	
	for(int i = 0; i < input.size(); i++){
		char ch = input[i];

		if(ch == '('){
			int openIdx = i; 
			st.push({ch, openIdx});
		}

		if(ch == ')'){
			int openIdx = st.top().second; 
			int closeIdx = i; 

			// 괄호 쌍의 인덱스를 저장한다. 
			paren.push_back({openIdx, closeIdx});

			// 스택의 top에 있는 여는 괄호를 꺼낸다. 
			st.pop(); 
		}
	}
}

string removeParentheses(string str, int idx){
	int left = paren[idx].first; 
	int right = paren[idx].second; 

	str.replace(left, 1, " ");
	str.replace(right, 1, " ");

	return str;
}

void solution(int n, string input){
	for(int r = 1; r <= n; r++){
		vector<int> arr(n);
		for(int i = 0; i < n; i++){
			arr[i] = i; 
		}
		
		vector<bool> selected(n, false);
		for(int i = 0; i < r; i++){
			selected[i] = true; 
		}

		do{
			string str = input;
			for(int i = 0; i < n; i++){
				if(selected[i]){ // 1~r개 선택 
					str = removeParentheses(str, arr[i]);
				}
			}

			// 공백 제거 후 set에 저장하기 (중복되는 문자열 없도록)
			str.erase(remove(str.begin(), str.end(), ' '), str.end());
			result.insert(str);
		}while(prev_permutation(selected.begin(), selected.end()));  
	}
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0); 

	string input; 
	cin >> input; 

	saveParenthesesPosition(input);
	solution(paren.size(), input);

	for(auto e: result){
		cout << e << "\n"; 
	}
	
	return 0; 
}