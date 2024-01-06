def solve():
    s = input()
    if "." in s:
        s = s.split(".")
        print(
            f"{int(s[0][::-1])}.{s[1][::-1].rstrip('0') if s[1][::-1].rstrip('0') else '0'}"
        )
    elif "/" in s:
        s = s.split("/")
        print(f"{int(s[0][::-1])}/{int(s[1][::-1])}")
    elif "%" in s:
        print(str(int(s.strip("%")[::-1])) + "%")
    else:
        print(int(s[::-1]))


solve()
