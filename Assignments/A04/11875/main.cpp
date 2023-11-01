#include <iostream>

using namespace std;

int main() {
  int x, y, mid, it, c = 0;
  bool found = 0;

  cin >> it;

  while (it--) {
    c++;

    cin >> x;

    // Determine if even and decriment to get mid location during loop
    if(x % 2 == 0) {
      mid = (x / 2) - 1;
    }
    else {
      mid = x / 2;
    }

    // Run through players until mid age is found
    for (int i = 0; i < x; i++) {
      cin >> y;
      if (i == mid && !found) {
        mid = y;
        found = 1;
      }
    }

    cout << "Case " << c << ": " << mid << endl;
    found = 0;
  }
}