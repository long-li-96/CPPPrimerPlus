// 在使用枚举类型时，需要是整数类型或者是unscoped枚举类型（未指定枚举类型），而不是scoped枚举类型（指定了枚举类型）。在C++11标准中，引入了scoped枚举类型（也称为枚举类）
// enum class EnumName { /*enumerator list*/ };
// switch (static_cast<int>(card.color)) {
//     case static_cast<int>(PokerPlayer::Card::Color::diamond):
//         // do something
//         break;
//     case static_cast<int>(PokerPlayer::Card::Color::heart):
//         // do something
//         break;
//     // other cases
// }

#include "14_7_4.h"

#include <chrono>
#include <cstdlib>  // for rand() and srand()

using std::cin;
using std::cout;
using std::endl;

// Person class///////////////////////////////////////
void Person::Data() const {
  cout << "family name: " << family_name << endl;
  cout << "personal name: " << personal_name << endl;
}

void Person::Get() {
  cout << "Please enter the family name: ";
  getline(cin, family_name);
  cout << "Please enter the personal name: ";
  getline(cin, personal_name);
}

void Person::Show() const {
  cout << "Category: Person" << endl;
  Data();
}

void Person::Set() { Get(); }

// Gunslinger class //////////////////////////////////
void Gunslinger::Data() const {
  cout << "time to draw the gun: " << draw_time << endl;
  cout << "number of gun's nicks: " << num_nicks_gun << endl;
}

void Gunslinger::Get() {
  cout << "Please enter the time to draw the gun: ";
  cin >> draw_time;
  cout << "Please enter the number of gun's nicks: ";
  cin >> num_nicks_gun;
  while (cin.get() != '\n') continue;
}

void Gunslinger::Set() {
  Person::Get();
  Get();
}

void Gunslinger::Show() const {
  cout << "Category: Gunslinger" << endl;
  Person::Data();
  Data();
}

// PokerPlayer class //////////////////////////

void PokerPlayer::make_ms_srand() {
  // 获取当前时间的时间戳，该时间戳是一个以纳秒为单位的整数。
  auto now = std::chrono::high_resolution_clock::now();
  // 将时间戳转换成毫秒数
  auto ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now)
                .time_since_epoch()
                .count();
  srand(static_cast<unsigned int>(ms));
}

void PokerPlayer::Card::Show() const {
  std::string card_color, card_number;
  switch (static_cast<int>(color)) {
    case static_cast<int>(Color::diamond):
      card_color = "diamond";
      break;
    case static_cast<int>(Color::club):
      card_color = "club";
      break;
    case static_cast<int>(Color::heart):
      card_color = "heart";
      break;
    case static_cast<int>(Color::spade):
      card_color = "spade";
      break;
  }
  switch (static_cast<int>(number)) {
    case static_cast<int>(Number::ace):
      card_number = "ace";
      break;
    case static_cast<int>(Number::two):
      card_number = "two";
      break;
    case static_cast<int>(Number::threee):
      card_number = "three";
      break;
    case static_cast<int>(Number::four):
      card_number = "four";
      break;
    case static_cast<int>(Number::five):
      card_number = "five";
      break;
    case static_cast<int>(Number::six):
      card_number = "six";
      break;
    case static_cast<int>(Number::seven):
      card_number = "seven";
      break;
    case static_cast<int>(Number::eight):
      card_number = "eight";
      break;
    case static_cast<int>(Number::nine):
      card_number = "nine";
      break;
    case static_cast<int>(Number::ten):
      card_number = "ten";
      break;
    case static_cast<int>(Number::jack):
      card_number = "jack";
      break;
    case static_cast<int>(Number::queen):
      card_number = "queen";
      break;
    case static_cast<int>(Number::king):
      card_number = "king";
      break;
  }
  cout << "Category: Card" << endl;
  cout << "The card's color is: " << card_color << endl;
  cout << "The card's number is: " << card_number << endl;
}

PokerPlayer::Card PokerPlayer::Draw() const {
  Card::Color color_temp;
  Card::Number number_temp;
  int range_color = 4;
  int range_number = 13;
  int num_color = rand() % range_color;
  int num_num = rand() % range_number;
  switch (num_color) {
    case 0:
      color_temp = Card::Color::diamond;
      break;
    case 1:
      color_temp = Card::Color::club;
      break;
    case 2:
      color_temp = Card::Color::heart;
      break;
    case 3:
      color_temp = Card::Color::spade;
      break;
  }

  switch (num_num) {
    case 0:
      number_temp = Card::Number::ace;
      break;
    case 1:
      number_temp = Card::Number::two;
      break;
    case 2:
      number_temp = Card::Number::threee;
      break;
    case 3:
      number_temp = Card::Number::four;
      break;
    case 4:
      number_temp = Card::Number::five;
      break;
    case 5:
      number_temp = Card::Number::six;
      break;
    case 6:
      number_temp = Card::Number::seven;
      break;
    case 7:
      number_temp = Card::Number::eight;
      break;
    case 8:
      number_temp = Card::Number::nine;
      break;
    case 9:
      number_temp = Card::Number::ten;
      break;
    case 10:
      number_temp = Card::Number::jack;
      break;
    case 11:
      number_temp = Card::Number::queen;
      break;
    case 12:
      number_temp = Card::Number::king;
      break;
  }
  return Card(color_temp, number_temp);
}

void PokerPlayer::Show() const {
  cout << "Category: PokerPlayer" << endl;
  Person::Data();
}

// BadDude class //////////////////////////////
void BadDude::Set() {
  Person::Get();
  Gunslinger::Get();
}

void BadDude::Show() const {
  cout << "Category: BadDude" << endl;
  Person::Data();
  Gunslinger::Data();
}