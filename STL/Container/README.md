# STL的使用
## string
string相当于basic_string<char>,其中basic_string<T>为字符串模板类，该模板提供了许多字符串类所需的成员以及方法，其中T为单个字符所属的类型。basic_string<T>没有虚函数，这点和其他标准库类型一致，当需要设计更复杂的文字处理类时，可以用它加以实现。

``` C++
1.string的构造与析构-constructor and destructor
构造:
    //C++ reference
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
```C++
2.元素访问-Element Access
    1)通过以下方式访问元素
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
    2)通过迭代器访问
    begin	Return iterator to beginning (public member function )
    end		Return iterator to end (public member function )
    //反向迭代器，reverse_iterator<iterator>
    rbegin	Return reverse iterator to reverse beginning (public member function )
    rend	Return reverse iterator to reverse end (public member function )
    //const_iterator是指向const character的迭代器,意味着无法修改这个只有读权限
    //当去修改时，会报错“表达式必须是可修改的左值”
    //以下均为C++11新特性
    //其类型：const_iterator,reverse_iterator<const_iterator>
    cbegin  Return const_iterator to beginning (public member function )
    cend  	Return const_iterator to end (public member function )
    crbegin Return const_reverse_iterator to reverse beginning (public member function )
    crend  	Return const_reverse_iterator to reverse end (public member function )
    
```
```C++
3.字符串的修改
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

    push_back    Append character to string (public member function )
    assign	       Assign content to string (public member function )
    insert	        Insert into string (public member function )
    erase	      Erase characters from string (public member function )
    replace          Replace portion of string (public member function )
    swap 	      Swap string values (public member function )
    pop_back      Delete last character (public member function )
```
