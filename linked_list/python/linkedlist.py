class Result():
    is_error: bool
    value: int
    def __init__(self, is_error: bool, value: int) -> None:
        self.is_error = is_error
        self.value = value

class Node:
    value = 0 
    next = None
    def __init__(self, value) -> None:
        self.value = value

class Linked:
    next = None
    def insert(self, value):
        if self.next == None:
            self.next = Node(value)
            return
        tmp = self.next
        while tmp.next != None:
            tmp = tmp.next
        tmp.next = Node(value)
    
    def insert_many(self, value: []):
        s = 0
        if self.next == None:
            self.next = Node(value[0])
            s = 1
        tmp = self.next
        for i in range(s, len(value)):
            while tmp.next != None:
                tmp = tmp.next
            tmp.next = Node(value[i])
        
    def get_index(self, index: int)-> Result:
        if self.next == None: return Result(True, -1)
        tmp = self.next
        for i in range(1, index + 1):
            if tmp.next == None:
                return Result(True, -1)
            tmp = tmp.next
        return Result(False, tmp.value)
    def pop(self):
        v = -1
        if self.next == None: return Result(True, -1)
        if self.next.next == None:
            v = self.next.value
            self.next = None
            return Result(False, v)
        tmp = self.next
        while tmp.next.next != None:
            tmp = tmp.next
        v = tmp.next.value
        tmp.next = None
        return Result(False, v)
    
    def pop_index(self, index):
        if self.next == None: return Result(True, -1)
        v = 0
        if index == 0:
            v = self.next.value
            if self.next.next != None:
                self.next = self.next.next
            else:
                self.next = None
            return Result(False, v)
        tmp: Node = self.next
        for i in range(1, index):
            if tmp.next == None:
                return Result(True, -1)
            tmp = tmp.next
        v = tmp.next.value
        if tmp.next.next != None:
            tmp.next = tmp.next.next
        else:
            tmp.next = None
        return Result(False, v)

    def set(self, index, value):
        tmp = self.next
        for i in range(index):
            if tmp.next == None: return Result(True, -1)
            tmp = tmp.next
        tmp.value = value
        return Result(False, value)

    def len(self):
        if self.next == None: return 0
        tmp = self.next
        i = 1
        while tmp.next != None:
            tmp = tmp.next
            i+=1 
        return i
    
    def show(self):
        if self.next == None:
            print("empty array")
            return
        count = 0
        v = self.get_index(0)
        while not v.is_error:
            print(f"arr[{count}] = {v.value}")
            count+=1
            v = self.get_index(count)
        