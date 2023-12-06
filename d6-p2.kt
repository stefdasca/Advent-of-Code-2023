import java.util.Scanner
fun main(args: Array<String>){
    val input = Scanner(System.`in`)
    var n = 4
    var total = 0
    var times = LongArray(5) { 0 } // 41     66     72     66
    var distances = LongArray(5) { 0 } // 244   1047   1228   1040
    for(i in 1..n)
    {
        var value = input.nextLong()
        times[i] = value
    }
    for(i in 1..n)
    {
        var value = input.nextLong()
        distances[i] = value
    }
    var totaltime = times[1] * 1000000 + times[2] * 10000 + times[3] * 100 + times[4]
    var totaldist = distances[1] * 10000 * 10000 * 10000 + distances[2] * 10000 * 10000 + distances[3] * 10000 + distances[4]
    for(hold in 1..totaltime)
        if(hold * (totaltime - hold) > totaldist)
            total = total + 1

    println(total)
}