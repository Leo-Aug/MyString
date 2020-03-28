#include<iostream>
#include<cstring>
#include<cctype>


class myString
{
public :
    explicit myString(const char *pn = nullptr);
    myString(const myString &S);
    ~myString();
    friend std::ostream &operator<<(std::ostream &os, const myString &S);// ����ַ�������ͳ���
    char &operator[](int i);  // �����ַ����е��±�Ϊi���ַ���ע��i ����Ч��
    void toUpper();   //ת��Ϊ��д�ַ���
    myString &operator=(const myString &S);
    myString &operator=(const char *S);
    bool operator==(const myString& s);   //�Ƚ��ַ���
    myString operator+(const myString &S);
private:
    char *pStr ;    // ָ��洢�ַ����Ŀռ� new char[size+1]
    int size ;      //�����ַ�����Ŀ
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
    char *pt = tmp.pStr, *ps = pStr;
    while(*ps)
    {
        *pt = *ps;
        ++*pt;
        ++*ps;
    }
    ps = S.pStr;
    strcpy(pt, ps);
    return tmp;
}


int main()
{
    myString s2, s1("HELLO");
    std::cout<< s1[0] <<std::endl; //���H
    std::cout << s2 << std::endl;
    s2 = "Hello world";
    std::cout << s2 << std::endl;  //�����Hello world��
    s1.toUpper();
    std::cout << s1 << std::endl;  //���HELLO
    s1 = s2;
    if(s2 == s1) std::cout<<"�ַ�����ͬ";
    else std::cout<<"�ַ�����ͬ";
    return 0;
}
