#include<iostream>
using namespace std;
#include <mysql/mysql.h>
int main(){
	MYSQL *conn;
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, "sql6.freemysqlhosting.net", "sql6449193", "hHQdh26Iai", "sql6449193", 0, NULL, 0);
	if (conn){
		cout<<"Connected"<<endl;
    }
    else{
    	cout<<"Not Connected";
    }
	return 0;
}