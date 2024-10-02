class UnionFindSolution {
    val parent = MutableList(8) { 0 }

    fun findParent(x: Int): Int {
        if(x == parent[x]) return x
        parent[x] = findParent(parent[x])
        return parent[x]
    }
    
    fun unionParent(a: Int, b: Int) {
        val pa = findParent(a)
        val pb = findParent(b)
        if(pa == pb) return
        if(pa < pb) parent[pb] = pa
        else parent[pa] = pb
    }
    
    fun main() {
        for(i in 1..7){
            parent[i] = i
        }
    
        unionParent(1, 2) // parent[2] = 1
        unionParent(4, 5) // parent[5] = 4
        unionParent(5, 6) // parent[6] = 4
        println("2번과 4번은 같은 집합인가? ${findParent(2) == findParent(4)}") // false
    
        unionParent(1, 4) // parent[4] = 1
        println("2번과 4번은 같은 집합인가? ${findParent(2) == findParent(4)}") // true 
    }
}