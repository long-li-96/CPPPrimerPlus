// Tv and Remote classes
#ifndef TV_H_
#define TV_H_
#include <iostream>

class Remote;  // 前向声明

class Tv {
 public:
  friend class Remote;  // Remote can access Tv private parts
  enum { Off, On };
  enum { MinVal, MaxVal = 20 };
  enum { Antenna, Cable };
  enum { TV, DVD };

  Tv(int s = Off, int mc = 125)
      : state(s),
        volume(5),
        maxchannel(mc),
        channel(2),
        mode(Cable),
        input(TV) {}
  void onoff() { state = (state == On) ? Off : On; }
  bool ison() const { return state == On; }
  bool volup();
  bool voldown();
  void chanup();
  void chandown();
  void set_mode() { mode = (mode == Antenna) ? Cable : Antenna; }
  void set_input() { input = (input == TV) ? DVD : TV; }
  void settings() const;  // display all settings
  void set_Rintmote(Remote& r);

 private:
  int state;       // On or Off
  int volume;      // assumed to be digitized
  int maxchannel;  // maximum number of channels
  int channel;     // current channel setting
  int mode;        // broadcast or cable
  int input;       // TV or DVD
};

class Remote {
 private:
  enum { normal, interactive };
  int mode;         // controls TV or DVD
  int intera_mode;  // normal or interactive
 public:
  friend class Tv;
  //   int & display_intmode() {return intera_mode;}
  Remote(int m = Tv::TV) : mode(m), intera_mode(normal) {}
  void display_intmode() {
    std::cout << "Remote's intera_mode is: " << (intera_mode == normal ? "normal" : "interactive")
              << std::endl;
  }
  bool volup(Tv& t) { return t.volup(); }
  bool voldown(Tv& t) { return t.voldown(); }
  void onoff(Tv& t) { t.onoff(); }
  void chanup(Tv& t) { t.chanup(); }
  void chandown(Tv& t) { t.chandown(); }
  void set_chan(Tv& t, int c) { t.channel = c; }
  void set_mode(Tv& t) { t.set_mode(); }
  void set_input(Tv& t) { t.set_input(); }
};

#endif