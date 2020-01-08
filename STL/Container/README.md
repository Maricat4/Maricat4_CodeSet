# string的使用
## string
string相当于basic_string<char>,其中basic_string<T>为字符串模板类，该模板提供了许多字符串类所需的成员以及方法，其中T为单个字符所属的类型。basic_string<T>没有虚函数，这点和其他标准库类型一致，当需要设计更复杂的文字处理类时，可以用它加以实现。
## 1.string的构造与析构-constructor and destructor
default (1)             string();
copy (2)	            string (const string& str);
substring (3)	      	string (const string& str, size_t pos, size_t len = npos);
from c-string (4)		string (const char* s);
from buffer (5)	        string (const char* s, size_t n);
//构造n个c
fill (6)	            string (size_t n, char c);
//根据迭代器构造一个string，尝试使用过list迭代器初始化，显示无匹配的构造函数
//而使用vector的迭代器是可以初始化string，文档中的对于InputIterator的要求，它指向可转
//换为char类型的数据
range (7)	       template <class InputIterator>
		string  (InputIterator first, InputIterator last);
initializer list (8)    string (initializer_list<char> il);
//右值引用
move (9)				string (string&& str) noexcept;
析构: ~string()

## 2.元素访问-Element Access
*1)通过以下方式访问元素*
    //C++ reference
    operator[]	Get character of string (public member function )
    at			Get character in string (public member function )
    //通过以下两函数实现，区别于[]的访问方式，这种访问方式，会自动检查访问的位置是否有效
    //使用两个的函数的原因是为了方便实现===>对象的不同的访问权限
          char& at (size_t pos);
    const char& at (size_t pos) const;
    //访问最前、最后元素
    back		Access last character (public member function )
    front 		Access first character (public member function )
*2)通过迭代器访问*
    begin	Return iterator to beginning (public member function )
    end		Return iterator to end (public member function )
    //反向迭代器，reverse_iterator<iterator>
    rbegin	Return reverse iterator to reverse beginning (public member function )
    rend	Return reverse iterator to reverse end (public member function )
    //const_iterator是指向const character的迭代器,意味着无法修改这个。只有读权限
    //当去修改时，会报错“表达式必须是可修改的左值”
    //以下均为C++11新特性
    //其类型：const_iterator,reverse_iterator<const_iterator>
    cbegin  Return const_iterator to beginning (public member function )
    cend  	Return const_iterator to end (public member function )
    crbegin Return const_reverse_iterator to reverse beginning (public member function )
    crend  	Return const_reverse_iterator to reverse end (public member function )

## 3.字符串的修改

operator+= 	Append to string (public member function )
    //四种=重载，初始化列表单独测试，暂时搁一搁
        string (1)	string& operator+= (const string& str);
        c-string (2)	string& operator+= (const char* s);
        character (3)	string& operator+= (char c);
        initializer list (4)	string& operator+= (initializer_list<char> il);
    
append	     Append to string (public member function )
   //7种重载，较之+=更灵活
   string (1)	string& append (const string& str);
   substring (2)	string& append (const string& str, size_t subpos, size_t sublen);
   c-string (3)	string& append (const char* s);
   buffer (4)	string& append (const char* s, size_t n);
   fill (5)	string& append (size_t n, char c);
   range (6)	template <class InputIterator>
       string& append (InputIterator first, InputIterator last);
   initializer list(7)	string& append (initializer_list<char> il);
    //压入字符及弹出字符
    push_back    Append character to string (public member function )
    pop_back      Delete last character (public member function )
    
    
    
assign	       Assign content to string (public member function )
//字符串的赋值
//有以下重载
    string (1)	string& assign (const string& str);
    substring (2)	string& assign (const string& str, size_t subpos, size_t sublen);
    c-string (3)	string& assign (const char* s);
    buffer (4)	string& assign (const char* s, size_t n);
    fill (5)	string& assign (size_t n, char c);
    range (6)	 <class InputIterator>
    string& assign (InputIterator first, InputIterator last);
    initializer list(7)	string& assign (initializer_list<char> il);
    move (8)	string& assign (string&& str) noexcept;

//插入字符串
insert	        Insert into string (public member function )
    //有以下重载
    string (1)	string& insert (size_t pos, const string& str);
    substring (2)	string& insert (size_t pos, const string& str, size_t subpos, size_t sublen);
    c-string (3)	string& insert (size_t pos, const char* s);
    buffer (4)	string& insert (size_t pos, const char* s, size_t n);
    fill (5)	string& insert (size_t pos,   size_t n, char c);
   			 iterator insert (const_iterator p, size_t n, char c);
    single character (6)	iterator insert (const_iterator p, char c);
    range (7)	template <class InputIterator>
    iterator insert (iterator p, InputIterator first, InputIterator last);
    initializer list (8)	string& insert (const_iterator p, initializer_list<char> il);
    
erase	      Erase characters from string (public member function )
//清除函数，三种重载分别对应序列，迭代器（指向的某一个字符），以及两个迭代器之间的范围
//依据字符串字符顺序清除，默认清除整个字符串，两个参数相等时不能清除一个字符，两参数的差表示清除字符的个数，而第一个参数表示起始位置
sequence (1)	string& erase (size_t pos = 0, size_t len = npos);
//依据字符串的迭代器清除，分别清除字符以及子串

character (2)	iterator erase (const_iterator p);
//参数相同时不会清除单个字符，无论是sequence还是range都是按照Erases the sequence of characters in the range [first,last)此种方式清除，参数相同时不会清除一个，同时string第二参数可以在第一个参数之前，结果是不确定的（可以尝试自行研究源码）
range (3)	iterator erase (const_iterator first, const_iterator last);

replace          Replace portion of string (public member function )
//七种重载，主要是输入的不同以及要替换的方式不同，*注意pos以及len表示的是，要被取代的部分。当len=0时，即表示插入字符串*。当然两个迭代器相等时，同样表示在迭代器位置处插入字符串
    string (1)	string& replace (size_t pos,size_t len,const string& str);
    string& replace (const_iterator i1, const_iterator i2, const string& str);
    //使用子串进行代替
    substring (2)	string& replace (size_t pos,size_t len, const string& str,size_t subpos, size_t sublen);
    c-string (3)	string& replace (size_t pos,size_t len, const char* s);
    string& replace (const_iterator i1, const_iterator i2, const char* s);
    buffer (4)	string& replace (size_t pos, size_t len,const char* s, size_t n);
    string& replace (const_iterator i1, const_iterator i2, const char* s, size_t n);
    fill (5)	string& replace (size_t pos,size_t len,size_t n, char c);
    string& replace (const_iterator i1, const_iterator i2, size_t n, char c);
    range (6)	template <class InputIterator>
    string& replace (const_iterator i1, const_iterator i2,InputIterator first, InputIterator last);
    initializer list (7)	string& replace (const_iterator i1, const_iterator i2, initializer_list<char> il);
     
swap 	      Swap string values (public member function )


