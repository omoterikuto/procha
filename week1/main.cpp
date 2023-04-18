// mian.c
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<std::string> split(std::string str, char del)
{
  int first = 0;
  int last = str.find_first_of(del);

  std::vector<std::string> result;

  while (first < str.size())
  {
    std::string subStr(str, first, last - first);

    result.push_back(subStr);

    first = last + 1;
    last = str.find_first_of(del, first);
    if (last == std::string::npos)
    {
      last = str.size();
    }
  }
  return result;
}

int main()
{
  int n;
  cin >> n;
  cin.ignore();
  float total;

  for (; n > 0; n--)
  {
    string line;
    getline(cin, line);
    vector<std::string> strs = split(line, ' ');
    float val = std::stof(strs[0]);
    float span = std::stof(strs[1]);
    total += val * span;
  }
  cout << total << endl;
}