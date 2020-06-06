/* 备忘录 Menmento */

class Menmento{
	private:
	 string state;
	public:
     Menmento( const string &s )	
	 {
		 this.state = s;
	 }
	
	~Menmento(){}
	string getState(){
		return this.state;
	}
}


/* 原状态 */
class Origination{
	private:
	  string state;
	
	public:
	  Origination(){  }
	  Menmento createMenmento()
	  {
		Menmento m( this.state ) ; /* 保存状态 */
		return m ; 
	  }
	  
	  void setMenmeto( const Memento & m )
	  {
		  this.state = m.state;
	  }
}

int main()
{
	Origination  orginator;
	
	//捕获对象状态，存储到备忘录
    Memento mem = orginator.createMomento();
	orginator.setMenmeto( Memento  );
}





