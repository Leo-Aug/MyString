#include<iostream>
#include<cstring>
#include<cctype>


class myString
{
public :
    explicit myString(const char *pn = nullptr);
    ~myString();
    void set(const char *pn);  // 将字符串设置为pn指向的内容，注意避免越界
    void set(const myString & rStr);  // 将字符串设置为rStr中的内容，注意避免越界
    void print()const;// 输出字符串整体和长度
    char get(int i)const;  // 返回字符串中的下标为i的字符，注意i 的有效性
    void toUpper();   //转化为大写字符串
    bool str_compare(const myString& s);   //比较字符串
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
    std::cout<< s1.get(0) <<std::endl; //输出H
    s2.print();   //输出“空字符串”，0
    s2.set("Hello world");
    s2.print();  //输出“Hello world”
    s1.toUpper();
    s1.print();  //输出HELLO
    s1.set(s2);
    if( s2. str_compare(s1 )) std::cout<<"字符串相同";
    else std::cout<<"字符串不同";
    return 0;
}
