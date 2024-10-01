# 리스트 생성, 요소 접근 

```kotlin 
fun main() {
    val list = listOf(1, 2, 3, 4, 5)
    val list1 = emptyList<String>()
    val list2 = listOfNotNull(2, 4, null, 5) // [2, 4, 5]
    
    val list3 = listOf("apple", "banana", "cherry", "banana")
    println(list3.indexOf("banana")) // 1 
    println(list3.lastIndexOf("banana")) // 3 
    
    println(list3.contains("apple")) // true
    println(list.containsAll(listOf(1, 7))) // false
    
    val iterator = list3.listIterator()
    while (iterator.hasNext()) {
        print("${iterator.next()} ") // apple banana cherry banana
    }
    println()

    while (iterator.hasPrevious()) {
        print("${iterator.previous()} ")  // banana cherry banana apple
    }
    println()
    
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
    
    nums.removeAt(3)
    println(nums) // [1, 2, 3, 4, 4]
    
    nums.addAll(listOf(6, 7, 8))
    println(nums) // [1, 2, 3, 4, 4, 6, 7, 8]
    
    nums.removeAll(listOf(3, 4))
    println(nums) // [1, 2, 6, 7, 8]
    
    nums.retainAll(listOf(6, 7))
    println(nums) // [6, 7]
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
    // Map<K, List<T>>
    println((0..10).toList().groupBy { it % 2 }) // {0=[0, 2, 4, 6, 8, 10], 1=[1, 3, 5, 7, 9]}
    println((0..10).toList().groupBy { it % 2 }[0]) // [0, 2, 4, 6, 8, 10]
    
    // List<Pair<T, R>>
    val strs = listOf("a", "b", "c")
	val nums = listOf(1, 2, 3, 4)
	println(strs.zip(nums)) // [(a, 1), (b, 2), (c, 3)]
    
    // 중복 제거 
	println(listOf(1, 2, 3, 4, 5, 1, 2, 3, 6).distinct()) // [1, 2, 3, 4, 5, 6]
    println(listOf(1, 2, 3, 4, 5, 6).distinctBy { it % 3 }) // [1, 2, 3]
}
```