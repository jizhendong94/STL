#include<iostream>
using namespace std;

//vector 常见用法

1. vector<int>obj;   //创建一个空的vector
   vector<int>a(10); // 定义了10个整形数，但是没有给出初始值，所以其值是不确定的
   vector<int>a(10,1) //定义了10个元素，每个初始值为1
   vector<int>a(b)     // 用b向量来创建a向量 整体性赋值
   vector<int>a(b.begin(),b.begin()+3) //定义了a值为b中第0个到第2个（共3个）元素
   int b[7] = {1,2,3,4,5,6,7}
   vector<int>a(b,b+7)  //从数组中获得初始值

2. obj.push_back(i);  //在数组后面添加一个元素

3. obj.pop_back();    //去掉数组最后一个元素

4. obj.back()  //返回 obj的最后一个元素

5. obj.front()  //返回 obj的第一个元素

6. obj.clear()  //清空obj中的元素

7. obj.empty()  // 判断a是否为空，空返回true  

8. obj.erase(obj.begin()+1,obj.begin()+3)  //删除下标为 1 2 的两个元素，不包括下标为3的元素

9. obj.insert(obj.begin()+1,5)   // 在下标为1的地方插入数值5  如a=1,2,3,4, 插入后 1，5，2，3，4

10. obj.insert(obj.begin()+1,3,5)  //在下标为1的地方插入3个数 ，数值都是5 

11. obj.size()   //返回向量中的元素的个数


// stack 常见用法

#include<stack>
1. stack<int>a

2. a.empty()  //判断栈是否是空的  

3. a.size()   //返回stack中的元素的个数

4. a.top()   //返回栈顶元素  不删除 如果栈为空，程序会报错

5. a.pop()   //移除栈顶元素 

6. a.push()  //在栈顶增加元素

//queue  常见用法
#include<queue>

queue<int>a

1. a.back()   // 返回最后一个元素

2. a.empty()  // 队列为空则返回为真

3. a.front()  // 返回第一个元素

4. a.push()   // 在末尾加入一个元素

5. a.pop()    // 删除第一个元素

6. a.size()   // 返回队列中元素的个数


//map  函数
// map基于红黑树实现，红黑树具有自动排序的功能，因此map内的所有数据，在任何时候，都是有序的
// unordered_map c++11新加入的容器，内部实现了一个哈希表，元素的排列顺序使无序的。
#include<map>

map<int,string>stu;

map<int, string> map_test4(map_test2);			// 复制构造 

1. stu.insert(pair<int,string>(1,"student_one"));  // 插入元素
   stu.insert(make_pair(1,"student_one"));         //插入元素
   
2. at 和 [] 的区别  []如果没有，会插入   at 如果不存在会抛出异常

3. stu.empty()  //查询是否为空

4. stu.size()  //查询map中键值对的数量

5. stu.clear()  //删除所有元素

6. stu.find()    // 查找一个元素

7. stu.count()   //返回指定元素出现的次数

8. 


int main()
{
    map<int,string>student;
    student.insert(pair<int,string>(0,"stu_zero"));
    student.insert(make_pair(1,"stu_one"));
    for(auto iter = student.begin();iter!=student.end();iter++)
    {
        cout<<iter->second<<endl;

    }

    if(student.find(1)!=student.end())
        cout<<"find 1 is "<<student[1]<<endl;
    return 0;
}

#include<unordered_map>	

std::unordered_map<std::string, std::string> umap2(umap);


1. .epmty()
2. .size()
3. .insert()
4. .erease()
5. .clear()
6. .emplace() //向容器中添加新键值对，效率比insert()方法高
7. .find()    //查找元素

unordered_map<string, string> umap;  
umap.emplace("Python教程", "http://c.biancheng.net/python/");














