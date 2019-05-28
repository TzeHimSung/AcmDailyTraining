import java.util.Scanner

fun main(args:Array<String>){
    var cin=Scanner(System.`in`)
    var n=cin.nextInt()
    while (n-->0){
        var a=cin.nextInt()
        var b=cin.nextInt()
        if (a<b){
            var k=a
            a=b
            b=k
        }
        var z=1
        var y=a-b+1
        var x=a-y
        print(x)
        print(" ")
        print(y)
        print(" ")
        println(z)
    }
}