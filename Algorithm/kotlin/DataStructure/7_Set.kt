fun main() {
    // Set (중복을 허용하지 않으며, 순서가 없는 집합)
    val fruits = setOf("apple", "banana", "cherry", "banana")
    println(fruits) // [apple, banana, cherry] 
    println(fruits.size) // 3
    println(fruits.contains("apple")) // true
    println(fruits.elementAt(2)) // cherry
    
    // MutableSet 
    val colors = mutableSetOf("yellow", "red", "blue")
    colors.add("orange") 
    println(colors) // [yellow, red, blue, orange]
    colors.remove("blue")
    println(colors) // [yellow, red, orange]
    
    colors.addAll(listOf("green", "purple")) // true 
    colors.removeAll(setOf("black")) // false
    colors.removeAll(setOf("yellow")) // true
    colors.clear()
    
    // HashSet
    val hashSet = hashSetOf(1, 2, 3, 4)
    println(hashSet.elementAtOrNull(2)) // 3
    println(hashSet.elementAtOrElse(4) {"unkown index"}) // unknown index
    
    // TreeSet 
    val sortedSet1 = sortedSetOf(3, 5, 8, 1, 2)
    println(sortedSet1) // [1, 2, 3, 5, 8]
    
    val sortedSet2 = sortedSetOf(Comparator { a: Int, b: Int -> b - a }, 3, 1, 4, 2)
    println(sortedSet2) // [4, 3, 2, 1]
    
    val sortedSet3 = sortedSetOf(Comparator { a: String, b: String -> a.length - b.length }, "apple", "banana", "kiwi")
    println(sortedSet3) // [kiwi, apple, banana]
} 