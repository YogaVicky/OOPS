#include<iostream>
using namespace std;
#include <mysql/mysql.h>
int main(){
	MYSQL *conn;
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, "localhost", "testuser", "test", "oops2022", 0, NULL, 0);
	if (conn){
		cout<<"Connected"<<endl;
    }
    else{
    	cout<<"Not Connected"<<endl;
    }
	return 0;
}