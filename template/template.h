#ifndef TEMPLATE_H
#define TEMPLATE_H

class AbstractClass
{
public:
    virtual ~AbstractClass();
    void templateMethod();
protected:
    virtual void primitiveOperation1() = 0;
    virtual void primitiveOperation2() = 0;
    AbstractClass();
private:
};



class ConcreteClass1:public AbstractClass
{
public:
    ConcreteClass1();
    ~ConcreteClass1();
protected:
    void primitiveOperation1();
    void primitiveOperation2();
};

class ConcreteClass2:public AbstractClass
{
public:
    ConcreteClass2();
    ~ConcreteClass2();
protected:
    void primitiveOperation1();
    void primitiveOperation2();
};


#endif // TEMPLATE_H
