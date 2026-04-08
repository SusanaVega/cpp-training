#ifndef CSVREADER_H
#define CSVREADER_H

#include <vector>
#include <string>
#include <fstream>

class CSVReader {
public:
    /**
     * Reads a CSV file and returns each full row as a single string.
     * Example entry: "7078,Benita,Desai,78621649.91"
     */
    static std::vector<std::string> readCSV(std::string csvFilename) {
        std::vector<std::string> rows;
        std::ifstream file(csvFilename);
        std::string line;

        if (!file.is_open()) {
            return rows; // Returns empty vector if file fails to open
        }

        // Read the file line by line
        while (std::getline(file, line)) {
            // Remove trailing \r for Windows compatibility
            if (!line.empty() && line.back() == '\r') {
                line.pop_back();
            }
            
            // Add the full raw line to the vector
            if (!line.empty()) {
                rows.push_back(line);
            }
        }

        file.close();
        return rows;
    }
};

#endif
