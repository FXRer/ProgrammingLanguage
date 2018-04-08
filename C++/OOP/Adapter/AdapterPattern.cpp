#include <iostream>
#include <string>
using namespace std;
 
class IDBConnection
{
public:
   virtual bool connectX(const string& sHost, const string& sDb, const string& sUserName, const string& sPassword) = 0;
   virtual bool closeX() = 0;
   virtual bool execX(const string& sQuery) = 0;
};
 
class CDBConnectionX:public IDBConnection
{
 
public:
   CDBConnectionX();
 
   bool connectX(const string& sHost, const string& sDb, const string& sUserName, const string& sPassword){
      cout<<"\n Connecting database through lib X";
   }
 
   bool closeX(){
      cout<<"\n Closing database through lib X";
   }
 
   bool execX(const string& sQuery){
      cout<<"\n Executing the database query through lib X";
   }
 
};
 
class CDBConnectionY
{
public:
   CDBConnectionY() {};
   bool connectY(const string& sHost, const string& sDb, const string& sUserName, const string& sPassword){
      cout<<"\n Connecting database through lib Y";
      return true;
   }
 
   bool closeY(){
      cout<<"\n Closing database through lib Y";
      return true;
   }
 
   bool execY(const string& sQuery){
      cout<<"\n Executing the database query through lib Y";
      return true;
   }
};
 
class CDBConnectionAdapterY: public IDBConnection
{
 
public:
   CDBConnectionAdapterY():m_pDbConn(NULL) { m_pDbConn = new CDBConnectionY; }
   bool connectX(const string& sHost, const string& sDb, const string& sUserName, const string& sPassword){
      cout<<"\n Connecting database through adapter";       
      m_pDbConn->connectY(sHost, sDb, sUserName, sPassword);
      return true;
   }
 
   bool closeX(){
      cout<<"\n Closing database through adapter";       
      m_pDbConn->closeY();
      return true;
   }
 
   bool execX(const string& sQuery){
      cout<<"\n Executing the database query through adapter";       
      m_pDbConn->execY(sQuery);
      return true;
   }
private:
   CDBConnectionY* m_pDbConn;
};
 
int main()
{
   IDBConnection *pDbConnection = new CDBConnectionAdapterY();
   pDbConnection->connectX("localhost","root", "admin","pwd");
   pDbConnection->execX("Select * from user");
   
   return 0;
}
