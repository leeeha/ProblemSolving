# 배열 생성 

```kotlin 
import java.util.*

fun main() {
    // 1차원 배열 
    val a1 = arrayOf(1, 2, 3)
    println(a1.contentToString()) // [1, 2, 3]
    
    val a2 = arrayOfNulls<Int>(3)
    println(Arrays.toString(a2)) // [null, null, null]
    
    println(emptyArray<Int>().contentToString()) // []
    
    val a3 = Array(5) { it * 2 }
    println(a3.contentToString()) // [0, 2, 4, 6, 8]
    
    val a4 = (0..10).toList().toTypedArray()
    println(a4.contentToString()) // [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    
    // 2차원 배열 
    val a5 = arrayOf(a1, a3, a4)
    for(row in a5){
        for(col in row){
            print("$col ")
        }
        println()
    }
}
```

# 배열 순회

```kotlin
fun main() {
    val r1 = Array(4, { it + 1 }) // 1 2 3 4
    val r2 = Array(4, { it + 5 }) // 5 6 7 8
    val r3 = Array(4, { it + 9 }) // 9 10 11 12 
    
    val arr = arrayOf(r1, r2, r3)
	for(row in arr){
        for(col in row){
            print("$col ")
        }
        println()
    }
    
    arr.forEach { row -> 
        row.forEach { col -> 
            print("$col ")
        }
        println()
    }
    
    for((i, row) in arr.withIndex()){
        for(j in row.indices){
            print("[$i, $j] ${row[j]} ")
        }
        println()
    }
    
    arr.forEachIndexed { i, row ->
        for(j in 0 until row.size){ // for(j in 0..row.lastIndex) 
            print("[$i, $j] ${row[j]} ")
        }
        println()
    }
}
```

# 배열 원소 추가 및 삭제 

배열은 기본적으로 크기가 고정되어 있기 때문에, 한번 할당되면 그 크기를 변경할 수 없다. 

유일한 방법은 메모리에 새 배열을 할당해서 기존 배열의 원소를 모두 복사하는 것이다. 

```kotlin
fun main() {
    val arr1 = intArrayOf(1, 2, 3, 4, 5)

    // 요소 추가
    val arr2 = arr1.plus(6)
    println("${arr2.contentToString()}") // [1, 2, 3, 4, 5, 6]

    // 요소 삭제 (범위 내의 원소만 남기기)
    val arr3 = arr1.sliceArray(0..2)
    println("${arr3.contentToString()}") // [1, 2, 3]
}
```

# 배열 정렬 

```kotlin 
fun main() {
    val arr = arrayOf(8, 4, 3, 2, 5, 9, 1)

    // 정렬된 배열 반환
    val sortedArr = arr.sortedArray() // 오름차순
    println(sortedArr.contentToString()) // [1, 2, 3, 4, 5, 8, 9]

    val sortedArrDesc = arr.sortedArrayDescending() // 내림차순
    println(sortedArrDesc.contentToString()) // [9, 8, 5, 4, 3, 2, 1]

    // 원본 배열에 대한 정렬
    arr.sort(0, 4) // [startIndex, endIndex) 범위의 원소 정렬 
    println(arr.contentToString()) // [2, 3, 4, 8, 5, 9, 1]

    arr.sortDescending()
    println(arr.contentToString()) // [9, 8, 5, 4, 3, 2, 1]

    // 정렬된 List 반환
    val listSorted = arr.sorted()
    val listDesc = arr.sortedDescending()
    println(listSorted) // 리스트는 toString() 오버라이딩 되어있음.
    println(listDesc)

    // sortBy로 특정 기준에 따라 정렬 
    val items = arrayOf("Dog", "Cat", "Lion", "Kangaroo", "Po")
    items.sortBy { item -> item.length } 
    println(items.contentToString()) // [Po, Dog, Cat, Lion, Kangaroo] 
}
```

```kotlin
data class Product(val name: String, val price: Double)

fun main() {
    val products = arrayOf(
        Product("Snowball", 870.00),
        Product("Smart Phone", 999.00),
        Product("Drone", 240.00),
        Product("Mouse", 333.56),
        Product("Keyboard", 125.99),
        Product("Smart Phone B", 150.99),
        Product("Mouse", 512.89)
    )

    products.sortBy { it.price } // 오름차순 
    products.forEach { println(it) }
    
    products.sortByDescending { it.price } // 내림차순 
    products.forEach { println(it) }
    
    // 가격에 따라 오름차순 정렬 
    products.sortWith(
        Comparator { p1, p2 ->
          // p1이 크면 1, 같으면 0, 작으면 -1
          p1.price.compareTo(p2.price)
        }
  	)
    products.forEach { println(it) }

    // 이름을 기준으로 오름차순 정렬 
    // 이름이 같으면, 가격을 기준으로 오름차순 정렬 
    products.sortWith(compareBy({it.name}, {it.price}))
    products.forEach { println(it) }

    // 지정된 프로퍼티의 최솟값, 최댓값 구하기 
    println(products.minOf {it.price}) 
    println(products.maxOf {it.price}) 
}
```

# 배열 필터링

```kotlin
fun main() {
    val nums = arrayOf(1, 2, 3)
    println(nums.filter { it % 2 != 0 }) // [1, 3]
    println(nums.filterIndexed { i, e -> i != 0 && e % 2 != 0 }) // [3]
    
    val arr = arrayOf(listOf(1,2,3), setOf(1,2), listOf(2)) 
    println(arr.filterIsInstance<List<Int>>()) // [[1, 2, 3], [2]]
}
```

# 다차원 배열 펼치기 

```kotlin 
fun main() {
    val nums = arrayOf(1, 2, 3)
    val strs = arrayOf("one", "two", "three")
    val arr = arrayOf(nums, strs)
    
    // [1, 2, 3]
	// [one, two, three]
    arr.forEach { println(it.contentToString()) }
    
    println(arr.flatten()) // [1, 2, 3, one, two, three]
    println(arr.flatMap { it.take(2) }) // [1, 2, one, two]
}
```
