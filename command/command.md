##### Command模式

##### 动机（Motivation)

- 在软件构建过程中，“行为请求者”与行为实现者通常呈现出一种“紧耦合”。但在某些场合，比如需要对行为进行“记录、撤销、重返（undo/redo)、事务等处理，这种无法抵御变化的紧耦合是不适合的。
- 在这种情况下，如何将“行为请求者”和“行为实现者“解耦？将一组行为抽象为对象，可以实现二者之间的松耦合。

##### 模式定义

- 将一个请求（行为）封装为一个对象，从而使你可以用不同的请求对客户进行参数化；对请求排队或记录请求日志，以及支持可撤销的操作。《设计模式》

##### 要点总结

- Command模式的根本目的在于将”行为请求者“与”行为实现者“解耦，在面向对象语言中，常见的实现手段是”将行为抽象为对象“。
- 实现Command接口的具体命令对象ConcreteCommand有时候根据需要可能会保存一些额外的状态信息。通过使用Composite模式，可以将多个命令封装为一个“复合命令”MacroCommand。
- Command模式与C++中的函数对象 有些类似。但两者定义行为接口的规范有所区别：Command以面向对象中的“接口-实现”来定义行为接口规范，更严格，但 有性能损失；C++函数对象以函数签名来定义行为接口规范，更灵活，性能更高。

##### 代碼實現

```
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Command{
public:
    virtual void execute() = 0;
};

class CopyCommand:public Command{
public:
    int id;
    string arg;
public:
    CopyCommand(const string& a):arg(a){

    }

    void execute() override{
        cout << "#1 process..." << arg <<　endl;
    }
};

class CutCommand:public Command{
    int arg;
public:
    CutCommand(const int &a):arg(a){

    }
    void execute() override{
        cout << "#2 process..." << arg << endl;
    }
};

class PasteCommand:public Command{
    int arg;
public:
    PasteCommand(const int &a):arg(a){
    }
    void execute() override{
        cout << "#2 process.." << endl;
    }
};

class MacroCommand:public Command{
    vector<unique_ptr<Command>> commands;
public:
    void addCommand(unique_ptr<Command> c){
        commands.push_back(std::move(c));
    }

    void execute() override{
        for(auto &c : commands){
            c->execute();
        }
    }
};

void process(const Command& command){

}

template <typename T>
class FunctionObject{
public:
    void operator()(T data){

    }
};


int main()
{
    auto cmd1 = make_unique<CopyCommand>("Arg ###");
    auto cmd2 = make_unique<CutCommand>(190);

    MacroCommand macrol;
    macrol.addCommand(cmd1);
    macrol.addCommand(cmd2);
    macro.execute();
}
```
