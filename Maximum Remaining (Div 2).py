n = int(input())
a = list(set(map(int,input().split())))
a.sort()
print(int(a[len(a)-2]%a[len(a)-1]))
