#include <iostream>

using namespace std;

const int MaxSize = 100;        //队列的容量
template<typename T>
class CSqQueue                //循环队队列类模板
{
public:
    T *data;                //存放队中元素
    int front, rear;            //队头和队尾指针
    //队列的基本运算算法

    CSqQueue()            //构造函数
    {
        data = new T[MaxSize];    //为data分配容量为MaxSize的空间
        front = rear = 0;        //队头队尾指针置初值
    }

    ~CSqQueue()            //析构函数
    {
        delete[] data;
    }

    bool empty()        //判队空运算
    {
        return (front == rear);
    }

    bool push(T e)                //进队列运算
    {
        if ((rear + 1) % MaxSize == front)    //队满上溢出
            return false;
        rear = (rear + 1) % MaxSize;
        data[rear] = e;
        return true;
    }

    bool pop(T &e)            //出队列运算
    {
        if (front == rear)        //队空下溢出
            return false;
        front = (front + 1) % MaxSize;
        e = data[front];
        return true;
    }

    bool gethead(T &e)        //取队头运算
    {
        if (front == rear)        //队空下溢出
            return false;
        int head = (front + 1) % MaxSize;
        e = data[head];
        return true;
    }

    int getlength()        //返回队中元素个数
    {
        return (rear - front + MaxSize) % MaxSize;
    }

    bool pushk(CSqQueue<int> &qu, int k, int e) //进队第k个元素e
    {
        int x;
        int n = qu.getlength();
        if (k < 1 || k > n + 1)      //可以添加到第1 ~ n + 1的位置上
            return false;            //参数k错误返回False
        if (k <= n) {
            for (int i = 1; i <= n; i++)        //循环处理队中所有元素
            {
                if (i == k)
                    qu.push(e);        //将e元素进队到第k个位置
                qu.pop(x);            //出队元素x
                qu.push(x);            //进队元素x
            }
        } else qu.push(e);            //k=n+1时直接进队e
        return true;

    }

    bool popk(CSqQueue<int> &qu, int k, int &e)    //出队第k个元素
    {
        int x;
        int n = qu.getlength();
        if (k < 1 || k > n) return false;    //参数k错误返回false
        if (k == 1) qu.pop(e);
        else
            for (int i = 1; i <= n; i++)        //循环处理队中所有元素
            {
                qu.pop(x);            //出队元素x
                if (i != k)
                    qu.push(x);           //将非第k个元素进队
                else
                    e = x;            //取第k个出队的元素
            }
        return true;
    }


};
