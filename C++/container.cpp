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
//�ų���stack queue
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
    //�������飬��̬��չ���������¿�������Ԥ���ռ䣬�������
    //����
    vector<int> a;
    vector<int> b(a);
    vector<int> c(3, 3); //n elem ,����n��Ԫ��
    vector<int> d(c.begin(), c.end());

    //��ֵ
    a = c;
    b.assign(c.begin(), c.end()); // ���ܷ��򿽱�
    d.assign(3, 5); //����n��Ԫ��,����ǰ���

    //��Ԥ���������ͣ���ǰ����С
    a.reserve(50);  //����Ԥ���ռ�
    a.empty();
    a.capacity();
    a.size();
    a.resize(20);  //����0���̶ϣ�����
    b.resize(30, 30); //����elem(30),�̶�

    //�����ɾ��������
    a.push_back(0);
    a.insert(a.begin(), 10);
    a.insert(a.end(), 10, 10);

    a.pop_back();
    a.erase(a.begin());
    a.erase(a.begin(), a.end());
    b.clear();

    //���� 
    c.swap(d);

    //Ԫ�ض�ȡ
    c.at(100);
    //c[0]; ����ȫ
    //c.front();
    //c.back();

    /*  vector<int>::iterator it;
    for (it = d.begin(); it != d.end(); ++it)
    cout << *it << " ";
    cout << endl;*/

}
void test_deque()
{
    //˫�����飬��ͷ������vector�ã�������vector��
    //deque�ڲ����п���(�ŵ�ַ)��ά��ÿ�λ����������ݣ��������ڴ����ʵ����
    /*
    ����
    deque<T> arg;
    deque(beg,end);
    deque(n,elem);
    deque(const deque &);

    ��ֵ
    deque &operator = (const deque &);
    assign(beg,end);
    assign(n,elem);

    ��С
    empty();
    size();
    resize(int size);
    resize(int size,elem);

    �����ɾ��
    push_back(elem);
    push_front(elem);
    insert(pos,elem);
    void insert(pos,n,elme);
    void insert(pos,beg,end);

    pop_back();
    pop_front();
    erase(pos); //������һ������
    erase(beg,end); //������һ������
    clear();

    //��ȡ
    at(int index);
    operator[](int index);
    front();
    back();

    //����
    sort(beg,end);
    */
}
void test_queue()
{
    //���У��Ƚ��ȳ���������
    /*        ___________________
    |                   |
    push ->| 1  2  3 ...       | 
    pop <-|___________________|
    */

    /*
    ����
    queue<T> arg;
    queue(const queue &);

    ��ֵ�뽻��
    queue &operator = (const queue &);
    swap(queue<T> &)

    ��С
    empty();
    size();

    �����ɾ��
    push(elem);
    pop();
    front();
    end();
    emplace(elem);  // insert at begining

    //��ȡ
    at(int index);
    operator[](int index);
    front();
    back();

    //����
    sort(beg,end);

    //����
    while(!arg.empty())
    {
    cout<<arg.front()<<" "<<arg.end()<<endl;
    arg.pop();
    }
    */

}
void test_stack()
{
    //ջ���Ƚ����������ȳ���
    /*
    pop -    - push     
    |�� ��| 
    |     |
    |_____|  <- first, battom
    */

    /*
    ����
    stack<T> arg;
    stack(const stack &);

    ��ֵ�뽻��
    stack &operator = (const stack &);
    swap(stack<T> &)

    ��С
    empty();
    size();

    �����ɾ��
    push(elem);
    pop();
    top(); //ջ��

    //��ȡ
    at(int index);
    operator[](int index);
    front();
    back();

    //����
    sort(beg,end);

    //����
    while(!arg.empty())
    {
    cout<< arg.top()<<endl;
    arg.pop();
    }
    */


}
void test_list()
{
    //˫��ѭ������ָ����������� end->next = front ,˫�������++.--,!=,==
    //����ɾ�����㣬��̬�ڴ���䣨���˷ѣ�������������û�����,ռ�ڴ����
    //ջ���Ƚ����������ȳ���

    /*
    ����
    list<T> arg;
    list(beg,end);
    list(n,elem);
    list(const list &);

    ��ֵ
    list &operator = (const list &);
    assign(beg,end);
    assign(n,elem);
    swap(const list &)

    ��С
    empty();
    size();
    resize(int size);
    resize(int size,elem);

    �����ɾ��
    push_back(elem);
    push_front(elem);
    insert(pos,elem);
    void insert(pos,n,elme);
    void insert(pos,beg,end);

    pop_back();
    pop_front();
    erase(pos); //������һ������
    erase(beg,end); //������һ������
    remove(elem); //ɾ�����е���elem��Ԫ��
    clear();

    //��ȡ
    at(int index);
    operator[](int index);
    front();
    back();

    //����
    sort();
    reverse(); //��ת����
    //���ػ�
    unique();
    */

}
void test_map()
{
    // map������ݶ���pair��
    /* pair<type1,type2> p(key,value)  ��key����value, ��iostream
    pair<type1,type2> p = make_pair(key,value);  
    p.first(); p.second();
    */
    // map(���ظ�Ԫ��) �� multimap(�����ظ�Ԫ��),������ʵ�֣�����ʽ����
    /*
    ����
    map<T> arg;
    map(const map &);
    map(const key_compare& _Pred, const allocator_type& _Al)��

    ��ֵ�뽻��
    map &operator = (const map &);
    swap(map<T> &)

    ��С
    empty();
    size();

    �����ɾ��
    insert(pair<string,int>("we",5));
    find(key);
    count(key);
    emplace(elem);  // insert at begining

    //��ȡ��ɾ��
    at();
    count(elem);

    erase(pos);
    erase(beg,end);
    erase(elem);
    clear();

    //����
    map<typ1,type2,class>
    ����ʱ�÷º���
    */
    map<string, int> a;
    a.at

}
void test_set()
{
    // set(���ظ�Ԫ��) �� multiset(�����ظ�Ԫ��),������ʵ�֣�����ʽ����
    /*
    ����
    set<T> arg;
    set(const set &);
    set(const key_compare& _Pred, const allocator_type& _Al)��
    set<T> arg(...)
    ��ֵ�뽻��
    set &operator = (const set &);
    swap(set<T> &)

    ��С
    empty();
    size();

    �����ɾ��
    insert(elem);
    emplace(elem);  // insert at begining

    //��ȡ��ɾ��
    find(elem)
    count(elem);

    erase(pos);
    erase(beg,end);
    erase(elem);
    clear();

    //����˳��Ĭ��С->��
    set<type,class>
    �ڽ�����ʱ���÷º�������
    */

}
void test_string()
{
    //���캯��
    string();
    string a = "a"; //string a("a");
    string b = string("b");  // string b(string &)
    string c = string(1, 'c'); 
    //��ֵ
    a = "66666";
    b = string("bb");
    c = '/222';
    //c.assign(...) const char *,[int] || const string & || int, char
    //�ַ���ƴ��
    a += "xxxxx";
    b += 'b';
    c += string("ada");
    //c.append(...)  char *,[int] || const string & || const string &, int pos, int n

    //���Һ��滻
    //c.find(...) string &,int pos || char *,int pos, [int n] || const char, int pos
    //c.rfind(...) ͬ��,�Ӻ�������
    //c.replace(...) int pos,int n,( const string & || const char * )

    //�Ƚ�(-1,0,1)
    a == b;
    a.compare(b);
    a.compare("dadaw");
    //��ȡ
    a[0];
    a.at(0);
    a.substr(0, 4);// int pos, int n=npos ,��ȡ�Ӵ�
                   //����
                   //a.insert(...)  int pos,(const char * || const string &)  ||  int pos, int n, char c
                   //ɾ��
    a.erase(0, 4);  // int pos, int n=npos  ,ɾ��pos ���� n ���ַ�
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