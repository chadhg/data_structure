#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>
using namespace std;

template<typename DataType> class Queue{
public:
    Queue(int size){
        maxSize = size;     // 初始化最大容量
        front = 0;
        rear = 0;
        count = 0;
        elements = new DataType[size];
        if(elements == NULL)
            exit(1);
    }
    ~Queue(){
        delete [] elements;
    }
    bool insert(DataType data);
    DataType delElement();
private:
    int maxSize;            // 队列最大容量
    int count;              // 元素个数
    int front;              // 对首
    int rear;               // 对尾
    DataType *elements;     // 数据指针
};

template<typename DataType> bool Queue<DataType>::insert(DataType data){
    if(count == maxSize)
        return false;
    elements[rear] = data;
    rear = (rear+1)%maxSize;
    count++;
    return true;
}
template<typename DataType> DataType Queue<DataType>::delElement(){
    if(count == 0)
        exit(1);
    DataType temp = elements[front];
    front = (front+1)%maxSize;
    count--;
    return temp;
}

#endif // QUEUE_H
