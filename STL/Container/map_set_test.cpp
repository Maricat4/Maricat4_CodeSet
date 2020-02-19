#include "utility.hpp"
using namespace std;
namespace Map_Set_Test{
void map_set_init(){
    //initializer list
    map<int,char> m1{{5,'a'},{2,'b'},{6,'d'},{-1,'f'},{9,'z'}};
    set<int> s1 = {9,-85,8,67,699};
    showContainerContent(m1);
    showContainerContent(s1);
    auto it1 = m1.begin();
    auto it2 = s1.begin();
    cout<<*it2<<endl;
    it1->second = 'h';
    showContainerContent(m1);
}
void map_set_capcicity(){
    pair<int,int> a[10]{{1,2},{2,2},{3,2},{4,2},{5,2},{6,2},{7,2},{8,2},{9,2},{10,2}};
    vector<pair<int,int>> v1;
    //range
    map<int,int> m1(a,a+10);
    showContainerContent(m1);
    showVar(m1.size());
    showVar(m1.max_size());
    showVar(v1.max_size());
    showVar(v1.max_size()/m1.max_size());
    showVar(sizeof(map<int,int>));
    showVar(sizeof(pair<int,int>));
    showVar(m1.empty());
}
void map_set_lookup(){
    pair<int,char> p[10]{{1,'a'},{2,'b'},{3,'c'},{4,'d'},{5,'e'},{6,'f'},{7,'g'},{8,'h'},{9,'i'},{10,'j'}};
    map<int,char> m1(p,p+10);
    showContainerContent(m1);
    //find
    m1.find(8)->second = 'H';
    showContainerContent(m1);
    //lower_bound&&upper_bound
    auto it1 = m1.upper_bound(8);
    for (auto i = m1.lower_bound(5); i != it1; i++)
    {
        cout<<i->first<<",";
    }
    cout<<endl;

    //equal_bound
    pair<int,char> p1[10]{{1,'a'},{2,'b'},{3,'c'},{3,'d'},{3,'e'},{3,'f'},{3,'g'},{8,'h'},{9,'i'},{10,'j'}};
    multimap<int,char> multim1(p1,p1+10);
    auto pairit = multim1.equal_range(3);
    for (auto i = pairit.first; i != pairit.second; i++)
    {
        cout<<i->second<<",";
    }
    cout<<endl;
    showVar(multim1.count(3));
}

void map_set_modifiers(){
    pair<int,char> p[10]{{1,'a'},{2,'b'},{3,'c'},{4,'d'},{5,'e'},{6,'f'},{7,'g'},{8,'h'},{9,'i'},{10,'j'}};
    map<int,char> m1(p,p+10);
    showContainerContent(m1);
    //insert
    //single element,返回值是pair<iterator,bool>,
    //当插入已有的key数据时，不会覆盖，会插入不成功，返回的iterator
    auto it1 = m1.insert(pair<int,char>{11,'M'});
    auto it2 = m1.insert({11,'N'});
    showVar(it1.first->second);
    showVar(it2.second);
    showContainerContent(m1);
    //with hint,通过一个迭代器指引（可以是在相近key值附近的迭代器,这样可以提高效率，不然与普通insert没有区别）
    //最终返回的是迭代器，或者拥有相同key值的已有元素
    auto it3 = m1.insert(it1.first, {12,'P'});
    showVar(it3->first);
    showVar(it3->second);
    showContainerContent(m1);

    //range 返回值为空
    m1.insert(p,p+10);
    showContainerContent(m1);
    //initializer list,注意每一个value需要用花括号，用括号是错误的，其返回值也为空
    m1.insert({{78,'c'},{98,'d'}});
    showContainerContent(m1);

    //insert_or_assign
    m1.insert_or_assign(it3,98,'a');
    //使用的标准若不是C++17,上面的方法会无法运行
    cout<<__cplusplus<<endl;
    showContainerContent(m1);
    
    //extract 提取元素，同样会断开其在map中的连接
    auto value1 = m1.extract(98);
    showContainerContent(m1);
    showVar(value1.key());
    showVar(value1.mapped());

    pair<int,char> p1[10]{{1,'a'},{2,'b'},{3,'c'},{4,'d'},{5,'e'},{6,'f'},{7,'g'},{888,'h'},{999,'i'},{1000,'j'}};
    map<int,char> m2(p1,p1+10);
    showContainerContent(m2);
    m1.merge(m2);
    showContainerContent(m1);
    showContainerContent(m2);
    m2.clear();
    showContainerContent(m2);


}
//返回仿函数
void map_set_observers(){
    
}
}
int main(){
    try
    {
       //Map_Set_Test::map_set_init();      
       //Map_Set_Test::map_set_capcicity();   
       //Map_Set_Test::map_set_lookup();
       Map_Set_Test::map_set_modifiers();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    system("pause");
    
}