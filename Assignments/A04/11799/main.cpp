#include <iostream>
#include <string>

using namespace std;

int main() {
  int it, c = 0, x = 0, y, num;
  string in;

  cin >> it;

  while (it--) {
    c++;
    
    cin >> y;

    for (int i = 0; i < y; i++) {
      cin >> num;
      if (num > x)
        x = num;
    }

    cout << "Case " << c << ": " << x << "\n";

    x = 0;
  }
}