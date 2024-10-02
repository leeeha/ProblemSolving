class KruskalSolution {
    var V = 0
    var E = 0
    val edges = mutableListOf<Edge>()
    lateinit var parent: MutableList<Int>
    
    data class Edge(
        val start: Int,
        val end: Int,
        val cost: Int
    )
    
    fun input() = with(System.`in`.bufferedReader()) {
        val nums = readLine().split(" ").map { it.toInt() }
        V = nums[0]
        E = nums[1]
    
        repeat(E) {
            val (a, b, c) = readLine().split(" ").map { it.toInt() }
            edges.add(Edge(a, b, c))
        }
    
        parent = MutableList(V + 1) { 0 }
        for (i in 1..V) {
            parent[i] = i
        }
    }
    
    fun findParent(x: Int): Int {
        if (x == parent[x]) return x
        parent[x] = findParent(parent[x])
        return parent[x]
    }
    
    fun unionParent(a: Int, b: Int) {
        val pa = findParent(a)
        val pb = findParent(b)
        parent[pb] = pa
    }
    
    fun kruskal() {
        // 가중치가 작은 순으로 정렬
        edges.sortBy { it.cost }
    
        // 사이클을 형성하지 않을 때만 MST에 포함
        var sum = 0
        for (edge in edges) {
            if (findParent(edge.start) != findParent(edge.end)) {
                unionParent(edge.start, edge.end)
                sum += edge.cost
            }
        }
    
        println(sum)
    }
    
    fun main() {
        input()
        kruskal()
    }    
}