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
  - move型构造函数，其参数包含vector 右值引用
  
  
- [**(destructor)**](http://www.cplusplus.com/reference/vector/vector/~vector/)
  Vector destructor (public member function )

- [**operator=**](http://www.cplusplus.com/reference/vector/vector/operator=/)
  Assign content (public member function )