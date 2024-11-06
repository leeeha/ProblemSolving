# String 

**문자 검색**

- `charAt(index: Int)` : 해당 위치의 문자 반환
- `indexOf(char: Char/String, startIndex: Int = 0, ignoreCase: Boolean = false)` : 특정 문자나 문자열의 첫번째 위치 반환
- `lastIndexOf(char: Char/String)` : 특정 문자나 문자열의 마지막 위치 반환
- `startsWith(prefix: String)` : 특정 접두사로 시작하는지 확인
- `endsWith(suffix: String)` : 특정 접미사로 끝나는지 확인
- `contains(substring: String)` : 문자열에 특정 문자열이 포함되어 있는지 확인

**문자열 변환** 

- `uppercase()` , `lowercase()` : 대소문자 변환
- `substring(startIndex: Int, endIndex: Int)` : 부분 문자열 반환 [startIndex, endIndex) 
- `replace(old: Char/String, new: Char/String)` : 특정 문자나 문자열을 다른 값으로 대체
- `trim()` : 문자열의 양끝 공백 제거 (중간에 있는 공백 제외)
- `split(delimiter: String)` : 문자열을 특정 구분자로 분할하여 리스트 반환

**문자열 비교** 

- `equals(other: String)` : 문자열의 내용이 같은지 비교 (동등성)
- `compareTo(other: String)`: 문자를 아스키 코드로 변환하여 크기 비교 (같으면 0, 크면 양수, 작으면 음수 반환)

**그외**

- `length`: 문자열 길이 반환 
- `joinToString(separator: String)` : 리스트나 배열을 문자열로 변환할 때 사용
- `repeat(n: Int)` : 문자열을 n번 반복한 결과 반환

```kotlin
fun main() {
    val str = "Hello, Kotlin!"

    // 문자열 길이 
    println(str.length) // 14 

    // 문자 검색
    println("char at index 1: ${str[1]}")  // e
    println("first index of 'Kotlin': ${str.indexOf("Kotlin")}")  // 7
    println("substring from index 7 to 13: ${str.substring(7, 13)}")  // Kotlin

    // 문자열 변환
    println("uppercase: ${str.uppercase()}")  // HELLO, KOTLIN!
    println("replaced: ${str.replace("Kotlin", "World")}")  // Hello, World!

    // 문자열 비교
    val anotherStr = "hello, kotlin!"
    println("equals: ${str.equals(anotherStr, ignoreCase = true)}")  // true
}
```

```kotlin 
fun main() {
    var str = "    Kotlin is awesome    "
    println(str.trim()) // Kotlin is awesome
    println(str.replace(" ", "")) // Kotlinisawesome
}
```

```kotlin
fun main() {
    val words = listOf("Kotlin", "is", "awesome")
    
    val sentence = words.joinToString(separator = " ")
    println(sentence)  // Kotlin is awesome

    val repeated = "Kotlin".repeat(3)
    println(repeated)  // KotlinKotlinKotlin
}
```

# StringBuilder

- `length`: 문자열 길이 반환 
- `append(value: Any)` : 문자열의 끝에 값을 추가
- `insert(offset: Int, value: Any)` : 특정 위치에 값 삽입
- `delete(startIndex: Int, endIndex: Int)` : 특정 범위의 문자열 삭제
- `deleteCharAt(index: Int)` : 특정 위치의 문자 삭제
- `replace(startIndex: Int, endIndex: Int, str: String)` : 특정 범위의 문자열을 다른 문자열로 대체
- `reverse()` : 문자열을 역순으로 변환
- `substring(int start, int end)` : [start, end) 범위의 부분 문자열 추출 
- `setCharAt(int index, String s)` : index 위치의 문자를 s로 변경
- `setLength(int length)` : 문자열 길이 변경 (현재보다 길게 설정하면 공백으로 채워지고, 현재보다 짧게 설정하면 문자 삭제)

```kotlin 
fun main() {
    val sb = StringBuilder("Hello")

    // 문자열 길이 
    println(sb.length) // 5 

    // 문자열 추가
    sb.append(", Kotlin!")
    println("After append: $sb")  // Hello, Kotlin!

    // 문자열 삽입
    sb.insert(7, "beautiful ")
    println("After insert: $sb")  // Hello, beautiful Kotlin!

    // 문자열 삭제
    sb.delete(7, 17)
    println("After delete: $sb")  // Hello, Kotlin!
    
    // 문자열 교체 
    sb.replace(0, 5, "Hi")
    println("After replace: $sb") // Hi, Kotlin!

    // 문자열 뒤집기
    sb.reverse()
    println("After reverse: $sb")  // !nitloK ,iH
}
```