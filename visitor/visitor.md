#### Visitor模式

##### 动机（Motivation)

- 在软件构建过程中，由于需求的变化，某些类层次结构中常常需要增加新的行为（方法），如果直接在基类中做这样的更改，将会给子类带来很繁重的变更负担，甚至破坏原有设计。
- 如何在不更改类层次结构的前提下，在运行时根据需要透明地为类层次结构上的各个类动态添加新的操作，从而避免上述问题？

```c++
#include <iostream>
using namespace std;

class Visitor;

class Element
{
    public:
    	virtual void accept(Visitor& visitor)=0;//第一次多态辨析
    	virtual ~Element(){}
};

class ElementA:public Element
{
	public:
		void accept(Visitor& visitor) override
		{
			visitor.visitElementA(*this);
		}
};

class ElementB:public Element
{
	public:
		void accept(Visitor& visitor) override
		{
			visitor.visitElementB(*this);//第二次动态辨析
		}
};

class Visitor
{
    public:
    	virtual void visitElementA(ElementA& element) = 0;
    	virtual void visitElementB(ElementB& element) = 0;
    	virtual ~Visitor(){}
};

class Visitor1:public Visitor
{
	public:
		void visitElementA(ElementA& element) override
		{
			cout << "Visitor1 is processing ElementA" << endl;
		}
		
		void visitElementB(ElementB& element) override
		{
			cout << "Visitor1 is processing ElementB" << endl;
		}
};

class Visitor2:public Visitor
{
	public:
		void visitElementA(ElementA& element) override
		{
			cout << "Visitor2 is processing ElementA" << endl;
		}
		
		void visitElementB(ElementB& element) override
		{
			cout << "Visitor2 is processing ElementB" << endl;
		}
};

int main()
{
    Visitor2 visitor;
    ElementB element;
    element.accept(visitor);
    
    ElementA elementA;
    elementA.accept(visitor);
    return 0;
}
```

##### 要点总结

- Visitor模式通过所谓的双重分发（double dispatch)来实现在不更改（不添加新的操作-编译时）Element类层次结构的前提下，在运行时透明地为类层次结构上的各个类动态添加新的操作（支持变化）。
- 所谓双重分发即Visitor模式中间包括了两个多态分发（注意其中的多态机制）：第一个为accept方法的多态辨析；第二个为visitElementX方法的多态辨析。
- Visitor模式的最大缺点在于扩展类层次结构（增添新的Element子类），会导致Visitor的改变。因此Visitor模式适用于“Element“类层次结构稳定，而其中的操作却经常面临频繁改动”。
