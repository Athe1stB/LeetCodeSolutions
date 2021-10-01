#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
  int A[3][3];
  srand(3);
  for (int i = 0; i < 3; i++, cout << endl) {
    for (int z = 0; z < 3; z++) {
      A[i][z] = rand() % 20 - 10; // fill matrix of random numbers
                                  /*
                                   * cin >> A[i][z]; //fill from keyboard
                                   *
                                   */
      cout << "\t" << A[i][z] << "\t ";
    }
  }
  int det = A[0][0] * A[1][1] * A[2][2] + A[0][1] * A[1][2] * A[2][0] +
            A[0][2] * A[1][0] * A[2][1] - A[0][2] * A[1][1] * A[2][0] -
            A[0][0] * A[1][2] * A[2][1] - A[0][1] * A[1][0] * A[2][2];
  cout << "Determinant: " << det << endl;
  return 0;
}
