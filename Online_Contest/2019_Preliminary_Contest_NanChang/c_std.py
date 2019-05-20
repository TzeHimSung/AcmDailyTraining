

def mul(a, b):
	return [a[0]*b[0]+a[1]*b[2], a[0]*b[1]+a[1]*b[3], a[2]*b[0]+a[3]*b[2], a[2]*b[1]+a[3]*b[3]]

f=[[1,1,1,0]]

for i in range(1,22):
	f.append(mul(f[i-1],f[i-1]))
	"""
	if(f[i][0]+f[i][2]>=10**100000):
		print(i)
		break
	"""

fib=[0,1,1]
for i in range(3,35):
	fib.append(fib[i-1]+fib[i-2])

def cal(n):
	if(n<=2):
		return 1
	n-=2
	ans = [1,0,0,1]
	for i in range(0,35):
		if((n>>i)==0):
			break
		if((n>>i)&1):
			ans=mul(ans,f[i])
	return ans[0]+ans[2]

F=[0]

for i in range(1,35):
	F.append(cal(fib[i]))
	if(F[i]>=10**100000):
		break

sz = len(F)

T = int(input())

def Print(ans):
	cnt = len(ans)
	for i in range(cnt-1,-1,-1):
		print(ans[i],end='')
		if(i>0):
			print(' ',end='')
	print()	

while T>0:
	T-=1
	n = int(input())
	ans = []
	for i in range(sz-1,0,-1):
		if(n==0):
			break
		if(n==3):
			if(i<3):
				break
			ans.append(3)
			ans.append(2)
			ans.append(1)
			n=0
			break		
		if(n==2):
			if(i<2):
				break
			ans.append(2)
			ans.append(1)
			n=0
			break
		if(n==1):
			ans.append(1)
			n=0
			break
		if(n==5):
			if(i<4):
				break
			ans.append(4)
			ans.append(3)
			ans.append(2)
			ans.append(1)
			n=0
			break
		if(n>=F[i]):
			ans.append(i)
			n-=F[i]
	if(n!=0):
		print(-1)
		continue
	Print(ans)