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
            if(text2[i] >= 'A' && text2[i] <= 'Z')
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
    var str = "AAA"
    var cnt = 0
    while (str != "ZZZ")
    {
        var rem = cnt % text.length
        cnt += 1
        for (i in 0..n-1)
        {
            if (first[i] == str)
            {
                if(text[rem] == 'L')
                {
                    str = second[i]
                    break
                }
                else
                {
                    str = third[i]
                    break
                }
            }
        }
    }
    println(cnt)
}