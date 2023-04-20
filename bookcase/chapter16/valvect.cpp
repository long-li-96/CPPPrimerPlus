// comparing vector and valrarray
// 对比vector和valarray

#include <algorithm>
#include <iostream>
#include <valarray>
#include <vector>

int main() {
  using namespace std;

  vector<double> data;
  double temp;
  cout << "Enter numbers(<= 0 to quit):\n";
  while (cin >> temp && temp > 0) {
    data.push_back(
        temp);  // vector支持的STL方法,追加元素到末尾，自动扩充容器长度
  }
  sort(data.begin(), data.end());  // STL函数使用默认的<排序，
  int size = data.size();

  valarray<double> numbers(size);
  int i;
  for (i = 0; i < size; i++) numbers[i] = data[i];

  valarray<double> sq_rts(size);
  sq_rts = sqrt(numbers);  // STL函数求每个元素的平方根

  valarray<double> results(size);
  results = numbers + 2.0 * sq_rts;

  cout.setf(ios_base::fixed);
  cout.precision(4);

  for (i = 0; i < size; i++) {
    cout.width(8);
    cout << numbers[i] << ": ";
    cout.width(8);
    cout << results[i] << endl;
  }
  cout << "done\n";
  return 0;
}