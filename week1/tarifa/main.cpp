#include <string>
#include <iostream>

using namespace std;

int main()
{
  int x;
  cin >> x;
  cin.ignore();

  int n;
  cin >> n;
  cin.ignore();

  int nums[n];
  int total = x;

  for (; n > 0; n--)
  {
    int p;
    cin >> p;
    cin.ignore();

    total += x - p;
  }
  cout << total << endl;
}