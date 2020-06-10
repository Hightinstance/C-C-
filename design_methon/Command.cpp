#include<iosrteam>
#include<vector>
#include<string>
using namespace std;

class Command
{
	public:
	   virtual void execute() = 0;
}


/* 命令本身和具体实现依赖关系抽象出来，定义具体的命令实现变化 */
class ConcreteCommand1 : public Command
{
    string arg;
public:
    ConcreteCommand1(const string & a) : arg(a) {}
    void execute() override
    {
        cout<< "#1 process..."<<arg<<endl;
    }
};

class ConcreteCommand2 : public Command
{
    string arg;
public:
    ConcreteCommand2(const string & a) : arg(a) {}
    void execute() override
    {
        cout<< "#2 process..."<<arg<<endl;
    }
};
        
        
class MacroCommand : public Command
{
    vector<Command*> commands;
public:
    void addCommand(Command *c) { commands.push_back(c); }
    void execute() override
    {
        for (auto &c : commands)
        {
            c->execute();
        }
    }
};        
int main()
{

    ConcreteCommand1 command1(receiver, "Arg ###");
    ConcreteCommand2 command2(receiver, "Arg $$$");
    
    MacroCommand macro;
    macro.addCommand(&command1);
    macro.addCommand(&command2);
    
    macro.execute();

}