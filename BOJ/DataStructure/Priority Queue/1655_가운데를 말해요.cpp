#include <iostream>
#include <queue>
#include <algorithm> // sort
#define MAX_N 100002
using namespace std;

int arr[MAX_N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<int, vector<int>, less<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    int n;
    cin >> n;

    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;

        // 처음에 값이 없는 경우
        if (maxHeap.empty()) {
            maxHeap.push(x);
        }
        else {
            // 최대 힙의 크기가 더 크다면, 최소 힙에 값을 넣는다.
            if (maxHeap.size() > minHeap.size()) {
                minHeap.push(x);
            }
            else { // 크기가 같다면 최대 힙에 넣는다.
                maxHeap.push(x);
            }

            // 최대 힙의 루트 노드 > 최소 힙의 루트 노드 -> swap
            if (maxHeap.top() > minHeap.top()) {
                int maxTop = maxHeap.top();
                int minTop = minHeap.top();

                maxHeap.pop();
                minHeap.pop();

                maxHeap.push(minTop);
                minHeap.push(maxTop);
            }

        }

        // 최대 힙의 루트 노드가 중간값
        cout << maxHeap.top() << '\n';
    }

    return 0;
}