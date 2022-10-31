#include<iostream>
using namespace std;
#include <mysql/mysql.h>
int main(){
    MYSQL *conn;
    int qstate;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "localhost", "testuser", "test", "oops2022", 0, NULL, 0);
    if (conn){
        if (conn){
        	cout<<"Connected"<<endl;
            qstate = mysql_query(conn,"INSERT INTO Student VALUES(2,'Rahul',90)");
            if (!qstate){
                cout<<"Inserted"<<endl;
            }
            else{
                cout<<"Insert Error"<<mysql_error(conn) << endl;
            }
        }
        else{
        	cout<<"Not Connected";
        }
    }
	return 0;
}