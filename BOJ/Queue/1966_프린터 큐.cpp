#include<iostream>
#include<queue>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

	while(t--){
        int n, m;
        cin >> n >> m;
        
        // 인덱스가 m인 문서가 몇번째로 인쇄되었는지 카운팅하는 변수
        int cnt = 0;

        queue<pair<int, int>> q;
        priority_queue<int> pq; // 기본적으로 최대 힙 

        for (int i = 0; i < n; i++){
			int x; 
			cin >> x; 
			
            q.push({ i, x }); // 인덱스와 중요도 
            pq.push(x); // 중요도가 높은 순으로 
        }

        while (!q.empty()){
            // 큐의 front 원소를 꺼내서
            int idx = q.front().first;
            int priority = q.front().second;
            q.pop();

            // 우선순위 큐의 top과 중요도가 일치하면
            if (pq.top() == priority){
                pq.pop();
                cnt++; // 문서 하나 인쇄할 때마다 증가

                // 현재 문서의 인덱스가 m인 경우
                if (idx == m){
                    // 몇번째로 인쇄되었는지 출력
                    cout << cnt << '\n'; 
                    break; // 그 다음 테스트 케이스로 넘어가기
                }
            }
            else { 
				// 중요도가 높지 않으면 큐의 rear에 다시 push
                q.push({ idx, priority });
            }
        }

        // 각 테스트 케이스마다 q, pq를 새로 생성하기 때문에 
        // 컨테이너 초기화는 필요하지 않다.  
    }

    return 0;
}