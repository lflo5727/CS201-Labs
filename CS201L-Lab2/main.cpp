/*
 * Liam Floyd
 * 9/14/17
 * CS201L 003L
 * Lab #2 (2D Arrays)
 */

#include <iostream>
#include <fstream>
using namespace std;

void addMat(int matrixA[20][20], int matrixB[20][20], int addedMat[20][20]){
    //Add each position of the matrices to the same position of third matrix
    for(int i = 0; i < 20; i++){
        for(int k = 0; k <20; k++){
            addedMat[i][k] = matrixA[i][k] + matrixB[i][k];
        }
    }
}

int main() {
    int matrixA[20][20];
    int matrixB[20][20];
    int matrixOut[20][20];
    int row;
    int col;
    //Declare all arrays and the row and column numbers

    // Each set of two matrices is preceded by a line containing m and n, where m = # rows and n = # cols
    // A blank line will separate two sets of matrices
    ifstream fin("input.txt");
    // A line containing the # of rows and #of cols should come before each matrix sum
    // A blank line should proceed two matrix sums
    ofstream fout("output.txt");

    // * Ensure input file opens properly *

    // * Start loop for reading in file data *
    // * Create variables to store input matrices *

    for(int i = 0; fin.good(); i++){
        fin >> row >> col;
        //Set the row and column for each pair of matrices
        for(int m = 0; m < row; m++){
            for(int n = 0; n < col; n++){
                fin >> matrixA[m][n];
            }
        }
        for(int m = 0; m < row; m++){
            for(int n = 0; n < col; n++){
                fin >> matrixB[m][n];
            }
        }
        //Input the correct values into the two matrices to be added
        addMat(matrixA, matrixB, matrixOut);
        fout << row << " " << col << endl;
        for(int p = 0; p < row; p++){
            for(int q = 0; q < col; q++){
                fout << matrixOut[p][q] << " ";
            }
            fout << endl;
        }
        //After adding the matrices with a function the final matrix is printed to the output file
        //end of pair
        fout << endl;
    }



    return 0;
}
