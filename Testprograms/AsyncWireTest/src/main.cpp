#include <Arduino.h>
#include <ethernetUtils.h>
#include <audioUtils.h>
#include <console.h>
#include <preferences.h>
#include <utils.h>
#include <sensors.h>
#include <gnss.h>

#include <GC9A01A_t3n.h>
#include <CHSC6413.h>
#include <lvgl.h>
#include "Gui/generated/gui_guider.h"

#define TFT_SCLK 13
#define TFT_MOSI 11
#define TFT_CS 10
#define TFT_DC 30
#define TFT_BL 29
#define TCH_IRQ 28
#define RGB_LED 35
#define SCL_HMI 16
#define SDA_HMI 17
#define SCL_SYS 19
#define SDA_SYS 18
#define SCL_GPS 24
#define SDA_GPS 25
#define HMI_BUZZER 36
#define GPS_RST 31
#define LINK_LED 41

static AudioUtils audio;
static EthernetUtils ethernet(LINK_LED);
static Utils utils(SCL_SYS, SDA_SYS, SCL_HMI, SDA_HMI, SCL_GPS, SDA_GPS);
static Gnss gnss(GPS_RST);
static Sensors sensors;

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
  utils.begin();
  audio.begin();
  gnss.begin(utils);
  sensors.begin(utils);
  ethernet.begin(utils, audio);

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
  ethernet.update();
  threads.yield(); // Call very often, otherwise Network-Stack will crash: https://forum.pjrc.com/index.php?threads/qnethernet-and-teensythreads-causes-assertions-crashes-solved.73198/

  static uint32_t lvT = 0;
  if (millis() - lvT > 5)
  {
    lvT = millis();
    lv_task_handler();
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
