
void EEPROM_GET_ALL_DATA() {

  EEPROM.get(0, Turn_Device); //Turn_Device
  EEPROM.get(4, Turn_Siren); //Turn_Siren
  EEPROM.get(8, Turn_Beep); //Turn_Beep

  //Serial.println(Turn_Device);
  //Serial.println(Turn_Siren);
  //Serial.println(Turn_Beep);

  EEPROM.get(12, Turn_ZONE[0]); //Turn_ZONE1
  EEPROM.get(16, Turn_ZONE[1]); //Turn_ZONE2
  EEPROM.get(20, Turn_ZONE[2]); //Turn_ZONE3
  EEPROM.get(24, Turn_ZONE[3]); //Turn_ZONE4
  EEPROM.get(28, Turn_ZONE[4]); //Turn_ZONE5
  EEPROM.get(32, Turn_ZONE[5]); //Turn_ZONE6
  EEPROM.get(36, Turn_ZONE[6]); //Turn_ZONE7
  EEPROM.get(40, Turn_ZONE[7]); //Turn_ZONE8
  EEPROM.get(44, Turn_ZONE[8]); //Turn_ZONE9
  EEPROM.get(48, Turn_ZONE[9]); //Turn_ZONE10
  EEPROM.get(52, Turn_ZONE[10]); //Turn_ZONE11
  EEPROM.get(56, Turn_ZONE[11]); //Turn_ZONE12
  EEPROM.get(60, Turn_ZONE[12]); //Turn_ZONE13
  EEPROM.get(64, Turn_ZONE[13]); //Turn_ZONE14

  //Serial.println(Turn_ZONE[0]);
  //Serial.println(Turn_ZONE[1]);
  //Serial.println(Turn_ZONE[2]);
  //Serial.println(Turn_ZONE[2]);
  //Serial.println(Turn_ZONE[3]);
  //Serial.println(Turn_ZONE[4]);
  //Serial.println(Turn_ZONE[5]);
  //Serial.println(Turn_ZONE[6]);
  //Serial.println(Turn_ZONE[7]);
  //Serial.println(Turn_ZONE[8]);
  //Serial.println(Turn_ZONE[9]);
  //Serial.println(Turn_ZONE[10]);
  //Serial.println(Turn_ZONE[11]);
  //Serial.println(Turn_ZONE[12]);
  //Serial.println(Turn_ZONE[13]);

  EEPROM.get(68, Time_Siren); //Time_Siren

  EEPROM.get(72, Data_ZONE[0]); //Data_ZONE5
  EEPROM.get(76, Data_ZONE[1]); //Data_ZONE6
  EEPROM.get(80, Data_ZONE[2]); //Data_ZONE7
  EEPROM.get(84, Data_ZONE[3]); //Data_ZONE8
  EEPROM.get(88, Data_ZONE[4]); //Data_ZONE9
  EEPROM.get(92, Data_ZONE[5]); //Data_ZONE10
  EEPROM.get(96, Data_ZONE[6]); //Data_ZONE11
  EEPROM.get(100, Data_ZONE[7]); //Data_ZONE12
  EEPROM.get(104, Data_ZONE[8]); //Data_ZONE13
  EEPROM.get(108, Data_ZONE[9]); //Data_ZONE14

  //  Serial.println(Data_ZONE[0]);
  //Serial.println(Data_ZONE[1]);
  //Serial.println(Data_ZONE[2]);

  EEPROM.get(112, Data_Remote_On[0]); //Data_Remote1_On
  EEPROM.get(116, Data_Remote_On[1]); //Data_Remote2_On
  EEPROM.get(120, Data_Remote_On[2]); //Data_Remote3_On
  EEPROM.get(124, Data_Remote_On[3]); //Data_Remote4_On
  EEPROM.get(128, Data_Remote_On[4]); //Data_Remote5_On
  EEPROM.get(132, Data_Remote_On[5]); //Data_Remote6_On
  EEPROM.get(136, Data_Remote_On[6]); //Data_Remote7_On
  EEPROM.get(140, Data_Remote_On[7]); //Data_Remote8_On
  EEPROM.get(144, Data_Remote_On[8]); //Data_Remote9_On
  EEPROM.get(148, Data_Remote_On[9]); //Data_Remote10_On

  EEPROM.get(152, Data_Remote_Off[0]); //Data_Remote1_Off
  EEPROM.get(156, Data_Remote_Off[1]); //Data_Remote2_Off
  EEPROM.get(160, Data_Remote_Off[2]); //Data_Remote3_Off
  EEPROM.get(164, Data_Remote_Off[3]); //Data_Remote4_Off
  EEPROM.get(168, Data_Remote_Off[4]); //Data_Remote5_Off
  EEPROM.get(172, Data_Remote_Off[5]); //Data_Remote6_Off
  EEPROM.get(176, Data_Remote_Off[6]); //Data_Remote7_Off
  EEPROM.get(180, Data_Remote_Off[7]); //Data_Remote8_Off
  EEPROM.get(184, Data_Remote_Off[8]); //Data_Remote9_Off
  EEPROM.get(188, Data_Remote_Off[9]); //Data_Remote10_Off

  EEPROM.get(192, Phone_Number[0]); //Phone_Number1
  EEPROM.get(196, Phone_Number[1]); //Phone_Number2
  EEPROM.get(200, Phone_Number[2]); //Phone_Number3
  EEPROM.get(204, Phone_Number[3]); //Phone_Number4
  EEPROM.get(208, Phone_Number[4]); //Phone_Number5
  EEPROM.get(212, Phone_Number[5]); //Phone_Number6
  EEPROM.get(216, Phone_Number[6]); //Phone_Number7
  EEPROM.get(220, Phone_Number[7]); //Phone_Number8
  EEPROM.get(224, Phone_Number[8]); //Phone_Number9
  EEPROM.get(228, Phone_Number[9]); //Phone_Number10

  EEPROM.get(232, Turn_Time_Reset); //Turn_Time_Reset


  //  for (byte i = 0; i < 10 ; i++) {
  //    mySerial.print("Phone_Number :");
  //    mySerial.println(Phone_Number[i]);
  //    mySerial.print("Data_Remote_On :");
  //    mySerial.println(Data_Remote_On[i]);
  //    mySerial.print("Data_Remote_Off :");
  //    mySerial.println(Data_Remote_Off[i]);
  //    mySerial.print("Data_ZONE :");
  //    mySerial.println(Data_ZONE[i]);
  //  }
}

////////////////////////////////////////////////////////////////////////////////////

bool CELEAR_MEMORY() {
  boolean CHECK = 0;

  //EEPROM.put(0, Turn_Device); //Turn_Device
  EEPROM.put(4, 1); //Turn_Siren
  EEPROM.put(8, 1); //Turn_Beep


  EEPROM.put(12, 1); //Turn_ZONE1
  EEPROM.put(16, 1); //Turn_ZONE2
  EEPROM.put(20, 1); //Turn_ZONE3
  EEPROM.put(24, 1); //Turn_ZONE4
  EEPROM.put(28, 1); //Turn_ZONE5
  EEPROM.put(32, 1); //Turn_ZONE6
  EEPROM.put(36, 1); //Turn_ZONE7
  EEPROM.put(40, 1); //Turn_ZONE8
  EEPROM.put(44, 1); //Turn_ZONE9
  EEPROM.put(48, 1); //Turn_ZONE10
  EEPROM.put(52, 1); //Turn_ZONE11
  EEPROM.put(56, 1); //Turn_ZONE12
  EEPROM.put(60, 1); //Turn_ZONE13
  EEPROM.put(64, 1); //Turn_ZONE14

  EEPROM.put(68, 15); //Time_Siren

  CHECK = EEPROM.commit();
  if (CHECK == 0) {
    return 0;
  }


  EEPROM.put(72, 0); //Data_ZONE5
  EEPROM.put(76, 0); //Data_ZONE6
  EEPROM.put(80, 0); //Data_ZONE7
  EEPROM.put(84, 0); //Data_ZONE8
  EEPROM.put(88, 0); //Data_ZONE9
  EEPROM.put(92, 0); //Data_ZONE10
  EEPROM.put(96, 0); //Data_ZONE11
  EEPROM.put(100, 0); //Data_ZONE12
  EEPROM.put(104, 0); //Data_ZONE13
  EEPROM.put(108, 0); //Data_ZONE14


  CHECK = EEPROM.commit();
  if (CHECK == 0) {
    return 0;
  }

  EEPROM.put(112, 0); //Data_Remote1_On
  EEPROM.put(116, 0); //Data_Remote2_On
  EEPROM.put(120, 0); //Data_Remote3_On
  EEPROM.put(124, 0); //Data_Remote4_On
  EEPROM.put(128, 0); //Data_Remote5_On
  EEPROM.put(132, 0); //Data_Remote6_On
  EEPROM.put(136, 0); //Data_Remote7_On
  EEPROM.put(140, 0); //Data_Remote8_On
  EEPROM.put(144, 0); //Data_Remote9_On
  EEPROM.put(148, 0); //Data_Remote10_On

  CHECK = EEPROM.commit();
  if (CHECK == 0) {
    return 0;
  }

  EEPROM.put(152, 0); //Data_Remote1_Off
  EEPROM.put(156, 0); //Data_Remote2_Off
  EEPROM.put(160, 0); //Data_Remote3_Off
  EEPROM.put(164, 0); //Data_Remote4_Off
  EEPROM.put(168, 0); //Data_Remote5_Off
  EEPROM.put(172, 0); //Data_Remote6_Off
  EEPROM.put(176, 0); //Data_Remote7_Off
  EEPROM.put(180, 0); //Data_Remote8_Off
  EEPROM.put(184, 0); //Data_Remote9_Off
  EEPROM.put(188, 0); //Data_Remote10_Off

  CHECK = EEPROM.commit();
  if (CHECK == 0) {
    return 0;
  }

  EEPROM.put(192, 0); //Phone_Number1
  EEPROM.put(196, 0); //Phone_Number2
  EEPROM.put(200, 0); //Phone_Number3
  EEPROM.put(204, 0); //Phone_Number4
  EEPROM.put(208, 0); //Phone_Number5
  EEPROM.put(212, 0); //Phone_Number6
  EEPROM.put(216, 0); //Phone_Number7
  EEPROM.put(220, 0); //Phone_Number8
  EEPROM.put(224, 0); //Phone_Number9
  EEPROM.put(228, 0); //Phone_Number10

  EEPROM.put(232, 0); //Turn_Time_Reset

  CHECK = EEPROM.commit();

  //mySerial.println(CHECK);
  if (CHECK == 1) {
    EEPROM_GET_ALL_DATA();
    return 1;
  }
  else {
    return 0;
  }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

int PHONE_NUMBER_DATA(uint64_t data) {

  if (data < 10000000) {
    return 0;
  }

  for (byte i = 0; i < 10 ; i++) {
    if (Phone_Number[i] == data) {


      EEPROM.put((192 + (i * 4)), 0);
      boolean CHECK = EEPROM.commit();
      if (CHECK) {
        Phone_Number[i] = 0;
        return  -3;
      }
      else {
        return 0;
      }


    }
  }

  for (byte i = 0; i < 10 ; i++) {

    //mySerial.println(Phone_Number[i]);


    if (Phone_Number[i] == 0) {
      EEPROM.put((192 + (i * 4)), data);
      boolean CHECK = EEPROM.commit();
      if (CHECK) {
        Phone_Number[i] = data;
        return  i + 1;
      }
      else {
        return 0;
      }
    }
  }
  return -1;
}




////////////////////////////////////////////////////////////////////////////////////////////

int TURN_ON_DEVICE() {
  if (Turn_Device == HIGH) {
    return -2;
  }
  else {
    EEPROM.put(0, HIGH);
    boolean CHECK = EEPROM.commit();
    if (CHECK) {
      Turn_Device = HIGH;
      return 1;
    }
    else {
      return 0;
    }
  }
}

//////////////////////////////////////////////////////////////////////////////////////////////

int TURN_OFF_DEVICE() {
  if (Turn_Device == LOW) {
    return -2;
  }
  else {
    EEPROM.put(0, LOW);
    boolean CHECK = EEPROM.commit();
    if (CHECK) {
      Turn_Device = LOW;
      return 1;
    }
    else {
      return 0;
    }
  }
}

//////////////////////////////////////////////////////////////////////////////////////////////

int TURN_ON_SIREN() {
  if (Turn_Siren == HIGH) {
    return -2;
  }
  else {
    EEPROM.put(4, HIGH);
    boolean CHECK = EEPROM.commit();
    if (CHECK) {
      Turn_Siren = HIGH;
      return 1;
    }
    else {
      return 0;
    }
  }
}

//////////////////////////////////////////////////////////////////////////////////////////////

int TURN_OFF_SIREN() {
  if (Turn_Siren == LOW) {
    return -2;
  }
  else {
    EEPROM.put(4, LOW);
    boolean CHECK = EEPROM.commit();
    if (CHECK) {
      Turn_Siren = LOW;
      return 1;
    }
    else {
      return 0;
    }
  }
}

//////////////////////////////////////////////////////////////////////////////////////////////

int TURN_ON_BEEP() {
  if (Turn_Beep == HIGH) {
    return -2;
  }
  else {
    EEPROM.put(8, HIGH);
    boolean CHECK = EEPROM.commit();
    if (CHECK) {
      Turn_Beep = HIGH;
      return 1;
    }
    else {
      return 0;
    }
  }
}

//////////////////////////////////////////////////////////////////////////////////////////////

int TURN_OFF_BEEP() {
  if (Turn_Beep == LOW) {
    return -2;
  }
  else {
    EEPROM.put(8, LOW);
    boolean CHECK = EEPROM.commit();
    if (CHECK) {
      Turn_Beep = LOW;
      return 1;
    }
    else {
      return 0;
    }
  }
}

//////////////////////////////////////////////////////////////////////////////////////////////

int SET_TIME_SIREN(uint32_t value) {
  if (Time_Siren == value) {
    return -2;
  }
  else {
    if (value > 15) {
      value = 15;
    }
    EEPROM.put(68, value);
    boolean CHECK = EEPROM.commit();
    if (CHECK) {
      Time_Siren = value;
      return 1;
    }
    else {
      return 0;
    }
  }
}

//////////////////////////////////////////////////////////////////////////////////////////////

int TURN_ON_ZONE(uint32_t zone) {

  int SIZE = 14;

  if (zone <= SIZE) {
    if (Turn_ZONE [zone - 1] == HIGH) {
      return -2;
    }
    else {
      EEPROM.put((12 + ((zone - 1) * 4)), HIGH);
      boolean CHECK = EEPROM.commit();
      if (CHECK) {
        Turn_ZONE [zone - 1] = HIGH;
        return 1;
      }
      else {
        return 0;
      }
    }
  }
  else {
    return 0;
  }
}

//////////////////////////////////////////////////////////////////////////////////////////////

int TURN_OFF_ZONE(uint32_t zone) {

  int SIZE = 14;

  if (zone <= SIZE) {
    if (Turn_ZONE [zone - 1] == LOW) {
      return -2;
    }
    else {
      EEPROM.put((12 + ((zone - 1) * 4)), LOW);
      boolean CHECK = EEPROM.commit();
      if (CHECK) {
        Turn_ZONE [zone - 1] = LOW;
        return 1;
      }
      else {
        return 0;
      }
    }
  }
  else {
    return 0;
  }
}

////////////////////////////////////////////////////////////////////////////////////

int TURN_TIME_RESET_ON() {
  if (Turn_Time_Reset == HIGH) {
    return -2;
  }
  else {
    EEPROM.put(232, HIGH);
    boolean CHECK = EEPROM.commit();
    if (CHECK) {
      Turn_Time_Reset = HIGH;
      return 1;
    }
    else {
      return 0;
    }
  }
}
////////////////////////////////////////////////////////////////////////////////////

int TURN_TIME_RESET_OFF() {
  if (Turn_Time_Reset == LOW) {
    return -2;
  }
  else {
    EEPROM.put(232, LOW);
    boolean CHECK = EEPROM.commit();
    if (CHECK) {
      Turn_Time_Reset = LOW;
      return 1;
    }
    else {
      return 0;
    }
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
void RESTART() {
  //POWER_SIM800L_ACTION.beep(10000);
  //delay(10000);
  ESP.restart();
}

////////////////////////////////////////////////////////////////////////////////////

void SIREN_STOP() {
  if (RALAY_ACTION.getState() != BUZZER_IDLE) {
    RALAY_ACTION.stop();
  }
}

////////////////////////////////////////////////////////////////////////////////////

void BEEP_ACTION() {
  //Serial.println(Turn_Beep);
  if (TIMER_S11 >= 300) {
    if (Turn_Beep) {
      RALAY_ACTION.beep(50);
    }
  }
}
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////sim800l///////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////





String SIM800L_CHEACK_TIME() {
  String StringReturn = "" ;
if (rtc.getYear() > 2001){
  StringReturn = rtc.getTime("%d %B %Y %H:%M:%S");
}
  return StringReturn;
}
