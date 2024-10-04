```kotlin
fun main() {
    // Map 
    val map = mapOf<String, Int>("math" to 98, "english" to 80, "science" to 75)
    println(map) // {math=98, english=80, science=75}
    println(map.size) // 3
    println(map.keys) // [math, english, science]
    println(map.values) // [98, 80, 75]
    println(map.isEmpty()) // false
    println(map.containsKey("math")) // true
    println(map.containsValue(70)) // false
    println(map["math"]) // 98 
    println(map.getOrDefault("art", -1)) 
    println(map.getOrElse("art") {"unknown subject"})
    
    // MutableMap 
    val mutableMap = mutableMapOf<String, Int>()
    mutableMap.put("math", 77)
    mutableMap.putAll(mapOf("english" to 80, "science" to 75))
    println(mutableMap) // {math=77, english=80, science=75}
    println(mutableMap.getOrPut("art") { 99 }) // 99
    
    // SortedMap 
    val sortedMapByKey = map.toSortedMap() // 기존 맵의 얕은 복사 
    println(sortedMapByKey) // {english=80, math=98, science=75}
    
    val sortedMapByValue = sortedMapByKey.entries // Set<Entry<K, V>>
        .sortedBy { it.value } // List<Map<K, V>>
        .associate { it.key to it.value } // Map<K, V>
    println(sortedMapByValue) // {science=75, english=80, math=98}
    
    // Map의 깊은 복사 
    val originalMap = mapOf("A" to Fruit("apple", 5), "B" to Fruit("banana", 3))
    val deepCopiedMap = originalMap.mapValues { (key, value) -> value.copy() }
    println(deepCopiedMap)
} 

data class Fruit(val name: String, val quantity: Int)
```