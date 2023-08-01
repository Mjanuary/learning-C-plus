//
//  app.cpp
//  CSV-App
//
//  Created by Muhawenimana Janvier on 01/08/2023.
//

#include "app.hpp"

void menu() {
    std::cout << std::endl << "************************************" << std::endl;
    std::cout << "* Commands: ⌨️                     *" << std::endl;
    std::cout << "* 'exit'    👉 Close app           *" << std::endl;
    std::cout << "* 'list'    👉 Display contents    *" << std::endl;
    std::cout << "* 'list-c' 👉 Display a column     *" << std::endl;
    std::cout << "* 'SUM'     👉 Display a column    *" << std::endl;
    std::cout << "************************************" << std::endl << std::endl;
}

int app() {
    ReadCsv csv;
    std::string filename;
    std::cout << "Enter the file path 📂: "; //   /Users/muhawenimanajanvier/dev/c++/helloWorld/CHelloWord/CHelloWord/data.csv
    std::cin >> filename;
    csv.path(filename);

    if (csv.read()) {
        std::cout << std::endl << "✅ File loaded successfully!" << std::endl;
    } else {
        std::cout << std::endl << "⚠️ Failed to read the file, please make sure the path and the file is a csv" << std::endl;
        return 0;
    }

    std::string command;
    menu();
    do {
        std::cin >> command;
        if (command == "list") csv.display();
        if (command == "list-c") {
            int pos;
            std::cout << "Enter the column position: ";
            std::cin >> pos;
            csv.display(pos);
        }
        
        if (command == "SUM") {
            int pos;
            std::cout << "Enter the column position: ";
            std::cin >> pos;
            std::vector<double> result = csv.getColumnNumeric(pos);
            std::cout << std::endl << "Sum is: " << SUM(result) << std::endl;
        }
        
    } while (command != "exit");
    return 0;
}
