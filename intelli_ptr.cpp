/*
**智能指针相关
**  shared_ptr   unique_ptr   weak_ptr
*/

#include<memory>

//shared_ptr 是一种共享的指针，会记录有多少个shared_ptrs共同指向一个对象
//如果引用计数变成0，那么这个对象就会被销毁，

//例子1
// p.use_count() 返回与p共享对象的shared_ptr数量
// unique()      若use.count()为1 返回true 否则返回0
// swap(p,q)     交换p q 中的指针
// p.swap(q)
// p.reset()     若p是唯一指向其对象的shared_ptr，reset会释放此对象
// p.reset(q)    若传递了可选的指针q，会将p指向q，否则将p置为空。
  5
  6 int main()
  7 {
  8     string *s1 = new string("s1");
  9
 10     shared_ptr<string>ps1(s1);
 11     shared_ptr<string>ps2;
 12
 13     ps2=ps1;
 14     cout<<"begin"<<endl;
 15     cout<<ps1.use_count()<<endl;
 16     cout<<ps2.use_count()<<endl;
 17     cout<<ps1.unique()<<endl;
 18
 19     string *s3 = new string("s3");
 20     shared_ptr<string>ps3(s3);
 21
 22
 23     cout<<ps1.get()<<endl;  //get() 返回托管的指针
 24     cout<<ps3.get()<<endl;
 25     swap(ps1,ps3);
 26     cout<<ps1.get()<<endl;
 27     cout<<ps3.get()<<endl;
 28
 29     cout<<"after ps1 ps3 swap"<<endl;
 30     cout<<ps1.use_count()<<endl; //交换后，ps1指向s3,只有一个
 31     cout<<ps2.use_count()<<endl;
 32     cout<<ps3.use_count()<<endl;
 33
 34     ps2 = ps1;
 35     cout<<"after p2=p1"<<endl;
 36     cout<<ps1.use_count()<<endl;
 37     cout<<ps2.use_count()<<endl;
 38     cout<<ps3.use_count()<<endl;
 39
 40     ps1.reset();
 41     cout<<"after reset"<<endl;
 42     cout<<ps1.use_count()<<endl;
 43     cout<<ps2.use_count()<<endl;
 44     cout<<ps3.use_count()<<endl;
 45
 46 }

//输出
begin
2
2
0
0x55e7ea831eb0
0x55e7ea832310
0x55e7ea832310
0x55e7ea831eb0
after ps1 ps3 swap
1
2
2
after p2=p1
2
2
1
after reset
0
1
1

//例子2

  5 class Test{
  6     public:
  7         int i;
  8         Test(int n):i(n) {}
  9         ~Test() {cout<<i<<"  "<<"destructed"<<endl;}
 10 };
 11 int main()
 12 {
 13     shared_ptr<Test>ps1(new Test(2));
 14     shared_ptr<Test>ps2(ps1);
 15     shared_ptr<Test>ps3;
 16
 17     ps3 = ps2;
 18     cout<<ps1->i<<" "<<ps2->i<<" "<<ps3->i<<" "<<endl<<endl;
 19
 20     Test* ps4=ps3.get();
 21     cout<<ps4->i<<endl;
 22     cout<<ps3.use_count()<<endl<<endl;
 23
 24     ps1.reset(new Test(3));
 25     ps2.reset(new Test(4));
 26     cout<<ps1->i<<endl;
 27
 28     ps3.reset(new Test(5)); //Test(2)没有shared_ptr指向了，调用析构函数
 29     cout<<"end"<<endl;
 30
 31     return 0;
 32 }

root@jzd:/home/jzd/cpp# ./a.out
2 2 2

2
3

3
2  destructed
end
5  destructed
4  destructed
3  destructed


//unique_ptr   
//某个时刻只能有一个unique_ptr指向一个给定对象，因此unique_ptr不支持普通的拷贝和赋值操作
// u.release()  u放弃对指针的控制权，返回指针，并将u置为空
// u.reset()    释放u指向的对象
// u.reset(q)   如果提供了内置指针q 令u指向这个对象，否则将u置为空

 unique_ptr<int>p1(new int);
 unique_ptr<int>p2(p1); // ERROR  不能共享
 unique_ptr<int>p3(move(p1));  //正确，调用移动构造函数
 
 //例子  
  5 int main()
  6 {
  7     unique_ptr<int>p1(new int);
  8     *p1=10;
  9
 10     int *p = p1.release(); //p1释放 p接收
 11     cout<<*p<<endl<<endl;
 12
 13     if(p1)
 14         cout<<"p1 not null"<<endl;
 15     else
 16         cout<<"p1 is null"<<endl;
 17
 18     unique_ptr<int>p2;
 19
 20     p2.reset(p);//获取p的所有权
 21     cout<<*p2<<endl;
 22     return 0;
 23 }

//结果
root@jzd:/home/jzd/cpp# ./a.out
10

p1 is null
10



//weak_ptr 
//shared_ptr虽然已经很好用了，但是有一点shared_ptr还是有内存泄露的情况，
//当两个对象互相使用一个shared_ptr成员变量指向对方，会造成循环引用，使引用计数失效，
//从而导致内存泄露
//.expired()   本身不会增加引用计数，所以他指向的对象可能在使用时就释放了，所以使用前 检测是否过期了
//.lock()      获取其对应的shared_ptr对象，然后继续进行后期操作。
/*
* weak_ptr设计的目的是为了配和shared_ptr而引入的一种智能指针来协助shared_ptr工作，
* 它的构造和析构不会引起引用计数的增加或者减少，weak_ptr是用来解决shared_ptr相互引用时，
* 的死锁问题，如果说两个shared_ptr相互引用，那么这连个指针的引用计数用永远不可能减少为0
*/



//例子
  4
  5 class CB;
  6 class CA{
  7     public:
  8         CA() {cout<<"CA() called"<<endl;}
  9         ~CA() {cout<<"~CA() callled"<<endl;}
 10         void set_ptr(shared_ptr<CB>& ptr) {m_ptr_b = ptr;}
 11     private:
 12         shared_ptr<CB>m_ptr_b;
 13 };
 14
 15 class CB{
 16     public:
 17         CB() {cout<<"CB() callend"<<endl;}
 18         ~CB() {cout<<"~CB called"<<endl;}
 19         void set_ptr(shared_ptr<CA>ptr) {m_ptr_a = ptr;}
 20     private:
 21         shared_ptr<CA>m_ptr_a;
 22 };
 23
 24 void fun()
 25 {
 26     shared_ptr<CB>pb(new CB());
 27     shared_ptr<CA>pa(new CA());
 28
 29     cout<<"pb :"<<pb.use_count()<<endl;
 30     cout<<"pa :"<<pa.use_count()<<endl;
 31
 32     pb->set_ptr(pa);
 33     pa->set_ptr(pb);
 34
 35     cout<<"pb :"<<pb.use_count()<<endl;
 36     cout<<"pa :"<<pa.use_count()<<endl;
 37
 38 }
 39 int main()
 40 {
 41     fun();
 42     return 0;
 43 }

//输出
root@jzd:/home/jzd/cpp# ./a.out
CB() callend
CA() called
pb :1
pa :1
pb :2
pa :2

//由于shared_ptr相互引用，程序结束时，CA CB没有正常被析构 ,造成了内存泄露
//解决方法：把其中一个修改为weak_ptr 就可以了

//输出 
CB() callend
CA() called
pb :1
pa :1
pb :2
pa :1
~CA() callled
~CB called



















