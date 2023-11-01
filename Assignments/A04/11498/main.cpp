#include <iostream>

using namespace std;

int main() {
  int it, xDiv, yDiv, x, y;

  // read it in do the stuffs until no stuffs left to do
  while(cin>>it>>xDiv>>yDiv){ 
    while(it--) {
      cin>>x>>y;

      if(x == xDiv || y == yDiv)
        cout << "divisa" << "\n";
      if(x > xDiv && y > yDiv)
        cout << "NE" << "\n";
      if(x < xDiv && y > yDiv)
        cout << "NO" << "\n";
      if(x > xDiv && y < yDiv)
        cout << "SE" << "\n";
      if(x < xDiv && y < yDiv)
        cout << "SO" << "\n";
    }
  }
}