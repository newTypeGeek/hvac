#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
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
        
void read_csv(std::string filepath) {
    std::string line;
    std::ifstream file (filepath);

    std::vector<std::string> col_names;
    std::map< std::string, std::vector<std::string> > data_tmp;

    int num_cols;
    if ( file.is_open() ) {
        int count = 0;
        while ( std::getline(file, line)) {
            // std::cout << line << std::endl;
            std::vector<std::string> splited_values = split(line, ',');
        }
        file.close();
    } else {
        std::cout << "Unable to open " << filepath << std::endl;
    }
}

int main() {
    std::string filepath = "data.csv";
    read_csv(filepath);
    return 0;
}