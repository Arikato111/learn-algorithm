import random
import datetime
from quick_sort import quick_sort

ARR_LEN = 2_000_000
arr = [None] * ARR_LEN
for i in range(ARR_LEN):
    arr[i] = random.randint(0, 255)

s1 = (datetime.datetime.now())
quick_sort(arr)
s2 = (datetime.datetime.now())
print(s2 - s1)
# print(arr)