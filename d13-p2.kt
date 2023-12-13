import java.util.Scanner
fun main(args: Array<String>){
    val input = Scanner(System.`in`)

    var ansA = 0
    var ansB = 0
    var xA = -1
    var xB = -1
    fun solve(arr: Array<String>)
    {
        xA = -1
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
                xA = (i + 1)
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
                xB = (i+1)
        }
        var found = 0
        for (p in 0..arr.size-1)
            for (q in 0..arr[p].length-1) {
                var xxA = -1
                var xxB = -1
                val chars = arr[p].toCharArray()
                if (arr[p][q] == '.') {
                    chars[q] = '#'
                    arr[p] = String(chars)
                }
                else
                {
                    chars[q] = '.'
                    arr[p] = String(chars)
                }
                for (i in 0..arr.size - 2) {
                    var ok = 1
                    for (j in 0..i) {
                        var kk = i + (i - j) + 1
                        if (kk < arr.size) {
                            if (arr[j] != arr[kk])
                                ok = 0
                        }
                    }
                    if (ok == 1) {
                        xxA = (i + 1)
                    }
                }
                for (i in 0..arr[0].length - 2) {
                    var ok = 1
                    for (j in 0..i) {
                        var kk = i + (i - j) + 1
                        if (kk < arr[0].length) {
                            for (poz in 0..arr.size - 1)
                                if (arr[poz][j] != arr[poz][kk])
                                    ok = 0
                        }
                    }
                    if (ok == 1)
                        xxB = (i + 1)
                }
                if (arr[p][q] == '.') {
                    chars[q] = '#'
                    arr[p] = String(chars)
                }
                else
                {
                    chars[q] = '.'
                    arr[p] = String(chars)
                }

                if(found == 0) {
                    if(xxA == -1)
                    {
                        if (xxB != -1 && xxB != xB) {
                            ansB += xxB
                            found = 1
                        }
                    }
                    else {
                        if (xxA != xA) {
                            ansA += xxA
                            found = 1
                        }
                    }
                }
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