//
// Created by 朱俊杰 on 2022/10/12.
//

bool isMatch(string str)        //判断表达式各种括号是否匹配的算法
{
    SqStack<char> st;            //建立一个顺序栈
    int i = 0;
    char e;
    while (i < str.length()) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            st.push(str[i]);    //遇到将左括号,均进栈
        else {
            if (str[i] == ')')        //遇到')'
            {
                if (st.empty())        //栈空时返回false
                    return false;
                st.pop(e);            //出栈元素e
                if (e != '(')        //栈顶不是匹配的'(',返回false
                    return false;
            }
            if (str[i] == ']')        //遇到']'
            {
                if (st.empty())        //栈空时返回false
                    return false;
                st.pop(e);            //出栈元素e
                if (e != '[')        //栈顶不是匹配的'[',返回false
                    return false;
            }
            if (str[i] == '}')        //遇到'}'
            {
                if (st.empty())        //栈空时返回false
                    return false;
                st.pop(e);            //出栈元素e
                if (e != '{')        //栈顶不是匹配的'{',返回false
                    return false;
            }
        }
        i++;                //继续遍历str
    }
    return st.empty();
}

