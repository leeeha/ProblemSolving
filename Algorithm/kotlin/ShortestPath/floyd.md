```kotlin 
import kotlin.math.min

val INF = 1e9.toInt() // 두 개 더해도 Int 범위 넘지 않도록
var V = 0
var E = 0
lateinit var dist: Array<IntArray>

fun input() = with(System.`in`.bufferedReader()) {
    V = readLine().toInt()
    E = readLine().toInt()

    // 최단 거리 테이블 초기화
    dist = Array(V + 1) { IntArray(V + 1) { INF } }
    for (i in 1..V) {
        dist[i][i] = 0
    }

    repeat(E) {
        val (u, v, w) = readLine().split(" ").map { it.toInt() }
        if (dist[u][v] > w) dist[u][v] = w
    }
}

fun floyd() {
    for (k in 1..V) {
        for (a in 1..V) {
            for (b in 1..V) {
                // 자기 자신으로 가는 경로 제외
                if (a == b) continue

                // 출발, 도착 노드에서 경유 노드 제외
                if (k == a || k == b) continue

                // a에서 b로 가는 최단 거리 갱신
                dist[a][b] = min(dist[a][b], dist[a][k] + dist[k][b])
            }
        }
    }
}

fun printResult() {
    for (i in 1..V) {
        for (j in 1..V) {
            if (dist[i][j] == INF) print("0 ")
            else print("${dist[i][j]} ")
        }
        println()
    }
}

fun main() {
    input()
    floyd()
    printResult()
}
```