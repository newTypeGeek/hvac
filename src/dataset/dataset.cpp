#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>


std::vector<std::string> split(std::string str, char seperator) {
    std::vector<std::string> splited_str;

    std::string tmp = "";
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] != seperator) {
            tmp += str[i];
        } else {
            // std::cout << tmp << "   ";
            splited_str.push_back(tmp);
            tmp = "";
        }
    }
    return splited_str;
}
        
std::map<std::string, std::vector<std::string> > read_csv(std::string filepath) {
    std::string line;
    std::ifstream file (filepath);

    std::vector<std::string> col_names;
    std::map<std::string, std::vector<std::string> > data;

    int num_cols;
    if ( file.is_open() ) {

        std::getline(file, line);
        std::vector<std::string> col_names = split(line, ',');
        int num_cols = col_names.size();

        int line_number = 1;    
        while ( std::getline(file, line) ) {
            // std::cout << line << std::endl;
            std::vector<std::string> splited_values = split(line, ',');

            // iterate over both splited_values & col_names using indices
            for (int i = 0; i < num_cols; ++i) {
                std::string key = col_names[i];
                std::string value = splited_values[i];
                data[key].push_back(value);
            }
        }
        file.close();

        return data;
    } else {
        std::cerr << "Failed to open " << filepath << ": " << std::strerror(errno) << std::endl;
        exit(0);
    }
}

int main() {
    std::string filepath = "data.csv";
    read_csv(filepath);
    return 0;
}