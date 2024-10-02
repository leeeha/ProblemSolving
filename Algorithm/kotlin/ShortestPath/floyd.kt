import kotlin.math.*

class FloydSolution {
    val INF = 1e9.toInt()
    var N = 0
    var M = 0
    lateinit var dist: MutableList<MutableList<Int>>
    
    fun input() = with(System.`in`.bufferedReader()) {
        N = readLine().toInt()
        M = readLine().toInt()
    
        dist = MutableList(N + 1) { MutableList(N + 1) { INF } }
        for (i in 1..N) {
            dist[i][i] = 0
        }
    
        repeat(M) {
            val (a, b, c) = readLine().split(" ").map { it.toInt() }
            if (dist[a][b] > c) dist[a][b] = c
        }
    }
    
    fun floyd() {
        for(k in 1..N){
            for(a in 1..N){
                for(b in 1..N){
                    if(a == b) continue
                    if(a == k || b == k) continue
                    dist[a][b] = min(dist[a][b], dist[a][k] + dist[k][b])
                }
            }
        }
    }
    
    fun printResult() {
        for(i in 1..N){
            for(j in 1..N){
                if(dist[i][j] == INF){
                    print("0 ")
                }else{
                    print("${dist[i][j]} ")
                }
            }
            println()
        }
    }
    
    fun main() {
        input()
        floyd()
        printResult()
    }    
}