//pin out
#define KAY_Pin 15
#define RALAY_Pin 4
#define BUZZER_Pin 0
#define RF_Receiver_Pin 5
#define ZONE1_Pin 16
#define ZONE2_Pin 14
#define ZONE3_Pin 12
#define ZONE4_Pin 13
#define Analog_Pin A0
#define SIM800L_RESET_Pin 2

#define SIM800L_POWER_Pin 10

//timing
#define timeset1 3
#define timeset2 6
#define timeset3 9
#define timeset4 20

RCSwitch mySwitch = RCSwitch();

ezButton button(KAY_Pin);

ezButton ZONE1_isPressed(ZONE1_Pin);
ezButton ZONE2_isPressed(ZONE2_Pin);
ezButton ZONE3_isPressed(ZONE3_Pin);
ezButton ZONE4_isPressed(ZONE4_Pin);

//SoftwareSerial mySerial(12, 14); // RX, TX

ezBuzzer buzzer(BUZZER_Pin);
ezBuzzer RALAY_ACTION(RALAY_Pin);
ezBuzzer RESET_SIM800L_ACTION(SIM800L_RESET_Pin);
ezBuzzer POWER_SIM800L_ACTION(SIM800L_POWER_Pin);

ESP32Time rtc(0);
