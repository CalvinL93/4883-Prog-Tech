#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
  string x, emptyLine;
  int total, temp = 0;
  vector<string> treeType;
  vector<double> count;
  bool found;
  // Get total number of data sets
  cin >> total;

  // Clear out the enpty lines after total number
  getline(cin, emptyLine);
  getline(cin, emptyLine);

  // Continue for total
  for(int i = 0; i < total; i++) {

    // Get data until empty line and add to treeType vector
    while(getline(cin,x) && x.length() != 0)
      treeType.push_back(x);

    // Sort the treeType vector alphabeticaly
    sort(treeType.begin(), treeType.end());

    // Add first tree to count vector
    count.push_back(1);

    // Count how many times each tree appears. If first time seeing tree add it to vector
    for (int j = 1; j < treeType.size(); j++) {
      if (treeType.at(j) == treeType.at(j - 1)) {
        temp++;
        count[j - temp]++;
      }
      else
        count.push_back(1);
    }
    
    temp = treeType.size();

    // Remove repeated vallues in treeType vector
    treeType.erase(unique(treeType.begin(), treeType.end()), treeType.end());

    // Output tree type and percentage of tree type from overall trees.
    for (int k = 0; k < treeType.size(); k++)
      cout << treeType.at(k) << " " << fixed << setprecision(4) << (count.at(k) / temp) * 100 << "\n";

    // Add new line to between data sets until last set is reached.
    if (i != (total - 1))
      cout << "\n";

    // Empty vectors and temp data.
    treeType.clear();
    count.clear();
    temp = 0;
  }
}