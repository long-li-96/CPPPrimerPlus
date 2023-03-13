// Person class, Gunslinger class, PokerPlayer class, BadDude class

#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>
#include <string>

// class Human {
//  public:
//   Human() {}
//   virtual void Show() const = 0;
//   virtual void Set() = 0;
//   virtual ~Human() = 0;
// };

class Person {
 private:
  std::string family_name;
  std::string personal_name;

 protected:
  virtual void Data() const;
  virtual void Get();

 public:
  Person() : family_name("no name"), personal_name("no name"){};
  Person(const char* fname, const char* pname)
      : family_name(fname), personal_name(pname) {}
  virtual void Show() const;
  virtual void Set();
  virtual ~Person() {}
};

class Gunslinger : virtual public Person {
 private:
  double draw_time;
  int num_nicks_gun;

 protected:
  void Data() const;
  void Get();

 public:
  Gunslinger() : Person(), draw_time(0.0), num_nicks_gun(0) {}
  Gunslinger(const char* fname, const char* pname, double dtime, int num_n_g)
      : Person(fname, pname), draw_time(dtime), num_nicks_gun(num_n_g) {}
  Gunslinger(const Person& p, double dt = 0.0, int num_n_g = 0)
      : Person(p), draw_time(dt), num_nicks_gun(0) {}
  double Draw() const { return draw_time; }
  void Set();
  void Show() const;
  ~Gunslinger() {}
};

class PokerPlayer : virtual public Person {
 private:
  void make_ms_srand();

 protected:
  class Card {
   public:
    enum class Color { diamond, club, heart, spade };
    enum class Number {
      ace,
      two,
      threee,
      four,
      five,
      six,
      seven,
      eight,
      nine,
      ten,
      jack,
      queen,
      king
    };
    Card() : color(Color::diamond), number(Number::ace) {}
    Card(Color& c, Number& n) : color(c), number(n) {}
    void Show() const;

   private:
    Color color;
    Number number;
  };

 public:
  PokerPlayer() : Person() { make_ms_srand(); }
  PokerPlayer(const char* fname, const char* pname) : Person(fname, pname) {
    make_ms_srand();
  }
  PokerPlayer(Person& p) : Person(p) { make_ms_srand(); }
  Card Draw() const;
  void Set() { Person::Get(); }
  void Show() const;
  ~PokerPlayer() {}
};
class BadDude : public Gunslinger, public PokerPlayer {
 public:
  BadDude() : Person(), Gunslinger(), PokerPlayer() {}
  BadDude(const char* fname, const char* pname, double dt = 0.0,
          int num_n_g = 0)
      : Person(fname, pname),
        Gunslinger(fname, pname, dt, num_n_g),
        PokerPlayer(fname, pname) {}
  BadDude(Person& p, double dt = 0.0, int num_n_g = 0)
      : Person(p), Gunslinger(p, dt, num_n_g), PokerPlayer(p) {}
  BadDude(Gunslinger& g) : Person(g), Gunslinger(g), PokerPlayer(g) {}
  BadDude(PokerPlayer& pp, double dt = 0.0, int num_n_g = 0)
      : Person(pp), Gunslinger(pp, dt, num_n_g), PokerPlayer(pp) {}
  double Gdraw() const { Gunslinger::Draw(); }
  PokerPlayer::Card& Cdraw() const { PokerPlayer::Draw(); }
  void Set();
  void Show() const;
  ~BadDude() {}
};

#endif