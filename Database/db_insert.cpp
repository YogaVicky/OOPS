#include<iostream>
using namespace std;
#include <mysql/mysql.h>
int main(){
	MYSQL *conn;
	MYSQL_ROW row;
    MYSQL_RES* res;
    int qstate;
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, "sql6.freemysqlhosting.net", "sql6449193", "hHQdh26Iai", "sql6449193", 0, NULL, 0);
	if (conn){
		cout<<"Connected"<<endl;
        string s = "";
        const char* q = s.c_str();
        qstate = mysql_query(conn,"INSERT INTO People VALUES(3,'Subin','Subin Address,Kanyakumari','Kanyakumari')");
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
	return 0;
}