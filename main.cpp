#include <iostream>
#include "channel.hpp"

using namespace std;
using namespace gsc;

int main() {
  Channel<int> c;
  c.put(3);
  cout << c.get() << endl;
  return EXIT_SUCCESS;
}