#include <iostream>
#include <stack>

using namespace std;

int main() {
    int size, x, y, z;
    stack<int> cars;
    //bool same = true;

    while(cin >> x) {
      size = y = x;
      
      while(x != 0) {
        cin >> x;
        if (z < size) {
          cars.push(z);
          z++;
          break;
        }
        if(x == z) {
          cars.pop();
          y--;
        }
        if(y != 0) {
          if(z != size) {
            cars.push(z);
            z++;
          }
          else {
            cout << "No\n";
            break;
          }
        }
        if (y == 0 && z == size) {
          cout << "Yes\n";
        }
      }

      // while(x != 0) {
      //   while(size != 0) {
      //     cin >> x;
      //     if (x == 0) 
      //       break;
      //     if (x != size) {
      //       same = false;
      //     }
      //     size--;
      //   }
      //   if (x == 0) 
      //       break;
      //   if (size == 0 && same != false) 
      //     cout << "Yes\n";
      //   if (same == false)
      //     cout << "No\n";
      //   size = y;
      //   same = true;
      // }
        cout << "\n";
    } 
}