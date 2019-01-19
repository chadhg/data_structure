#ifndef HASHTABLE_H
#define HASHTABLE_H
/*
 * 散列表
 */

#include<iostream>
using namespace std;

template<typename DataType> class HashTable{
public:
    HashTable(int size){
        maxSize = size;
        count = 0;
        elements = new DataType[size];
        if(elements == NULL)
            exit(1);
        for(int i=0; i<size; i++)
            elements[i] = 0;    // = NULL
    }
    ~HashTable(){
        delete [] elements;
    }
    int hash(DataType value);   // 散列函数
    int searchHash(DataType value); // 查找函数，返回查找元素的地址
    DataType getData(int i){
        // 返回散列表第i个元素的值
        if(i<=0)
            cout << "索引值无效！" << endl;
        return elements[i-1];
    }
    bool insertHash(DataType value);
private:
    int maxSize;            // 最大容量
    int count;              // 当前元素数
    DataType *elements;     // 数据指针
};

template<typename DataType> int HashTable<DataType>::hash(DataType value){
    return value % 13;      // 采用除留余法计算散列地址
}
template<typename DataType> int HashTable<DataType>::searchHash(DataType value){
    int p = hash(value);    // 计算地址
    if(elements[p] == value)        // 如果相等，没有发生冲突，返回p
        return p;
    int rp = (p+1) % maxSize;       // 线性探测法处理冲突，选取d=1
    while(rp != p){
        if(elements[rp] == value)   // 如果新地址的值与value相等，返回新地址
            return rp;
        if(!elements[rp])    // 找到空白地址
            break;
        rp = (rp+1) % maxSize;      // 循环使用线性探测法找空白地址
    }
    if(rp == p)
        return -2;
    else{
        // elements[rp] = value;    // 在空白地址上插入此元素并返回地址
        return rp;
    }
}
template<typename DataType> bool HashTable<DataType>::insertHash(DataType value){
    int pos = searchHash(value);    // 查找指定元素，看看散列表中是否已经存在
    if(pos<0)
        return false;
    else if (elements[pos] == value) {  // 有重复元素
        cout << "重复的元素！" << endl;
        return false;
    }
    else {                          // 在空白地址插入元素
        elements[pos] = value;
        return true;
    }
}
#endif // HASHTABLE_H
