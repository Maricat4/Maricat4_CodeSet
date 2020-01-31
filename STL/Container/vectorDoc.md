# vector使用

## 构造、析构、以及赋值
- [**(constructor)**](http://www.cplusplus.com/reference/vector/vector/vector/)
  Construct vector (public member function )构造函数
  
  | 依据函数参数的分类   | 具体函数                                                     |
  | :------------------- | :----------------------------------------------------------- |
  | default (1)          | *vector(); <br>explicit vector (const allocator_type& alloc);* |
  | fill (2)             | *explicit vector (size_type n, const allocator_type& alloc = allocator_type());  <br> vector (size_type n, const value_type& val, const allocator_type& alloc = allocator_type());* |
  | range (3)            | *template < class InputIterator>   <br>vector (InputIterator first, InputIterator last,  const allocator_type& alloc = allocator_type());* |
  | copy (4)             | *vector (const vector& x); <br>vector (const vector& x, const allocator_type& alloc);* |
  | move (5)             | *vector (vector&& x); <br>vector (vector&& x, const allocator_type& alloc);* |
  | initializer list (6) | *vector (initializer_list<value_type> il,const allocator_type& alloc = allocator_type());* |
  Note:
  - 拷贝构造函数(copy,构造函数参数包含vector)需要定义的值类型与拷贝的值类型一致，并且是深拷贝，会开辟新空间。
  - move型构造函数，移动构造函数，C++11新特性，可以减少内存的分配与释放。
  
- [**(destructor)**](http://www.cplusplus.com/reference/vector/vector/~vector/)
  Vector destructor (public member function )

- [**operator=**](http://www.cplusplus.com/reference/vector/vector/operator=/)
  Assign content (public member function )
  copy (1)	vector& operator= (const vector& x);
  move (2)	vector& operator= (vector&& x);
  initializer list (3)	vector& operator= (initializer_list<value_type> il);
  
- [**assign**](http://www.cplusplus.com/reference/vector/vector/assign/)
  range (1)           template <class InputIterator>
              void assign (InputIterator first, InputIterator last);
  fill (2)	               void assign (size_type n, const value_type& val);
  initializer list(3)   void assign (initializer_list<value_type> il);
  
  普普通通的操作符重载以及赋值函数

## 元素访问

| 访问方式   | 具体函数                                                     |
| ---------- | ------------------------------------------------------------ |
| at()       | //带有边界检查的元素访问方式<br>reference   at( size_type pos );<br>const_reference at( size_type pos ) const; |
| operator[] | reference       operator[ ] ( size_type pos );<br>const_reference operator[ ] ( size_type pos ) const; |
| front      | // 访问第一个元素<br>reference front();<br>const_reference front() const; |
| back       | //访问最后一个元素<br> reference back();<br>const_reference back() const; |
| data       | //直接访问隐藏的数组，注意与string不同这里有T * 的重载，而string只有返回const T* 的重载<br>T*   data();          (since C++11)<br>const T* data() const;(since C++11) |
|  |            |

### 迭代器

| begin()<br>cbegin() //const iterator   | returns an iterator to the beginning (public member function) |
| :------------------------------------- | -----------------------------------------------------------: |
| end()<br>cend() //const iterator       |      returns an iterator to the end (public member function) |
| rbegin()<br>crbegin() //const iterator | returns a reverse iterator to the beginning (public member function) |
| rend()<br>crend() //const iterator     | returns a reverse iterator to the end (public member function) |

## 容量与大小

| Capacity                           |                                                              |
| ---------------------------------- | -----------------------------------------------------------: |
| bool empty() const;                | checks whether the container is empty (public member function)<br>检验是否存储的数据为0个，若为0,返回true,否则返回false |
| size_type size() const;            | returns the number of elements (public member function)<br>当前存储的数据大小（个数） |
| size_type max_size() const;        | returns the maximum possible number of elements (public member function)<br>存储该类型的最大数目 |
| void reserve( size_type new_cap ); |                    reserves storage (public member function) |
| size_type capacity() const;        | returns the number of elements that can be held in currently allocated storage (public member function)<br>当前所申请的内存空间大小 |
| void shrink_to_fit();<br>//(C++11) | reduces memory usage by freeing unused memory (public member function)<br>这个函数会申请当前大小的空间，并转移数据 |

## vector的修改

| Modifiers                 |                                                              |
| ------------------------- | :----------------------------------------------------------- |
| void clear();             | clears the contents (public member function)<br>void clear() noexcept;<br>清除过后，beign()==end(),但是size()==0,capacity()等于原来的空间 |
| insert()                  | inserts elements (public member function) <br>返回的是插入元素的位置（迭代器）<br>single element                               (1)<br>iterator insert (const_iterator position, const value_type& val);<br>fill                                                     (2)<br>iterator insert (const_iterator position, size_type n, const value_type& val);<br>range                                               (3)<br>template < class InputIterator><br>iterator insert (const_iterator position, InputIterator first,InputIterator last)<br>move                                               (4)<br>iterator insert (const_iterator position, value_type&& val);<br>initializer list                                  (5)<br>iterator insert (const_iterator position, initializer_list<value_type> il); |
| emplace() <br>//C++11     | constructs element in-place (public member function)<br>根据要插入的位置，以及各参数，构造一个新元素插入，返回的是插入元素的位置（迭代器）<br>template< class... Args ><br/>iterator emplace( const_iterator pos, Args&&... args ); |
| erase()                   | erases elements (public member function)<br>返回的是最后一个被删除元素后一个元素<br>1.single element<br>iterator erase( iterator pos );<br>iterator erase( const_iterator pos ); <br>2.range<br>iterator erase (const_iterator first, const_iterator last);<br>iterator erase (const_iterator first, const_iterator last); |
| push_back()               | adds an element to the end (public member function)<br>void push_back (const value_type& val); <br>void push_back (value_type&& val); |
| emplace_back()<br>//C++11 | constructs an element in-place at the end (public member function)<br>template <class... Args>   <br>void emplace_back (Args&&... args); |
| pop_back()                | removes the last element (public member function)<br>void pop_back(); |
| resize()                  | changes the number of elements stored (public member function)<br>void resize (size_type n); <br>void resize (size_type n, const value_type& val) |
| swap()                    | swaps the contents (public member function)<br>交换两个vector的内容<br>void swap (vector& x); |

