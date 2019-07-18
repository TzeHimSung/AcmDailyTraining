import sys
 
for line in sys.stdin:
    (x, y, a, b) = line.split()
    x = int(x)
    y = int(y)
    a = int(a)
    b = int(b)
    if (x * b == a * y):
        print("=")
    elif (x * b < a * y):
        print("<")
    else:
        print(">")