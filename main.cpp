#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <numeric>
#include <optional>
#include <set>
#include <string>
#include <vector>

namespace Sudoku {
    using Board = std::vector<std::vector<int>>;
    using std::literals::string_literals::operator""s;
    struct loc {
        size_t row{0};
        size_t col{0};
    };

    bool readBoard(std::vector<Board>& dst, const std::string& path) {
        std::fstream board_read;
        board_read.open(path, std::ios::in);

        if (!board_read.is_open()) {
            std::cout << "File Not Found\n";
            return false;
        }

        Board tmp_board{};
        for (std::string buffer{}; std::getline(board_read, buffer);) {
            if ((buffer.substr(0ul, 4ul) == "Grid"s)) {
                if (!tmp_board.empty() && tmp_board.size() == 9 &&
                    std::all_of(tmp_board.begin(), tmp_board.end(),
                                [](const auto& i) { return i.size() == 9; }))
                    dst.emplace_back(tmp_board);
                tmp_board.clear();
            } else {
                std::vector<int> tmp_line{};
                for (const char& c : buffer) {
                    int v{static_cast<int>(c - '0')};
                    tmp_line.emplace_back((v == 0) ? -1 : v);
                }
                tmp_board.emplace_back(std::move(tmp_line));
            }
        }
        dst.emplace_back(tmp_board);
        board_read.close();
        return true;
    }

    void printBoard(const Board& board) {
        for (const auto& row : board) {
            for (const auto& cell : row) {
                std::cout << cell << ", ";
            }
            std::cout << "\n";
        }
    }

    bool test_subgrid(const Board& b, int option, const loc& loc_) {
        auto ul = (loc_.col / 3) * 3;
        auto ut = (loc_.row / 3) * 3;
        for (size_t idx_r{ut}; idx_r < (ut + 3); idx_r++) {
            for (size_t idx_c{ul}; idx_c < (ul + 3); idx_c++) {
                if (b[idx_r][idx_c] == option) return false;
            }
        }
        return true;
    }

    bool test_row(const Board& b, int option, const loc& loc_) {
        for (size_t idx{0}; idx < 9; idx++)
            if (b[loc_.row][idx] == option) return false;
        return true;
    }
    bool test_column(const Board& b, int option, const loc& loc_) {
        for (size_t idx{0}; idx < 9; idx++)
            if (b[idx][loc_.col] == option) return false;
        return true;
    }
    bool test_rc(const Board& b, int option, const loc& loc_) {
        return test_column(b, option, loc_) && test_row(b, option, loc_);
    }

    std::vector<int> genOptions(const Board& b, const loc& loc_) {
        std::vector<int> options_v1{};
        for (int option{1}; option < 10; option++) {
            if (test_subgrid(b, option, loc_)) options_v1.push_back(option);
        }
        if (options_v1.size() == 1) return options_v1;

        std::vector<int> options{};
        for (const int option : options_v1) {
            if (test_rc(b, option, loc_)) options.push_back(option);
        }
        return options;
    }

    bool valid_solution(const Board& b) {
        std::set<int> line_holder{};
        for (const auto& b_r : b) {
            line_holder.clear();
            for (const auto& cell : b_r) {
                if (cell <= 0) {
                    return false;
                }
                line_holder.insert(cell);
            }
            if (line_holder.size() != 9) return false;
        }

        for (size_t idx_c{0ul}; idx_c < 9ul; idx_c++) {
            line_holder.clear();
            for (size_t idx_r{0ul}; idx_r < 9ul; idx_r++) {
                if (b[idx_r][idx_c] <= 0) {
                    return false;
                }
                line_holder.insert(b[idx_r][idx_c]);
            }
        }
        if (line_holder.size() != 9) return false;
        return true;
    }

    void inline get_empty_cell(const Board& b,
                               std::vector<std::pair<loc, std::vector<int>>>& possible_cells) {
        possible_cells.clear();
        for (size_t idx_row{0ul}; idx_row < 9; idx_row++) {
            for (size_t idx_col{0ul}; idx_col < 9; idx_col++) {
                if (b[idx_row][idx_col] < 0) {
                    possible_cells.emplace_back(std::pair<loc, std::vector<int>>(
                        loc{idx_row, idx_col}, genOptions(b, {idx_row, idx_col})));
                }
            }
        }
    }

    bool solveBoard(Board& b) {
        std::vector<std::pair<loc, std::vector<int>>> possible_cells{};
        get_empty_cell(b, possible_cells);
        if (possible_cells.empty()) return true;
        // end if no empty cells remaining

        std::sort(possible_cells.begin(), possible_cells.end(),
                  [](const auto& a, const auto& b) { return a.second.size() < b.second.size(); });

        // Choose cell with least number of options
        auto cell{possible_cells[0].first};
        // Choose the options available for that cell
        auto options{possible_cells[0].second};

        /**
         * Insert Sorting Algorithm for options to respect LCV
         */

        bool solved_flag{false};
        for (const auto& option : options) {
            b[cell.row][cell.col] = option;
            solved_flag = solved_flag || solveBoard(b);
            if (solved_flag) break;
        }
        if (!solved_flag) b[cell.row][cell.col] = -1;
        return solved_flag;
    }
};  // namespace Sudoku

/**
 * Using for loop go through each board
 * Using recursion go through each missing on board --> Backtracking
 *  Build all options of all empty cells
 *      Heuristics: <https://www.baeldung.com/cs/csp>
 *          [x] Fewest Legal values --> Choose which cell to work on
 *          [ ] Least constraining on other values --> Choose order of values to back trace
 *          *
 */

using std::literals::string_literals::operator""s;
int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[]) {
    
    std::vector<Sudoku::Board> list_of_games{};
    const auto boards_path{"./p096_sudoku.txt"s};
    if (Sudoku::readBoard(list_of_games, boards_path)) {
        size_t counter{0};
        for (auto& board : list_of_games) {
            if (!Sudoku::solveBoard(board)) {
                std::cout << "Failed to Solve:\t" << counter << std::endl;
                break;
            }
            counter++;
        }
    }


    std::cout << std::accumulate(list_of_games.begin(), list_of_games.end(), 0, [](auto acc,
    const auto& board){
        return acc + ((board[0][0]*100) + (board[0][1]*10) + board[0][2]);
    }) << std::endl;

    return 0;
}