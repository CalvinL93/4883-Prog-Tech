#include <iostream>

using namespace std;

int main() {
  int it, x;

  cin >> it;

  while(it--) {
    cin >> x;

    x = (((((x * 567) / 9 ) + 7492) * 235) / 47) - 498;

    x = (x / 10) % 10;   

    cout << abs(x) << "\n";
  }
}