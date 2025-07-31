#include "SparseMatrix.h"

int main() {
    int rows, cols;
    std::cout << "Enter matrix size (rows and columns): ";
    std::cin >> rows >> cols;

    SparseMatrix matrix(rows, cols);
    matrix.input();
    matrix.print();

    return 0;
}

