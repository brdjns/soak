// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: 2023 Bradley Jones <brdjns@gmx.us

#include <fstream>
#include <iostream>
#include <vector>

int main(int argc, char** argv)
{
    std::string prog{argv[0]};

    if (argc > 2) {
        std::cerr << prog << ": error: invalid number of arguments\n";
        std::cerr << "Usage: " << prog << " <file>\n";
        return 1;
    }

    if (argc == 1) {
        char c{};
        std::vector<char> buf;

        while (std::cin.get(c)) {
            buf.push_back(c);
        }

        for (auto& e : buf) {
            std::cout << e;
        }
    }

    if (argc == 2) {
        char c{};
        std::vector<char> buf;

        while (std::cin.get(c)) {
            buf.push_back(c);
        }

        std::string file{argv[1]};
        std::ofstream out{file};
        if (!out) {
            std::cerr << prog << ": error: can't open file '" << file << "'\n";
            return 1;
        }

        if (out) {
            for (auto& e : buf) {
                out << e;
            }
        }

        out.close();
    }
    return 0;
}
