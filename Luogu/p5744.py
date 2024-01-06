class Student:
    def __init__(self, name, age, score) -> None:
        self.name = name
        self.age = int(age) + 1
        self.score = min(600, int(int(score) * 1.2))


def solve():
    student: list[Student] = []
    n = int(input())
    for i in range(n):
        a = input().split()
        student.append(Student(*a))
    for i in student:
        print(f"{i.name} {i.age} {i.score}")


solve()
