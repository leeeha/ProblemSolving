import java.util.PriorityQueue

val MAX = 20001
val INF = Int.MAX_VALUE
var V = 0
var E = 0
var startNode = 0
val dist = MutableList(MAX) { INF }
val graph = MutableList(MAX) { mutableListOf<Pair<Int, Int>>() }

fun input() = with(System.`in`.bufferedReader()) {
    val numbers = readLine().split(" ").map { it.toInt() }
    V = numbers[0]
    E = numbers[1]
    startNode = readLine().toInt()

    repeat(E) {
        val (u, v, w) = readLine().split(" ").map { it.toInt() }
        graph[u].add(Pair(v, w))
    }
}

fun dijkstra() {
    // 노드 번호, 거리 (거리 기준으로 최소 힙)
    val pq = PriorityQueue<Pair<Int, Int>>(compareBy { it.second })
    pq.offer(Pair(startNode, 0))
    dist[startNode] = 0

    while(pq.isNotEmpty()){
        val curNum = pq.peek().first
        val curDist = pq.peek().second
        pq.poll()

        // 이미 확정된 최단 경로는 무시 
        if(curDist > dist[curNum]) continue

        // 인접 노드 확인 
        for(pair in graph[curNum]){
            val nextNum = pair.first
            val nextDist = pair.second
            val totalDist = curDist + nextDist

            // 최단 거리 테이블 갱신 
            if(dist[nextNum] > totalDist){
                dist[nextNum] = totalDist
                pq.offer(Pair(nextNum, totalDist))
            }
        }
    }
}

fun printResult(){
    for(i in 1..V){
        if(dist[i] == INF){
            println("INF")
        }else{
            println(dist[i])
        }
    }
}

fun main() {
    input()
    dijkstra()
    printResult()
}