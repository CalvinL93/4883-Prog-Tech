#include <iostream>

using namespace std;

int main() {
    int size, x, y;
    bool same = true;

    while(cin>>x) {
      size = y = x;
      
      while(x != 0) {
        while(size != 0) {
          cin >> x;
          if (x == 0) 
            break;
          if (x != size) {
            same = false;
          }
          size--;
        }
        if (x == 0) 
            break;
        if (size == 0 && same != false) 
          cout << "Yes\n";
        if (same == false)
          cout << "No\n";
        size = y;
        same = true;
      }
        cout << "\n";
    } 
}