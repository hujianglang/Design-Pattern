#### 状态模式

##### “状态变化”模式

- 在组件构建过程中，某些对象的状态经常面临着变化，如何对这些变化进行有效的管理？同是又维持高层模块的稳定？“状态变化”模式为这一问题提供了一种解决方案。
- 典型模式
  - State
  - Memento

##### 动机（Motivation)

- 在软件构建过程中，某些对象的状态如果改变，其行为也会随之而发生变化，比如文档处于只读状态，其支持的行为和读写状态支持的行为就可能完全不同。
- 如何在运行时根据对象的状态来透明地更改对象的行为？而不会为对象操作和状态转换之间引入紧耦合？

```C++
enum NetworkState
{
    Network_Open,
    Network_Close,
    Network_Connect,
    Network_Wait,//如何修改以下代码？
};

class NetworkProcessor
{
    NetworkState state;
    public:
    	void Operation1()
        {
            if(state == Network_Open)
            {
                //....
                state = Network_Close;
            }
            else if(state == Network_Close)
            {
                //....
                state = Network_Connect;
            }
            else if(state == Network_Connect)
            {
                //....
                state = Network_Open;
            }
        }
    	void Operation2()
        {
            if(state == Network_Open)
            {
                //..
                state = Network_Connect;
            }
            else if(state == Network_Close)
            {
                //...
                state == Network_Open;
            }
            else if(state == Network_Connect)
            {
                //...
                state = Network_Close;
            }
        }
}

修改为：
class NetworkState
{
    public:
    	NetworkState* pNext;
    	virtual void Operation1()=0;
    	virtual void Operation2()=0;
    	virtual void Operation3()=0;
    	virtual ~NetworkState(){}
};

class OpenState:public NetworkState
{
	static NetworkState* m_instance;
	public:
		static NetworkState* getInstance()
		{
			if(m_instance == nullptr)
				m_instance = new OpenState();
		}
		
		void Operation1()
		{
			//...
			pNext = CloseState::getInstance();
		}
		void Operation2()
		{
			//...
			pNext = ConnectState::getInstance();
		}
		void Operation3()
		{
			//..
			pNext = OpenState::getInstance();
		}
}

class CloseState:public NetworkState
{
	//
};

//扩展方法
class WaitState:public NetworkState
{
	//...
};

class NetworkProcessor
{
    NetworkState* pState;
    public:
    	NetworkProcessor(NetworkState* pState)
        {
            this->pState = pState;
        }
    	
    	void Operation1()
        {
            //..
            pState->Operation1();
            pState = pState->pNext;
        }
    	void Operation2()
        {
            //..
            pState->Operation2();
            pState = pState->pNext;
        }
    	void Operation3()
        {
            //..
            pState->Operation3();
            pState = pState->pNext; 
        }
}
```

##### 模式定义

- 允许一个对象在其内部状态改变时改变它的行为。从而使对象看起来似乎修改了其行为。《设计模式》

##### 要点总结

- State模式将所有与一个特定状态相关的行为都放入一个State的子类对象中，在对象状态切换时，切换相应的对象；但同时维持State的接口，这样实现了具体操作与状态转换之间的解耦。

- 为不同的状态引入不同的对象使得状态转换变得更加明确，而且可以保证不会出现状态不一致的情况，因为转换是原子性的，即 要么彻底转换过来，要么不转换。

- 如果State对象没有实例变量，那么各个上下文可以共享同一个State对象，从而节省对象开销。

  

