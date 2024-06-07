// ЛР-18.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

class Matrix {
private:
    std::vector<std::vector<int>> data;
    int rows, cols;

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        data.resize(rows, std::vector<int>(cols, 0));
    }

    void setElement(int r, int c, int value) {
        if (r >= 0 && r < rows && c >= 0 && c < cols) {
            data[r][c] = value;
        }
    }

    int getElement(int r, int c) const {
        if (r >= 0 && r < rows && c >= 0 && c < cols) {
            return data[r][c];
        }
        return 0; // або можна кинути виключення
    }

    Matrix operator+(const Matrix& other) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.setElement(i, j, this->getElement(i, j) + other.getElement(i, j));
            }
        }
        return result;
    }

    Matrix operator-(const Matrix& other) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.setElement(i, j, this->getElement(i, j) - other.getElement(i, j));
            }
        }
        return result;
    }

    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            throw std::invalid_argument("Matrices dimensions do not match for multiplication");
        }
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                int sum = 0;
                for (int k = 0; k < cols; ++k) {
                    sum += this->getElement(i, k) * other.getElement(k, j);
                }
                result.setElement(i, j, sum);
            }
        }
        return result;
    }

    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Matrix mat1(4, 3);
    Matrix mat2(4, 3);

    // Заповнюємо матриці якимись значеннями
    mat1.setElement(0, 0, 1);
    mat1.setElement(0, 1, 2);
    mat1.setElement(0, 2, 3);
    mat1.setElement(1, 0, 4);
    mat1.setElement(1, 1, 5);
    mat1.setElement(1, 2, 6);
    mat1.setElement(2, 0, 7);
    mat1.setElement(2, 1, 8);
    mat1.setElement(2, 2, 9);
    mat1.setElement(3, 0, 10);
    mat1.setElement(3, 1, 11);
    mat1.setElement(3, 2, 12);

    mat2.setElement(0, 0, 1);
    mat2.setElement(0, 1, 1);
    mat2.setElement(0, 2, 1);
    mat2.setElement(1, 0, 1);
    mat2.setElement(1, 1, 1);
    mat2.setElement(1, 2, 1);
    mat2.setElement(2, 0, 1);
    mat2.setElement(2, 1, 1);
    mat2.setElement(2, 2, 1);
    mat2.setElement(3, 0, 1);
    mat2.setElement(3, 1, 1);
    mat2.setElement(3, 2, 1);

    Matrix resultAdd = mat1 + mat2;
    Matrix resultSub = mat1 - mat2;

    // Для множення приклад невірний, оскільки розміри матриць не підходять. Якщо потрібно, зробіть так, щоб розміри були правильними.
    // Matrix resultMul = mat1 * mat2; // це буде працювати тільки для матриць з правильними розмірами

    std::cout << "Result of addition:\n";
    resultAdd.print();
    std::cout << "\nResult of subtraction:\n";
    resultSub.print();

    return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
