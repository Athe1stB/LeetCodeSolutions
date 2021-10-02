from collections import OrderedDict
class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.ordered_map = OrderedDict()
        

    def get(self, key: int) -> int:
        if key in self.ordered_map:
            popped = self.ordered_map.pop(key)
            self.ordered_map[key] = popped
            return popped
        return -1
        

    def put(self, key: int, value: int) -> None:
        if key in self.ordered_map:
            self.ordered_map.pop(key)
        self.ordered_map[key] = value
        if len(self.ordered_map) > self.capacity:
            self.ordered_map.popitem(last=False)
        

