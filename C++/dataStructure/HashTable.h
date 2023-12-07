#ifndef _HASHTABLE_H
#define _HASHTABLE_H

#include <iostream>
#include <vector>
using namespace std;

class Array {
private:
    vector<string> data;
    int capacity;

public:
    Array(int capacity) {
        this->capacity = capacity;
        data.resize(capacity);
    }

    string& operator[](int index) {
        return data[index];
    }

    int getCapacity() const {
        return capacity;
    }
};

class HashTable {
private:
    Array array;
    double loadfactor;
    int size;
    vector<vector<pair<int, string>>> bucket;

public:
    HashTable(int capacity, double loadfactor = 0.7)
        : array(capacity), loadfactor(loadfactor), size(0), bucket(capacity) {

    }

    string& operator[](int index) {
        return array[index];
    }

    int HashCode(int key) {
        return key % array.getCapacity();
    }

    int getArrayCapacity() const {
        return array.getCapacity();
    }

    void put(int key, const string& value) {
        if (size >= array.getCapacity() * loadfactor) {
            resize();
        }
        int index = HashCode(key);
        if (bucket[index].empty()) {
            bucket[index] = vector<pair<int, string>>();
        }
        for (auto& item : bucket[index]) {
            if (item.first == key) {
                item.second = value;
                return;
            }
        }
        bucket[index].push_back(make_pair(key, value));
        size++;
    }

    string get(int key) {
        int index = HashCode(key);
        if (!bucket[index].empty()) {
            for (auto& item : bucket[index]) {
                if (item.first == key) {
                    return item.second;
                }
            }
        }
        return "";
    }

    void remove(int key) {
        int index = HashCode(key);
        if (!bucket[index].empty()) {
            for (int i = 0; i < bucket[index].size(); i++) {
                if (bucket[index][i].first == key) {
                    bucket[index].erase(bucket[index].begin() + i);
                    size--;
                    break;
                }
            }
        }
    }

    void resize() {
        int new_capacity = array.getCapacity() * 2;
        Array new_array(new_capacity);
        vector<vector<pair<int, string>>> new_bucket(new_capacity);
        for (auto& items : bucket) {
            if (!items.empty()) {
                for (auto& item : items) {
                    int new_index = HashCode(item.first) % new_capacity;
                    if (new_bucket[new_index].empty()) {
                        new_bucket[new_index] = vector<pair<int, string>>();
                    }
                    new_bucket[new_index].push_back(item);
                }
            }
        }
        array = new_array;
        bucket = new_bucket;
    }
};
#endif