#include <iostream>

using namespace std;

int main() {
  int in, it = 0, x = 1, y = 0;
  
  while(cin>>in) { 
    if(in < 0)
      break;
    
    int x = 1, y = 0;
    
    it++;

    while (x < in) {
      x *= 2;
      y++;
    }
    
    cout << "Case " << it  << ": " << y << "\n";
  }
}