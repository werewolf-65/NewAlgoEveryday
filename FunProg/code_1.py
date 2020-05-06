import math
n=786432
count=0
x=1

sqr=math.sqrt(n)
while(sqr!=int(sqr)):
    n=n*x
    sqr=math.sqrt(n)
    x=x+1
    count=count+1

print(count)
print(sqr)
