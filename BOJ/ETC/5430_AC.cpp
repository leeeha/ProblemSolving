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

	while (t--) { // �ִ� 100
		string p;
		cin >> p; // �ִ� 10��
		
		int n;
		cin >> n; // �ִ� 10��
		
		string arr;
		cin >> arr;

		parseString(arr);
	
		bool isError = false;
		bool forward = true; // �������̸� true 
		
		for(int i = 0; i < p.size(); i++){
			if(p[i] == 'R'){
				// ���� ��ȯ 
				forward = !forward;
			}else{
				// ����ִµ� �����Ϸ��� �ϸ� ���� 
				if(dq.empty()){
					isError = true;
					cout << "error\n";
					break;
				}

				// ���� ���⿡ ���� ���̳� ���� ���� ���� 
				if(forward){
					dq.pop_front();
				}else{
					dq.pop_back();
				}
			}
		}

		if(!isError){
			// ���� ���⿡ ���� �迭 ��� 
			printArray(forward);
		}
	}
	
	return 0;
}