# STL的使用
## string
string相当于basic_string<char>,其中basic_string<T>为字符串模板类，该模板提供了许多字符串类所需的成员以及方法，其中T为单个字符所属的类型。basic_string<T>没有虚函数，这点和其他标准库类型一致，当需要设计更复杂的文字处理类时，可以用它加以实现。

``` C++
1.string的构造与析构
构造:
	stringstrs                           //生成空字符串
	strings(str)                         //生成字符串str的复制品
	strings(str,stridx)               //将字符串str中始于stridx的部分，作为构造函数的初值
	strings(str,strbegin,strlen)//将字符串str中始于strbegin,长度为strlen的部分作为字符串初值
	strings(cstr)                      //以C_string类型cstr作为字符串s的初值
	strings(cstr,char_len)       //以C_string类型cstr的前char_len个字符串作为字符轮串s的初值
	strings(num,c)                      //生成一个字符串，包含num个c字符
	strings(strs,beg,end)           //以区间[beg，end]内的字符作为字符串s的初值，文档中没有这种构造函数，只有range构造函数，见如下，string(beg,end)beg，end为迭代器
	//C++ reference
	default (1)             string();
	copy (2)	            string (const string& str);
	substring (3)	      	string (const string& str, size_t pos, size_t len = npos);
	from c-string (4)		string (const char* s);
	from buffer (5)	        string (const char* s, size_t n);
	fill (6)	            string (size_t n, char c);
	range (7)	       template <class InputIterator>
				string  (InputIterator first, InputIterator last);
	initializer list (8)    string (initializer_list<char> il);
	move (9)				string (string&& str) noexcept;
析构: ~string()
```

