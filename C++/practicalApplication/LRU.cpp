#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class Node {
public:
    Node(string key, string value) {
        this->key = key;
        this->value = value;
        pre = nullptr;
        next = nullptr;
    }
    Node* pre;
    Node* next;
    string key;
    string value;
};

class LRUCache {
private:
    Node* head;
    Node* end;
    int limit;
    unordered_map<string, Node*> hashMap;

    void refreshNode(Node* node) {
        // 如果访问的是尾节点，则无须移动节点
        if (node == end) {
            return;
        }
        // 移除节点
        removeNode(node);
        // 重新插入节点
        addNode(node);
    }

    string removeNode(Node* node) {
        if (node == head && node == end) {
            // 移除唯一的节点
            head = nullptr;
            end = nullptr;
        } else if (node == end) {
            // 移除尾节点
            end = end->pre;
            end->next = nullptr;
        } else if (node == head) {
            // 移除头节点
            head = head->next;
            head->pre = nullptr;
        } else {
            // 移除中间节点
            node->pre->next = node->next;
            node->next->pre = node->pre;
        }
        delete node;
        return node->key;
    }

    void addNode(Node* node) {
        if (end != nullptr) {
            end->next = node;
            node->pre = end;
            node->next = nullptr;
        }
        end = node;
        if (head == nullptr) {
            head = node;
        }
    }

public:
    LRUCache(int limit) {
        this->limit = limit;
        head = nullptr;
        end = nullptr;
        hashMap.clear();
    }

    string get(string key) {
        auto iter = hashMap.find(key);
        if (iter == hashMap.end()) {
            //缓存中不存在该key
            return "找不到该用户";
        }
        Node* node = iter->second;
        refreshNode(node);
        return node->value;
    }

    void put(string key, string value) {
        auto iter = hashMap.find(key);
        if (iter == hashMap.end()) {
            // 如果key不存在，则插入Key-Value
            if (hashMap.size() >= limit) {
                string oldkey = removeNode(head);
                hashMap.erase(oldkey);
            }
            Node* node = new Node(key, value);
            addNode(node);
            hashMap[key] = node;
        } else {
            // 如果key存在，则刷新key-value
            Node* node = iter->second;
            node->value = value;
            refreshNode(node);
        }
    }

    void remove(string key) {
        auto iter = hashMap.find(key);
        if (iter != hashMap.end()) {
            Node* node = iter->second;
            removeNode(node);
            hashMap.erase(iter);
        }
    }
};

int main() {
    LRUCache lruCache(5);
    lruCache.put("001", "用户1信息");
    lruCache.put("002", "用户2信息");
    lruCache.put("003", "用户3信息");
    lruCache.put("004", "用户4信息");
    lruCache.put("005", "用户5信息");
    cout << lruCache.get("002") << endl;
    lruCache.put("004", "用户4信息更新");
    lruCache.put("006", "用户6信息");
    cout << lruCache.get("001") << endl;
    cout << lruCache.get("006") << endl;

    return 0;
}
