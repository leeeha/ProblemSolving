#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;

	string tmp = ""; // ���� �ϳ��� �ӽ� �����ϴ� ����
	int ans = 0; 
	bool minus = false;

	// [] �����ڴ� �迭 �ε��� ���� �Ѿ ���� �߻�x
	for(int i = 0; i <= s.length(); i++){
		if(s.at(i) == '+' || s[i] == '-' || i == s.length()){
			if(minus){
				ans -= stoi(tmp); // 50 40 
			}else{
				ans += stoi(tmp); // 55
			}
			tmp = ""; // �ӽ� ���� �ʱ�ȭ

			// - ���ڰ� �ѹ��̶� ������ �� ���� ���ڵ��� ��� ���� ���� 
			if(s[i] == '-'){
				minus = true;
			}
		}
		else{ // tmp ���ڿ��� ���� ���ڸ��� ���̱�
			tmp += s[i];
		}
	}

	cout << ans << "\n";
	
	return 0;
}
