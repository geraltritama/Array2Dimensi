#include <iostream>
using namespace std;

void printGaris(int panjang = 50) {
    for (int i = 0; i < panjang; i++) {
        cout << "-";
    }
    cout << endl;
}

void rotateMatriks(int **matriks, int n){
    // Transpose matriks menukar matriks[i][j] dengan matriks[j][i])
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int temp = matriks[i][j];
            matriks[i][j] = matriks[j][i];
            matriks[j][i] = temp;
        }
    }

    // Membalikkan setiap baris
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n / 2; j++) {
            int temp = matriks[i][j];
            matriks[i][j] = matriks[i][n - j - 1];
            matriks[i][n - j - 1] = temp;
        }
    }

    printGaris();

    cout << "Matriks setelah diputar:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    cout << "Selamat datang di program pemutaran matriks sebesar 90 derajat searah jarum jam :)" << endl ;

    printGaris();

    int n;
    cout << "Masukkan ukuran matriks (n x n): ";
    cin >> n;

    int **matriks = new int*[n];
    for (int i = 0; i < n; i++) {
        matriks[i] = new int[n];
    }

    cout << "Masukkan elemen matriks:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Masukkan nilai matriks [" << i << "][" << j << "]: ";
            cin >> matriks[i][j];
        }
    }

    printGaris();
    cout << "Matriks sebelum diputar:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }

    rotateMatriks(matriks, n);

    for (int i = 0; i < n; i++) {
        delete[] matriks[i];
    }
    delete[] matriks;

    return 0;
}
