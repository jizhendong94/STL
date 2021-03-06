/*
* 类型转换相关
*cast
*
*/
、
1. const_cast 是一种c++运算符，主要用来去除符合类型的const和volatile属性
	变量本身的const属性是不能去除的，要想修改变量的值，一般是去除指针(或引用)的const属性，再进行间接引用
	const_cast<type>(expression)
	通过const_cast运算符，也只能将const type*转换为type* ,将const type&转换为type&
	
	
	
eg1::
    const int g = 20;
     //int h = const_cast<int>(g); //不允许对普通数据进行操作
 
     const int a = 5;
     int *p;
     p = const_cast<int*>(&a);
     (*p)++;
     cout<<"a :"<<a <<endl;
     cout<<*p<<endl;

	root@jzd:/home/jzd/stl# ./a.out
	a :5
	6

	常量指针被转化为非常量指针，转换后指针指向原来的变量（转换后的指针地址不变）
	
eg::
	
  5 class A{
  6     public:
  7         A() {my_num = 0;}
  8         int my_num;
  9 };
 10 int main()
 11 {
 12     //指针指向类
 13     const A* const_ptr1 = new A();
 14     A* ptr2 = const_cast<A*>(const_ptr1);
 15
 16     ptr2->my_num = 200;
 17     cout<<const_ptr1->my_num<<endl<<ptr2->my_num<<endl;
 18
 19     //指针指向基本类型
 20     const int ica = 100;
 21     int* ia = const_cast<int*>(&ica);
 22     *ia=200;
 23
 24     cout<<*ia<<endl<<ica<<endl;

root@jzd:/home/jzd/stl# ./a.out
200
200
200
100

//指向对象的指针在去const之后，重新赋值，会改变原来对象的值
//但是基本类型，const int ica 就是const的，所以值不会改变，即使ia和ica的地址一样，但是ica=100 *ia=200
//说明C++里是const，就是const，外界千变万变，我就不变。不然真的会乱套了，const也没有存在的意义了

eg1::   //有点困惑，定义的类型加& 和不加& 表现不一致

 17     const T a={1};
 18     //a.i = 10;  //直接修改 const类型，编译错误
 19     T &b = const_cast<T&>(a);
 20     b.i=10;
 21     cout<<a.i<<endl<<b.i<<endl;
 22
 23     const T c={1};
 24     const T &c1=c;
 25
 26     T c2=const_cast<T&>(c1);
 27
 28     c2.i=200;
 29     cout<<c.i<<endl<<c1.i<<endl<<c2.i<<endl;
 30
 31     return 0;

root@jzd:/home/jzd/stl# ./a.out
10
10
1
1
200
/////////////////////////////////////////////////////////////////
 17     const T a={1};
 18     //a.i = 10;  //直接修改 const类型，编译错误
 19     T &b = const_cast<T&>(a);
 20     b.i=10;
 21     cout<<a.i<<endl<<b.i<<endl;
 22
 23     const T c={1};
 24     const T &c1=c;
 25
 26     T &c2=const_cast<T&>(c1);       //和上一个例子不同  T& c2  结果不同
 27
 28     c2.i=200;
 29     cout<<c.i<<endl<<c1.i<<endl<<c2.i<<endl;
 30
 31     return 0;

root@jzd:/home/jzd/stl# ./a.out
10
10
200
200
200





	
