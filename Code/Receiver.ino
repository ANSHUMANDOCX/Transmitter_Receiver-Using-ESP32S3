#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>

#define CE_PIN  17
#define CSN_PIN 16

RF24 radio(CE_PIN, CSN_PIN);
const byte address[6] = "00001";

struct DataPacket {
  uint16_t channels[10];
};

DataPacket data;

Servo servos[10];
int servoPins[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

void setup() {
  Serial.begin(115200);

  for (int i = 0; i < 10; i++) {
    servos[i].attach(servoPins[i]);
  }

  SPI.begin(35, 37, 36); // SCK, MISO, MOSI
  radio.begin();
  radio.setPALevel(RF24_PA_LOW);
  radio.setChannel(108);
  radio.setDataRate(RF24_250KBPS);
  radio.openReadingPipe(0, address);
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    radio.read(&data, sizeof(data));

    for (int i = 0; i < 10; i++) {
      int angle = map(data.channels[i], 0, 4095, 0, 180);
      servos[i].write(angle);
    }
  }
}
