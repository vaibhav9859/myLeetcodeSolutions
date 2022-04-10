#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void printEncoding(string str, string asf, map<string, char>& myMap, int pos) {

  if (pos == str.size()) {

    cout << asf << endl;
    return;
  }
  if (pos > str.size()) return;



  string temp = "";
  if (str[pos] != '0')printEncoding(str, asf + myMap[temp + str[pos]], myMap, pos + 1);

  if (pos + 1 < str.size() and str[pos] >= '1' and str[pos] <= '2') {
    if (str[pos] != '2') {
      printEncoding(str, asf + myMap[str.substr(pos, 2)], myMap, pos + 2);
    }
    if (str[pos] == '2' and (str[pos + 1] >= '0' and str[pos + 1] <= '6')) {
      printEncoding(str, asf + myMap[str.substr(pos, 2)], myMap, pos + 2);
    }
  }

}

int main() {
  string str;
  cin >> str;

  map<string, char> myMap;
  char chr = 'a';
  for (int i = 1; i <= 26; i++) {
    myMap[to_string(i)] = chr;
    chr++;
  }


  printEncoding(str, "", myMap, 0);

}
