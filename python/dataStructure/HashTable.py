from array import MyArray

class MyHashTable:
    def __init__(self, capacity, loadfactor=0.7):
        self.myarr = MyArray(capacity)
        self.loadfactor = loadfactor
        self.size = 0
        self.bucket = [None] * capacity
    
    def __getitem__(self, index):
        return self.myarr[index]
    
    def __setitem__(self, index, value):
        self.myarr[index] = value

    def hash_code(self, key):
        return key % self.myarr.capacity

    def put(self, key, value):
        if self.size >= self.myarr.capacity * self.loadfactor:
            self.resize()
        index = self.hash_code(key)
        if self.bucket[index] is None:
            self.bucket[index] = []
        for item in self.bucket[index]:
            if item[0] == key:
                item[1] = value
                return
        self.bucket[index].append((key, value))
        self.size += 1

    def get(self, key):
        index = self.hash_code(key)
        if self.bucket[index] is not None:
            for item in self.bucket[index]:
                if item[0] == key:
                    return item[1]
        return None

    def remove(self, key):
        index = self.hash_code(key)
        if self.bucket[index] is not None:
            for i, item in enumerate(self.bucket[index]):
                if item[0] == key:
                    del self.bucket[index][i]
                    self.size -= 1
                    break

    def resize(self):
        new_capacity = self.myarr.capacity * 2
        new_myarr = MyArray(new_capacity)
        new_bucket = [None] * new_capacity
        for bucket in self.bucket:
            if bucket is not None:
                for key, value in bucket:
                    new_index = key % new_capacity
                    if new_bucket[new_index] is None:
                        new_bucket[new_index] = []
                    new_bucket[new_index].append((key, value))
        self.myarr = new_myarr
        self.bucket = new_bucket

if __name__ == "__main__":
    myhashtable = MyHashTable(8)

    for i in range(100):
        myhashtable.put(i, f'value {i}')

    for i in range(100):
        print(myhashtable.get(i))

    print(myhashtable.myarr.capacity)
