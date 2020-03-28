#include<iostream>
#include<cstring>
#include<cctype>


class myString
{
public :
    explicit myString(const char *pn = nullptr);
    myString(const myString &S);
    ~myString();
    friend std::ostream &operator<<(std::ostream &os, const myString &S);// 输出字符串整体和长度
    friend std::istream &operator>>(std::istream &is, myString &S);
    char &operator[](int i);  // 返回字符串中的下标为i的字符，注意i 的有效性
    void toUpper();   //转化为大写字符串
    myString &operator=(const myString &S);
    myString &operator=(const char *S);
    bool operator==(const myString& s);   //比较字符串
    myString operator+(const myString &S);
    myString operator()(int begin, int end);
private:
    char *pStr ;    // 指向存储字符串的空间 new char[size+1]
    int size ;      //包含字符的数目
};

myString::myString(const char *pn)
{
    if(pn)
    {
        pStr = new char[strlen(pn) + 1];
        strcpy(pStr, pn);
        size = strlen(pn);
    }
    else
    {
        pStr = new char[1];
        *pStr = 0;
        size = 0;
    }
}

myString::myString(const myString &S)
{
    size = S.size;
    pStr = new char[size + 1];
    strcpy(pStr, S.pStr);
}

myString::~myString()
{
    if(*pStr)
    {
        delete[] pStr;
    }
}

std::ostream &operator<<(std::ostream &os, const myString &S)
{
    os << S.pStr;
    return os;
}

std::istream &operator>>(std::istream &is, myString &S)
{
    delete[] S.pStr;
    S.pStr = new char[1];
    S.pStr[0] = 0;
    char tmp;
    is.get(tmp);
    while(tmp != '\n')
    {
        char a[] = {tmp, '\0'};
        S = S + myString(a);
        is.get(tmp);
    }
    return is;
}

myString &myString::operator=(const myString &S)
{
    if(this == &S);
    else
    {
        size = S.size;
        delete[] pStr;
        pStr = new char[size + 1];
        strcpy(pStr, S.pStr);
    }
    return *this;
}

myString &myString::operator=(const char *S)
{
    if(S)
    {
        size = strlen(S);
        delete[] pStr;
        pStr = new char[size + 1];
        strcpy(pStr, S);
    }
    else
    {
        delete[] pStr;
        pStr = new char[1];
        *pStr = 0;
    }
    return *this;
}

char &myString::operator[](int i)
{
    if(i < size)
        return pStr[i];
    else
    {
        std::cerr << "Subscript error: The parameter i can't larger than size" << std::endl;
        return pStr[size];
    }
}

void myString::toUpper()
{
    for(char *p = pStr;*p;p++)
        if(islower(*p))
            *p += 32;
}

bool myString::operator==(const myString& s)
{
    return !strcmp(pStr, s.pStr);
}

myString myString::operator+(const myString &S)
{
    myString tmp(S.pStr);
    delete[] tmp.pStr;
    tmp.pStr = new char[size + S.size + 1];
    tmp.size = size + S.size;
    char *pt = tmp.pStr, *ps = pStr;
    while(*ps)
    {
        *pt = *ps;
        ++pt;
        ++ps;
    }
    ps = S.pStr;
    strcpy(pt, ps);
    return tmp;
}

myString myString::operator()(int begin, int end)
{
    char tmp[end - begin + 2];
    int i, j;
    for(i = begin, j = 0;i <= end;i++, j++)
    {
        tmp[j] = this->pStr[i];
    }
    tmp[j] = 0;
    return myString(tmp);
}


int main()
{
    myString s2, s1("HELLO");
    std::cout<< s1[0] <<std::endl; //输出H
    std::cout << s2 << std::endl;
    s2 = "Hello world";
    std::cout << s2 << std::endl;  //输出“Hello world”
    s1.toUpper();
    std::cout << s1 << std::endl;  //输出HELLO
    s1 = s2;
    if(s2 == s1) std::cout<<"字符串相同"<<std::endl;
    else std::cout<<"字符串不同"<<std::endl;
    std::cin >> s1;
    std::cout << s1(1, 2);
    return 0;
}
