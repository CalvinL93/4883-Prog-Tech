#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
    int size, x, y, z;
    stack<int> carsIn;
    queue<int> carsOut;

    while(cin >> x) {
      size = y = x;

      // Continue for current amount of trains.
      while (x != 0) {
        carsIn.push(1);

        // Read in trains to leave station and compare to see whats available.
        for (int i = 0; i < size; i++) {
          cin >> x;
          
          if (x == 0)
            break;
          
          carsOut.push(x);
          
          while (y > 0 && !carsOut.empty() && !carsIn.empty()) {
            if (carsOut.front() == carsIn.top()) {
              carsOut.pop();
              carsIn.pop();
              y--;
            }
            else
              break;
          }
          
          if ((i + 2) <= size) 
            carsIn.push(i + 2);
        }
        
        if (x == 0)
          break;

        // Empty train stack if it matches queue
        while (y != 0) {
          if (carsOut.front() == carsIn.top()) {
            carsOut.pop();
            carsIn.pop();
            y--;
            
          }
          else
            break;
        }

        if(y == 0)
          cout << "Yes\n";
          
        // If fail emtpy carsOut queue
        else if(y < 0 || y > 0) {
          cout << "No\n";
          while (!carsOut.empty()) {
            carsOut.pop();
          }
        }
        
        // Reset y to size for next iteration
        y = size;
      }

      // Create proper amount of new lines
      if(y == 0 && x == 0)
      {}
      else
        cout << "\n";
    } 
}