#include <iostream>
#include "HashTable.h"
using namespace std;

int main() {
    HashTable hashtable(8);

    for (int i = 0; i < 100; i++) {
        hashtable.put(i, "value" + to_string(i));
    }

    hashtable.resize(); // 扩容到足够大的尺寸

    for (int i = 0; i < 100; i++) {
        cout << hashtable.get(i) << endl;
    }

    cout << hashtable.getArrayCapacity() << endl;

    return 0;
}