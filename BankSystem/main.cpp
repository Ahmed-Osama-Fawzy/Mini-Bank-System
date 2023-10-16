#include <iostream>
#include "BankAccount.h"
#include "Client.h"
#include "BankApplication.h"
#include "sqlite3.h"
sqlite3 *db;
sqlite3_stmt *stmt;
int result;

void Open(){
    if(sqlite3_open("Users.db" , & db) == SQLITE_OK ){
        // To Set NEw TAble & NAames IT With (Users)
    result =sqlite3_prepare_v2(db , "CREATE TABLE IF NOT EXISTS Users(Name VARCHAR(100), Password VARCHAR(100), Email VARCHAR(100), Phone VARCHAR(100)) ;" , -1 ,&stmt , NULL );
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
       // To Check If The Connect With The Database Are Right OR HAve Error To Show IT & Exit The Progarm WIth Errors
        if (result != SQLITE_OK){
            cout << "you Have Error is: "<< sqlite3_errmsg(db)<<endl;
        }else{
            cout << "success Connections" << endl;
        }
    }else{
        cout << "You Have Error in Connection With Database is:" << sqlite3_errmsg(db)  << endl;
        Exit();
    }
    sqlite3_close(db);
}

bool CheckNameToLogin(string UserName){
    query = "SELECT Name FROM Users WHERE Name =(?)";
    result = sqlite3_prepare_v2(db , query.c_str() , -1 , &stmt , NULL );
    sqlite3_bind_text(stmt , 1 , UserName.c_str() , UserName.length() , SQLITE_TRANSIENT );
    if(result != SQLITE_OK){
        cout << "you Have Error is: "<< endl;
    }else{
        while (result = sqlite3_step(stmt) == SQLITE_ROW){
            if(sqlite3_column_text(stmt , 0))
                return true;
            else
                return false ;
        }
    }
}

bool CheckPasswordToLogin(string Password){
    query = "SELECT Password FROM Users WHERE Password =(?)";
    result = sqlite3_prepare_v2(db , query.c_str() , -1 , &stmt , NULL );
    sqlite3_bind_text(stmt , 1 , Password.c_str() , Password.length() , SQLITE_TRANSIENT );
    if(result != SQLITE_OK){
        cout << "you Have Error is: "<< endl;
    }else{
        while (result = sqlite3_step(stmt) == SQLITE_ROW){
            if(sqlite3_column_text(stmt , 0))
                return true;
            else
                return false ;
        }
    }
}


bool CheckIfHereBefore(string Username , string password){
    query = "SELECT Name FROM Users WHERE Name =(?)";
    result = sqlite3_prepare_v2(db , query.c_str() , -1 , &stmt , NULL );
    sqlite3_bind_text(stmt , 1 , Username.c_str() , Username.length() , SQLITE_TRANSIENT );
    if(result != SQLITE_OK){
        cout << "you Have Error is: "<< endl;
    }else{
      while (result = sqlite3_step(stmt) == SQLITE_ROW){
            if(sqlite3_column_text(stmt , 0)){
                query = "SELECT Password FROM Users WHERE Name =(?)";
                result = sqlite3_prepare_v2(db , query.c_str() , -1 , &stmt , NULL );
                sqlite3_bind_text(stmt , 1 , Password.c_str() , Password.length() , SQLITE_TRANSIENT );
                if(result != SQLITE_OK){
                    cout << "you Have Error is: "<< endl;
                }else{
                    while (result = sqlite3_step(stmt) == SQLITE_ROW){
                        if(sqlite3_column_text(stmt , 0))
                            return true;
                        else
                            return false ;
                    }
                }
            }
            else
                return false ;
        }
    }
}

void AddData(string Name , string Password , string Email , string Phone){
    query = "INSERT INTO Users(Name , Password , Email , Phone) VALUES (? , ? , ? , ?)" ;
    result = sqlite3_prepare_v2(db , query.c_str() , -1 , &stmt , NULL );
    sqlite3_bind_text(stmt , 1 , Name.c_str() , Name.length() , SQLITE_TRANSIENT );
    sqlite3_bind_text(stmt , 2 , Password.c_str() , Password.length() , SQLITE_TRANSIENT );
    sqlite3_bind_text(stmt , 3 , Email.c_str() , Email.length() , SQLITE_TRANSIENT );
    sqlite3_bind_text(stmt , 3 , Phone.c_str() , Phone.length() , SQLITE_TRANSIENT );
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    if (result != SQLITE_OK){
        cout << "you Have Error is: "<< endl;
    }else{
        cout << "success Inserting" << endl;
    }
}

void UpdateData(string Password ){
    query = "SELECT rowid ,* FROM Users";
    result = sqlite3_prepare_v2(db , query.c_str() , -1 , &stmt , NULL );
    if(result != SQLITE_OK){
        cout << "you Have Error is: "<< endl;
    }else{
        while (result = sqlite3_step(stmt) == SQLITE_ROW){
            cout
            << sqlite3_column_text(stmt , 0) << "   "
            << sqlite3_column_text(stmt , 2) << "  "
            <<  sqlite3_column_text(stmt , 3) << endl ;
        }
    }
    int ID ;
    cout << "Please Enter The Number OF Id: ";
    cin >> ID ;
    query = "UPDATE Users SET  Password = ?  WHREE rowid = ? ;" ;
    result = sqlite3_prepare_v2(db , query.c_str() , -1 , &stmt , NULL );
    sqlite3_bind_text(stmt , 1 , Password.c_str() , Password.length() , SQLITE_TRANSIENT );
    sqlite3_bind_int(stmt , 2 , ID );
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    if (result != SQLITE_OK){
        cout << "you Have Error is: "<< endl;
    }else{
        cout << "success Inserting" << endl;
    }
}

using namespace std;

int main() {

	BankApplication bankApp;
	return 0;
}
