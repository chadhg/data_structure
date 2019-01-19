#include<iostream>
#include"linear_include/stack_init.h"
#include"linear_include/stack_eg1.h"
using namespace std;

/*
 * 有一个整数集合{23, 56, 11, 4, 87, 98}，将他们依次输入，要求输出的顺序为11,4,56,98,87,23
*/
int printStack(){
    Stack<int> s = Stack<int>(6);
    int temp = 0;
    s.push(23);
    s.push(56);
    s.push(11);
    temp = s.pop();
    cout << temp << " ";
    s.push(4);
    temp = s.pop();
    cout << temp << " ";
    temp = s.pop();
    cout << temp << " ";
    s.push(87);
    s.push(98);
    temp = s.pop();
    cout << temp << " ";
    temp = s.pop();
    cout << temp << " ";
    temp = s.pop();
    cout << temp << " ";
    return 0;
}

/*
 * 输出最小值
 */
int Stack_Eg1(){
    Stack_eg1<int> stack;
    int b[]={6, 8, 15, 2, 3, 1, 2};
    for(int i=0; i<7; i++){
        cout << "入栈值：" << b[i] << " ";
        stack.push(b[i]);
        cout << "当前最小值min：" << stack.min() << endl;
    }
    cout << "出栈情况：" << endl;
    while (!stack.isEmpty()) {
        cout << "出栈值：" << " ";
        stack.printValue();
        cout << "当前最小值min：" << stack.min() << endl;
        stack.pop();
    }
    return 0;
}
