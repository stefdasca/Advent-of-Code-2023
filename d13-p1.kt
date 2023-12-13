import java.util.Scanner
fun main(args: Array<String>){
    val input = Scanner(System.`in`)

    var ansA = 0
    var ansB = 0
    fun solve(arr: Array<String>)
    {
        for (i in 0..arr.size-2)
        {
            var ok = 1
            for (j in 0..i)
            {
                var kk = i + (i - j) + 1
                if(kk < arr.size)
                {
                    if(arr[j] != arr[kk])
                        ok = 0
                }
            }
            if(ok == 1) {
                ansA += (i + 1)
            }
        }

        for(i in 0..arr[0].length-2)
        {
            var ok = 1
            for (j in 0..i)
            {
                var kk = i + (i - j) + 1
                if(kk < arr[0].length)
                {
                    for (poz in 0..arr.size-1)
                        if(arr[poz][j] != arr[poz][kk])
                            ok = 0
                }
            }
            if(ok == 1)
                ansB += (i+1)
        }
    }
    var n = 1305
    var grid = emptyArray<String>()
    for(i in 1..n)
    {
        val text2 = readln()
        if(text2.length == 0) {
            solve(grid)
            grid = emptyArray<String>()
        }
        else
            grid += text2
    }
    solve(grid)

    println(100 * ansA + ansB)
}