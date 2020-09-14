#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <iomanip>
using namespace std;

void ClearScreen() {
  for (int i=0; i<10; i++)
    cout << endl << endl << endl << endl << endl;
}

int main(int argc, char const *argv[])
{
  ifstream fin("words.txt");
  if (!fin.is_open()) {
    cerr << "Can't read input txt!" << endl;
    return -1;
  }

  std::vector<pair<string, string>> v;
  while (!fin.eof()) {
    string str1, str2;
    fin >> str1 >> str2;
    if (fin.eof()) break; // to skip the last empty string
    v.push_back(make_pair(str1, str2));
  }

  int right=0;
  int wrong=0;
  std::vector<pair<string, string>> vWr;
  std::vector<string> vMemWr;
  for (int i=0; i<v.size(); i++) {
    cout << setw(2) << i+1 << ": " << v[i].first << " ";
    string str;
    cin >> str;
    if (str == v[i].second) right++;
    else {
      wrong++;
      vWr.push_back(make_pair(v[i].first, v[i].second));
      vMemWr.push_back(str);
    }
  }
  cout << endl << "right: " << right << ", wrong: " << wrong << endl;
  cin.get(); cin.get();
  if (wrong > 0) {
    cout << "Wrongs: " << endl;
    for (int i=0; i< vWr.size(); i++) {
      cout << setw(2) << i+1 << ": " << vWr[i].first << ", " << vWr[i].second << ", "
           << vMemWr[i] << endl;
    }
  }
  cout << "Are you ready for the next step?" << endl;
  cin.get();
  ClearScreen();
  vWr.clear();
  vMemWr.clear();
  right=0;
  wrong=0;
  for (int i=0; i<v.size(); i++) {
    cout << setw(2) << i+1 << ": " << v[i].second << " ";
    string str;
    cin >> str;
    if (str == v[i].first) right++;
    else {
      wrong++;
      vWr.push_back(make_pair(v[i].first, v[i].second));
      vMemWr.push_back(str);
    }
  }
  cout << endl << "right: " << right << ", wrong: " << wrong << endl;
  cin.get(); cin.get();
  if (wrong > 0) {
    cout << "Wrongs: " << endl;
    for (int i=0; i< vWr.size(); i++) {
      cout << setw(2) << i+1 << ": " << vWr[i].first << ", " << vWr[i].second << ", "
           << vMemWr[i] << endl;
    }
  }

  cout << "The end!" << endl;
  return 0;
}
