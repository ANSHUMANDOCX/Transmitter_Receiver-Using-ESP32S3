#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define CE_PIN  11
#define CSN_PIN 12

#define SDA_PIN 20
#define SCL_PIN 19

RF24 radio(CE_PIN, CSN_PIN);
const byte address[6] = "00001";

int joy1X = 34, joy1Y = 35;
int joy2X = 36, joy2Y = 37;
int pot1  = 38, pot2  = 39;
int sw1   = 40, sw2   = 41, sw3 = 42, sw4 = 43;

struct DataPacket {
  uint16_t channels[10];
};

DataPacket data;

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);

  Wire.begin(SDA_PIN, SCL_PIN);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);

  SPI.begin(35, 37, 36); // SCK, MISO, MOSI
  radio.begin();
  radio.setPALevel(RF24_PA_LOW);
  radio.setChannel(108);
  radio.setDataRate(RF24_250KBPS);
  radio.openWritingPipe(address);
  radio.stopListening();
}

void loop() {
  data.channels[0] = analogRead(joy1X);
  data.channels[1] = analogRead(joy1Y);
  data.channels[2] = analogRead(joy2X);
  data.channels[3] = analogRead(joy2Y);
  data.channels[4] = analogRead(pot1);
  data.channels[5] = analogRead(pot2);
  data.channels[6] = digitalRead(sw1) * 4095;
  data.channels[7] = digitalRead(sw2) * 4095;
  data.channels[8] = digitalRead(sw3) * 4095;
  data.channels[9] = digitalRead(sw4) * 4095;

  radio.write(&data, sizeof(data));

  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("TX Channel Data:");
  for (int i = 0; i < 10; i++) {
    display.print("CH");
    display.print(i + 1);
    display.print(": ");
    display.println(data.channels[i]);
  }
  display.display();

  delay(50);
}
