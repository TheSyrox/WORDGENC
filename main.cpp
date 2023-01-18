#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <time.h>

using namespace std;

int main() {
  srand(time(NULL));
  ofstream wordlist_file;
  ifstream names_file;
  int nrand = 0, nrands = 0;
  string names[10000];
  char cchar;
  int numbers;
  int howmany;
  double stime, etime;
  string genpass;
  wordlist_file.open("wordlist.txt");
  cout << "Kaç tane şifre : ";
  cin >> howmany;
  cout << "Kaç haneli : ";
  cin >> numbers;
  stime = clock();
  for (int b = 0; b < howmany; b++) {
    for (int a = 0; a < numbers; a++) {
      cchar = (rand() % 10) + 48;
      genpass += cchar;
    }
    wordlist_file << genpass << endl;
    nrand = rand() % 10000;
    for (int i = nrands; i < nrand + 1; i++)
      getline(names_file, names[i]);
    if (nrands > nrand)
      ;
    nrands = nrand;
    genpass = names[nrand];
  }
  etime = clock();
  wordlist_file.close();
  double time_taken = double(etime - stime) / double(CLOCKS_PER_SEC);
  cout << "Tamamlandı! " << time_taken << " saniye..." << endl;
}
