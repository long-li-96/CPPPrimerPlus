// nested exceptions
// 嵌套异常类
#include <iostream>

#include "15_8_4.h"

int main() {
  using std::cin;
  using std::cout;
  using std::endl;

  double vals1[12] = {1200, 1100, 1122, 2212, 1232, 2334,
                      2884, 2393, 3302, 2922, 3002, 3544};

  double vals2[12] = {12, 11, 22, 21, 32, 34, 28, 29, 33, 29, 32, 35};

  Sales sales1(2011, vals1, 12);
  LabeledSales sales2("Blogstar", 2012, vals2, 12);



  cout << "First try block: \n";
  try {
    int i;
    cout << "Year = " << sales1.Year() << endl;
    for (i = 0; i < 12; ++i) {
      cout << sales1[i] << ' ';
      if (i % 6 == 5) cout << endl;
    }
    cout << "Year = " << sales2.Year() << endl;
    cout << "Label = " << sales2.Label() << endl;
    for (i = 0; i <= 12; ++i) {
      cout << sales2[i] << ' ';
      if (i % 6 == 5) cout << endl;
    }
    cout << "End of try block 1.\n";
  } 
  catch (std::logic_error & le)
  {
    
    LabeledSales::nbad_index * nbad;
    Sales::bad_index * bad;
    cout << le.what();
     if (nbad = dynamic_cast<LabeledSales::nbad_index *>(&le))
        cout << "Company: " << nbad->label_val() << endl;
    if (bad = dynamic_cast<Sales::bad_index *>(&le))
        cout << "bad_index: " << bad->bi_val() << endl;
  }
  cout << "\n Next try block: \n";
  try {
    sales2[2] = 37.5;
    sales2[20] = 23345;
    cout << "End of try block 2.\n";
  } 
  catch (std::logic_error & le)
  {
    
    LabeledSales::nbad_index * nbad;
    Sales::bad_index * bad;
    cout << le.what();
    if (bad = dynamic_cast<Sales::bad_index *>(&le))
        bad->bi_val();
    if (nbad = dynamic_cast<LabeledSales::nbad_index *>(bad))
        nbad->label_val();
  }
  cout << "done\n";
  return 0;
}