# Transmitter_Receiver-Using-ESP32S3
This is an RF ESP32-S3-based 10-channel Transmitter and Receiver which can also be used with the ESP-NOW protocol.

## PARTS
- ESP32-S3 WROOM-1U
- NRF24L01+ Transceiver Module
- SSD1309 2.42 inch OLED
- 2 Joysticks
- 4 Switches
- 2 Potentiometers

## PLAN
This is an RF transmitter with 10 channels, all of which support PWM output. The 10 channels include: 4 from joysticks 2 from potentiometers 4 from toggle switches

The setup includes a 2.42-inch OLED display to show the status of each channel, bind status, and battery level.

The receiver and transmitter will be programmed using an FTDI module.

The transmitter is designed to run for 5–6 hours on a 1000mAh LiPo battery (ideally).

The code is subject to change depending on in hand testing currently its just a sample code for controlling 10 servo motor with the 10 inputs.
# Transmitter 

![image](https://github.com/user-attachments/assets/cc0d7638-6b33-49c5-8a1e-c446c6baa4fc)
![Screenshot 2025-06-24 120350](https://github.com/user-attachments/assets/a4f2a7c2-9d11-44fb-b010-e9bfb4aa33e1)
![image](https://github.com/user-attachments/assets/6ef52723-bfa4-48f4-8c92-48c94e22bfbc)
# Receiver

![image](https://github.com/user-attachments/assets/5cb271f2-eff7-424c-91ec-af8129dca5e4)
![image](https://github.com/user-attachments/assets/8d316921-2f9d-4971-a223-9a69cc73cf77)


## BOM

| Supplier             | Item                                           | Price (USD) |
|----------------------|------------------------------------------------|-------------|
| **LCSC**             | Joystick (x2)                                  | $0.85       |
|                      | SSD1309 2.42" OLED                             | $11.28      |
|                      | ESP32-S3 WROOM                                 | $7.69       |
|                      | Potentiometer (x2)                             | $3.31       |
|                      | Switches (x4)                                  | $2.33       |
|                      | MIC5219 3.3V LDO                               | $1.41       |
|                      | Pin headers+passive component                  | $7.71       |
|                      | Shipping                                       | $3.74       |
|                      | **Total (LCSC)**                               | **$38.05**  |
| **JLCPCB**           | PCB                                            | $6.00       |
|                      | Shipping                                       | $14.00      |
|                      | **Total (JLCPCB)**                             | **$20.00**  |
| **Sharvi Electronics** | nRF24L01+ + Heatset Insert + Charging Module+antenna | $9.53|
|                      | **Total (Sharvi)**                             | **$9.53**   |
| **Electronics Comp.** | Battery                                        | $5.38       |
|                      | **Total (Electronics Comp.)**                 | **$5.38**   |
