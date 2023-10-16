#include <iostream>
#include <string>
#include "sqlite3.h"
#include <vector>
using namespace std;
sqlite3 *db;
sqlite3_stmt *stmt;
int result;
string query ;
vector<string> Names;
vector<string> Phones;
vector<string> Addresses;
vector<int> IDS;

// Opening & Creating The Database
void OpenDatabse(){
    if(sqlite3_open("Clients.db" , & db) == SQLITE_OK ){
        // To Set NEw TAble & NAames IT With (Users)
    result = sqlite3_prepare_v2(db , "CREATE TABLE IF NOT EXISTS Clients(Name VARCHAR(100), Phone VARCHAR(100), Address VARCHAR(100), BaseID  VARCHAR(100) , BaseBalance REAL , SavingID VARCHAR(100) , SavingBalance VARCHAR(100) , MinBalance REAL ) ;" , -1 ,&stmt , NULL );
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
       // To Check If The Connect With The Database Are Right OR HAve Error To Show IT & Exit The Progarm WIth Errors
        if (result != SQLITE_OK){
            cout << "you Have Error is: "<< sqlite3_errmsg(db)<<endl;
        }
    }else{
        cout << "You Have Error in Connection With Database is:" << sqlite3_errmsg(db)  << endl;
        exit(1);
    }
}
/*
// adding New Client To Database
// The Balance set 0 as defult
void AddNewClient(string Name , string Phone , string Address , int ID ){
    query = "INSERT INTO Clients(Name , Phone , Address , ID , Balance ) VALUES (? , ? , ? , ? , 0)" ;
    result = sqlite3_prepare_v2(db , query.c_str() , -1 , &stmt , NULL );
    sqlite3_bind_text(stmt , 1 , Name.c_str() , Name.length() , SQLITE_TRANSIENT );
    sqlite3_bind_text(stmt , 2 , Phone.c_str() , Phone.length() , SQLITE_TRANSIENT );
    sqlite3_bind_text(stmt , 3 , Address.c_str() , Address.length() , SQLITE_TRANSIENT );
    sqlite3_bind_int(stmt , 4 , ID );
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    if (result != SQLITE_OK){
        cout << "you Have Error is: "<< sqlite3_errmsg(db)<<endl;
    }
}

// return the balance By id of The Client
int GetBalance(int ID){
    query = "SELECT * FROM Clients";
    result = sqlite3_prepare_v2(db , query.c_str() , -1 , &stmt , NULL );
    if(result != SQLITE_OK){
        cout << "you Have Error is: " << sqlite3_errmsg(db)<<endl;
    }else{
        while (result = sqlite3_step(stmt) == SQLITE_ROW){
            if ( sqlite3_column_int(stmt , 3) == ID)
                return sqlite3_column_int(stmt , 4);
        }
    }
}

// Another Version For get Balance function Using Name
// return the balance By Name of The Client

int GetBalance(string Name){
    query = "SELECT * FROM Clients";
    result = sqlite3_prepare_v2(db , query.c_str() , -1 , &stmt , NULL );
    if(result != SQLITE_OK){
        cout << "you Have Error is: " << sqlite3_errmsg(db)<<endl;
    }else{
        while (result = sqlite3_step(stmt) == SQLITE_ROW){
            if ( sqlite3_column_text(stmt , 0) == Name)
                return sqlite3_column_int(stmt , 4);
        }
    }
}


// Update The Balance  after Finish the Operations At it
void UpdateBalance(int ID  , int NewBalance){
    query = "SELECT * FROM Clients";
    result = sqlite3_prepare_v2(db , query.c_str() , -1 , &stmt , NULL );
    if(result != SQLITE_OK){
        cout << "you Have Error is: " << sqlite3_errmsg(db)<<endl;
    }
    query = "UPDATE Clients SET  Balance = ?  WHERE ID = ? ;" ;
    result = sqlite3_prepare_v2(db , query.c_str() , -1 , &stmt , NULL );
    sqlite3_bind_int(stmt , 1 , NewBalance );
    sqlite3_bind_int(stmt , 2 , ID  );
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    if (result != SQLITE_OK){
        cout << "you Have Error is: " << sqlite3_errmsg(db)<<endl;
    }else{
        cout << "Updating Has Been Successfully" << endl;
    }
}


// Another Version For Update The Balance function Using Name
// Update The Balance  after Finish the Operations At it
/*
void UpdateBalance(string Name , int NewBalance){
    query = "SELECT * FROM Clients";
    result = sqlite3_prepare_v2(db , query.c_str() , -1 , &stmt , NULL );
    if(result != SQLITE_OK){
        cout << "you Have Error is: " << sqlite3_errmsg(db)<<endl;
    }
    query = "UPDATE Clients SET  Balance = ?  WHERE Name = ? ;" ;
    result = sqlite3_prepare_v2(db , query.c_str() , -1 , &stmt , NULL );
    sqlite3_bind_int(stmt , 1 , NewBalance );
   sqlite3_bind_text(stmt , 2 , Name.c_str() , Name.length() , SQLITE_TRANSIENT );
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    if (result != SQLITE_OK){
        cout << "you Have Error is: " << sqlite3_errmsg(db)<<endl;
    }else{
        cout << "Updating Has Been Successfully" << endl;
    }
}


// Show The Full Availabe Data About the Clients
void ShowClients(){
    query = "SELECT rowid , * FROM Clients";
    result = sqlite3_prepare_v2(db , query.c_str() , -1 , &stmt , NULL );
    if(result != SQLITE_OK){
        cout << "you Have Error is: " << sqlite3_errmsg(db)<<endl;
    }else{
        while (result = sqlite3_step(stmt) == SQLITE_ROW){
             cout << "\n   Number: " <<
                    sqlite3_column_int(stmt , 0) << "\n   Name:" <<
                    sqlite3_column_text(stmt , 1) << "\n   Phone:" <<
                    sqlite3_column_int(stmt , 2) << "\n   Address:" <<
                    sqlite3_column_int(stmt , 3) << "\n   ID:" <<
                    sqlite3_column_int(stmt , 4) <<  endl ;
        }
    }
}

// Show The Full Data About the Client
void GetClentData(int ID){
    query = "SELECT rowid , * FROM Clients";
    result = sqlite3_prepare_v2(db , query.c_str() , -1 , &stmt , NULL );
    if(result != SQLITE_OK){
        cout << "you Have Error is: " << sqlite3_errmsg(db)<<endl;
    }else{
        while (result = sqlite3_step(stmt) == SQLITE_ROW){
            if ( sqlite3_column_int(stmt , 4) == ID)
                cout << "\n   Number: " <<
                    sqlite3_column_int(stmt , 0) << "\n   Name:" <<
                    sqlite3_column_text(stmt , 1) << "\n   Phone:" <<
                    sqlite3_column_int(stmt , 2) << "\n   Address:" <<
                    sqlite3_column_int(stmt , 3) << "\n   ID:" <<
                    sqlite3_column_int(stmt , 4) << "\n   Balance:" <<
                    sqlite3_column_int(stmt , 5) <<  endl ;
        }
    }
}
*/
void CloseDattabase(){
    sqlite3_close(db);
}


int main()
{
    // This Function Must Called At The First OF the Applaction
    OpenDatabse();

    // This Function must Called At the End Of the Applation
    CloseDattabase();
    return 0;
}
