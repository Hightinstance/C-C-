#include<stdio.h>
#include<stdlib.h>
using namespace std;

enum class RequestType{
	REQ_HANDLER1,
    REQ_HANDLER2,
    REQ_HANDLER3
};
class Request{
     private:
	 string description;
	 RequestType reqType;
	 
     public:
	 Request( const string &desc, RequestType type  ):description( desc ),:reqType( type ){}
	 RequestType getType() const { return type }
	 const string& getDescription() const { return description; }
};


class ChainHandler{
private;
	ChainHandler  *nextChain;
	void sendReqestToNextHandler( const Request &req )
	{
		if( nextChain != nullptr )
		{
			nextChain->handle(req);
		}
	}
protected:
   ChainHandler(){ nextChain = nullptr; }
   /* 设置下一个节点 */
   void setNextChain(){  ChainHandler* next } 
   {
		nextChain = next;
   }
   /* 判断当前对象是否能够处理这个请求不能处理向后移动链表 */
    void handle(const Reqest & req)
    {
        if (canHandleRequest(req))
            processRequest(req);
        else
            sendReqestToNextHandler(req);
    }
}

class Handler1 : public ChainHandler{
protected:
    bool canHandleRequest(const Reqest & req) override
    {
        return req.getReqType() == RequestType::REQ_HANDLER1;
    }
    void processRequest(const Reqest & req) override
    {
        cout << "Handler1 is handle reqest: " << req.getDescription() << endl;
    }
};
        
class Handler2 : public ChainHandler{
protected:
    bool canHandleRequest(const Reqest & req) override
    {
        return req.getReqType() == RequestType::REQ_HANDLER2;
    }
    void processRequest(const Reqest & req) override
    {
        cout << "Handler2 is handle reqest: " << req.getDescription() << endl;
    }
};

class Handler3 : public ChainHandler{
protected:
    bool canHandleRequest(const Reqest & req) override
    {
        return req.getReqType() == RequestType::REQ_HANDLER3;
    }
    void processRequest(const Reqest & req) override
    {
        cout << "Handler3 is handle reqest: " << req.getDescription() << endl;
    }
};


int main(){
    Handler1 h1;
    Handler2 h2;
    Handler3 h3;
    h1.setNextChain(&h2);
    h2.setNextChain(&h3);
    
    Reqest req("process task ... ", RequestType::REQ_HANDLER3);
    h1.handle(req);
    return 0;
}

