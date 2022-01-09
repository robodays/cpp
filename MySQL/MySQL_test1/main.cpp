/* Standard C++ includes */
#include <xdevapi.h>


//#include <stdlib.h>
#include <iostream>
/*#include <mysql.h>
#include <mysql_connection.h>
#include <mysql_error.h>*/
//#include <cppconn/*>

/*
 *
  Include directly the different
  headers from cppconn/ and mysql_driver.h + mysql_util.h
  (and mysql_connection.h). This will reduce your build time!
*/
//#include <resultset.h>
//#include <driver.h>
//#include "mysql_driver.h"

//include "mysql_connection.h"

/*#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>*/

//using namespace std;

int main(void)
{
/*    std::cout << std::endl;
    std::cout << "Running 'SELECT 'Hello World!' AS _message'..." << std::endl;

    sql::mysql::MySQL_Driver *driver;
    sql::Connection *con;

    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306", "user", "password");

    delete con;*/

   // try {
        //sql::Driver *driver;
        //sql::Connection *con;
        //sql::Statement *stmt;
        //sql::ResultSet *res;
/* Create a connection */
        //driver = sql::mysql::get_driver_instance();//get_driver_instance();
       // sql::
        //con = driver->connect("tcp://127.0.0.1:3306", "root", "root");
        /* Connect to the MySQL test database */
       /* con->setSchema("test");

        stmt = con->createStatement();
        res = stmt->executeQuery("SELECT 'Hello World!' AS _message"); // replace with your statement
        while (res->next()) {
            cout << "\t... MySQL replies: ";
            *//* Access column data by alias or column name *//*
            cout << res->getString("_message") << endl;
            cout << "\t... MySQL says it again: ";
            *//* Access column fata by numeric offset, 1 is the first column *//*
            cout << res->getString(1) << endl;
        }
        delete res;
        delete stmt;
        delete con;
*/
/*    } catch (sql::SQLException &e) {
        std::cout << "# ERR: SQLException in " << __FILE__;
        std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
        std::cout << "# ERR: " << e.what();
        std::cout << " (MySQL error code: " << e.getErrorCode();
        std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
    }

    std::cout << std::endl;*/

    return EXIT_SUCCESS;
}



/*#include <iostream>
#include <mysql_connection.h>


int main() {
    std::cout << "Hello, World!" << std::endl;
    //sql::mysql::MySQL_Connection
    return 0;
}*/
