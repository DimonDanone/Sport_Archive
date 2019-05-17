def key(l):
    k = 0
    for i in l:
        if i == 0:
            k += 1
        else:
            break
    return k

def maxi(l1, l2):
    return True if key(l1) > key(l2) else False

def NOD(a, b):
    while b:
        a, b = b, a % b
    return abs(a)

def dec(v1, v2, a1, a2):
    for i in range(len(v1)):
        v2[i] = a2 * v2[i] - a1 * v1[i]


n = int(input())

v = []
delit = []

for i in range(n):
    v.append(list(map(int, input().split())))

r = 1
for i in range(n):
    minimum, pos = key(v[i]), i
    for j in range(i + 1, n):
        a = key(v[j])
        if (a < minimum):
            maximum = a
            pos = j
    if pos != i:
        v[i], v[pos] = v[pos], v[i]
        r *= -1

ok = True

for i in range(n - 1):
   if v[i][i] == 0:
       print(0)
       ok = False
       break

   for j in range(i + 1, n):
       if (v[j][i] != 0 and v[i][i] != 0):
           a = NOD(v[j][i], v[i][i])

           a = v[j][i] * v[i][i] // a

           a1 = a // v[i][i]
           a2 = a // v[j][i]
           delit.append(a2)

           dec(v[i], v[j], a1, a2)


if ok:
    ans = 1

    for i in range(n):
        ans *= v[i][i]

    for i in delit:
        ans //= i

    print(r*ans)