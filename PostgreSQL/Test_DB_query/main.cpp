// Visual Studio 2019

#include <iostream>
#include <pqxx/pqxx>

#include <windows.h>

/// Query employees from database.  Return result.
pqxx::result query(std::string query)
{
    pqxx::connection c("dbname = test_db user = postgres password = root hostaddr = 127.0.0.1 port = 5432");
//  pqxx::connection c{"postgresql://accounting@localhost/company"};
    pqxx::work txn{c};

    pqxx::result r{txn.exec(query)};
/*
    for (auto row: r)
        std::cout
        // Address column by name.  Use c_str() to get C-style string.
        << row["product_name"].c_str()
        << " makes "
        // Address column by zero-based index.  Use as<int>() to parse as int.
        << row["price"].as<double>()
//        << row[1].as<int>()
        << std::endl;
*/

    // Not really needed, since we made no changes, but good habit to be
    // explicit about when the transaction is done.
    txn.commit();

    // Connection object goes out of scope here.  It closes automatically.
    return r;
}


/// Query from database, print results.
int main(int, char *argv[])
{
    //system("chcp 65001");
    SetConsoleOutputCP(CP_UTF8);
    try
    {
        std::string SQLQuery = "SELECT product_id, product_name, price, categories_name, price as p "
                               "FROM goods "
                               "JOIN categories ON category = categories_id "
                               "WHERE category IN (3, 4) "
                               "ORDER BY product_id;";

//        std::string SQLQuery = "INSERT INTO goods (product_name, price, category) VALUES ('Мёд', 233.55, 3);";

        pqxx::result r{query(SQLQuery)};

        // Results can be accessed and iterated again.  Even after the connection
        // has been closed.
        for (auto row: r)
        {
            std::cout << "Row: ";
            // Iterate over fields in a row.
            for (auto field: row) std::cout << field.c_str() << " ";
            std::cout << std::endl;
        }
    }
    catch (pqxx::sql_error const &e)
    {
        std::cerr << "SQL error: " << e.what() << std::endl;
        std::cerr << "Query was: " << e.query() << std::endl;
        return 2;
    }
    catch (std::exception const &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}



