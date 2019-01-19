#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

template<typename DataType> class Stack
{
public:
    Stack(int size){
        maxSize = size;
        top = -1;       // top=-1是为空栈
        elements = new DataType[size];
    }
    ~Stack(){
        delete [] elements;
    }
    bool push(DataType data);   // 入栈操作
    DataType pop();             // 出栈操作
    bool isEmpty();             // 栈判空
    int eleNumber();            // 获取元素数
private:
    DataType *elements;
    int top;
    int maxSize;
};

template<typename DataType> bool Stack<DataType>::push(DataType data){
    if(top == maxSize)
        return false;
    elements[++top] = data;
    return true;
}
template<typename DataType> DataType Stack<DataType>::pop(){
    if(top == -1){
        cout << "empty stack!" << endl;
        exit(1);
    }
    return elements[top--];
}
template<typename DataType> bool Stack<DataType>::isEmpty(){
    if(top == -1)
        return true;
    else
        return false;
}
template<typename DataType> int Stack<DataType>::eleNumber(){
    if(top >= 0)
        return top+1;
    else
        return 0;
}
#endif // STACK_H
