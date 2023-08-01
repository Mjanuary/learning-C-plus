//
//  Header.h
//  CSV-App
//
//  Created by Muhawenimana Janvier on 31/07/2023.
//

#ifndef Header_h
#define Header_h

#include <iostream>
#include <string>

#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

class ReadCsv {
    private:
        string filePath;
        std::vector<std::vector<string>> data;
        bool isColumnValid(int col) const;
        double convert(const std::string& str);

    public:
        void path(string path);
        bool read();
        void display() const;
        void display(int col) const;
        vector<double> getColumnNumeric(int col);
        vector<string> getColumnString(int col);
};

#endif /* Header_h */
