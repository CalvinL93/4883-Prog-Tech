#include <iostream>

using namespace std;

int main() {
  int it, c = 0, up = 0, down = 0, x, y, temp;

  cin >> it;

  while(it--) {
    cin >> y;
    cin >> x;

    c++;

    temp = x;
    y--;

    while(y--) {
      cin >> x;

      if (x > temp) {
        up++;
      }
      if (x < temp) {
        down++;
      }

      temp = x;
    }

    cout << "Case " << c << ": " << up << " " << down << "\n";
    up = down = 0;
  }
}