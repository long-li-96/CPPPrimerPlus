#include <cstring>

#include "14_7_4.h"

const int SIZE = 5;

// 判断基类指针指向的是什么类，根据是哪种类调用相应的方法
void makePersonPlay(Person * per);

int main() {
  using std::cin;
  using std::cout;
  using std::endl;
  using std::strchr;

  Person* Persons[SIZE];

  int ct;
  for (ct = 0; ct < SIZE; ct++) {
    char choice;
    cout << "Enter the People's category: \n"
         << "p: person g: gunslinger "
         << "P: pokerplayer b: baddude q: quit\n";
    cin >> choice;
    while (strchr("pgPbq", choice) == NULL) {
      cout << "Please enter a p, g, P, b, or q: ";
      cin >> choice;
    }
    while (cin.get() != '\n') continue;
    if (choice == 'q') break;
    switch (choice) {
      case 'p':
        Persons[ct] = new Person;
        Persons[ct]->Set();  // 抽象基类必须有派生类对应的虚方法
        break;
      case 'g':
        Persons[ct] = new Gunslinger;
        Persons[ct]->Set();
        break;
      case 'P':
        Persons[ct] = new PokerPlayer;
        Persons[ct]->Set();
        break;
      case 'b':
        Persons[ct] = new BadDude;
        Persons[ct]->Set();
        break;
    }
    cout << endl;
  }
  cout << "\nHere is Persons: \n";
  int i;
  for (i = 0; i < ct; i++) {
    Persons[i]->Show();
    makePersonPlay(Persons[i]);
  }
  cout << "Bye.\n";
  return 0;
}

// dynamic_cast<new_type>(expression)
// 其中，new_type 是要转换成的类型，expression 是要进行类型转换的指针或引用。
// dynamic_cast 返回的是一个指向 new_type 类型的指针或引用，如果类型转换不合法，则返回一个空指针或引用。
void makePersonPlay(Person * per)
{
    if (PokerPlayer * p = dynamic_cast<PokerPlayer*>(per))
    {
        std::cout << "This person is a PokerPlayer\n"
                  << "Let's see his card which have issued: \n";
        p->Draw().Show();
    }
    else std::cout << "no more things to show!\n";
}