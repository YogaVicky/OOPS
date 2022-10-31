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
        qstate = mysql_query(conn, "SELECT * FROM Student");
        if (!qstate){
            res = mysql_store_result(conn);
            while(row = mysql_fetch_row (res)){
                cout<<"StudentID : "<< row [0]<<endl;
                cout <<"Name: "<<row [1]<<endl;
                cout <<"Marks: "<< row [2]<<endl;
            }
        }
        else{
            cout<<"View Error"<<mysql_error(conn) << endl;
        }
    }
    else{
    	cout<<"Not Connected";
    }
	return 0;
}