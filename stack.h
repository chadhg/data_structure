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

#endif // STACK_H
