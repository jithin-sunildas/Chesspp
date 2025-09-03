#include <fstream>
#include <ios>
#include <iostream>
#include <numeric>
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

Cell read_user() {
    Cell cell;
    std::cout << "Your turn!\n>>> ";
    std::cin >> cell.row >> cell.col;

    return cell;
}

void write_to_file(Cell cell) {
    std::ofstream file(file_path, std::ios::app);

    if (file.is_open()) {
        file << cell.row << ',' << cell.col << std::endl;
        file.close();
    } else {
        std::cerr << "Coudnt open file "
                     ""
                  << file_path << std::endl;
        file.close();
    }
}

std::vector<Cell> list_threat(Cell cell) {
    std::vector<Cell> threat;

    while (cell.row < 3) {
        cell.row++;
        threat.push_back(cell);
    }
    while (cell.row >= 0) {
        cell.row--;
        threat.push_back(cell);
    }
    while (cell.col < 3) {
        cell.col++;
        threat.push_back(cell);
    }
    while (cell.col >= 0) {
        cell.col--;
        threat.push_back(cell);
    }
    // cells with even sum of indeces can be used for cross matching.
    if ((cell.row + cell.col) % 2 == 0) {
        while (cell.row >= 0) {
            cell.row--;
            cell.col--;
            threat.push_back(cell);
        }
        while (cell.row < 3) {
            cell.row--;
            cell.col--;
            threat.push_back(cell);
        }
    }
    return threat;
}

int match(std::vector<Cell> a, std::vector<Cell> b) {
    for (Cell i : a) {
        for (Cell j : b) {
            if (i.row == j.row && i.col == j.col) {
                return 1;

            } else
                return 0;
        }
    }
}

int match(Cell a, std::vector<Cell> b) {
    for (Cell i : b) {
        if (a.row == i.row && a.col == i.col) {
            return 1;

        } else
            return 0;
    }
}

Cell partner(std::vector<Cell> self_moves, std::vector<Cell> threat_list) {
    for (Cell i : threat_list) {
        for (Cell j : self_moves) {
            if (i.row == j.row && i.col == j.col) {
                if (i.row) {
                }
            } else
        }
    }
}

void SosEngine(std::vector<Cell> &ops_moves, std::vector<Cell> &self_moves, Cell last_move) {
    Cell decided_cell;
    std::vector<Cell> target_list = list_threat(self_moves.back());
    std::vector<Cell> threat_list = list_threat(last_move);

    // Check if any of our moves is in target list, then we can win in one move.
    if (match(target_list, self_moves)) {
        // find partner
        decided_cell = partner(self_moves.back(), target_list);
        // decided_cell = partner
    } else if (/*last_move in threat_list*/) {
    }

    // learn iteration thru std::vector
    // do iteration
    // find partner
    // align conde
    // make ui

    self_moves.push_back(decided_cell);
    write_to_file(decided_cell);
}

int main() {
    std::vector<Cell> ops_moves;
    std::vector<Cell> self_moves;
    return 0;
}
