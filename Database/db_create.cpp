#include<iostream>
using namespace std;
#include <mysql/mysql.h>
int main(){
  MYSQL *conn;
  MYSQL_ROW row;
  MYSQL_RES* res;
  int qstate;
  conn = mysql_init(0);
  conn = mysql_real_connect(conn, "localhost", "testuser", "test", "oops2022", 0, NULL, 0);
  if (conn){
    cout<<"Connected"<<endl;
        qstate = mysql_query(conn,"CREATE TABLE Student(StudentID int,Name text,Marks int)");
        if (!qstate){
            cout<<"Table Created"<<endl;
        }
        else{
            cout<<"Create Error"<<mysql_error(conn) << endl;
        }
    }
    else{
      cout<<"Not Connected";
    }
  return 0;
}