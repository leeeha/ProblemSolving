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

	while (t--) { // �ִ� 100�� 
		string p;
		cin >> p; // �迭�� ������ ���ڿ� (�ִ� ���� 10��) 

		int n;
		cin >> n; // �迭 ���� ���� (�ִ� 10����) 

		string s; 
		cin >> s; // ���ȣ�� ������ ���� �迭 �Է�

		deque<int> dq; 

		string temp; // �� �ڸ��� �̻��� ���ڸ� ���� 
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

		bool print = true; // error�� �ƴ� ��� true
		bool left = true;  // �������� ���� ������ true
		for(int i = 0; i < p.size(); i++){
			if(p[i] == 'R'){
				left = !left;
			}else{
				if(dq.empty()){
					print = false;
					cout << "error\n";
					break;
				}else{
					if(left){ // �������� ���� ������ 
						dq.pop_front(); // ���� ���� ���� 
					}else{ // �������� ������ 
						dq.pop_back(); // ������ ���� ���� 
					}
				}
			}
		}

		if(print){    // error�� �ƴϰ� 
			if(left){ // �������� ���� ������ 
				cout << "[";
				while(!dq.empty()){
					cout << dq.front();
					dq.pop_front(); // �տ��� pop 
					if(!dq.empty()){
						cout << ","; 
					}
				}
				cout << "]\n";
				}else{ // �������� ������ 
					cout << "[";
					while(!dq.empty()){
						cout << dq.back(); 
						dq.pop_back(); // �ڿ��� pop
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