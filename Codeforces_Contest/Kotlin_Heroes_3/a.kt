fun readint()=readLine()!!.toInt()
fun readll()=readLine()!!.toLong()
fun readline_int()=(readLine()!!.split(" ").map{it.toInt()}).toIntArray()
fun readline_ll()=(readLine()!!.split(" ").map{it.toLong()}).toLongArray()
data class pair(var first:Int, var second:Int)

fun main() {
	var t = readint()
	for (cnt in 0 until t){
		var curr=readint()
		if (0<=curr && curr<1000){
			println("%d".format(curr))
		} else if (1000<=curr && curr<1000000){
			var remain=curr%1000;
			if (remain<500) {
				println("%dK".format(curr/1000))
			} else{
				var tmp=curr/1000+1
				if (tmp==1000) {
					println("1M")
				} else{
					println("%dK".format(curr/1000+1))
				}
			}
		} else{
			var remain=curr%1000000
			if (remain<500000){
				println("%dM".format(curr/1000000))
			} else{
				println("%dM".format(curr/1000000+1))
			}
		}
	}
}