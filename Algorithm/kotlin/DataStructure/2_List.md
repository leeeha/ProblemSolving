# 리스트 생성, 요소 접근 

```kotlin 
fun main() {
    // 생성 
    val list = listOf(1, 2, 3, 4, 5)
    val list1 = emptyList<String>()
    val list2 = listOfNotNull(2, 4, null, 5) // [2, 4, 5]
    
    // 접근 
    val fruits = listOf("apple", "banana", "cherry", "banana")
    println(fruits.first()) // apple
    println(fruits.last()) // banana
    println(fruits.indexOf("banana")) // 1 
    println(fruits.lastIndexOf("banana")) // 3

    println(fruits.getOrElse(4) { "unknown fruit" })
    println(fruits.getOrNull(4) ?: "unknown fruit")

    println(fruits.contains("apple")) // true
    println(fruits.containsAll(listOf("apple", "cherry"))) // true
    
    // 순회
    val iterator = fruits.listIterator()
    while (iterator.hasNext()) {
        print("${iterator.next()} ") // apple banana cherry banana
    }
    println()

    while (iterator.hasPrevious()) {
        print("${iterator.previous()} ") // banana cherry banana apple
    }
    println()
    
    // subList 
    val list4 = listOf(1, 2, 3, 4, 5, 6, 7)
    println(list4.subList(2, 5)) // [3, 4, 5]
}
```

# 리스트 요소 추가 및 삭제 

```kotlin 
fun main() {
    val nums = mutableListOf(1, 2, 3, 4, 5)
    nums.add(4)
    nums.add(4)
    println(nums) // [1, 2, 3, 4, 5, 4, 4]
    
    nums.remove(4) // 가장 첫번째로 발견된 요소 삭제 
    println(nums) // [1, 2, 3, 5, 4, 4]
    
    nums.removeAt(3) // 인덱스 기준으로 삭제 
    println(nums) // [1, 2, 3, 4, 4]
    
    nums.addAll(listOf(6, 7, 8, 9))
    println(nums) // [1, 2, 3, 4, 4, 6, 7, 8, 9]
    
    nums.removeAll(listOf(3, 4))
    println(nums) // [1, 2, 6, 7, 8, 9]

    nums.removeIf { it % 2 == 0 }
    println(nums) // [1, 7, 9]
    
    nums.retainAll(listOf(1, 7))
    println(nums) // [1, 7]
}
```

# 리스트 필터링 

```kotlin 
fun main() {
    // filter 
    val nums = listOf(1, 2, 3)
    println(nums.filter { it % 2 != 0 }) // [1, 3]
    println(nums.filterIndexed { i, e -> i != 0 && e % 2 != 0 }) // [3]
    
    val arr = listOf(listOf(1,2,3), setOf(1,2), listOf(2)) 
    println(arr.filterIsInstance<List<Int>>()) // [[1, 2, 3], [2]]

    // take 
    println((0..10).toList().take(3)) // [0, 1, 2]
    println((0..10).toList().takeWhile { it < 6 }) // [0, 1, 2, 3, 4, 5]
    println((0..10).toList().takeLast(3)) // [8, 9, 10]
    println((0..10).toList().takeLastWhile { it > 5 }) // [6, 7, 8, 9, 10]

    println((0..10).toList().takeIf { it.size <= 20 }) // [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    println("string".takeIf { it == "string" }) // "string"
    println("string".takeIf { it == "string1" }) // null
    
    // drop 
    println((0..10).toList().drop(3)) // [3, 4, 5, 6, 7, 8, 9, 10]
	println((0..10).toList().dropWhile { it < 5 }) // [5, 6, 7, 8, 9, 10]
	println((0..10).toList().dropLast(3)) // [0, 1, 2, 3, 4, 5, 6, 7]
    println((0..10).toList().dropLastWhile { it > 5 }) // [0, 1, 2, 3, 4, 5]
}
```

# groupBy, zip, distinct 

```kotlin
fun main() {
    // groupBy: Map<K, List<T>>
    // {even=[0, 2, 4, 6, 8, 10], odd=[1, 3, 5, 7, 9]}
    println((0..10).toList().groupBy { if (it % 2 == 0) "even" else "odd" }) 
    // [0, 2, 4, 6, 8, 10]
    println((0..10).toList().groupBy { it % 2 }[0]) 
    
    // zip: List<Pair<T, R>>
    val strs = listOf("a", "b", "c")
	val nums = listOf(1, 2, 3, 4)
	println(strs.zip(nums)) // [(a, 1), (b, 2), (c, 3)]
    
    // distinct: 중복 제거 
	println(listOf(1, 2, 3, 4, 5, 1, 2, 3, 6).distinct()) // [1, 2, 3, 4, 5, 6]
    println(listOf(1, 2, 3, 4, 5, 6).distinctBy { it % 3 }) // [1, 2, 3]
}
```