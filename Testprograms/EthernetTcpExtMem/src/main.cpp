#include <Arduino.h>
#include <console.h>
#include <Audio.h>
#include <utils.h>
#include "Audio/transmit_wav_buffered.h"
#include <QNEthernet.h>
using namespace qindesign::network;

#include <GC9A01A_t3n.h>
#include <CHSC6413.h>
#include <lvgl.h>
#include "Gui/generated/gui_guider.h"

#define TFT_SCLK 13 // SCLK can also use pin 14
#define TFT_MOSI 11 // MOSI can also use pin 7
#define TFT_CS 10   // CS & DC can use pins 2, 6, 9, 10, 15, 20, 21, 22, 23
#define TFT_DC 30   // but certain pairs must NOT be used: 2+10, 6+9, 20+23, 21+22
#define TFT_BL 29   // BL can use any pin

#define TCH_IRQ 28 // IRQ can use any pin

AudioSynthWaveformSine sine1;
AudioSynthWaveformSine sine2;
AudioSynthWaveformSine sine3;
AudioSynthWaveformSine sine4;
AudioSynthWaveformSine sine5;
AudioSynthWaveformSine sine6;
AudioSynthWaveformSine sine7;
AudioSynthWaveformSine sine8;
AudioSynthWaveformSine sine9;
AudioSynthWaveformSine sine10;
AudioSynthWaveformSine sine11;
AudioSynthWaveformSine sine12;
AudioSynthWaveformSine sine13;
AudioSynthWaveformSine sine14;
AudioSynthWaveformSine sine15;
AudioSynthWaveformSine sine16;
AudioSynthWaveformSine sine17;
AudioSynthWaveformSine sine18;
AudioSynthWaveformSine sine19;
AudioSynthWaveformSine sine20;
AudioSynthWaveformSine sine21;
AudioSynthWaveformSine sine22;
AudioSynthWaveformSine sine23;
AudioSynthWaveformSine sine24;
AudioSynthWaveformSine sine25;
AudioSynthWaveformSine sine26;
AudioSynthWaveformSine sine27;
AudioSynthWaveformSine sine28;
AudioSynthWaveformSine sine29;
AudioSynthWaveformSine sine30;
AudioSynthWaveformSine sine31;
AudioSynthWaveformSine sine32;

AudioTransmitWAV32 transmitWav1;

AudioConnection patchCord2(sine1, 0, transmitWav1, 0);
AudioConnection patchCord3(sine2, 0, transmitWav1, 1);
AudioConnection patchCord4(sine3, 0, transmitWav1, 2);
AudioConnection patchCord5(sine4, 0, transmitWav1, 3);
AudioConnection patchCord6(sine5, 0, transmitWav1, 4);
AudioConnection patchCord7(sine6, 0, transmitWav1, 5);
AudioConnection patchCord8(sine7, 0, transmitWav1, 6);
AudioConnection patchCord9(sine8, 0, transmitWav1, 7);
AudioConnection patchCord10(sine9, 0, transmitWav1, 8);
AudioConnection patchCord11(sine10, 0, transmitWav1, 9);
AudioConnection patchCord12(sine11, 0, transmitWav1, 10);
AudioConnection patchCord13(sine12, 0, transmitWav1, 11);
AudioConnection patchCord14(sine13, 0, transmitWav1, 12);
AudioConnection patchCord15(sine14, 0, transmitWav1, 13);
AudioConnection patchCord16(sine15, 0, transmitWav1, 14);
AudioConnection patchCord17(sine16, 0, transmitWav1, 15);
AudioConnection patchCord18(sine17, 0, transmitWav1, 16);
AudioConnection patchCord19(sine18, 0, transmitWav1, 17);
AudioConnection patchCord20(sine19, 0, transmitWav1, 18);
AudioConnection patchCord21(sine20, 0, transmitWav1, 19);
AudioConnection patchCord22(sine21, 0, transmitWav1, 20);
AudioConnection patchCord23(sine22, 0, transmitWav1, 21);
AudioConnection patchCord24(sine23, 0, transmitWav1, 22);
AudioConnection patchCord25(sine24, 0, transmitWav1, 23);
AudioConnection patchCord26(sine25, 0, transmitWav1, 24);
AudioConnection patchCord27(sine26, 0, transmitWav1, 25);
AudioConnection patchCord28(sine27, 0, transmitWav1, 26);
AudioConnection patchCord29(sine28, 0, transmitWav1, 27);
AudioConnection patchCord30(sine29, 0, transmitWav1, 28);
AudioConnection patchCord31(sine30, 0, transmitWav1, 29);
AudioConnection patchCord32(sine31, 0, transmitWav1, 30);
AudioConnection patchCord33(sine32, 0, transmitWav1, 31);

IPAddress ip(192, 168, 40, 80);
IPAddress subnet(255, 255, 255, 0);
IPAddress gateway(192, 168, 40, 1);

EthernetServer server(6666);
// Utils utils;

DMAMEM lv_ui guider_ui;
GC9A01A_t3n disp = GC9A01A_t3n(TFT_CS, TFT_DC, -1, TFT_MOSI, TFT_SCLK);
CHSC6413 touch = CHSC6413(&Wire1, TCH_IRQ);

const int screenWidth = 240;
const int screenHeight = 240;
const int screenBufferHeight = 120;
const int lvglUpdateRate = 20;

void my_disp_flush(lv_disp_drv_t *dispDrv, const lv_area_t *area, lv_color_t *color_p);
void touchpad_read(lv_indev_drv_t *drv, lv_indev_data_t *data);
void my_print(const char *buf);

DMAMEM static lv_disp_draw_buf_t draw_buf;
DMAMEM static lv_color_t buf[screenWidth * screenBufferHeight];

void setup()
{
  console.begin();
  while (!console)
  {
    threads.delay(100);
  }
  console.log.println("[MAIN] Console initialized.");

  if (CrashReport)
  {
    util::StdioPrint p{stdout};
    p.println();
    p.println(CrashReport);
    p.println();
    CrashReport.clear();
  }

  AudioMemory(128);
  sine1.frequency(261.63);
  sine2.frequency(277.19);
  sine3.frequency(293.67);
  sine4.frequency(311.13);
  sine5.frequency(329.63);
  sine6.frequency(349.23);
  sine7.frequency(369.99);
  sine8.frequency(392.00);
  sine9.frequency(415.30);
  sine10.frequency(440.00);
  sine11.frequency(466.16);
  sine12.frequency(493.88);
  sine13.frequency(523.25);
  sine14.frequency(554.37);
  sine15.frequency(587.33);
  sine16.frequency(622.25);
  sine17.frequency(659.25);
  sine18.frequency(698.46);
  sine19.frequency(739.99);
  sine20.frequency(783.99);
  sine21.frequency(830.61);
  sine22.frequency(880.00);
  sine23.frequency(932.33);
  sine24.frequency(987.77);
  sine25.frequency(1046.50);
  sine26.frequency(1108.73);
  sine27.frequency(1174.66);
  sine28.frequency(1244.51);
  sine29.frequency(1318.51);
  sine30.frequency(1396.91);
  sine31.frequency(1479.98);
  sine32.frequency(1567.98);

  if (!Ethernet.begin(ip, subnet, gateway))
  {
    console.error.println("[MAIN] Failed to configure Ethernet using static IP");
  }
  else
  {
    console.ok.println("[MAIN] Ethernet configured using static IP");
  }

  console.print("Server is at ");
  console.println(Ethernet.localIP());

  if (!transmitWav1.begin(&server))
  {
    console.error.println("[MAIN] Transmit WAV buffered could not be initialized.");
  }
  else
  {
    console.ok.println("[MAIN] Transmit WAV buffered initialized.");
  }

  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, LOW);
  disp.begin(GC9A01A_SPICLOCK, GC9A01A_SPICLOCK_READ);
  disp.fillScreen(GC9A01A_BLACK);
  disp.updateScreenAsync();

  if (!touch.begin())
  {
    console.error.println("[MAIN] Failed to initialize touch screen!");
  }
  else
  {
    console.ok.println("[MAIN] Touch screen initialized.");
  }
  // touch.setContinuousMode(true);

  lv_log_register_print_cb(my_print);
  lv_init();
  lv_disp_draw_buf_init(&draw_buf, buf, NULL, screenWidth * screenBufferHeight);
  disp.setFrameBuffer((uint16_t *)buf);

  DMAMEM static lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv);
  disp_drv.hor_res = screenWidth;
  disp_drv.ver_res = screenHeight;
  disp_drv.flush_cb = my_disp_flush;
  disp_drv.draw_buf = &draw_buf;
  disp_drv.user_data = &disp;
  lv_disp_t *dispDrv = lv_disp_drv_register(&disp_drv);
  lv_timer_set_period(dispDrv->refr_timer, 1000.0 / lvglUpdateRate);

  DMAMEM static lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv);
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = touchpad_read;
  indev_drv.user_data = &touch;
  lv_indev_drv_register(&indev_drv);

  setup_ui(&guider_ui);
  digitalWrite(TFT_BL, HIGH);
}

void loop()
{
  Ethernet.loop();
  threads.yield(); // Call very often, otherwise Network-Stack will crash: https://forum.pjrc.com/index.php?threads/qnethernet-and-teensythreads-causes-assertions-crashes-solved.73198/

  static uint32_t lvT = 0;
  if (millis() - lvT > 5)
  {
    lvT = millis();
    lv_task_handler();
  }

  static float dataRateAvr = 0;
  if (millis() < 10000)
  {
    dataRateAvr = transmitWav1.getDataRate();
  }
  else
  {
    dataRateAvr = dataRateAvr * 0.9 + transmitWav1.getDataRate() * 0.1;
  }
  static uint32_t t = 0;
  if (millis() - t > 200)
  {
    t = millis();
    if (transmitWav1.getConnectionState())
    {
      console.log.printf("[MAIN] Audio Stream Datarate: %5.2f MBit/s, Buffer Fillrate: %.1f %%\n", (dataRateAvr * 8.0) / 1024.0 / 1024.0, transmitWav1.getBufferFillLevel() * 100.0);
    }
    else
    {
      console.warning.println("[MAIN] No client connected.");
    }
  }

  if (transmitWav1.getBufferOverflowDetected())
  {
    console.warning.println("[MAIN] Buffer overflow detected.");
  }
}

void my_disp_flush(lv_disp_drv_t *dispDrv, const lv_area_t *area, lv_color_t *color_p)
{
  ((GC9A01A_t3n *)dispDrv->user_data)->writeRect(area->x1, area->y1, (area->x2 - area->x1 + 1), (area->y2 - area->y1 + 1), (uint16_t *)color_p);
  ((GC9A01A_t3n *)dispDrv->user_data)->updateScreenAsync(); // DMA the stuff to the screen
  lv_disp_flush_ready(dispDrv);
}

void touchpad_read(lv_indev_drv_t *drv, lv_indev_data_t *data)
{
  CHSC6413 *touch = (CHSC6413 *)drv->user_data;
  if (touch->available())
  {
    data->state = LV_INDEV_STATE_PR; // Indicate that the touchpad is pressed
    data->point.x = touch->x;
    data->point.y = touch->y;
  }
  else
  {
    data->state = LV_INDEV_STATE_REL;
  }
}

void my_print(const char *buf)
{
  console.log.printf("[LVGL] %s", buf);
}
