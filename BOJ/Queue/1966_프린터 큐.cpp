#include<iostream>
#include<queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 테스트 케이스의 수
    int test;
    cin >> test;

    for (int i = 0; i < test; i++) {
        // n: 문서의 수
        // m: 몇번째로 인쇄되었는지 궁금한 문서의 현재 큐에서의 위치
        int n, m;
        cin >> n >> m;

        // 인덱스가 m인 문서가 몇번째로 인쇄되었는지 카운팅하는 변수
        int cnt = 0; // 각 테스트 케이스마다 0으로 초기화!!!

        queue<pair<int, int>> q;
        priority_queue<int> pq;

        int ipt; // 각 문서의 중요도
        for (int j = 0; j < n; j++) {
            cin >> ipt;

            // 각 문서의 인덱스와 중요도를 묶어서 큐에 push
            q.push({ j, ipt });

            // 우선순위 큐는 중요도에 따라 내림차순 정렬
            pq.push(ipt);
        }

        while (!q.empty()) {
            // 큐의 front 원소를 꺼내서
            int idx = q.front().first;
            int val = q.front().second;
            q.pop();

            // 우선순위 큐의 top과 중요도가 일치하면
            if (pq.top() == val) {
                pq.pop();
                cnt++; // 문서 하나 인쇄할 때마다 증가

                // 현재 문서의 인덱스가 m인 경우
                if (idx == m) {
                    // 몇번째로 인쇄되었는지 출력
                    cout << cnt << '\n';
                    break; // 그 다음 테스트 케이스로 넘어가기
                }
            }
            else { // 중요도가 높지 않으면 큐의 rear에 다시 push
                q.push({ idx, val });
            }
        }
    }

    return 0;
}