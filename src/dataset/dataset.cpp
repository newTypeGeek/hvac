#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <cmath>


std::vector<std::string> split(std::string str, char seperator) {
    std::vector<std::string> splited_str;

    std::string tmp = "";
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] != seperator) {
            tmp += str[i];
        } else {
            splited_str.push_back(tmp);
            tmp = "";
        }
    }
    // don't forget the last element
    splited_str.push_back(tmp);
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

                std::cout << "Set " << value << " to " << key << std::endl;
            }
        }
        file.close();

        return data;
    } else {
        std::cerr << "Failed to open " << filepath << ": " << std::strerror(errno) << std::endl;
        exit(0);
    }
}

bool isnan_str(std::string str) {
    std::string nan_strs[] = {"nan", "n/a", "", "none", "null"};
    for (std::string s : nan_strs) {
        if (s == str) {
            return true;
        }
    }
    return false;
}

std::map<std::string, std::vector<double>> cast_to_numeric_type(
    std::map<std::string, std::vector<std::string>> raw_data
) {
    std::map<std::string, std::vector<double>> numeric_data;
    for (auto const& [col_name, data] : raw_data) {
        for (std::string datum : data) {
            double datum_;
            if (isnan_str(datum)) {
                datum_ = std::numeric_limits<double>::quiet_NaN();
            } else {
                datum_ = std::stod(datum);
            }
            numeric_data[col_name].push_back(datum_);
            
        }
    }
    return numeric_data;
}

int main() {
    std::string filepath = "data_simple.csv";
    std::map<std::string, std::vector<std::string>> raw_data = read_csv(filepath);
    std::map<std::string, std::vector<double>> numeric_data = cast_to_numeric_type(raw_data);

    for (auto &[key, val] : numeric_data) {
        std::cout << key << " : ";
        for (double v : val) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}