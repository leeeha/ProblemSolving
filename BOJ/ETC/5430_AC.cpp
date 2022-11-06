#include <iostream>
#include <vector>
#include <string>
#include <deque>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
	
	int t;
	cin >> t; 

	while (t--) { // 최대 100개 
		string p;
		cin >> p; // 배열을 변형할 문자열 (최대 길이 10만) 

		int n;
		cin >> n; // 배열 원소 개수 (최대 10만개) 

		string s; 
		cin >> s; // 대괄호를 포함한 정수 배열 입력

		deque<int> dq; 

		string temp; // 두 자릿수 이상의 숫자를 위해 
		for(int i = 0; i < s.size(); i++){
			if(s[i] == '['){
				continue;
			}
			else if('0' <= s[i] && s[i] <= '9'){
				temp += s[i];
			}
			else if(s[i] == ',' || s[i] == ']'){
				if(!temp.empty()){
					dq.push_back(stoi(temp));
					temp.clear();
				}
			}
		}

		bool print = true; // error가 아닐 경우 true
		bool left = true;  // 뒤집어져 있지 않으면 true
		for(int i = 0; i < p.size(); i++){
			if(p[i] == 'R'){
				left = !left;
			}else{
				if(dq.empty()){
					print = false;
					cout << "error\n";
					break;
				}else{
					if(left){ // 뒤집어져 있지 않으면 
						dq.pop_front(); // 왼쪽 원소 제거 
					}else{ // 뒤집어져 있으면 
						dq.pop_back(); // 오른쪽 원소 제거 
					}
				}
			}
		}

		if(print){    // error가 아니고 
			if(left){ // 뒤집어져 있지 않으면 
				cout << "[";
				while(!dq.empty()){
					cout << dq.front();
					dq.pop_front(); // 앞에서 pop 
					if(!dq.empty()){
						cout << ","; 
					}
				}
				cout << "]\n";
				}else{ // 뒤집어져 있으면 
					cout << "[";
					while(!dq.empty()){
						cout << dq.back(); 
						dq.pop_back(); // 뒤에서 pop
						if(!dq.empty()){
							cout << ",";
						}
					}
					cout << "]\n";
				}
		}		
	}

	return 0;
}