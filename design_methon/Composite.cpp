class Compoent{
	public:
	 Compoent(){}
	 ~Compoent(){}
	 virtual void Process() = 0; /* 不同对象不同时间 1-多 转换成 1-1 1-N */
}

/* 树节点 */
class Composite  : public Component
{
	private:
	  string name;
	  list<Component*> elements;
	
	public:
	  Composite(const string & s) : name(s) {}
	  
	  void add( Component* element )
	  {
		  elements.push_back(element);
	  }
	  
	  void remove( Component* element )
	  {
		  elements.remove(element);
	  }
	  
	  void Process()
	  {
        //2. process leaf nodes
        for (auto &e : elements)
            e->process(); //多态调用  子节点树形结构 1-多 
		   
	  }
}

//叶子节点
class Leaf : public Component{
    string name;
public:
    Leaf(string s) : name(s) {}
            
    void process(){
        //process current node    //process current node
    }
};

void Invoke(Component & c){
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
    Leaf leat1("left1");
    Leaf leat2("left2");
    
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





