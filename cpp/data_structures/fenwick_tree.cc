#include <vector>

using namespace std;

class FenwickTree {
 public:
  FenwickTree(int n_) : n(n_), arr(n_ + 1, 0) {}
  
  void Add(int i, int v) {
    ++i;
    while (i <= n) {
      arr[i] += v;
      i += i & -i;
    }
  }

  int SumTo(int i) {
    ++i;
    int s = 0;
    while (i > 0) {
      s += arr[i];
      i -= i & -i;
    }
    return s;
  }

  int SumRange(int i, int j) {
    return SumTo(j) - SumTo(i);
  }

 private:
  int n;
  vector<int> arr;

};

