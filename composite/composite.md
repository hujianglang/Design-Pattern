#### Composite组合模式

##### “数据结构”模式

- 常常有一些组件在内部具有特定的数据结构，如果让客户程序依赖这些特定的数据结构，将极大地破坏组件的复用。这时候，将这些特定的数据结构封装在内部，在外部提供统一的接口，来实现与特定数据结构无关的访问，是一种行之有效的解决方案。
- 典型模式
  - Composite
  - Iterator
  - Chain of Resposibility

```c++
#include <algorithm>
using namespace std;

class Component
{
    public:
    	virtual void process() = 0;
    	virtual ~Component(){}
};

class Composite:public Component
{
	string name;
	list<Component*> elements;
	public:
		Composite(const string& s):name(s){}
		void add(Component* element)
		{
			elements.push_back(element);
		}
		
		void remove(Component* element)
		{
			elements.remove(element);
		}
		void process()
		{
			//process current node
			//process leaf nodes
			for(auto &e:elements)
				e->process();//多态调用
		}
};

//叶子节点
class Leaf : public Component
{
	string name;
	public:
		Leaf(string s) ： name(s){}
		void process()
		{
			//process current node
		}
}；

void Invoke(Component& c)
{
    //...
    c.process();
    //...
}

int main()
{
    Composite root("root");
    Composite treeNode1("treeNode1");
    Composite treeNode2("treeNode2");
    Composite treeNode3("treeNode3");
    Composite treeNode4("treeNode4");
    
    Leaf leaf1("leaf1");
    Leaf leaf2("leaf2");
    
    root.add(&treeNode1);
    treeNode1.add(&treeNode2);
    treeNode2.add(&leaf1);
    
    root.add(&treeNode3);
    treeNode3.add(&treeNode4);
    treeNode4.add(&leaf2);
    
    process(root);
    process(leaf2);
    process(treeNode3);
}
```

##### 模式定义

- 将对象组合成树形结构以表示“部分-整体”的层次结构。Composite使得用户对单个对象和组合对象的使用具有一致性（稳定）。《设计模式》

##### 要点总结

- Composite模式采用树形结构来实现普遍存在的对象容器，从而将“一对多”的关系转化为“一对一”关系，使得客户代码可以 一致地（复用）处理对象和对象容器，无需关心处理的是单个的对象，还是组合的对象容器。
- 将“客户代码与复杂的对象容器结构”解耦是Composite的核心思想，解耦之后，客户代码将与纯粹的抽象接口-而非对象容器的内部实现结构-发生依赖，从而更能应对“变化”。
- Composite模式在具体实现中，可以让父对象中的子对象反向追溯；如果父对象有频繁的遍历需求，可使用缓存技巧来改善效率。
