from decimal import *

getcontext().prec = 1000
x = Decimal(10**9 - 1)
print(x.sqrt())