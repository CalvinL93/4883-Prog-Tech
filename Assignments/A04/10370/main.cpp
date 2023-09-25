#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    int classes;
    double stu, x, average, totalGrade = 0;
    vector<int> grades;

    cin >> classes;

    while(classes--) {
        cin >> stu;

        for (int i = 0; i < stu; i++) {
            cin >> x;
            grades.push_back(x);
            totalGrade += x;  
        }

        average = totalGrade / stu; 

        x = 0;

        for (int j = 0; j < grades.size(); j++) {
          if (grades.at(j) > average) 
            x++;
        }

        x = (x / stu) * 100;

        grades.clear();
        average = 0;
        totalGrade = 0;

        cout << fixed << setprecision(3) << x << "%\n";
    }
}