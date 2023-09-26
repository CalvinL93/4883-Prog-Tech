#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
  string hour, minute;
  double angleH, angleM, h , m;

  while(cin) {
    getline(cin, hour, ':');
    getline(cin, minute);

    h = stoi(hour);
    m = stoi(minute);

    if (h == 0 && m == 0) 
      break;

    angleH = ((h * 60) + m)/2;
    angleM = m * 6;

    angleH = abs(angleH - angleM);

    if (angleH == 360)
      angleH = 0;
    else if (angleH > 180) 
      angleH = 180 - (angleH - 180);

    cout << fixed << setprecision(3) << angleH << "\n";
  }
}