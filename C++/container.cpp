#include<iostream>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<list>
#include<set>
#include<string>
#include<algorithm> // sort(beg,end,[class compare->operator() ])
using namespace std;
/*
//排除：stack queue
xxx<T>::iterator it;
for(it = arg.begin(); it!=arg.end(); ++it)
{
cout<< *it;
cout<< it->data;
}

*/
void test_vector()
{
    /*
    //单端数组，动态扩展（超过开新拷贝），预留空间，随机访问
    //构函
    vector<int> a;
    vector<int> b(a);
    vector<int> c(3, 3); //n elem ,拷贝n个元素
    vector<int> d(c.begin(), c.end());

    //赋值
    a = c;
    b.assign(c.begin(), c.end()); // 不能反向拷贝
    d.assign(3, 5); //拷贝n个元素,覆盖前面的

    //（预留）容器和（当前）大小
    a.reserve(50);  //设置预留空间
    a.empty();
    a.capacity();
    a.size();
    a.resize(20);  //长补0，短断，更改
    b.resize(30, 30); //长补elem(30),短断

    //插入和删除，单向
    a.push_back(0);
    a.insert(a.begin(), 10);
    a.insert(a.end(), 10, 10);

    a.pop_back();
    a.erase(a.begin());
    a.erase(a.begin(), a.end());
    b.clear();

    //交换 
    c.swap(d);

    //元素读取
    c.at(100);
    //c[0]; 不安全
    //c.front();
    //c.back();

    /*  vector<int>::iterator it;
    for (it = d.begin(); it != d.end(); ++it)
    cout << *it << " ";
    cout << endl;*/

}
void test_deque()
{
    //双端数组，对头操作比vector好，遍历比vector慢
    //deque内部有中控器(放地址)，维护每段缓存区的内容，缓存区内存放真实数据
    /*
    构造
    deque<T> arg;
    deque(beg,end);
    deque(n,elem);
    deque(const deque &);

    赋值
    deque &operator = (const deque &);
    assign(beg,end);
    assign(n,elem);

    大小
    empty();
    size();
    resize(int size);
    resize(int size,elem);

    插入和删除
    push_back(elem);
    push_front(elem);
    insert(pos,elem);
    void insert(pos,n,elme);
    void insert(pos,beg,end);

    pop_back();
    pop_front();
    erase(pos); //返回下一个数据
    erase(beg,end); //返回下一个数据
    clear();

    //读取
    at(int index);
    operator[](int index);
    front();
    back();

    //排序
    sort(beg,end);
    */
}
void test_queue()
{
    //队列，先进先出，后进后出
    /*        ___________________
    |                   |
    push ->| 1  2  3 ...       | 
    pop <-|___________________|
    */

    /*
    构造
    queue<T> arg;
    queue(const queue &);

    赋值与交换
    queue &operator = (const queue &);
    swap(queue<T> &)

    大小
    empty();
    size();

    插入和删除
    push(elem);
    pop();
    front();
    end();
    emplace(elem);  // insert at begining

    //读取
    at(int index);
    operator[](int index);
    front();
    back();

    //排序
    sort(beg,end);

    //遍历
    while(!arg.empty())
    {
    cout<<arg.front()<<" "<<arg.end()<<endl;
    arg.pop();
    }
    */

}
void test_stack()
{
    //栈，先进后出，后进先出，
    /*
    pop -    - push     
    |↑ ↓| 
    |     |
    |_____|  <- first, battom
    */

    /*
    构造
    stack<T> arg;
    stack(const stack &);

    赋值与交换
    stack &operator = (const stack &);
    swap(stack<T> &)

    大小
    empty();
    size();

    插入和删除
    push(elem);
    pop();
    top(); //栈底

    //读取
    at(int index);
    operator[](int index);
    front();
    back();

    //排序
    sort(beg,end);

    //遍历
    while(!arg.empty())
    {
    cout<< arg.top()<<endl;
    arg.pop();
    }
    */


}
void test_list()
{
    //双向循环链表，指针域和数据域， end->next = front ,双向迭代器++.--,!=,==
    //插入删除方便，动态内存分配（无浪费），遍历很慢，没数组快,占内存更大
    //栈，先进后出，后进先出，

    /*
    构造
    list<T> arg;
    list(beg,end);
    list(n,elem);
    list(const list &);

    赋值
    list &operator = (const list &);
    assign(beg,end);
    assign(n,elem);
    swap(const list &)

    大小
    empty();
    size();
    resize(int size);
    resize(int size,elem);

    插入和删除
    push_back(elem);
    push_front(elem);
    insert(pos,elem);
    void insert(pos,n,elme);
    void insert(pos,beg,end);

    pop_back();
    pop_front();
    erase(pos); //返回下一个数据
    erase(beg,end); //返回下一个数据
    remove(elem); //删除所有等于elem的元素
    clear();

    //读取
    at(int index);
    operator[](int index);
    front();
    back();

    //排序
    sort();
    reverse(); //反转链表
    //独特化
    unique();
    */

}
void test_map()
{
    // map里的数据都是pair对
    /* pair<type1,type2> p(key,value)  按key来找value, 在iostream
    pair<type1,type2> p = make_pair(key,value);  
    p.first(); p.second();
    */
    // map(无重复元素) 与 multimap(可有重复元素),二叉树实现，关联式容器
    /*
    构造
    map<T> arg;
    map(const map &);
    map(const key_compare& _Pred, const allocator_type& _Al)；

    赋值与交换
    map &operator = (const map &);
    swap(map<T> &)

    大小
    empty();
    size();

    插入和删除
    insert(pair<string,int>("we",5));
    find(key);
    count(key);
    emplace(elem);  // insert at begining

    //读取与删除
    at();
    count(elem);

    erase(pos);
    erase(beg,end);
    erase(elem);
    clear();

    //排序
    map<typ1,type2,class>
    构建时用仿函数
    */
    map<string, int> a;
    a.at

}
void test_set()
{
    // set(无重复元素) 与 multiset(可有重复元素),二叉树实现，关联式容器
    /*
    构造
    set<T> arg;
    set(const set &);
    set(const key_compare& _Pred, const allocator_type& _Al)；
    set<T> arg(...)
    赋值与交换
    set &operator = (const set &);
    swap(set<T> &)

    大小
    empty();
    size();

    插入和删除
    insert(elem);
    emplace(elem);  // insert at begining

    //读取与删除
    find(elem)
    count(elem);

    erase(pos);
    erase(beg,end);
    erase(elem);
    clear();

    //排序顺序（默：小->大）
    set<type,class>
    在建立的时候用仿函数的类
    */

}
void test_string()
{
    //构造函数
    string();
    string a = "a"; //string a("a");
    string b = string("b");  // string b(string &)
    string c = string(1, 'c'); 
    //赋值
    a = "66666";
    b = string("bb");
    c = '/222';
    //c.assign(...) const char *,[int] || const string & || int, char
    //字符串拼接
    a += "xxxxx";
    b += 'b';
    c += string("ada");
    //c.append(...)  char *,[int] || const string & || const string &, int pos, int n

    //查找和替换
    //c.find(...) string &,int pos || char *,int pos, [int n] || const char, int pos
    //c.rfind(...) 同上,从后面找起
    //c.replace(...) int pos,int n,( const string & || const char * )

    //比较(-1,0,1)
    a == b;
    a.compare(b);
    a.compare("dadaw");
    //提取
    a[0];
    a.at(0);
    a.substr(0, 4);// int pos, int n=npos ,提取子串
                   //插入
                   //a.insert(...)  int pos,(const char * || const string &)  ||  int pos, int n, char c
                   //删除
    a.erase(0, 4);  // int pos, int n=npos  ,删除pos 后面 n 个字符
}
int main()
{
    test_vector();
    test_deque();
    test_stack();
    test_queue();
    test_list();
    test_set();
    test_map();
    test_string();
}