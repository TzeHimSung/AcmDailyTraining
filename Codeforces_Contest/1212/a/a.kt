// Think twice, code once.
// Author: JHSeng

import kotlin.math.*;

private fun readln() = readLine()!!
private fun readint() = readln().toInt()
private fun readString() = readln().split(" ")
private fun readints() = readString().map{it.toInt()}

fun main(){
	var (n,m) = readints()
	while(m-->0){
		if (n%10!=0)
			n--
		else
			n/=10
	}
	println(n)
}
