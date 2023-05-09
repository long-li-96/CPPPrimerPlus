// using valarray slices from <valarray>
// slice类对象可以用作数组下标，slice对象可以表示一维数组的二维数据
// 使用slice对象可以将一维的valarray对象表示为二维数据
// slice(index1, count, distance)
// index1:起始索引，count:索引数,distacne:索引跨距
#include <cstdlib>
#include <iostream>
#include <valarray>

const int SIZE = 12;
typedef std::valarray<int> vint;  // simplify declarations
void show(const vint &v, int cols);

int main() {
  using std::cout;
  using std::slice;   // from <valarray>
  vint valint(SIZE);  // think of as 4 rows of 3

  int i;
  for (i = 0; i < SIZE; ++i) valint[i] = std::rand() % 10;
  cout << "Original array:\n";
  show(valint, 3);  // show in 3 columns

  vint vcol(valint[slice(1, 4, 3)]);  // extract 2nd column  vcol被复制构造为valint的第二列，slice(1,4,3)表示从valint的第二个元素开始，每隔3个元素取一个，取4个元素
  cout << "Second column:\n";
  show(vcol, 1);

  vint vrow(valint[slice(3, 3, 1)]);  // extract 2nd row  vrow被复制构造为valint的第二行
  cout << "Second row:\n";
  show(vrow, 3);

  valint[slice(2, 4, 3)] = 10;  // assign to 2nd column 给valint第三列的元素都赋值为10
  cout << "Set last column to 10:\n";
  show(valint, 3);

  cout << "Set first column to sum  of next two:\n";
  // + not defined for slices, so convert to valarray<int>
  valint[slice(0, 4, 3)] =
      vint(valint[slice(1, 4, 3)]) + vint(valint[slice(2, 4, 3)]);  // 将valint的第一列元素赋值为第二列元素+第三列元素（一一对应的相加）
  show(valint, 3);

  return 0;
}

void show(const vint &v, int cols) {
  using std::cout;
  using std::endl;

  int lim = v.size();
  for (int i = 0; i < lim; ++i) {
    cout.width(3);
    cout << v[i];
    if (i % cols == cols - 1) // i除cols取余如果为cols-1就换行，相当于每行cols个元素，i是从0开始的
      cout << endl;
    else
      cout << " ";
  }
  if (lim % cols != 0) cout << endl;
}