// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: 2023 Bradley Jones <brdjns@gmx.us

#include <cstdlib>
#include <fstream>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

const std::string prog{"soak"};
const std::string version{"1.0.0"};

void file_append(std::ofstream& ofs, std::string file)
{
    ofs.open(file, std::ios_base::app);
    if (!ofs) {
        std::cerr << prog << ": error: can't open file '" << file << "'\n";
        std::exit(1);
    }

    char c{};
    std::vector<char> buf;

    while (std::cin.get(c)) {
        buf.push_back(c);
    }

    for (auto& e : buf) {
        ofs << e;
    }

    ofs.close();
}

void file_truncate(std::ofstream& ofs, std::string file)
{
    ofs.open(file);
    if (!ofs) {
        std::cerr << prog << ": error: can't open file '" << file << "'\n";
        std::exit(1);
    }

    char c{};
    std::vector<char> buf;

    while (std::cin.get(c)) {
        buf.push_back(c);
    }

    for (auto& e : buf) {
        ofs << e;
    }

    ofs.close();
}

void display_help()
{
    const std::string help = R"(Usage: soak [-h] [-v] [-a <file>] | [file]

Soak up standard input and write it to a file.

Options:
  -a, --append    append to FILE
  -h, --help      this help message
  -v, --version   version information
)";

    std::cout << help;
    exit(0);
}

int main(int argc, char** argv)
{
    if (argc > 3) {
        std::cerr << prog << ": error: invalid number of arguments\n";
        return 1;
    }

    std::vector<std::string> args(argv + 1, argv + argc);
    bool a_flag = false;
    std::string a_opt;

    for (const auto& i : args) {
        if (i == "-a" || i == "--append") {
            a_opt = i;
            a_flag = true;
        }
        else if (i == "-h" || i == "--help") {
            display_help();
        }
        else if (i == "-v" || i == "--version") {
            std::cerr << prog << ' ' << version << '\n';
            return 0;
        }
    }

    if (argc == 1) {
        char c{};
        std::vector<char> buf;

        while (std::cin.get(c)) {
            buf.push_back(c);
        }

        for (const auto& e : buf) {
            std::cout << e;
        }

        return 0;
    }

    std::ofstream out;
    std::string file;
    if (a_flag) {
        if (argv[2] == nullptr) {
            std::cerr << prog << ": error: '" << a_opt << "' requires file\n";
            return 1;
        }
        else {
            file = argv[2];
            file_append(out, file);
        }
    }
    else {
        file = argv[1];
        file_truncate(out, file);
    }

    return 0;
}
