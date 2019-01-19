#include"linear_include/hashtable.h"

int printhashtable(){
    HashTable<int> hashtable = HashTable<int>(13);  // 构建散列表
    hashtable.insertHash(66);
    hashtable.insertHash(32);
    hashtable.insertHash(98);
    hashtable.insertHash(478);
    hashtable.insertHash(11);
    hashtable.insertHash(23);
    hashtable.insertHash(43);
    hashtable.insertHash(55);
    hashtable.insertHash(67);
    hashtable.insertHash(108);
    hashtable.insertHash(230);
    hashtable.insertHash(223);
    hashtable.insertHash(10);
    cout << "表中的元素为：";
    for(int i=1; i<=13; i++)
        cout << hashtable.getData(i) << " ";
    cout << endl;
    // 查找元素55
    cout << "元素55的位置：" << hashtable.searchHash(55) << endl;
    return 0;
}
