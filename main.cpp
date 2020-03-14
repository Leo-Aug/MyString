#include<iostream>
#include<cstring>
#include<cctype>


class myString
{
public :
    explicit myString(const char *pn = nullptr);
    ~myString();
    void set(const char *pn);  // ���ַ�������Ϊpnָ������ݣ�ע�����Խ��
    void set(const myString & rStr);  // ���ַ�������ΪrStr�е����ݣ�ע�����Խ��
    void print()const;// ����ַ�������ͳ���
    char get(int i)const;  // �����ַ����е��±�Ϊi���ַ���ע��i ����Ч��
    void toUpper();   //ת��Ϊ��д�ַ���
    bool str_compare(const myString& s);   //�Ƚ��ַ���
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

myString::~myString()
{
    if(*pStr)
    {
        delete[] pStr;
    }
}

void myString::set(const char *pn)
{
    if(pn)
    {
        size = strlen(pn);
        delete[] pStr;
        pStr = new char[size + 1];
        strcpy(pStr, pn);
    }
    else
    {
        delete[] pStr;
        pStr = new char[1];
        *pStr = 0;
    }
}

void myString::set(const myString & rStr)
{
    size = rStr.size;
    delete[] pStr;
    pStr = new char[size + 1];
    strcpy(pStr, rStr.pStr);
}

void myString::print()const
{
    for(char *p = pStr;p && *p;p++)
    {
        std::cout << *p;
    }
    std::cout << std::endl << size << std::endl;
}

char myString::get(int i)const
{
    char c = 0;
    if(i < size)
        c = pStr[i];
    else
        std::cerr << "Subscript error: The parameter i can't larger than size" << std::endl;
    return c;
}

void myString::toUpper()
{
    for(char *p = pStr;*p;p++)
        if(islower(*p))
            *p += 32;
}

bool myString::str_compare(const myString& s)
{
    return !strcmp(pStr, s.pStr);
}


int main()
{
    myString s2, s1("HELLO");
    std::cout<< s1.get(0) <<std::endl; //���H
    s2.print();   //��������ַ�������0
    s2.set("Hello world");
    s2.print();  //�����Hello world��
    s1.toUpper();
    s1.print();  //���HELLO
    s1.set(s2);
    if( s2. str_compare(s1 )) std::cout<<"�ַ�����ͬ";
    else std::cout<<"�ַ�����ͬ";
    return 0;
}
