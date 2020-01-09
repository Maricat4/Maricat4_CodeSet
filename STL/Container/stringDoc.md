# string的使用
## string
string相当于basic_string<char>,其中basic_string<T>为字符串模板类，该模板提供了许多字符串类所需的成员以及方法，其中T为单个字符所属的类型。basic_string<T>没有虚函数，这点和其他标准库类型一致，当需要设计更复杂的文字处理类时，可以用它加以实现。
## 1.string的构造与析构-constructor and destructor
```
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
```
## 2.元素访问-Element Access
### *1)通过以下方式访问元素*

```
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
```
### *2)通过迭代器访问*

```
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
```
## 3.字符串的修改

### operator+= 	Append to string (public member function )

```
    //四种重载，初始化列表单独测试，暂时搁一搁
        string (1)	string& operator+= (const string& str);
        c-string (2)	string& operator+= (const char* s);
        character (3)	string& operator+= (char c);
        initializer list (4)	string& operator+= (initializer_list<char> il);
```
### append	     Append to string (public member function )

```
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
```

### assign	       Assign content to string (public member function )

```
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
```

### insert	        Insert into string (public member function )

```
    //插入字符串
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
```
### erase      Erase characters from string (public member function )

```
    //清除函数，三种重载分别对应序列，迭代器（指向的某一个字符），以及两个迭代器之间的            范围
    //依据字符串字符顺序清除，默认清除整个字符串，两个参数相等时不能清除一个字符，两参            数的差表示清除字符的个数，而第一个参数表示起始位置
    sequence (1)	string& erase (size_t pos = 0, size_t len = npos);
    //依据字符串的迭代器清除，分别清除字符以及子串
    character (2)	iterator erase (const_iterator p);
    //参数相同时不会清除单个字符，无论是sequence还是range都是按照Erases the sequence               of characters in the range [first,last)此种方式清除，参数相同时不会清除一个，同时string第           二参数可以在第一个参数之前，结果是不确定的（可以尝试自行研究源码）
    range (3)	iterator erase (const_iterator first, const_iterator last);
```
### replace    Replace portion of string (public member function )

```
//七种重载，主要是输入的不同以及要替换的方式不同，*注意pos以及len表示的是，要被取代的部分。当len=0时，即表示插入字符串*。当然两个迭代器相等时，同样表示在迭代器位置处插入字符串
    string (1)	string& replace (size_t pos,size_t len,const string& str);
             string& replace (const_iterator i1, const_iterator i2, const string& str);
    //使用子串进行代替
    substring (2)	string& replace (size_t pos,size_t len, const string& str,size_t subpos, 		size_t sublen);
    c-string (3)	string& replace (size_t pos,size_t len, const char* s);
    string& replace (const_iterator i1, const_iterator i2, const char* s);
    buffer (4)	string& replace (size_t pos, size_t len,const char* s, size_t n);
    string& replace (const_iterator i1, const_iterator i2, const char* s, size_t n);
    fill (5)	string& replace (size_t pos,size_t len,size_t n, char c);
    string& replace (const_iterator i1, const_iterator i2, size_t n, char c);
    range (6)	template <class InputIterator>
    string& replace (const_iterator i1, const_iterator i2,InputIterator first, InputIterator last);
    initializer list (7)	string& replace (const_iterator i1, const_iterator i2, 	 		  
    initializer_list<char> il);
```
### swap   Swap string values (public member function )

```
    void swap (string& str);
    //交换两个字符串内容，经过测试后，字符串交换了对其数据的引用，并未实际复制字符
```
## 4.字符串大小与容量
```
size       Return length of string (public member function )
           size_t size() const noexcept;
           //返回字符串大小
length     Return length of string (public member function )
           size_t length() const noexcept;
           //返回字符串长度
max_size   Return maximum size of string (public member function )
           size_t length() const noexcept;
           //return the maximum length the string can reach.
           //返回字符串最大长度
resize     Resize string (public member function )
           void resize (size_t n);
           void resize (size_t n, char c);
           //将字符串长度调整为n个字符的长度
           //如果n小于当前长度移除末尾几个元素
           //如果n大于当前长度,若有第二参数则用其填充，若没有则填入空格
capacity   Return size of allocated storage (public member function )
           size_t capacity() const noexcept;
           //返回为字符串分配的空间大小
           //调用reserve可以显示改变空间大小
reserve    Request a change in capacity (public member function )
           void reserve (size_t n = 0);
           //无法改变字符串内容，以及其长度
           //只能增加为字符串的分配的空间
clear      Clear string (public member function )
           void clear() noexcept;
           //清除当前字符串的内容，不会改变分配空间的大小
empty      Test if string is empty (public member function )
           bool empty() const noexcept;
           //返回字符串是否为空串的布尔值
shrink_to_fit    Shrink to fit (public member function )
           void shrink_to_fit();
           //C++11新特性，将字符串的容量缩小至字符串大小
```



## 5.字符串操作

### 字符串比较

compare     Compare strings (public member function )

*返回值是：*

|    value  |两个字符串之间的关系      |
| :--: | :--: |
| 0 | 相同 |
| 小于0 | 可能是由于字典顺序在被比较之后，另外可能是，长度更短 |
| 大于0 | 可能是由于字典顺序在被比较之前，另外可能是，长度更长 |
6种重载可以分为如下四类：
其中需要说明的是，可能是子串与子串比，所以有参数pos,len等的重载

```
string (1)	    int compare (const string& str) const noexcept;
substrings (2)	int compare (size_t pos, size_t len, const string& str) const;
                int compare (size_t pos, size_t len, const string& str,
                size_t subpos, size_t sublen) const;
c-string (3)	int compare (const char* s) const;
                int compare (size_t pos, size_t len, const char* s) const;
buffer (4)	    int compare (size_t pos, size_t len, const char* s, size_t    
                n)const;
```
同样也可以通过比较运算符来比较两个字符串。
包括 >、<、==、>=、<=、!=

### 字符串查找



- [**find**](http://www.cplusplus.com/reference/string/string/find/)

  Find content in string (public member function )

- [**rfind**](http://www.cplusplus.com/reference/string/string/rfind/)

  Find last occurrence of content in string (public member function )

- [**find_first_of**](http://www.cplusplus.com/reference/string/string/find_first_of/)

  Find character in string (public member function )

- [**find_last_of**](http://www.cplusplus.com/reference/string/string/find_last_of/)

  Find character in string from the end (public member function )

- [**find_first_not_of**](http://www.cplusplus.com/reference/string/string/find_first_not_of/)

  Find absence of character in string (public member function )

- [**find_last_not_of**](http://www.cplusplus.com/reference/string/string/find_last_not_of/)

  Find non-matching character in string from the end (public member function )

各个函数原型

```
//find
/*查找第一次出现的位置根据传入的参数（字符串），pos参数表示的是寻找的起点。(除了第三个表示的传入参数的起点以及 n表示长度).寻找到会返回寻找到的位置，否则会返回string::npos*/
string (1)	    size_t find (const string& str, size_t pos = 0) const noexcept;
c-string (2)	size_t find (const char* s, size_t pos = 0) const;
buffer (3)	    size_t find (const char* s, size_t pos, size_type n) const;
character (4)	size_t find (char c, size_t pos = 0) const noexcept;

//rfind
/*查找最后一次出现的位置*/
string (1)	    size_t rfind (const string& str, size_t pos = npos) const noexcept;
c-string (2)	size_t rfind (const char* s, size_t pos = npos) const;
buffer (3)	    size_t rfind (const char* s, size_t pos, size_t n) const;
character (4)	size_t rfind (char c, size_t pos = npos) const noexcept;

//find_first_of
//只要找到匹配字符串中任一字符，就算找到位置
string (1)	    size_t find_first_of (const string& str, size_t pos = 0) const noexcept;
c-string (2)	size_t find_first_of (const char* s, size_t pos = 0) const;
buffer (3)	    size_t find_first_of (const char* s, size_t pos, size_t n) const;
character (4)	size_t find_first_of (char c, size_t pos = 0) const noexcept;
//find_last_of
//匹配字符串中的任一字符最后出现的位置
string (1)	    size_t find_last_of (const string& str, size_t pos = npos) const noexcept;
c-string (2)	size_t find_last_of (const char* s, size_t pos = npos) const;
buffer (3)	    size_t find_last_of (const char* s, size_t pos, size_t n) const;
character (4)	size_t find_last_of (char c, size_t pos = npos) const noexcept;

//find_first_not_of
//找到不在参数字符串的任一字符位置
string (1)	    size_t find_first_not_of (const string& str, size_t pos = 0) const noexcept;
c-string (2)	size_t find_first_not_of (const char* s, size_t pos = 0) const;
buffer (3)	    size_t find_first_not_of (const char* s, size_t pos, size_t n) const;
character (4)	size_t find_first_not_of (char c, size_t pos = 0) const noexcept;
//find_last_not_of
//找到不在参数字符串的最后一个字符位置
string (1)	    size_t find_last_not_of (const string& str, size_t pos = npos) const noexcept;
c-string (2)	size_t find_last_not_of (const char* s, size_t pos = npos) const;
buffer (3)	    size_t find_last_not_of (const char* s, size_t pos, size_t n) const;
character (4)	size_t find_last_not_of (char c, size_t pos = npos) const noexcept;
```



### 字符串IO及其他函数

#### *其他函数*

- [**c_str**](http://www.cplusplus.com/reference/string/string/c_str/)

  Get C string equivalent (public member function )，获取C风格的string（char*)
  const char* c_str() const noexcept;
  返回的是const char*一个指向常量字符串的指针。
  *const表示只读属性，其读法可以是从右往左来结合*

- [**data**](http://www.cplusplus.com/reference/string/string/data/)

  Get string data (public member function )
  const char* data() const noexcept;
  返回的是const char*一个指向常量字符串的指针。与c_str返回相同的值。
  
- [**get_allocator**](http://www.cplusplus.com/reference/string/string/get_allocator/)

  Get allocator (public member function )
  allocator_type get_allocator() const noexcept;
  返回的是分配器（为字符串分配内存的对象的copy）
  
- [**copy**](http://www.cplusplus.com/reference/string/string/copy/)

  Copy sequence of characters from string (public member function )
  size_t copy (char* s, size_t len, size_t pos = 0) const;
  复制子串给s，这个子串从pos开始，长度为len,*并且这个函数不会加上空字符在复制的内容后面（即"\0"）。*
  
- [**substr**](http://www.cplusplus.com/reference/string/string/substr/)

  Generate substring (public member function )
  string substr (size_t pos = 0, size_t len = npos) const;
  返回一个由这个对象子串的构造的新string对象。默认返回整个字符串的新对象。

#### *IO函数*
以下均是全局函数并非string的成员函数
- [**operator>>**](http://www.cplusplus.com/reference/string/string/operator>>/)

  Extract string from stream (function )
  istream& operator>> (istream& is, string& str);
  从输入流中提取一个字符串，将字符串存储在str中，并且这个字符串会替代str之前的值。每个提取的字符附加到字符串（这里指的并非str，可能是一个中间对象）上，就像调用成员函数push_back()一样。使用输入流提取字符串以空格作为分隔符。因此，此操作只会提取被视为“单词”的字符串。要提取整行，参见getline()。

- [**operator<<**](http://www.cplusplus.com/reference/string/string/operator<</)

  Insert string into stream (function )

- [**getline**](http://www.cplusplus.com/reference/string/string/getline/)

  Get line from stream into string (function )
  istream& getline (istream&  is, string& str, char delim);
  istream& getline (istream&& is, string& str, char delim);
  istream& getline (istream&  is, string& str);
  istream& getline (istream&& is, string& str);
  如上为getline函数原型，其中delim参数表示delimitation就是getline的界，表示读取到哪为止。这些函数表示从输入流中提取字符串，直到换行或者遇到了delim这个字符。
