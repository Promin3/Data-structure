#include<iostream>
using namespace std;

const int initcap = 5;
template <typename T>
class SqList {
public:
    T* data;
    int capacity;
    int lenth;
    SqList();
    SqList(const SqList <T>& s);
    ~SqList();
    void recap(int newcap);
    void Createlist(T a[], int n);
    void add(T e);
    int getlenth();
    bool GetElem(int i, T& e);
    bool setElem(int i, T e);
    int GetNo(T e);
    bool insert(int i, T e);
    bool Delete(int i);
    void display();
    void delete_x(SqList<T>& s,int x);
};

//创建空顺序表
template<typename T>
SqList<T>::SqList()
{
    capacity = initcap;
    data = new T[initcap];
    lenth = 0;
}

//创建并且复制顺序表
template<typename T>
SqList<T>::SqList(const SqList<T>& s)
{
    capacity = s.capacity;
    lenth = s.lenth;
    data = new T[capacity];
    for (int i = 0; i < lenth; i++)
    {
        data[i] = s.data[i];
    }
}


template<typename T>
SqList<T>::~SqList()
{
    delete[] data;
}

template<typename T>
void SqList<T>::recap(int newcap)
{
    if (newcap <= 0) return;
    T* olddata = data;
    data = new T[newcap];
    capacity = newcap;
    for (int i = 0; i < lenth; i++)
    {
        data[i] = olddata[i];
    }
    delete[] olddata;
}

// 用一个已知长度数组创建顺序表,前提是该顺序表已经使用默认构造方法创建
template<typename T>
void SqList<T>::Createlist(T a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (capacity == lenth)
            recap(2 * lenth);
        data[lenth] = a[i];
        lenth++;
    }
}

template<typename T>
void SqList<T>::add(T e)
{
    if (lenth == capacity)
        recap(2 * lenth);
    data[lenth] = e;
    lenth++;//可能出现add后lenth = capacity,capacity未扩容的情况
}

template<typename T>
int SqList<T>::getlenth()
{
    return lenth;
}

template<typename T>
bool SqList<T>::GetElem(int i, T& e)
{
    if (i < 0 || i >= lenth) {
        return false;
    }
    e = data[i];
    return true;
}

template<typename T>
bool SqList<T>::setElem(int i, T e)
{
    if (i < 0 || i >= lenth)
        return false;
    data[i] = e;
    return true;
}

template<typename T>
int SqList<T>::GetNo(T e)
{
    int i=0;
    while (i < lenth && data[i] != e)
        i++;
    if (i >= lenth)
        return -1;
    else
        return i;
}

template<typename T>
bool SqList<T>::insert(int i, T e)
{
    if (i< 0 || i>lenth)
        return false;
    if (lenth == capacity)
        recap(2 * lenth);
    for (int k = lenth; k > i; k--) {
        data[k] = data[k - 1];
    }
    data[i] = e;
    lenth++;
    return true;
}

template<typename T>
bool SqList<T>::Delete(int i)
{
    if (i < 0 || i >= lenth)
        return false;
    for (int j = i; j < lenth - 1; j++)
    {
        data[j] = data[j + 1];
    }
    lenth--;
    if (capacity > initcap && lenth <= capacity / 4)
        recap(capacity / 2);
    return true;
}

template<typename T>
void SqList<T>::display()
{
    for (int i = 0; i < lenth; i++)
    {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

template<typename T>
void SqList<T>::delete_x(SqList<T>& s, int x)// 删除顺序表中的元素x,时间复杂度O(n),空间复杂度O(1)
{
    int k = 0;
    for (int i = 0; i < lenth; i++)
    {
        if (s.data[i] != x) {
            s.data[k] = s.data[i];
            k++;
        }
    }
    s.lenth = k;
}




int main()
{
    int i, e;
    SqList<int> L;  //建立类型为int的顺序表对象L
    cout << "创建整数顺序表L" << endl;
    L.insert(0, 2);	//插入元素2
    L.insert(1, 3);	//插入元素3
    L.insert(2, 1);	//插入元素1
    L.insert(3, 5);	//插入元素5
    L.insert(4, 4);	//插入元素4
    L.insert(5, 1);	//插入元素1
    L.add(8);		//添加整数8 
    cout << "顺序表L:"; L.display();
    cout << "长度:" << L.lenth << "  容量:"
        << L.capacity << endl;
    i = 3; L.GetElem(i, e);
    cout << "序号为" << i << "的元素:" << e << endl;

}
