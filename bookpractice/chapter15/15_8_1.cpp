// methods for the Tv class (Remote methods are inline)
#include "15_8_1.h"

#include <iostream>

bool Tv::volup() {
  if (volume < MaxVal) {
    volume++;
    return true;
  }

  else
    return false;
}

bool Tv::voldown() {
  if (volume > MinVal) {
    volume--;
    return true;
  } else
    return false;
}

void Tv::chanup() {
  if (channel < maxchannel) {
    channel++;
  } else
    channel = 1;
}

void Tv::chandown() {
  if (channel > 1)
    channel--;
  else
    channel = maxchannel;
}

void Tv::settings() const {
  using std::cout;
  using std::endl;
  cout << "TV is " << (state == Off ? "Off" : "On") << endl;
  if (state == On) {
    cout << "Volume setting = " << volume << endl;
    cout << "Channel setting = " << channel << endl;
    cout << "Mode = " << (mode == Antenna ? "antenna" : "cable") << endl;
    cout << "Input =" << (input == TV ? "TV" : "DVD") << endl;
  }
}

void Tv::set_Rintmote(Remote& r) {
  if (state == On) {
    r.intera_mode = (r.intera_mode == Remote::interactive)
                        ? Remote::normal
                        : Remote::interactive;
  }
  else
    std::cout << "Tv is off, it can't change remote's intera_mode.\n";
}