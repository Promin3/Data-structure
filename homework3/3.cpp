//
// Created by 朱俊杰 on 2022/10/12.
//
const int maxsize = 100;

template<typename T>
class CSqQueue_size {
public:
    T *data;
    int rear;
    int size;

    // 初始化算法
    CSqQueue_size() {
        data = new T[maxsize];
        rear = 0;
    }

    // 入队算法
    bool push(T e) {
        if (size == maxsize - 1) return false;//循环队列中有一位不存值，用来判断是否队满
        else {
            rear = (rear + 1) % maxsize;
            data[rear] = e;
            size++;
            return true;
        }
    }

    //出队算法
    bool pop(T &e) {
        if (size == 0) return false;
        else {
            int head = (rear - size + maxsize) % maxsize;
            head ++;
            e = data[head];
            return true;
        }
    }

    //判空算法
    bool empty() {
        return size == 0;
    }
};
