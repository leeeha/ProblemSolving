import java.util.*
import kotlin.math.*
typealias PII = Pair<Int, Int>

/*
순위를 확정지을 수 있으려면, 자신을 제외한 다른 모든 노드와의 승패 결과를 알아야 한다.
N-1개의 노드와 승패를 확정지을 수 있다면 answer++

a > b, b > c -> a > c (플로이드 워셜)
N은 최대 100명 이하
*/
class Solution {
    fun solution(n: Int, results: Array<IntArray>): Int {
        var answer = 0
        val graph = MutableList(n + 1) { MutableList(n + 1) { 0 } }
        
        results.forEach { e ->
            graph[e[0]][e[1]] = 1
        }
        
        for(k in 1..n){
            for(i in 1..n){
                for(j in 1..n){
                    if(graph[i][k] == 1 && graph[k][j] == 1){
                        graph[i][j] = 1
                    }
                }
            }
        }
        
        for(i in 1..n){
            var cnt = 0
            for(j in 1..n){
                // 두 선수의 순위를 결정지을 수 있는 경우 
                if(graph[i][j] == 1 || graph[j][i] == 1){
                    cnt++
                }
            }
            
            // 자기 자신을 제외한 
            // 모든 선수와의 순위 확정 가능한 경우 
            if(cnt == n - 1) answer++
        }
        
        return answer
    }
}