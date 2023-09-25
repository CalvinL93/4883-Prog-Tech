#include <iostream>
#include <string>

using namespace std;

int main() {
    int x = 1, y = 1, z = 0, a, b, c;
    string input, input2;

    // Continue with valid input    
    while (input != "0" || input2 != "0") {

      // Get numbers on each side of space
      getline(cin, input, ' ');
      getline(cin, input2);
  
      // Convert string to int
      x = stoi(input);
      y = stoi(input2);

      // Set x as largest number
      if (y > x) {
        c = x;
        x = y;
        y = c;
      }

      // If no valid input break
      if (x == 0 && y == 0) 
        break;

      // For given set of numbers mod for last number, add and check if carry.
      while (x > 0) {
        a = x % 10;
        b = y % 10;

        x /= 10;
        y /= 10;

        // If there is a carry check the next numbers to see if they will become carries too
        if ((a + b) >= 10) {
          z++;
          x++;
          c = x;
          while(c > 0) {
            if ((c % 10) == 0) {
              z++;
              c /= 10;
            }
            else
              break;
          }
        }
      }


      if (z > 1) 
        cout << z << " carry operations.\n";
      else if (z == 1) 
        cout << "1 carry operation.\n";
      else
        cout << "No carry operation.\n";
      z = 0;

    }
    
    return 0;
}