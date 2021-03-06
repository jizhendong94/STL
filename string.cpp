#include<string>

1. string s1 //默认构造函数，s1为空串
2. string s2(s1)  
3. string s3("valuee")

4. s.empty()   //判断是否是空 
5. s.size()    //返回字符的个数
6. s1+s2       //字符串连接
7. clear()     //删除字符串所有内容
   const char* c_str() const  //将string对象转换成const char*
   size_type copy(char* c,size_type n,size_type pos=0) //将原srting对象从位置pos开始的地方复制n个字符到c中
   string &erase(pos=0,n=npos)   //删除从pos开始的N个字符
   
   iterator erase(const_iterator position)   //删除迭代器位置处的单个字符, 并返回下个元素的迭代器
   
   iterator erase(const_iterator first, const_iterator last)
   //删除迭代器[first, last)区间的所有字符,返回一个指向被删除的最后一个元素的下一个字符的迭代器.
   
   at(pos)  //string s = "abc"; 则 s.at(1) = s[1] = 'b'
   
   int compare(const basic_string& str) const noexcept  //c++11 起  比较字符串的大小
   
   
   string substr (size_t pos = 0, size_t len = npos)  const;   //获取子串 子串是，在字符位置pos开始，跨越len个字符（或直到字符串的结尾，以先到者为准）对象的部分。
   
   
   find(str,pos) //查找字符串出现的位置
   //可以不填第二个参数，默认从字符串的开头进行查找。
   //返回值为目标字符的位置，当没有找到目标字符时返回npos。
   
 eg1::
 
   string s1 = "hello world!"
	s.find("e");
	
	if(s1.find("a") != string::npos)
		cout<<"find"<<endl;
	else
		cout<<"not find"<<endl;

eg2::
	
	string str1("15451.5fjiggr12345");
 
    size_t position = str1.find("9");
    if(position != string::npos)
        cout<<"find pos:: "<<position<<endl;
    else
        cout<<"not find pos:: "<<position<<endl;
eg3::


	string str1("15451.5fjiggr12345");
 
    size_t position = str1.find("5");
    while(position != string::npos)
    {
       cout<<"position is :: "<<position<<endl;
       position = str1.find("5",position+1);
    }

	rfind()          //从指定位置向前查找 用法和find() 一致
	string str1("15451.5fjiggr12345");
 
    size_t position = str1.rfind("5");
    while(position != string::npos)
    {
       cout<<"position is :: "<<position<<endl;
       position = str1.rfind("5",position-1);
    }
	
	find_first_of()          //在源串中从位置pos起往后查找，只要在源串中遇到一个字符，该字符与目标串中任意一个字符相同，就停止查找，
							 //返回该字符在源串中的位置；若匹配失败，返回npos。
  	
eg1::
	
	string str("please, replace the vowels in this sentece by asterisks.");
    size_t pos = str.find_first_of("aeiou");
    while(pos != string::npos)
    {

        str[pos]='*';
        pos=str.find_first_of("aeiou",pos+1);
    }
    cout<<str<<endl;

	
	find_last_of()
	
	find_first_not_of()     //在源串中从位置pos开始往后查找，只要在源串遇到一个字符，该字符与目标串中的任意一个字符都不相同，就停止查找，
							//返回该字符在源串中的位置；若遍历完整个源串，都找不到满足条件的字符，则返回npos。 

	
	find_last_not_of()



8. to_string()   //可用于将数值类型转换为string

string to_string (int val);
string to_string (long val);
string to_string (long long val);
string to_string (unsigned val);
string to_string (unsigned long val);
string to_string (unsigned long long val);
string to_string (float val);
string to_string (double val);
string to_string (long double val);

9. //string 转数值
//利用C标准库函数转换
string s1 = string("8877");
1. int temp = atoi(s1.c_str())     //atoi会跳过前面的空白字符(空格,tab缩进)，函数要求被转换的字符串是按十进制数理解的

2. strtol(const char* nptr,char **endptr,int base)  // strtol函数会将参数nptr字符串根据参数base来转换成长整型数，参数base范围从2至36。

	string str("0x18")								//参数endptr指向停止转换的位置，若字符串nptr的所有字符都成功转换成数字则endptr指向串结束符'\0'。
	int temp = strtol(str.c_str(),NULL,16)			//判断是否转换成功，应检查**endptr是否为'\0'。
	
	
3. unsigned long strtoul(const char *nptr,char **endptr,int base); //strtoul，将参数nptr字符串根据参数base来转换成无符号的长整型数。

4. long long atoll（const char * str）            //

5. atof()

6. long double strtold (const char * optr, char ** nptr)  // strtold()会扫描参数optr字符串，跳过前面的空格字符，直到遇上数字或正负符号才开始做转换，
														  // 到出现非数字或字符串结束时('\0')才结束转换，并将结果返回。若字符串optr中包含不符合条件的字符，
														  // 这些字符将保存在nptr中。例如：optr=“15451.5fjiggr12345”，strtold返回值是15451.5，nptr中的值是fjiggr12345。
														  
7. 


	
	