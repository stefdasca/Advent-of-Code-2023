import java.util.Scanner
fun main(args: Array<String>){
    val input = Scanner(System.`in`)

    val text = readln()
    var n = 754
    var first = emptyArray<String>()
    var second = emptyArray<String>()
    var third = emptyArray<String>()
    for(i in 1..n)
    {
        val text2 = readln()
        var str = ""
        var cnt = 0
        for (i in 0..text2.length-1){
            if(text2[i] >= 'A' && text2[i] <= 'Z' || (text2[i] >= '0' && text2[i] <= '9'))
                str += text2[i]
            else
            {
                if(str != "") {
                    cnt += 1
                    if (cnt == 1)
                        first += str
                    if (cnt == 2)
                        second += str
                    if (cnt == 3)
                        third += str
                    str = ""
                }
            }
        }
    }
    var pos = emptyArray<Int>()

    var sz = 0
    for (i in 1..n)
    {
        val str = first[i-1]
        if(str[str.length-1] == 'A') {
            sz += 1
            pos += (i-1)
        }
    }
    val numbersMap = mutableMapOf("sample" to -1)
    for (i in 0..n-1)
        numbersMap[first[i]] = i

    var ans = 0.toBigInteger()

    for (j in 0..sz-1) {
        var ok = 1
        var cnt = 0
        while(ok == 1) {
            val rem = cnt % text.length
            cnt += 1
            var str = pos[j]
            if (text[rem] == 'L')
                str = numbersMap.get(second[str])!!
            else
                str = numbersMap.get(third[str])!!
            pos[j] = str
            if (first[str][first[str].length - 1] == 'Z')
                ok = 0
        }
        if (ans == 0.toBigInteger())
            ans = cnt.toBigInteger()
        else
        {
            var a = ans
            var b = cnt.toBigInteger()
            var c = 0.toBigInteger()
            while(b > 0.toBigInteger())
            {
                c = a % b
                a = b
                b = c
            }
            ans = ans / a * cnt.toBigInteger()
        }
    }

    println(ans)
}