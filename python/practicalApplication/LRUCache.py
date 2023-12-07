class LRUCache:
    def __init__(self, limit):
        self.head = None
        self.end = None
        self.limit = limit
        self.hashmap = {}

    def get(self, key):
        node = self.hashmap.get(key)
        if node is None:
            return None
        self.refreshNode(node)
        return node.value

    def put(self, key, value):
        node = self.hashmap.get(key)
        if node is None:
            # 如果key不存在，则插入key-value
            if len(self.hashmap) >= self.limit:
                old_key = self.removeNode(self.head)
                del self.hashmap[old_key]
            new_node = Node(key, value)
            self.addNode(new_node)
            self.hashmap[key] = new_node
        else:
            # 如果key存在，则刷新key-value
            node.value = value
            self.refreshNode(node)

    def remove(self, key):
        node = self.hashmap.get(key)
        self.removeNode(node)
        del self.hashmap[key]

    # 刷新被访问的节点位置
    def refreshNode(self, node):
        # 如果访问的是尾节点，则无须移动节点
        if node == self.end:
            return
        # 移除节点
        self.removeNode(node)
        # 重新插入节点
        self.addNode(node)

    # 删除节点
    def removeNode(self, node):
        if node == self.head and node == self.end:
            # 移除唯一的节点
            self.head = None
            self.end = None
        elif node == self.end:
            # 移除尾节点
            self.end = self.end.pre
            self.end.next = None
        elif node == self.head:
            # 移除头节点
            self.head = self.head.next
            self.head.pre = None
        else:
            # 移除中间节点
            node.pre.next = node.next
            node.next.pre = node.pre
        return node.key

    # 尾部插入节点
    def addNode(self, node):
        if self.end is not None:
            self.end.next = node
            node.pre = self.end
            node.next = None
        self.end = node
        if self.head is None:
            self.head = node


class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value


if __name__ == "__main__":
    lrucache = LRUCache(5)
    lrucache.put("001", "用户1信息")
    lrucache.put("002", "用户2信息")
    lrucache.put("003", "用户3信息")
    lrucache.put("004", "用户4信息")
    lrucache.put("005", "用户5信息")
    lrucache.get("002")
    lrucache.put("004", "用户4信息更新")
    lrucache.put("006", "用户6信息")
    print(lrucache.get("001"))
    print(lrucache.get("006"))
