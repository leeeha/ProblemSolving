#include <iostream> 
#include <vector> 
#include <string>
#include <deque>
using namespace std;

deque<int> dq;

void parseString(string arr){
	string num = "";
	int n = arr.size();
	
	for(int i = 1; i < n - 1; i++){
		char ch = arr[i];
		
		if(ch != ','){
			num += ch;
			if(i == n - 2){
				dq.push_back(stoi(num));
			}
		}else{
			dq.push_back(stoi(num)); 
			num = "";
		}
	}
}

void printComma() {
	if(!dq.empty()){
		cout << ","; 
	}
}

void printForwardArray() {
	while(!dq.empty()){
		cout << dq.front();
		dq.pop_front();
		printComma(); 
	}
}

void printBackwardArray() {
	while(!dq.empty()){
		cout << dq.back(); 
		dq.pop_back();
		printComma(); 
	}
}

void printArray(bool forward){
	cout << "[";
	if(forward){
		printForwardArray(); 
	}else{
		printBackwardArray(); 
	}
	cout << "]\n";
}

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);

	int t;
	cin >> t; 

	while (t--) { // 최대 100
		string p;
		cin >> p; // 최대 10만
		
		int n;
		cin >> n; // 최대 10만
		
		string arr;
		cin >> arr;

		parseString(arr);
	
		bool isError = false;
		bool forward = true; // 정방향이면 true 
		
		for(int i = 0; i < p.size(); i++){
			if(p[i] == 'R'){
				// 방향 전환 
				forward = !forward;
			}else{
				// 비어있는데 삭제하려고 하면 에러 
				if(dq.empty()){
					isError = true;
					cout << "error\n";
					break;
				}

				// 현재 방향에 따라 앞이나 뒤의 원소 삭제 
				if(forward){
					dq.pop_front();
				}else{
					dq.pop_back();
				}
			}
		}

		if(!isError){
			// 현재 방향에 따라 배열 출력 
			printArray(forward);
		}
	}
	
	return 0;
}