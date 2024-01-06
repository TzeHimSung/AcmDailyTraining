from operator import add, sub, mul

last_op = ""
op_dict = {"a": "+", "b": "-", "c": "*"}
op_func_dict = {"a": add, "b": sub, "c": mul}


def gen(x, y, op):
    exp = f"{x}{op_dict[op]}{y}={op_func_dict[op](x,y)}"
    print(exp)
    print(len(exp))


def solve():
    global last_op
    s = input().split()
    if len(s) == 2:
        gen(int(s[0]), int(s[1]), last_op)
    else:
        last_op = s[0]
        gen(int(s[1]), int(s[2]), s[0])


t = int(input())
while t > 0:
    solve()
    t -= 1
