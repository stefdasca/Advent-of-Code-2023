import java.util.Scanner
fun main(args: Array<String>){
    val input = Scanner(System.`in`)
    var n = 4
    var total = 1
    var times = IntArray(5) { 0 } // 41     66     72     66
    var distances = IntArray(5) { 0 } // 244   1047   1228   1040
    for(i in 1..n)
    {
        var value = input.nextInt()
        times[i] = value
    }
    for(i in 1..n)
    {
        var value = input.nextInt()
        distances[i] = value
    }
    for(i in 1..n)
    {
        var cnt = 0
        for(hold in 1..times[i])
            if(hold * (times[i] - hold) > distances[i])
                cnt = cnt + 1
        total = total * cnt
    }

    println(total)
}