#include <iostream>


void magicSquare1(int n) {


  const int arrSize = n;

  int magic1[arrSize][arrSize];
  memset(magic1, 0, sizeof(magic1));

  int a = arrSize/2;
  int b = arrSize-1;

  //int magic1[arrSize][arrSize] = 0;

  for (int digit = 1; digit <= arrSize*arrSize; ) {
    if (a == -1 && b == n) {
      a = 0;
      b = n-2;
    }
    else {
      if (b == n) {
        b = 0;
      }
      if (a < 0) {
        a = n - 1;
      }
    }

    if (magic1[a][b]) {
      a ++;
      b -= 2;
      continue;
    }
    else {
      magic1[a][b] = digit++;
      //std::cout << magic1[a][b] << std::endl;

    }

    a --;
    b ++;

  }

    std::cout << "Magic Square #1 is: " << std::endl;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        std::cout << magic1[i][j];
      }
      std::cout << std::endl;
      }

      //adds up the sums of the rows and prints the result
      std::cout << "Checking the sums of every row:\t\t";
      for (int c = 0; c < n; c++) {
        int rows = 0;
        for (int d = 0; d < n; d++) {
          rows += magic1[c][d];
        }
        std::cout << rows << " ";
      }
      std::cout << std::endl;

      //adds up the sums of the columns and prints the result
      std::cout << "Checking the sums of every column:\t";
      for (int f = 0; f < n; f++) {
        int cols = 0;
        for (int e = 0; e < n; e++) {
          cols += magic1[e][f];
        }
        std::cout << cols << " ";
      }
      std::cout << std::endl;

      //adds up the sums of the diagonals and prints the result
      std::cout << "Checking the sums of every diagonal:\t";
      int diag = 0;
      for (int g = 0; g < n; g++) {
        diag += magic1[g][g];
      }
      std::cout << diag << " ";
      diag = 0;
      for (int h = 0; h < n; h++) {
        int z = n - 1 - h;
        diag += magic1[h][z];
      }
      std::cout << diag << std::endl;


}




void magicSquare2(int m) {


  const int dimension = m;

  int magic2[dimension][dimension];
  memset(magic2, 0, sizeof(magic2));

  int a = dimension/2;
  int b = dimension-1;

  for (int number = 1; number <= dimension*dimension; ) {
    if (a == -1 && b == m) {
      a = 0;
      b = m-2;
    }
    else {
      if (b == m) {
        b = 0;
      }
      if (a < 0) {
        a = m - 1;
      }
    }

    if (magic2[b][a]) {
      a ++;
      b -= 2;
      continue;
    }
    else {
      magic2[b][a] = number++;
      //std::cout << magic2[b][a] << std::endl;

    }

    a --;
    b ++;

  }

    std::cout << "Magic Square #2 is: " << std::endl;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < m; j++) {
        std::cout << magic2[i][j];
      }
      std::cout << std::endl;
      }


      //adds up the sums of the rows and prints the result
      std::cout << "Checking the sums of every row:\t\t";
      for (int c = 0; c < m; c++) {
        int rows = 0;
        for (int d = 0; d < m; d++) {
          rows += magic2[c][d];
        }
        std::cout << rows << " ";
      }
      std::cout << std::endl;

      //adds up the sums of the columns and prints the result
      std::cout << "Checking the sums of every column:\t";
      for (int f = 0; f < m; f++) {
        int cols = 0;
        for (int e = 0; e < m; e++) {
          cols += magic2[e][f];
        }
        std::cout << cols << " ";
      }
      std::cout << std::endl;

      //adds up the sums of the diagonals and prints the result
      std::cout << "Checking the sums of every diagonal:\t";
      int diag = 0;
      for (int g = 0; g < m; g++) {
        diag += magic2[g][g];
      }
      std::cout << diag << " ";
      diag = 0;
      for (int h = 0; h < m; h++) {
        int z = m - 1 - h;
        diag += magic2[h][z];
      }
      std::cout << diag << std::endl;




}



void magicSquare3(int l) {


  const int dimension = l;

  int magic3[dimension][dimension];
  memset(magic3, 0, sizeof(magic3));

  int a = dimension/2;
  int b = dimension-1;

  for (int number = dimension*dimension; number >= 0; ) {
    if (a == -1 && b == l) {
      a = 0;
      b = l-2;
    }
    else {
      if (b == l) {
        b = 0;
      }
      if (a < 0) {
        a = l - 1;
      }
    }

    if (magic3[a][b]) {
      a ++;
      b -= 2;
      continue;
    }
    else {
      magic3[a][b] = number--;
      //std::cout << magic2[b][a] << std::endl;

    }

    a --;
    b ++;

  }

    std::cout << "Magic Square #3 is: " << std::endl;

    for (int i = 0; i < l; i++) {
      for (int j = 0; j < l; j++) {
        std::cout << magic3[i][j];
      }
      std::cout << std::endl;
      }


      //adds up the sums of the rows and prints the result
      std::cout << "Checking the sums of every row:\t\t";
      for (int c = 0; c < l; c++) {
        int rows = 0;
        for (int d = 0; d < l; d++) {
          rows += magic3[c][d];
        }
        std::cout << rows << " ";
      }
      std::cout << std::endl;

      //adds up the sums of the columns and prints the result
      std::cout << "Checking the sums of every column:\t";
      for (int f = 0; f < l; f++) {
        int cols = 0;
        for (int e = 0; e < l; e++) {
          cols += magic3[e][f];
        }
        std::cout << cols << " ";
      }
      std::cout << std::endl;

      //adds up the sums of the diagonals and prints the result
      std::cout << "Checking the sums of every diagonal:\t";
      int diag = 0;
      for (int g = 0; g < l; g++) {
        diag += magic3[g][g];
      }
      std::cout << diag << " ";
      diag = 0;
      for (int h = 0; h < l; h++) {
        int z = l - 1 - h;
        diag += magic3[h][z];
      }
      std::cout << diag << std::endl;




}




int main() {

  int size = 0;
  //makes sure n is an odd integer b/w 3 and 15
  do {
    std::cout << "Enter the size of a magic square: ";
    std::cin >> size;
  } while(size<3 || size>15 || size%2==0);

  //std::cout << size << std::endl;

  magicSquare1(size);
  magicSquare2(size);
  magicSquare3(size);

  return 0;
}
