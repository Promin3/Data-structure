#include <iostream>
const int MaxSize = 100;
template<typename T>
class queue {
    T *data;
    int front, rear;
    bool tag;

    queue() {
        front = rear = 0;
        tag = 0;
    }

    bool QueueEmpty() {
        if (front == rear && tag == 0)
            return true;
        else
            return false;
    }

    bool QueueFull(){
        if(front == rear && tag == 1)
            return true;
        else
            return false;
    }

    bool push(T x){
        if(QueueFull() == 1)
            return false;
        rear = (rear+1)%MaxSize;
        data[rear] = x;
        tag = 1;
        return true;
    }

    bool pop(T &e){
        if(QueueEmpty() == 1){
            return false;
        }
        front = (front + 1) % MaxSize;
        e = data[front];
        tag = 0;
        return true;
    }

};
