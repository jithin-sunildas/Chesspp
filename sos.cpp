#include <array>
#include <fstream>
#include <ios>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

typedef struct {
    int row;
    int col;
} Cell;

const std::string file_path = "sos_data.csv";

std::string get_last_line() {

    std::ifstream file(file_path, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Coudnt open file "
                     ""
                  << file_path << std::endl;
        return "";
    }

    file.seekg(0, std::ios::end);

    // Managing empty file condition.
    if (file.tellg() == 0) {
        std::cerr << "File empty" << std::endl;
        return "";
        file.close();
    }

    // Offset set to -1 to remove new line charector.
    file.seekg(-1, std::ios::end);

    char ch;
    std::string last_line;

    // Takin the file pointer to the beginning of the last line
    while (file.tellg() != 0) {
        file.get(ch);
        if (ch == '\n') {
            break;
        }
        file.seekg(-2, std::ios::cur);
    }

    // gets the line currently the pointer is in
    std::getline(file, last_line);

    file.close();
    return last_line;
}

Cell parse_csvtoint(std::string csv_string) {
    std::vector<int> integers;
    std::stringstream ss(csv_string);
    std::string segment;

    while (std::getline(ss, segment, ',')) {
        try {
            integers.push_back(std::stoi(segment));
        } catch (const std::invalid_argument &err) {
            std::cerr << "Invalid charector to parse into int: " << segment << std::endl;
        }
    }

    Cell cell;
    cell.row = integers[0];
    cell.col = integers[1];

    return cell;
}

void read_csvfile(std::vector<Cell> &moves) { moves.push_back(parse_csvtoint(get_last_line())); }

std::array<int, 2> read_user() {
    std::array<int, 2> input;

    std::cout << "Your turn!\n>>> ";
    std::cin >> input[0] >> input[1];

    return input;
}

void write_to_file(std::array<int, 2> input) {

    std::ofstream file(file_path, std::ios::app);

    if (file.is_open()) {
        file << input[0] << ',' << input[1] << std::endl;
        file.close();
    } else {
        std::cerr << "Coudnt open file "
                     ""
                  << file_path << std::endl;
        file.close();
    }
}

int main() {
    std::vector<Cell> ops_moves;
    std::vector<Cell> self_moves;
    return 0;
}
