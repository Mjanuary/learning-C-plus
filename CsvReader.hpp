//
//  CsvReader.hpp
//  CSV-App
//
//  Created by Muhawenimana Janvier on 01/08/2023.
//

#ifndef CsvReader_hpp
#define CsvReader_hpp

#include <stdio.h>
#include <iostream>
#include <string>

#include <fstream>
#include <sstream>
#include <vector>

class ReadCsv {
    private:
        std::string filePath;
        std::vector<std::vector<std::string>> data;
        bool isColumnValid(int col) const;
        double convert(const std::string& str);

    public:
        void path(std::string path);
        bool read();
        void display() const;
        void display(int col) const;
        std::vector<double> getColumnNumeric(int col);
        std::vector<std::string> getColumnString(int col);
};

#endif /* CsvReader_hpp */
