import sys
import random
sys.setrecursionlimit(10000)

from linked_list import LinkList
           
arr = LinkList()
for i in range(100):
    arr.insert(random.randrange(0, 100))
arr.show()

print("---------------------------")

for i in range(10):
    a = arr.get(i)
    if not a.is_error:
        print(f"arr[{i}] = {a.value}")
    else:
        print("out of range")