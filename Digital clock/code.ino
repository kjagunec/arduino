#include <RTClib.h>
#include <TM1637Display.h>

int CLK = 2;
int DIO = 3;
int prvi = 0;

TM1637Display display(CLK, DIO);
RTC_DS3231 rtc;

void setup() {
  rtc.begin();
  // rtc.adjust(DateTime(2021, 4, 17, 14, 20, 0));
  display.setBrightness(0);
  display.clear();
}

void loop() {
  DateTime now = rtc.now();
  if (now.second() == 0 || prvi == 0){
    display.showNumberDecEx(now.hour(), 0b01000000, true, 2, 0);
    display.showNumberDecEx(now.minute(), 0b01000000, true, 2, 2);
    prvi = 1;
  }
}
