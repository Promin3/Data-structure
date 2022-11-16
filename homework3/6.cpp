//
// Created by 朱俊杰 on 2022/10/12.
//
#include "iostream"

const int MaxSize = 100;

template<typename T>
class SqStack            //顺序栈类模板
{
public:
    T *data;            //存放栈中元素
    int top;            //栈顶指针
    int MaxSize;
    //栈的基本运算算法

    SqStack()            //构造函数
    {
        data = new T[MaxSize];    //为data分配容量为MaxSize的空间
        top = -1;            //栈顶指针初始化
    }

    ~SqStack()            //析构函数
    {
        delete[] data;
    }

    bool empty()            //判断栈是否为空
    {
        return top == -1;
    }

    bool push(T e)            //进栈算法
    {
        if (top == MaxSize - 1)    //栈满时返回false
            return false;
        top++;            //栈顶指针增1
        data[top] = e;        //将e进栈
        return true;
    }

    bool pop(T &e)            //出栈算法
    {
        if (empty())        //栈为空的情况，即栈下溢出
            return false;
        e = data[top];        //取栈顶指针元素的元素
        top--;            //栈顶指针减1
        return true;
    }

    bool gettop(T &e)        //取栈顶元素算法
    {
        if (empty())        //栈为空的情况，即栈下溢出
            return false;
        e = data[top];        //取栈顶指针位置的元素
        return true;
    }

};

template<typename T>
class SqQueue                //非循环队队列类模板
{
public:
    T *data;                //存放队中元素
    int front, rear;            //队头和队尾指针
    //队列的基本运算算法
    SqQueue()            //构造函数
    {
        data = new T[MaxSize];    //为data分配容量为MaxSize的空间
        front = rear = -1;        //队头队尾指针置初值
    }

    ~SqQueue()            //析构函数
    {
        delete[] data;
    }

    bool empty()        //判队空运算
    {
        return front == rear;
    }

    bool push(T e)                //进队列运算
    {
        if (rear == MaxSize - 1)        //队满上溢出
            return false;
        rear++;
        data[rear] = e;
        return true;
    }

    bool pop(T &e)            //出队列运算
    {
        if (front == rear)        //队空下溢出
            return false;
        front++;
        e = data[front];
        return true;
    }

    bool gethead(T &e)        //取队头运算
    {
        if (front == rear)        //队空下溢出
            return false;
        int head = front + 1;
        e = data[head];
        return true;
    }
};

void function() {
    int i, n, x;
    SqStack<int> Stack;
    int top = -1;
    SqQueue<int> Queue;
    int front = 0, rear = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("第%d个车皮编号：", i + 1);
        scanf("%d", &x);
        if (x % 2 == 1) {
            Queue.data[rear] = x;
            printf(" %d进队\n", x);
            rear++;
        } else {
            top++;
            Stack.data[top] = x;
            printf("%d进栈\n", x);
        }
    }
    printf("出轨操作：\n ");
    while (front != rear) {
        printf("%d出队", Queue.data[front]);
        front++;
    }
    while (top >= 0) {
        printf("%d出栈", Stack.data[top]);
        top--;
    }
    printf("\n");
}
