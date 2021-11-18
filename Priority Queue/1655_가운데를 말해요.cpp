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

        // ó���� ���� ���� ���
        if (maxHeap.empty()) {
            maxHeap.push(x);
        }
        else {
            // �ִ� ���� ũ�Ⱑ �� ũ�ٸ�, �ּ� ���� ���� �ִ´�.
            if (maxHeap.size() > minHeap.size()) {
                minHeap.push(x);
            }
            else { // ũ�Ⱑ ���ٸ� �ִ� ���� �ִ´�.
                maxHeap.push(x);
            }

            // �ִ� ���� ��Ʈ ��� > �ּ� ���� ��Ʈ ��� -> swap
            if (maxHeap.top() > minHeap.top()) {
                int maxTop = maxHeap.top();
                int minTop = minHeap.top();

                maxHeap.pop();
                minHeap.pop();

                maxHeap.push(minTop);
                minHeap.push(maxTop);
            }

        }

        // �ִ� ���� ��Ʈ ��尡 �߰���
        cout << maxHeap.top() << '\n';
    }

    return 0;
}