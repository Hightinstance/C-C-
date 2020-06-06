
class Singletion{
   private:
      Singletion(){};
      Singletion( const Singletion &other );
   public:
      static Singletion* getInstance();
      static Singletion* m_instance;
};

Singletion::m_instance = nullptr;

/* �̷߳ǰ�ȫ�汾 */
Singletion* Singletion::getInstance()
{
      if(  m_instance == nullptr )
      {
          m_instance = new Singletion();
      }
      return m_instance;
}

/* �̰߳�ȫ�汾 */
Singletion* Singletion::getInstance()
{
    Lock lock;  /* ���� */
    if( m_instance == nullptr )
    {
        m_instance = new Singletion();
    }

   return m_instance;
}

/* ˫����� ���������ڴ� recoder���²���ȫ */
Singletion* Singletion::getInstance()
{
    if( m_instance == nullptr )
    {
      Lock lock;  /* ���� */
      if( m_instance == nullptr )
      {
        m_instance = new Singletion();
      }
    }
   return m_instance;
}


