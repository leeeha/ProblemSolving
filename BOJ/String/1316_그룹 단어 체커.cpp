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

		// ù��° ���ĺ� ���ڿ� ���� ���� ���� ó�� 
		int index = s[0] - 'a'; 
		appeared[index] = true; 

		for(int i = 1; i < s.size(); i++){ 
			int index = s[i] - 'a'; 
			
			// ���� ���ڿ� ���� ������, ���� ���Դ� ������ ��� 
			if(s[i] != s[i - 1] && appeared[index]){
				cnt--; // �׷� �ܾ� X 
				break; // ���� ���̽��� �̵� 
			}

			if(!appeared[index]){ 
				appeared[index] = true; 
			}
		}
	}

	cout << cnt; 
	
	return 0; 
}