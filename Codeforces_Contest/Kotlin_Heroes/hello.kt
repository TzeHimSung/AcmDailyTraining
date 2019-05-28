import java.util.Scanner

fun main(args:Array<String>){
    var cin=Scanner(System.`in`)
    var y=cin.nextInt()
    var b=cin.nextInt()
    var r=cin.nextInt()
    var minn=minOf(y,b,r)
    var ans:Int
    if (minn==r) ans=3*(r-1)
    else if (minn==b) ans=3*b
    else if (r>=y+2) ans=3*(y+1)
    else ans=3*y
    println(ans)
}