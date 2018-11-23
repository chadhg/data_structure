/*
* 顺序表
*/

#ifndef SEQLIST_H
#define SEQLIST_H

#include<iostream>

using namespace std;

template<typename DataType> class SeqList
{
public:
    // 构造函数
    SeqList(int size=defaultSize){
        if(size > 0){
            maxSize = size;
            length = 0;
            elements = new DataType[maxSize];   // 分配内存大小
            for(int i=0; i<maxSize; i++)
                elements[i] = 0;
        }
    }
    ~SeqList(){
        delete [] elements;     // 回收内存空间
    }

    bool insertElement(DataType data);      // 向表尾插入新元素
    bool deleteElement(int location);       // 删除指定位置的元素
    DataType getElement(int location);      // 返回指定位置的元素
    bool changeElement(int location, DataType newData);     // 修改指定位置的元素值
    int getLength(){            // 获取顺序表长度
        return length;
    }

private:
    static const int defaultSize = 10;
    DataType *elements;
    int maxSize;
    int length;
};

// 函数实现
template <typename DataType> bool SeqList<DataType>::insertElement(DataType data)
{
    // 顺序表插入操作
    int currentIndex = length;
    if(length >= maxSize){
        cout << "顺序表已满，插入失败！" << endl;
        return false;
    }
    else {
        elements[currentIndex] = data;  // 将新元素插入顺序表的结尾
        length++;                       // 顺序表有效长度+1
        return true;
    }
}

template <typename DataType> DataType SeqList<DataType>::getElement(int location)
{
    // 获取指定位置的元素
    if(location < 0 || location >= length){
        cout << "参数无效！" << endl;
        return 0;
    }
    else {
        return elements[location];
    }
}

template <typename DataType> bool SeqList<DataType>::deleteElement(int location)
{
    // 删除指定位置的元素
    if(location < 0 || location >= length){
        cout << "参数无效！" << endl;
        return false;
    }
    else {
        for(int i=location; i < length; i++){
            elements[i] = elements[i+1];        // 将指定位置之后的元素依次往前移动覆盖前一个元素
        }
        length--;
        return true;
    }
}

template <typename DataType> bool SeqList<DataType>::changeElement(int location, DataType newData)
{
    // 修改指定位置的元素
    if(location < 0 || location >= length){
        cout << "参数无效！" << endl;
        return false;
    }
    else {
        elements[location] = newData;
        return true;
    }
}

#endif // SEQLIST_H
