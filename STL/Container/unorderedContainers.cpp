#include "utility.hpp"
using namespace std;

namespace unordered_test{
    //探索内在结构
    void deepExplore(){
        unordered_map<string,int> m1;
        showVar(sizeof(unordered_map<string,int>));

    }
    //构造赋值，有关
    void init(){
        //empty
        unordered_map<string,int> m1(17);
        unordered_map<string,int> m2;
        //设置的桶数量
        showVar(m1.bucket_count());
        //默认桶数量为1
        showVar(m2.bucket_count());
        //range
        pair<string,int> p1[] = {{"gao",1},{"wang",2},{"love",3},{"you",4}};
        unordered_map<string,int> m3(p1,p1+4,7);
        showVar(m3.bucket_count());
        showContainerContent(m3);

        //initializer list
        unordered_map<string,int> m4{{"gao",1},{"wang",2},{"love",3},{"you",4}};
        showVar(m4.bucket_count());
        showContainerContent(m4);  
    }
    void Modifiers(){
        //insert&&emplace
        // default_random_engine r1;
        // uniform_int_distribution<unsigned> u(0, 20);
        // r1.seed(10);

        unordered_map<int,int> m1;
        m1.rehash(1);
        auto hashfun = m1.hash_function();
        
        showVar(m1.bucket_count());
        for (size_t i = 0; i < 5; i++)
        {
            m1.emplace(i,i);
            showVar(hashfun(i));
        }
        showVar(m1.bucket_count());
        showVar(m1.load_factor());
        showContainerContent(m1);
        m1.insert_or_assign(1,2);
        showContainerContent(m1);

        //extract 提取出元素，修改其key值，利用move塞回去
        auto a1 = m1.extract(4);
        a1.key() = 5;
        m1.insert(move(a1));
        showContainerContent(m1);



    }
    void lookup(){

    }
    void bucket(){
        unordered_map<int,int> m1;
        for (size_t i = 0; i < 5; i++)
        {
            m1.emplace(i,i);
        }
        showContainerContent(m1);
        //bucket
        for (size_t i = 0; i < 5; i++)
        {
            cout<<m1.bucket(i)<<",";
        }
        cout<<endl;
        m1.emplace(5,5);
        showContainerContent(m1);
        //bucket_cout 桶的数量
        showVar(m1.bucket_count());
        for (size_t i = 0; i < 5; i++)
        {
            //显示桶中元素数量
            showVar(m1.bucket_size(i));
        }
        //最大数量
        showVar(m1.max_bucket_count());
        showVar(m1.max_size());
        unordered_multimap<int,int> m2;
        showVar(m2.load_factor());
        m2.max_load_factor(3.0);
        for (size_t i = 0; i < 1000; i++)
        {
            m2.insert(pair<int,int>(i,i));
        }
        showVar(m2.load_factor());
        showVar(m2.max_load_factor());
        showVar(m2.size());
        showVar(m2.bucket_count());
        double d = m2.size()/(double)m2.bucket_count();
        showVar(d);
        int i1 = 0;
        //寻找第一个元素数量大于1的桶
        for (size_t i = 0; i < m2.bucket_count(); i++)
        {
            i1 = m2.bucket_size(i) > 1 ? m2.bucket_size(i) : 0 ;
            if(i1>0) break;
        }
        auto it1 = m2.begin(i1);
        auto it2 = m2.end(i1);
        for ( ; it1 != it2; it1++)
        {
            cout<<it1->first<<","<<it1->second<<endl;
        }
    }
    void hashpolicy(){
        unordered_multimap<int,int> m1;
        m1.max_load_factor(3.0);
        for (size_t i = 0; i < 1000; i++)
        {
            m1.insert(pair<int,int>(i,i));
        }
        showVar(m1.max_load_factor());
        showVar(m1.load_factor());
        m1.rehash(1000);
        showVar(m1.max_load_factor());
        showVar(m1.load_factor());
    }
}


int main(){
    try
    {
        // unordered_test::deepExplore();
        // unordered_test::init();
        // unordered_test::Modifiers();
        // unordered_test::bucket();
        unordered_test::hashpolicy();

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    system("pause");
}