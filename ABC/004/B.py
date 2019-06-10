s = [raw_input().split() for _ in range(4)]
for j in s[::-1]:
    print "{} {} {} {}".format(j[3],j[2],j[1],j[0])
