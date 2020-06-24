#ifndef ESP32_BLE_GAMEPAD_H
#define ESP32_BLE_GAMEPAD_H
#include "sdkconfig.h"
#if defined(CONFIG_BT_ENABLED)

#include "BleConnectionStatus.h"
#include "BLEHIDDevice.h"
#include "BLECharacteristic.h"

#define BUTTON_1    (1<<0)
#define BUTTON_2    (1<<1)
#define BUTTON_3    (1<<2)
#define BUTTON_4    (1<<3)
#define BUTTON_5    (1<<4)
#define BUTTON_6    (1<<5)
#define BUTTON_7    (1<<6)
#define BUTTON_8    (1<<7)
#define BUTTON_9    (1<<8)
#define BUTTON_10 	(1<<9)
#define BUTTON_11 	(1<<10)
#define BUTTON_12 	(1<<11)
#define BUTTON_13 	(1<<12)
#define BUTTON_14 	(1<<13)
#define BUTTON_15 	(1<<14)
#define BUTTON_16 	(1<<15)

#define BUTTON_17   (1<<16)
#define BUTTON_18   (1<<17)
#define BUTTON_19   (1<<18)
#define BUTTON_20   (1<<19)
#define BUTTON_21   (1<<20)
#define BUTTON_22   (1<<21)
#define BUTTON_23   (1<<22)
#define BUTTON_24   (1<<23)
#define BUTTON_25   (1<<24)
#define BUTTON_26   (1<<25)
#define BUTTON_27   (1<<26)
#define BUTTON_28   (1<<27)
#define BUTTON_29   (1<<28)
#define BUTTON_30   (1<<29)
#define BUTTON_31   (1<<30)
#define BUTTON_32   (1<<31)

#define DPAD_CENTERED   0
#define DPAD_UP         1
#define DPAD_UP_RIGHT   2
#define DPAD_RIGHT      3
#define DPAD_DOWN_RIGHT 4
#define DPAD_DOWN       5
#define DPAD_DOWN_LEFT  6
#define DPAD_LEFT       7
#define DPAD_UP_LEFT    8

class BleGamepad {
private:
  uint32_t _buttons;
  BleConnectionStatus* connectionStatus;
  BLEHIDDevice* hid;
  BLECharacteristic* inputGamepad;
  void buttons(uint32_t b);
  void rawAction(uint8_t msg[], char msgSize);
  static void taskServer(void* pvParameter);
public:
  BleGamepad(std::string deviceName = "ESP32 BLE Gamepad", std::string deviceManufacturer = "Espressif", uint8_t batteryLevel = 100);
  void begin(void);
  void end(void);
  void setAxes(signed char x, signed char y, signed char z = 0, signed char rZ = 0, char rX = 0, char rY = 0, signed char hat = 0);
  void press(uint32_t b = BUTTON_1);   // press BUTTON_1 by default
  void release(uint32_t b = BUTTON_1); // release BUTTON_1 by default
  bool isPressed(uint32_t b = BUTTON_1); // check BUTTON_1 by default
  bool isConnected(void);
  void setBatteryLevel(uint8_t level);
  uint8_t batteryLevel;
  std::string deviceManufacturer;
  std::string deviceName;
protected:
  virtual void onStarted(BLEServer *pServer) { };
};

#endif // CONFIG_BT_ENABLED
#endif // ESP32_BLE_GAMEPAD_H
