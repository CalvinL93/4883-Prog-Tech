#include <iostream>
#include <fstream>

using namespace std;

// Function to take in array of stop light timers and use booleans to determine at which point all lights are green simultanously.
int RedGreen(int lights[], int a) {
  bool Green[a];
  bool Orange[a];
  int time[a];
  int temptime[a];
  int k, j, lowNum;
  int n = 0;
  int low = lights[0];
  int high = lights[0];

  // Initalize time, Green, Orange Arrays. Find lowest and highest value in array.
  for (int l = 0; l < a; l++) {
    time[l] = lights[l];
    Green[l] = true;
    Orange[l] = false;
    if (lights[l] <= low) {
      low = lights[l];
      lowNum = l;
    }
    if (lights[l] >= high) 
      high = lights[l];
  }

  // Check to see if any lights are near turning red and set to orange.
  for (int l = 0; l < a; l++) {
    if ((lights[l] - low) <= 5) {
      Orange[l] = true;
      Green[l] = false;
    }
  }

  // Set the first red light to the proper state.
  Orange[lowNum] = false;

  // Check for if all lights are the same duration.
  for (int l = 1; l < a; l++) {
    if (lights[l - 1] == lights[l]) {
      if (l == (a - 1))
        return lights[l] * 2;
    }
    else 
      break;
  }

  // Continue for every second in 5 hours.
  for (j = low + 1; j < 18000; j++) { // Start at first red light
    for (int i = 0; i < a; i++) { // Cycle through each light for given time.
      if (time[i] != 0) 
        temptime[i] = j % time[i]; // Count up to duration of light
      // Set light to Green
      if (temptime[i] == 0 && !Green[i] && !Orange[i])
        Green[i] = true;
      // Set light to Orange and Green to false
      else if ((time[i] - temptime[i]) == 5 && Green[i]) {
        Green[i] = false;
        Orange[i] = true;
      }
      // Set light to Red and Orange false
      else if (temptime[i] == 0 && Orange[i])
        Orange[i] = false;
    }
    // Once all lights have turned red check to see at what time all lights turn green again.

    //(j >= high) {
    for (int k = 0; k < a; k++) {
      if(Green[k])
        n++;
        else 
        n = 0;
    if (n == a)
      // returns how many seconds it took for all lights to turn green.
      return j;
    }
    //}
  }
  return 0; // If no time in 5 hours where all lights are green return 0.
};

int main() {
  int lights[100];
  int x , h, m, s, foundVal;
  int i = 0;
  
  // Receive data from console
  while(cin>>x) {
    if (x != 0) {
      lights[i] = x;
      i++;
    }
    // end of set of input data found
    else if (lights[0] != 0) {
      // Function to find seconds until green.
      foundVal = RedGreen(lights, i);
      // returns formated time
      if(foundVal != 0) {
        h = (foundVal / 60) / 60;
        if (h == 0)
          cout << "00:";
        else if (h < 10)
          cout << "0" << h << ":";
        else
          cout << h << ":";

        m = (foundVal % 3600) / 60;
        if (m == 0)
          cout << "00:";
        else if (m < 10)
          cout << "0" << m << ":";
        else
          cout << m << ":";

        s = foundVal % 60;
        if (s == 0)
          cout << "00\n";
        else if (s < 10)
          cout << "0" << s << "\n";
        else
          cout << s << "\n";
      }
      else
        cout << "Signals fail to synchronise in 5 hours\n";
        
      // empties lights array for next set of data and resets input counter.
      fill(begin(lights),end(lights), 0);
      i = 0;
    }
  }
}
