#include <iostream>
#include <vector>
using namespace std;

int main()
{
	// 1 ≤ H, W ≤ 500
	int h, w;
	cin >> h >> w;

	// 2차원 배열 선언
	int** m = new int* [h]; // h행
	for (int i = 0; i < h; i++) {
		m[i] = new int[w] {}; // w열 (0으로 초기화)
	}

	for (int c = 0; c < w; c++) {
		int tmp;
		cin >> tmp;

		// 열은 고정, 행은 아래에서 위로 이동
		int r = h - 1;
		while (tmp--) {
			m[r][c] = 1; // 1로 초기화
			r--;
		}
	}

	int sum = 0, cur = 0;
	for (int i = 0; i < h; i++) {
		int cnt = 0; // 각 행마다 빗물이 고일 수 있는 칸의 수 카운팅 
		 
		for (int j = 0; j < w; j++) {

			if (m[i][j] == 1) {
				int partialCnt = 0; // 1과 1 사이에 있는 0의 개수 카운팅 

				cur = j + 1; // 1이 등장한 바로 다음 열부터 검사 
				while (m[i][cur] == 0 && cur < w) {
					partialCnt++; // 0의 개수 증가
					cur++; // 커서 이동 
				}

				if (cur >= w) { // 인덱스 범위를 넘은 경우 
					if (m[i][cur - 1] == 1) { // 마지막 열이 1이어야 
						cnt += partialCnt; // 빗물이 고일 수 있음.
					}
				}
				else {
					// cur < w인데 while 루프가 종료되면, 1이 다시 등장한 것! 
					cnt += partialCnt;
				}

				// 검사를 다시 시작할 인덱스로 갱신 
				j = cur - 1; // j는 곧 ++되기 때문에 cur가 아니라 cur-1로 갱신해야 함.
			}
		}

		//cout << i << "행: " << cnt << "\n";
		sum += cnt;
	}

	cout << sum << endl;

	return 0;
}