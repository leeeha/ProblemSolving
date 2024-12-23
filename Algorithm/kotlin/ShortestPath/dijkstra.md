```kotlin
import java.util.*

typealias PII = Pair<Int, Int>

val INF = Int.MAX_VALUE
var V = 0
var E = 0
var start = 0
lateinit var dist: IntArray
lateinit var graph: Array<MutableList<PII>>

fun input() = with(System.`in`.bufferedReader()) {
    val nums = readLine().split(" ").map { it.toInt() }
    V = nums[0]
    E = nums[1]
    start = readLine().toInt()

    dist = IntArray(V + 1) { INF }
    graph = Array(V + 1) { mutableListOf() }

    repeat(E) {
        val (u, v, w) = readLine().split(" ").map { it.toInt() }
        graph[u].add(v to w)
    }
}

fun dijkstra() {
    // 노드 번호, 거리 (거리 기준으로 최소 힙)
    val pq = PriorityQueue<PII>(compareBy { it.second })

    // 시작 노드에 대한 초기화
    pq.offer(start to 0)
    dist[start] = 0

    while (!pq.isEmpty()) {
        val now = pq.poll()
        val curNode = now.first
        val curDist = now.second

        // 이미 확정된 최단 경로는 무시 
        if (curDist > dist[curNode]) continue

        // 현재 노드의 인접 노드들에 대해서 
        for (edge in graph[curNode]) {
            val nextNode = edge.first
            val nextDist = edge.second
            val totalDist = curDist + nextDist

            // 현재 노드를 거쳐가는 게 비용이 더 적은지 검사 
            if (dist[nextNode] > totalDist) {
                dist[nextNode] = totalDist
                pq.offer(nextNode to totalDist)
            }
        }
    }
}

fun printResult() {
    for (i in 1..V) {
        if (dist[i] == INF) {
            println("INF")
        } else {
            println(dist[i])
        }
    }
}

fun main() {
    input()
    dijkstra()
    printResult()
}
```