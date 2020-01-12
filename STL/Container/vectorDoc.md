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
| data       | //直接访问隐藏的数组(vector就是一个可动态增长的数组,一旦超出所分配的内存就会申请另一块内存保存数据---一般是原先的两倍大小，然后移动元素)<br>T*   data();          (since C++11)<br>const T* data() const;(since C++11) |
|  |            |



<p>简单列一些比较经典的paper：</p><ul><li>碰撞检测（GJK[3]、sweep-and-prune[6]、SAT[7]）</li><li>粒子模拟 [1][13]</li><li>刚体模拟 [2][4][12]</li><li>柔体模拟（mass-and-spring[5]、shape matching[11]）</li><li>流体模拟（stable fluid[8]、particle level set[9]、smoothed-particle hydrodynamics[10]）</li></ul><p>参考</p><p>[1] Reeves, William T. &#34;Particle systems—a technique for modeling a class of fuzzy objects.&#34;<i>ACM Transactions on Graphics (TOG)</i>2.2 (1983): 91-108.</p><p>[2] Moore, Matthew, and Jane Wilhelms. &#34;Collision detection and response for computer animation.&#34;<i>ACM Siggraph Computer Graphics</i>. Vol. 22. No. 4. ACM, 1988.</p><p>[3] Gilbert, Elmer G., Daniel W. Johnson, and S. Sathiya Keerthi. &#34;A fast procedure for computing the distance between complex objects in three-dimensional space.&#34;<i>IEEE Journal on Robotics and Automation</i>4.2 (1988): 193-203.</p><p>[4] Baraff, David. &#34;Analytical methods for dynamic simulation of non-penetrating rigid bodies.&#34;<i>ACM SIGGRAPH Computer Graphics</i>. Vol. 23. No. 3. ACM, 1989.</p><p>[5] Baraff, David, and Andrew Witkin. &#34;Large steps in cloth simulation.&#34;<i>Proceedings of the 25th annual conference on Computer graphics and interactive techniques</i>. ACM, 1998.</p><p>[6] Cohen, Jonathan D., et al. &#34;I-collide: An interactive and exact collision detection system for large-scale environments.&#34;<i>Proceedings of the 1995 symposium on Interactive 3D graphics</i>. ACM, 1995.</p><p>[7] Gottschalk, Stefan, Ming C. Lin, and Dinesh Manocha. &#34;OBBTree: A hierarchical structure for rapid interference detection.&#34;<i>Proceedings of the 23rd annual conference on Computer graphics and interactive techniques</i>. ACM, 1996.</p><p>[8] Stam, Jos. &#34;Stable fluids.&#34; <i>Proceedings of the 26th annual conference on Computer graphics and interactive techniques</i>. ACM Press/Addison-Wesley Publishing Co., 1999.</p><p>[9] Enright, Douglas, Stephen Marschner, and Ronald Fedkiw. &#34;Animation and rendering of complex water surfaces.&#34;<i>ACM Transactions on Graphics (TOG)</i>. Vol. 21. No. 3. ACM, 2002.</p><p>[10] Müller, Matthias, David Charypar, and Markus Gross. &#34;Particle-based fluid simulation for interactive applications.&#34;<i>Proceedings of the 2003 ACM SIGGRAPH/Eurographics symposium on Computer animation</i>. Eurographics Association, 2003.</p><p>[11] Müller, Matthias, et al. &#34;Meshless deformations based on shape matching.&#34;<i>ACM transactions on graphics (TOG)</i>. Vol. 24. No. 3. ACM, 2005.</p><p>[12] Müller, Matthias, et al. &#34;Position based dynamics.&#34;<i>Journal of Visual Communication and Image Representation</i>18.2 (2007): 109-118.</p><p>[13] Macklin, Miles, et al. &#34;Unified particle physics for real-time applications.&#34;<i>ACM Transactions on Graphics (TOG)</i>33.4 (2014): 153.</p>



[1]Physically Based Deformable Models in Computer Graphics

[2]Interactive Simulation of Rigid Body Dynamics in Computer Graphics

感脚基于物理的模拟的步伐是随者计算力学走，Meshless Method，Material Point Method，Peridynamics Methods