//
// Created by ADMIN on 7/30/2025.
//

#include "SparseMatrix.h"
SparseMatrix::SparseMatrix(int r, int c) : rows(r), cols(c) {}

void SparseMatrix::set(int i, int j, double val) {
    if (val != 0)
        data[{i, j}] = val; // store only non-zero
}

double SparseMatrix::get(int i, int j) const {
    auto it = data.find({i, j});
    return (it != data.end()) ? it->second : 0.0; // return 0 if not found
}

void SparseMatrix::input() {
    int nonZeroCount;
    std::cout << "Enter number of non-zero elements: ";
    std::cin >> nonZeroCount;

    std::cout << "Enter each as: row column value\n";
    std::cout << "Example: to set row 0, column 2 to value 8.5, type: 0 2 8.5\n";
    for (int k = 0; k < nonZeroCount; ++k) {
        int i, j;
        double val;
        std::cin >> i >> j >> val;

        if (i >= 0 && i < rows && j >= 0 && j < cols) {
            set(i, j, val);
        } else {
            std::cout << "Invalid position: (" << i << ", " << j << ")\n";
        }
    }
}

void SparseMatrix::print() const {
    std::cout << "Sparse Matrix (" << rows << "x" << cols << "):\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            std::cout << get(i, j) << " ";
        std::cout << "\n";
    }
}

