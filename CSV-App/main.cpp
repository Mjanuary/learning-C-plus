//
//  main.cpp
//  CSV-App
//
//  Created by Muhawenimana Janvier on 31/07/2023.
//

#include <iostream>
#include <string>

#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

class ReadCsv {
    private:
        string filePath;
        std::vector<std::vector<std::string>> data;
    
    public:
        void path(string path) {
            filePath = path;
        }
    
        bool read() {
            std::ifstream infile(filePath);
            
            if (!infile) {
                std::cerr << "Error opening file: " << filePath << std::endl;
                return false;
            }
            
            // Temporary string to hold each line of the CSV file
            std::string line;

            while (std::getline(infile, line)) {
                // Create a string stream to parse the line
                std::stringstream ss(line);

                // Vector to store the fields of the current row
                std::vector<std::string> row;

                // Read each field from the line and store it in the row vector
                std::string field;
                while (std::getline(ss, field, ',')) {
                    row.push_back(field);
                }

                // Add the row to the data vector
                data.push_back(row);
            }
            
            infile.close();
            return true;
        }
    
        void display() const {
            cout << "-------------- DATA DISPLAY --------------" << endl;
            for (const auto& row : data) {
                for (const auto& field : row) {
                    std::cout << field << ", ";
                }
                std::cout << std::endl;
            }
        }
    
        void display(int col) const {
            cout << "-------------- DISPLAY COL ("<< col <<") --------------" << endl;
            if (!isColumnValid(col)) {
                cout << "⚠️ Invalid column" << endl;
            } else {
                for (const auto& row : data) {
                    cout << row[col] << endl;
                }
            }

        }
   
    private:
        bool isColumnValid(int col) const {
            if (data.size() <= 0) {
                return false;
            }
            
            if (data[0].size() <= (col-1)) {
                return false;
            }
            
            return true;
        }
        
        double convert(const std::string& str) {
            std::istringstream iss(str);
            double value = 0.0;
            if (!(iss >> value)) {
                value = 0.0;
            }
            return value;
        }
    
    public:
    std::vector<double> getColumnNumeric(int col) {
        std::vector<double> result;
        result.push_back(0);
        if (!isColumnValid(col)) {
            return result;
        }
        
        for (const auto& row : data) {
            result.push_back(convert(row[col]));
        }
        return result;
    }
    
    std::vector<string> getColumnString(int col) {
        std::vector<string> result;
        for (const auto& row : data) {
            result.push_back(row[col]);
        }
        return result;
    }

};

double convert(const std::string& str) {
    std::istringstream iss(str);
    double value = 0.0;
    if (!(iss >> value)) {
        value = 0.0; // Set value to 0 if the conversion fails
    }
    return value;
}

void menu() {
    cout << endl << "************************************" << endl;
    cout << "* Commands: ⌨️                     *" << endl;
    cout << "* 'exit'    👉 Close app           *" << endl;
    cout << "* 'list'    👉 Display contents    *" << endl;
    cout << "* 'list-c' 👉 Display a column    *" << endl;
    cout << "* 'SUM'     👉 Display a column    *" << endl;
    cout << "************************************" << endl << endl;

}


double SUM(const std::vector<double>& numbers) {
    double sum = 0.0;
    for (double num : numbers) {
        sum += num;
    }
    return sum;
}


int main(int argc, const char * argv[]) {
    ReadCsv csv;
    string filename;
    cout << "Enter the file path 📂: "; //   /Users/muhawenimanajanvier/dev/c++/helloWorld/CHelloWord/CHelloWord/data.csv
    cin >> filename;
    csv.path(filename);




    if (csv.read()) {
        cout << endl << "✅ File loaded successfully!" << endl;
    } else {
        cout << endl << "⚠️ Failed to read the file, please make sure the path and the file is a csv" << endl;
        return 0;
    }

    string command;

    menu();
    do {
        cin >> command;
        if (command == "list") csv.display();
        if (command == "list-c") {
            int pos;
            cout << "Enter the column position: ";
            cin >> pos;
            csv.display(pos);
        }
        
        if (command == "SUM") {
            int pos;
            cout << "Enter the column position: ";
            cin >> pos;
            std::vector<double> result = csv.getColumnNumeric(pos);
            cout << endl << "Sum is: " << SUM(result) << endl;
        }
        
    } while (command != "exit");
    return 0;
}
