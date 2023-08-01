//
//  CsvReader.cpp
//  CSV-App
//
//  Created by Muhawenimana Janvier on 01/08/2023.
//

#include "CsvReader.hpp"


void ReadCsv::path(std::string path) {
    filePath = path;
}

bool ReadCsv::read() {
    std::ifstream infile(filePath);

    if (!infile) {
        std::cout << "Error opening file: " << filePath << std::endl;
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

void ReadCsv::display() const {
    std::cout << "-------------- DATA DISPLAY --------------" << std::endl;
    for (const auto& row : data) {
        for (const auto& field : row) {
            std::cout << field << ", ";
        }
        std::cout << std::endl;
    }
}

void ReadCsv::display(int col) const {
    std::cout << "-------------- DISPLAY COL ("<< col <<") --------------" << std::endl;
    if (!isColumnValid(col)) {
        std::cout << "⚠️ Invalid column" << std::endl;
    } else {
        for (const auto& row : data) {
            std::cout << row[col] << std::endl;
        }
    }
}

bool ReadCsv::isColumnValid(int col) const {
    if (data.size() <= 0) {
        return false;
    }

    if (data[0].size() <= (col-1)) {
        return false;
    }

    return true;
}

double ReadCsv::convert(const std::string& str) {
    std::istringstream iss(str);
    double value = 0.0;
    if (!(iss >> value)) {
        value = 0.0;
    }
    return value;
}

std::vector<double> ReadCsv::getColumnNumeric(int col) {
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

std::vector<std::string> ReadCsv::getColumnString(int col) {
    std::vector<std::string> result;
    for (const auto& row : data) {
        result.push_back(row[col]);
    }
    return result;
}
