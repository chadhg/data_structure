#include"linear_include/queue.h"
#include"linear_include/queue_eg1.h"

int printQueue(){
    Queue<int> queue = Queue<int>(6);
    for(int i = 0; i < 6; i++){
        queue.insert(i*3);
    }
    for(int i = 0; i < 6; i++){
        int temp = queue.delElement();
        cout << temp << " ";
    }
    cout << endl;
    return 0;
}

int StackQueue(){
    QueueFromStack<int> qs(12);
    cout << "入队元素：" << endl;
    for(int i = 1; i <= 12; i++){
        cout << i*i << " ";
        qs.push(i*i);
    }
    cout << endl;
    cout << "出对元素：" << endl;
    for(int i = 1; i <= 12; i++){
        cout << qs.pop() << " ";
    }
    cout << endl;
    return 0;
}
