```kotlin
import java.io.BufferedReader
import java.util.ArrayDeque
    
var V = 0
var E = 0
lateinit var indegree: MutableList<Int>
lateinit var graph: MutableList<MutableList<Int>> // 사이클이 없는 비순환 그래프
val answer = mutableListOf<Int>()

fun main() {
    input()
    topologySort()

    for(e in answer) {
        print("$e ")
    }
}

fun input() = with(System.`in`.bufferedReader()) {
    val (v, e) = getInputNumbers()
    V = v
    E = e
    indegree = MutableList(V + 1) { 0 }
    graph = MutableList(V + 1) { mutableListOf() }

    repeat(E) {
        val (a, b) = getInputNumbers()
        graph[a].add(b)
        indegree[b]++
    }
}

fun topologySort() {
    val q = ArrayDeque<Int>()

    for (i in 1..V) {
        if (indegree[i] == 0) {
            q.offer(i)
        }
    }

    while (q.isNotEmpty()) {
        val now = q.poll()
        answer.add(now)

        for (next in graph[now]) {
            indegree[next]--

            if (indegree[next] == 0) {
                q.offer(next)
            }
        }
    }
}

fun BufferedReader.getInputNumbers() = readLine().split(" ").map { it.toInt() }
```