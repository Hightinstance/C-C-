
class Singletion{
   private:
      Singletion(){};
      Singletion( const Singletion &other );
   public:
      static Singletion* getInstance();
      static Singletion* m_instance;
};

Singletion::m_instance = nullptr;

/* 线程非安全版本 */
Singletion* Singletion::getInstance()
{
      if(  m_instance == nullptr )
      {
          m_instance = new Singletion();
      }
      return m_instance;
}

/* 线程安全版本 */
Singletion* Singletion::getInstance()
{
    Lock lock;  /* 加锁 */
    if( m_instance == nullptr )
    {
        m_instance = new Singletion();
    }

   return m_instance;
}

/* 双检查锁 但是由于内存 recoder导致不安全 */
Singletion* Singletion::getInstance()
{
    if( m_instance == nullptr )
    {
      Lock lock;  /* 加锁 */
      if( m_instance == nullptr )
      {
        m_instance = new Singletion();
      }
    }
   return m_instance;
}




