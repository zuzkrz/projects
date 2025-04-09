#include "ErrorDatabase.h"
#include "EmployeeDatabase.h"
#include "LogDatabase.h"
#include <iostream>
#include "funkcje.h"



int main()
{
    std::vector<zk::Error> er_data;
    zk::ErrorDatabase error_database(er_data);
    error_database.createDatabase();
    std::vector<zk::Employee> employee_data;
    zk::EmpDatabase emp_database(employee_data);
    emp_database.createDatabase();
    std::vector<zk::LogData> log_data;
    zk::LogDatabase log_database(log_data);
    log_database.createDatabase();
    bool test = false;
    
    while (test == false)
    {
        welcome();
        std::string choice;
        std::cin >> choice;
        if (choice == "report"){
            reportBug(error_database);
        }
        else if (choice == "login") {
            int emp_id;
            bool test = false;
            login(emp_database, log_database, emp_id, test);
            if (test == true) {
                std::cout << "\nWhat would you like to do?: " << std::endl;


            }
            separator();
        }
        else if (choice == "exit") {
            std::cout << "\nGoodbye!";
            test = true;
        }
        else {
            std::cout << "\nUnknown command, please try again!" << std::endl;
            separator();
        }
        

    }

   

}

