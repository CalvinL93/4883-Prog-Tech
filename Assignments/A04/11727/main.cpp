#include <iostream>

using namespace std;

int main() {
  int it, ca = 1, max = 999, min = 10001, maxLoc = -1, minLoc = -1;
  int arr[3];

  cin >> it;

  while(it--) {
    cin >> arr[0] >> arr[1] >> arr[2];

    for(int i = 0; i < 3; i++) {
      if(arr[i] > max) {
        max = arr[i];
        maxLoc = i;
      }
      if(arr[i] < min) {
        min = arr[i];
        minLoc = i;
      }
    }
    
    if(maxLoc == 0 && minLoc == 1)
      cout << "Case " << ca << ": " << arr[2] << "\n";
    if(maxLoc == 0 && minLoc == 2)
      cout << "Case " << ca << ": " << arr[1] << "\n";
    if(maxLoc == 1 && minLoc == 0)
      cout << "Case " << ca << ": " << arr[2] << "\n";
    if(maxLoc == 1 && minLoc == 2)
      cout << "Case " << ca << ": " << arr[0] << "\n";
    if(maxLoc == 2 && minLoc == 0)
      cout << "Case " << ca << ": " << arr[1] << "\n";
    if(maxLoc == 2 && minLoc == 1)
      cout << "Case " << ca << ": " << arr[0] << "\n";
    if(maxLoc == minLoc)
      cout << "Case " << ca << ": " << arr[0] << "\n";

    ca++; max = 999; min = 10001; minLoc = -1; maxLoc = -1;
  }    
}