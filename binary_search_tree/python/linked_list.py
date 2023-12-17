class Result():
    is_error: bool
    value: int = 0

    def __init__(self, is_error: bool, value: int):
        self.is_error = is_error
        self.value = value

class Node:
    data = -1
    left = None
    right = None
    def __init__(self, data = None):
        self.data = data
        self.left = None
        self.right = None
    
class LinkList:
    head = None
    def __init__(self, data: [int] = []) -> None:
        if(len(data)):
            self.insert_many(data) 

    def __insert_node(self,n: Node, data):
        if n.data >= data:
            if n.left == None:
                n.left = Node(data)
            else:
                self.__insert_node(n.left, data) 
        else:
            if n.right == None:
                n.right = Node(data)
            else:
                self.__insert_node(n.right, data)

    def insert(self, data):
        if(self.head == None):
            self.head = Node(data)
        else:
            self.__insert_node(self.head, data) 

    def insert_many(self, data: [int]):
        start_at = 0
        if self.head == None:
            self.head = Node(data[0])
            start_at+=1
        for i in range(start_at, len(data)):
            self.__insert_node(self.head, data[i])
        
    def __get_node(self, n: Node, index: int, now_index: int) -> Result:
        v: Result
        if n.left != None:
            v = self.__get_node(n.left, index, now_index)
            if not v.is_error:
                return v
            now_index = v.value
        if index == now_index:
            return Result(False, n.data)
        now_index+=1
        if n.right != None:
            v = self.__get_node(n.right, index, now_index)
            if not v.is_error:
                return v
            now_index = v.value
        return Result(True, now_index)
    
    def get(self, index: int):
        if self.head == None:
            return Result(True, -1)
        return self.__get_node(self.head, index, 0)

    def __show_node(self, n: Node, index: int):
        if n.left != None:
           index = self.__show_node(n.left, index) 
        print(f"arr[{index}] = {n.data}")
        index+= 1
        if n.right != None:
            index = self.__show_node(n.right, index)
        return index

    def show(self):
        index = 0
        self.__show_node(self.head, index)
 