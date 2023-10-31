#include <Arduino.h>
#include <TeensyThreads.h>
#include <console.h>
#include <utils.h>
#include <audioUtils.h>
#include <hmi.h>
#include <gui.h>
#include <app.h>

#define TFT_SCLK        13
#define TFT_MOSI        11
#define TFT_CS          10
#define TFT_DC          25
#define TFT_RST         26
#define TFT_BL          24
#define TCH_RST         27
#define TCH_IRQ         28
#define RGB_LED         22
#define SCL_HMI         16
#define SDA_HMI         17
#define SCL_SYS         19
#define SDA_SYS         18
#define BTN_REC         30
#define BTN_SEL         31
#define VOL_POT         41

static AudioUtils audio;
static Utils utils(SCL_SYS, SDA_SYS, SCL_HMI, SDA_HMI);
static Gui gui(TFT_SCLK, TFT_MOSI, TFT_CS, TFT_DC, TFT_RST, TFT_BL, TCH_RST, TCH_IRQ);
static Hmi hmi(RGB_LED, BTN_REC, BTN_SEL, VOL_POT);
static App app(audio, hmi, gui, utils);

void setup()
{
  console.begin();
  utils.begin();
  hmi.begin(utils);
  gui.begin(utils);
  audio.begin();
  app.begin();
}

void loop()
{
  gui.update();
  utils.update();
}
