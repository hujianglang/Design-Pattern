#include "template.h"
#include <iostream>

using namespace std;

AbstractClass::AbstractClass()
{

}

AbstractClass::~AbstractClass()
{

}

void AbstractClass::templateMethod()
{
    this->primitiveOperation1();
    this->primitiveOperation2();
}

ConcreteClass1::ConcreteClass1()
{

}

ConcreteClass1::~ConcreteClass1()
{

}

void ConcreteClass1::primitiveOperation1()
{
    cout << "concreteclass1 primitiveOperation1";
}

void ConcreteClass1::primitiveOperation2()
{
    cout << "concreteclass1 primitiveOperation2";
}


ConcreteClass2::ConcreteClass2()
{


}

ConcreteClass2::~ConcreteClass2()
{

}

void ConcreteClass2::primitiveOperation1()
{
    cout << "concreteclass2 primitiveOperation1";
}

void ConcreteClass2::primitiveOperation2()
{
    cout << "concreteclass2 primitiveOperation2";
}
