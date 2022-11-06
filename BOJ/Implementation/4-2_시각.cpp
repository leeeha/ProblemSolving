#include<iostream>
#include<string>
using namespace std;

int main() {
	int h;
	cin >> h;

	int count = 0;
	for(int i = 0; i < h + 1; i++){
		for(int j = 0; j < 60; j++){
			for(int k = 0; k < 60; k++){
				// 매 시각 안에 '3'이 포함되어 있으면 카운트 증가
				string time = to_string(i) + to_string(j) + to_string(k);
				if(time.find('3') != -1){
					count++;
				}
			}
		}
	}

	cout << count << '\n';

    return 0;
}