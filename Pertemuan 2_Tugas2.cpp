#include <iostream>
using namespace std;

void printGaris(int panjang = 50) {
    for (int i = 0; i < panjang; i++) {
        cout << "-";
    }
    cout << endl;
}

void rotateMatriksPointer(int *px, int n=4) {
    // Transpose matriks, menukar px[i][j] dengan px[j][i]
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int temp = *(px + i * n + j);
            *(px + i * n + j) = *(px + j * n + i);
            *(px + j * n + i) = temp;
        }
    }

    // Membalikkan setiap baris, menukar px[i][j] dengan px[i][n-j-1]
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n / 2; j++) {
            int temp = *(px + i * n + j);
            *(px + i * n + j) = *(px + i * n + (n - j - 1));
            *(px + i * n + (n - j - 1)) = temp;
        }
    }
}

int main() {
    int matriks[4][4];

    cout << "Selamat datang di program pemutaran matriks 90 derajat\n";
    printGaris();

    cout << "Masukkan elemen matriks 4x4:\n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << "Elemen (" << i << ", " << j << "): ";
            cin >> matriks[i][j];
        }
    }

    printGaris();
    cout << "Matriks sebelum diputar:\n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }

    rotateMatriksPointer(&matriks[0][0], 4);

    printGaris();
    cout << "Matriks setelah diputar 90 derajat:\n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
