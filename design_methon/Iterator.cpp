template<typename T>
class Ierator{
public:
	virtual void first() = 0;
	virtual void next() = 0;
	virtual bool isDone() const = 0;
	virtual T& current() = 0;
}

template< typename T >
class MyCollection{
	public:
	  Iterator<T> GetIterator(){
        //...
    }
}


template< typename T >
class CollectionIterator: public Ierator
{
	public:
	CollectionIterator(const MyCollection<T> & c): mc(c){ }
	void frist override(){
		
		
	}
	void next() override {
        
    }
    bool isDone() const override{
        
    }
    T& current() override{
        
    }
}

void MyAlgorithm()
{
    MyCollection<int> m;
	Iterator<int> iter = m.GetIterator();
	
	for(iter.frist();!iter.isDone(),iter.next)
	{
		cout<<iter.current()<<endl;
	}
}






