
class RFTask : public Task {
  protected:


    ////////////////////////////////////////////////////////////////////////////////////
    void LOOPER() {
      button.loop();
      ZONE1_isPressed.loop();
      ZONE2_isPressed.loop();
      ZONE3_isPressed.loop();
      ZONE4_isPressed.loop();

      buzzer.loop();
      RALAY_ACTION.loop();
      RESET_SIM800L_ACTION.loop();
      POWER_SIM800L_ACTION.loop();
    }
    //
    //////////////////////////////////////////////////////////////////////////////////////////////
    //
    //int TURN_ON_DEVICE(){
    //  if (Turn_Device == HIGH){
    //    return -2;
    //  }
    //  else{
    //    EEPROM.put(0, HIGH);
    //    boolean CHECK = EEPROM.commit();
    //    if(CHECK){
    //      Turn_Device = HIGH;
    //       return 1;
    //    }
    //    else{
    //       return 0;
    //    }
    //  }
    //}
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //int TURN_OFF_DEVICE(){
    //  if (Turn_Device == LOW){
    //    return -2;
    //  }
    //  else{
    //    EEPROM.put(0, LOW);
    //    boolean CHECK = EEPROM.commit();
    //    if(CHECK){
    //      Turn_Device = LOW;
    //       return 1;
    //    }
    //    else{
    //       return 0;
    //    }
    //  }
    //}
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //int TURN_ON_SIREN() {
    //  if (Turn_Siren == HIGH){
    //    return -2;
    //  }
    //  else{
    //    EEPROM.put(4, HIGH);
    //    boolean CHECK = EEPROM.commit();
    //    if(CHECK){
    //      Turn_Siren = HIGH;
    //       return 1;
    //    }
    //    else{
    //       return 0;
    //    }
    //  }
    //}
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //int TURN_OFF_SIREN() {
    //  if (Turn_Siren == LOW){
    //    return -2;
    //  }
    //  else{
    //    EEPROM.put(4, LOW);
    //    boolean CHECK = EEPROM.commit();
    //    if(CHECK){
    //      Turn_Siren = LOW;
    //       return 1;
    //    }
    //    else{
    //       return 0;
    //    }
    //  }
    //}
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //int TURN_ON_BEEP() {
    //  if (Turn_Beep == HIGH){
    //    return -2;
    //  }
    //  else{
    //    EEPROM.put(8, HIGH);
    //    boolean CHECK = EEPROM.commit();
    //    if(CHECK){
    //      Turn_Beep = HIGH;
    //       return 1;
    //    }
    //    else{
    //       return 0;
    //    }
    //  }
    //}
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //int TURN_OFF_BEEP() {
    //  if (Turn_Beep == LOW){
    //    return -2;
    //  }
    //  else{
    //    EEPROM.put(8, LOW);
    //    boolean CHECK = EEPROM.commit();
    //    if(CHECK){
    //      Turn_Beep = LOW;
    //       return 1;
    //    }
    //    else{
    //       return 0;
    //    }
    //  }
    //}
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //int SET_TIME_SIREN(uint32_t value) {
    //  if (Time_Siren == value){
    //    return -2;
    //  }
    //  else{
    //    if(value>15){
    //      value = 15;
    //    }
    //    EEPROM.put(68, value);
    //    boolean CHECK = EEPROM.commit();
    //    if(CHECK){
    //      Time_Siren = value;
    //       return 1;
    //    }
    //    else{
    //       return 0;
    //    }
    //  }
    //}
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //int TURN_ON_ZONE(uint32_t zone){
    //
    //  int SIZE = 14;
    //
    //  if (zone <= SIZE){
    //    if(Turn_ZONE [zone-1] == HIGH){
    //      return -2;
    //    }
    //    else{
    //      EEPROM.put((12+((zone-1)*4)), HIGH);
    //      boolean CHECK = EEPROM.commit();
    //      if(CHECK){
    //          Turn_ZONE [zone-1] = HIGH;
    //         return 1;
    //       }
    //      else{
    //         return 0;
    //      }
    //    }
    //  }
    //  else{
    //    return 0;
    //  }
    //}
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //int TURN_OFF_ZONE(uint32_t zone){
    //
    //  int SIZE =14;
    //
    //  if (zone <= SIZE){
    //    if(Turn_ZONE [zone-1] == LOW){
    //      return -2;
    //    }
    //    else{
    //      EEPROM.put((12+((zone-1)*4)), LOW);
    //      boolean CHECK = EEPROM.commit();
    //      if(CHECK){
    //          Turn_ZONE [zone-1] = LOW;
    //         return 1;
    //       }
    //      else{
    //         return 0;
    //      }
    //    }
    //  }
    //  else{
    //    return 0;
    //  }
    //}

    //////////////////////////////////////////////////////////////////////////////////////////////

    int DATA_ZONE(uint32_t data) {

      int SIZE = 10;
      //Serial.println(SIZE);
      for (byte i = 0; i < SIZE; i++) {
        if (Data_ZONE[i] == data) {

          //Serial.println("dell");
          //Serial.println(i);
          EEPROM.put((72 + (i * 4)), 0);
          boolean CHECK = EEPROM.commit();
          if (CHECK) {
            Data_ZONE[i] = 0;
            //Serial.println("4");
            return  -3;

          }
          else {
            return 0;
          }
        }
      }

      for (byte i = 0; i < SIZE; i++) {
        if (Data_ZONE[i] == 0) {
          EEPROM.put((72 + (i * 4)), data);
          boolean CHECK = EEPROM.commit();
          if (CHECK) {
            Data_ZONE[i] = data;
            //Serial.println("ok");
            //Serial.println(i);
            return  i + 1;
          }
          else {
            return 0;
          }
        }
      }
      return -1;
    }

    //////////////////////////////////////////////////////////////////////////////////////////////

    int DATA_REMOTE_ON(uint32_t data) {

      int SIZE = 10;

      for (byte i = 0; i < SIZE; i++) {
        if (Data_Remote_On[i] == data) {

          EEPROM.put((112 + (i * 4)), 0);
          boolean CHECK = EEPROM.commit();
          if (CHECK) {
            Data_Remote_On[i] = 0;
            return -3;
          }
          else {
            return 0;
          }


        }
      }

      for (byte i = 0; i < SIZE; i++) {
        if (Data_Remote_On[i] == 0) {
          EEPROM.put((112 + (i * 4)), data);
          boolean CHECK = EEPROM.commit();
          if (CHECK) {
            Data_Remote_On[i] = data;
            return i + 1;
          }
          else {
            return 0;
          }
        }
      }
      return -1;
    }

    //////////////////////////////////////////////////////////////////////////////////////////////

    int DATA_REMOTE_OFF(uint32_t data) {

      int SIZE = 10;

      for (byte i = 0; i < SIZE; i++) {
        if (Data_Remote_Off[i] == data) {


          EEPROM.put((152 + (i * 4)), 0);
          boolean CHECK = EEPROM.commit();
          if (CHECK) {
            Data_Remote_Off[i] = 0;
            return -3;
          }
          else {
            return 0;
          }


        }
      }

      for (byte i = 0; i < SIZE; i++) {
        if (Data_Remote_Off[i] == 0) {
          EEPROM.put((152 + (i * 4)), data);
          boolean CHECK = EEPROM.commit();
          if (CHECK) {
            Data_Remote_Off[i] = data;
            return i + 1;
          }
          else {
            return 0;
          }
        }
      }
      return -1;
    }

    //////////////////////////////////////////////////////////////////////////////////////////////

    //int PHONE_NUMBER_DATA(uint64_t data){
    //
    //  int SIZE = 10;
    //
    //  for (byte i = 0; i < SIZE-1; i++) {
    //    if (Phone_Number[i] == data){
    //
    //
    //      EEPROM.put((192+(i*8)), 0);
    //      boolean CHECK = EEPROM.commit();
    //      if(CHECK){
    //            Phone_Number[i] = 0;
    //            return  -3;
    //       }
    //      else{
    //         return 0;
    //      }
    //
    //
    //    }
    //  }
    //
    //  for (byte i = 0; i < SIZE-1; i++) {
    //    if (Phone_Number[i] == 0){
    //      EEPROM.put((192+(i*8)), data);
    //      boolean CHECK = EEPROM.commit();
    //      if(CHECK){
    //            Phone_Number[i] = data;
    //            return  i+1;
    //       }
    //      else{
    //         return 0;
    //      }
    //    }
    //  }
    //   return -1;
    //}

    //////////////////////////////////////////////////////////////////////////////////////////////

    void STATUS_STATIC_ZONE() {
      if (NUMBER_ZONE == 0 && Turn_Device == 1) {

        if (TIMER_S11 >= 120) { //2min
          if (ZONE1_isPressed.isPressed()) {
            if (Turn_ZONE[0]) {
              NUMBER_ZONE = 1;
            }
          }
          if (ZONE2_isPressed.isPressed()) {
            if (Turn_ZONE[1]) {
              NUMBER_ZONE = 2;
            }
          }
          if (ZONE3_isPressed.isPressed()) {
            if (Turn_ZONE[2]) {
              NUMBER_ZONE = 3;
            }
          }
          if (ZONE4_isPressed.isPressed()) {
            if (Turn_ZONE[3]) {
              NUMBER_ZONE = 4;
            }
          }
        }
      }
    }

    ////////////////////////////////////////////////////////////////////////////////////

    void STATUS_POWER() {

      if (analogRead(A0) > 1000) {
        if (POWERFLAGE == false) {
          //Serial.println("The POWER ON is pressed");





          for (int o = 0; o < 10; o++) {
            if (Phone_Number[o] != 0) {
              for (int p = 0; p < 20; p++) {
                if (SMS_OUT_DATAS[p].flag == 0) {
                  SMS_OUT_DATAS[p].flag = 1;
                  SMS_OUT_DATAS[p].SMS_PHONE = Phone_Number[o];
                  String datastr = "Statuses!, Power-up!\n" ;
                  //if (CALL_STATUS == 0) {
                    datastr = datastr + SIM800L_CHEACK_TIME();
                  //}
                  strcpy(SMS_OUT_DATAS[p].SMS_TEXT, datastr.c_str());
                  SMS_OUT_DATAS[p].ESP_TIME = millis();
                  break;
                }
              }
            }
          }


          POWERFLAGE = true;
        }
      }
      if ((analogRead(A0) > 100) && (analogRead(A0) < 200)) {
        if (POWERFLAGE == true) {
          //Serial.println("The POWER OFF is pressed");




          for (int o = 0; o < 10; o++) {
            if (Phone_Number[o] != 0) {
              for (int p = 0; p < 20; p++) {
                if (SMS_OUT_DATAS[p].flag == 0) {
                  SMS_OUT_DATAS[p].flag = 1;
                  SMS_OUT_DATAS[p].SMS_PHONE = Phone_Number[o];
                  String datastr = "Warning!, Power-down!\n" ;
                  //if (CALL_STATUS == 0) {
                    datastr = datastr + SIM800L_CHEACK_TIME();
                  //}
                  strcpy(SMS_OUT_DATAS[p].SMS_TEXT, datastr.c_str());
                  SMS_OUT_DATAS[p].ESP_TIME = millis();
                  break;
                }
              }
            }
          }




          POWERFLAGE = false;
        }
      }
    }

    //    ////////////////////////////////////////////////////////////////////////////////////
    //
    //    void BEEP_ACTION() {
    //      //Serial.println(Turn_Beep);
    //      if (Turn_Beep) {
    //        RALAY_ACTION.beep(100);
    //      }
    //    }

    ////////////////////////////////////////////////////////////////////////////////////

    void SIREN_ACTION(int timer) {
      if (TIMER_S11 >= 300) {
        if (Turn_Siren) {
          RALAY_ACTION.beep(60000 * timer);
        }
      }
    }

    //    ////////////////////////////////////////////////////////////////////////////////////
    //
    //    void SIREN_STOP() {
    //      if (RALAY_ACTION.getState() != BUZZER_IDLE) {
    //        RALAY_ACTION.stop();
    //      }
    //    }

    //////////////////////////////////////////////////////////////////////////////////////
    //void RESTART(){
    //  ESP.restart();
    //}

    ////////////////////////////////////////////////////////////////////////////////////
    //
    //bool CELEAR_MEMORY(){
    //  boolean CHECK = 0;
    //
    //  //EEPROM.put(0, Turn_Device); //Turn_Device
    //  EEPROM.put(4,1); //Turn_Siren
    //  EEPROM.put(8,1); //Turn_Beep
    //
    //
    //  EEPROM.put(12, 1); //Turn_ZONE1
    //  EEPROM.put(16, 1); //Turn_ZONE2
    //  EEPROM.put(20, 1); //Turn_ZONE3
    //  EEPROM.put(24, 1); //Turn_ZONE4
    //  EEPROM.put(28, 1); //Turn_ZONE5
    //  EEPROM.put(32, 1); //Turn_ZONE6
    //  EEPROM.put(36, 1); //Turn_ZONE7
    //  EEPROM.put(40, 1); //Turn_ZONE8
    //  EEPROM.put(44, 1); //Turn_ZONE9
    //  EEPROM.put(48, 1); //Turn_ZONE10
    //  EEPROM.put(52, 1); //Turn_ZONE11
    //  EEPROM.put(56, 1); //Turn_ZONE12
    //  EEPROM.put(60, 1); //Turn_ZONE13
    //  EEPROM.put(64, 1); //Turn_ZONE14
    //
    //  EEPROM.put(68, 15); //Time_Siren
    //
    //     CHECK = EEPROM.commit();
    //      if(CHECK == 0){
    //            return 0;
    //      }
    //
    //
    //  EEPROM.put(72,0); //Data_ZONE5
    //  EEPROM.put(76, 0); //Data_ZONE6
    //  EEPROM.put(80, 0); //Data_ZONE7
    //  EEPROM.put(84, 0); //Data_ZONE8
    //  EEPROM.put(88, 0); //Data_ZONE9
    //  EEPROM.put(92, 0); //Data_ZONE10
    //  EEPROM.put(96, 0); //Data_ZONE11
    //  EEPROM.put(100, 0); //Data_ZONE12
    //  EEPROM.put(104, 0); //Data_ZONE13
    //  EEPROM.put(108, 0); //Data_ZONE14
    //
    //
    //     CHECK = EEPROM.commit();
    //      if(CHECK == 0){
    //            return 0;
    //      }
    //
    //  EEPROM.put(112, 0); //Data_Remote1_On
    //  EEPROM.put(116, 0); //Data_Remote2_On
    //  EEPROM.put(120, 0); //Data_Remote3_On
    //  EEPROM.put(124, 0); //Data_Remote4_On
    //  EEPROM.put(128, 0); //Data_Remote5_On
    //  EEPROM.put(132, 0); //Data_Remote6_On
    //  EEPROM.put(136, 0); //Data_Remote7_On
    //  EEPROM.put(140, 0); //Data_Remote8_On
    //  EEPROM.put(144, 0); //Data_Remote9_On
    //  EEPROM.put(148, 0); //Data_Remote10_On
    //
    //     CHECK = EEPROM.commit();
    //      if(CHECK == 0){
    //            return 0;
    //      }
    //
    //  EEPROM.put(152, 0); //Data_Remote1_Off
    //  EEPROM.put(156, 0); //Data_Remote2_Off
    //  EEPROM.put(160, 0); //Data_Remote3_Off
    //  EEPROM.put(164, 0); //Data_Remote4_Off
    //  EEPROM.put(168, 0); //Data_Remote5_Off
    //  EEPROM.put(172, 0); //Data_Remote6_Off
    //  EEPROM.put(176, 0); //Data_Remote7_Off
    //  EEPROM.put(180, 0); //Data_Remote8_Off
    //  EEPROM.put(184, 0); //Data_Remote9_Off
    //  EEPROM.put(188, 0); //Data_Remote10_Off
    //
    //     CHECK = EEPROM.commit();
    //      if(CHECK == 0){
    //            return 0;
    //      }
    //
    //  EEPROM.put(192, 0); //Phone_Number1
    //  EEPROM.put(200, 0); //Phone_Number2
    //  EEPROM.put(208, 0); //Phone_Number3
    //  EEPROM.put(216, 0); //Phone_Number4
    //  EEPROM.put(224, 0); //Phone_Number5
    //  EEPROM.put(232, 0); //Phone_Number6
    //  EEPROM.put(240, 0); //Phone_Number7
    //  EEPROM.put(248, 0); //Phone_Number8
    //  EEPROM.put(256, 0); //Phone_Number9
    //  EEPROM.put(264, 0); //Phone_Number10
    //
    //
    //     CHECK = EEPROM.commit();
    //      if(CHECK == 1){
    //            EEPROM_GET_ALL_DATA();
    //            return 1;
    //      }
    //      else{
    //            return 0;
    //      }
    //}

    ////////////////////////////////////////////////////////////////////////////////////////////

    void AFTER_START() {
      EEPROM_GET_ALL_DATA();
    }

    ////////////////////////////////////////////////////////////////////////////////////////////

    void SET_SENSOR() {
      ansewer  = 0;
      data =  0;
      NEW_TIME = 0;
      Start_SET_Time = millis();
      mySwitch.resetAvailable();
      while (NEW_TIME <= Start_SET_Time + 10000) {
        //Serial.println("TEST");
        NEW_TIME = millis();
        delay(1);
        LOOPER();

        if (button.isReleased()) {

          if (buzzer.getState() == BUZZER_IDLE) {
            length = sizeof(noteDurations1) / sizeof(int);
            buzzer.playMelody(melody1, noteDurations1, length); // playing

          }
          //Serial.println("key");
          break;
        }

        if (mySwitch.available()) {
          //Serial.println("20");
          if (mySwitch.getReceivedProtocol() == 1) {

            //Serial.println("30");
            data = mySwitch.getReceivedValue();
          }
          mySwitch.resetAvailable();
        }



        if (data) {
          //Serial.println("2");
          ansewer = DATA_ZONE(data);
          //Serial.println(ansewer);
          if (ansewer == -3) {

            if (buzzer.getState() == BUZZER_IDLE) {
              length = sizeof(noteDurations3) / sizeof(int);
              buzzer.playMelody(melody3, noteDurations3, length); // playing
            }

            break;
          }
          else if (ansewer == -2) {

            if (buzzer.getState() == BUZZER_IDLE) {
              length = sizeof(noteDurations1) / sizeof(int);
              buzzer.playMelody(melody1, noteDurations1, length); // playing

            }

            break;
          }
          else if (ansewer == -1) {

            if (buzzer.getState() == BUZZER_IDLE) {
              length = sizeof(noteDurations1) / sizeof(int);
              buzzer.playMelody(melody1, noteDurations1, length); // playing
            }

            break;
          }
          else if (ansewer == 0) {

            if (buzzer.getState() == BUZZER_IDLE) {
              length = sizeof(noteDurations1) / sizeof(int);
              buzzer.playMelody(melody1, noteDurations1, length); // playing
            }

            break;
          }
          else {

            if (buzzer.getState() == BUZZER_IDLE) {
              length = sizeof(noteDurations2) / sizeof(int);
              buzzer.playMelody(melody2, noteDurations2, length); // playing
            }

            break;
          }

        }
      }

    }

    ////////////////////////////////////////////////////////////////////////////////////

    void SET_REMOTE_ON() {

      ansewer  = 0;
      data =  0;
      Start_SET_Time = millis();
      mySwitch.resetAvailable();
      NEW_TIME = 0;
      while (NEW_TIME <= Start_SET_Time + 10000) {
        //Serial.println("TEST");
        NEW_TIME = millis();
        delay(1);
        LOOPER();

        if (button.isReleased()) {

          if (buzzer.getState() == BUZZER_IDLE) {
            length = sizeof(noteDurations1) / sizeof(int);
            buzzer.playMelody(melody1, noteDurations1, length); // playing

          }
          //Serial.println("key");
          break;
        }

        if (mySwitch.available()) {
          //Serial.println("20");
          if (mySwitch.getReceivedProtocol() == 1) {

            //Serial.println("30");
            data = mySwitch.getReceivedValue();
          }
          mySwitch.resetAvailable();
        }



        if (data) {
          //Serial.println("2");
          ansewer = DATA_REMOTE_ON(data);
          //Serial.println(ansewer);
          if (ansewer == -3) {

            if (buzzer.getState() == BUZZER_IDLE) {
              length = sizeof(noteDurations3) / sizeof(int);
              buzzer.playMelody(melody3, noteDurations3, length); // playing
            }

            break;
          }
          else if (ansewer == -2) {

            if (buzzer.getState() == BUZZER_IDLE) {
              length = sizeof(noteDurations1) / sizeof(int);
              buzzer.playMelody(melody1, noteDurations1, length); // playing

            }

            break;
          }
          else if (ansewer == -1) {

            if (buzzer.getState() == BUZZER_IDLE) {
              length = sizeof(noteDurations1) / sizeof(int);
              buzzer.playMelody(melody1, noteDurations1, length); // playing
            }

            break;
          }
          else if (ansewer == 0) {

            if (buzzer.getState() == BUZZER_IDLE) {
              length = sizeof(noteDurations1) / sizeof(int);
              buzzer.playMelody(melody1, noteDurations1, length); // playing
            }

            break;
          }
          else {

            if (buzzer.getState() == BUZZER_IDLE) {
              length = sizeof(noteDurations2) / sizeof(int);
              buzzer.playMelody(melody2, noteDurations2, length); // playing
            }
            break;
          }

        }
      }

    }

    ////////////////////////////////////////////////////////////////////////////////////

    void SET_REMOTE_OFF() {

      ansewer  = 0;
      data =  0;
      NEW_TIME = 0;
      Start_SET_Time = millis();
      mySwitch.resetAvailable();
      while (NEW_TIME <= Start_SET_Time + 10000) {
        NEW_TIME =  millis();
        delay(1);
        //Serial.println("TEST");
        LOOPER();

        if (button.isReleased()) {

          if (buzzer.getState() == BUZZER_IDLE) {
            length = sizeof(noteDurations1) / sizeof(int);
            buzzer.playMelody(melody1, noteDurations1, length); // playing

          }
          //Serial.println("key");
          break;
        }

        if (mySwitch.available()) {
          //Serial.println("20");
          if (mySwitch.getReceivedProtocol() == 1) {

            //Serial.println("30");
            data = mySwitch.getReceivedValue();
          }
          mySwitch.resetAvailable();
        }



        if (data) {
          //Serial.println("2");
          ansewer = DATA_REMOTE_OFF(data);
          //Serial.println(ansewer);
          if (ansewer == -3) {

            if (buzzer.getState() == BUZZER_IDLE) {
              length = sizeof(noteDurations3) / sizeof(int);
              buzzer.playMelody(melody3, noteDurations3, length); // playing
            }

            break;
          }
          else if (ansewer == -2) {

            if (buzzer.getState() == BUZZER_IDLE) {
              length = sizeof(noteDurations1) / sizeof(int);
              buzzer.playMelody(melody1, noteDurations1, length); // playing

            }

            break;
          }
          else if (ansewer == -1) {

            if (buzzer.getState() == BUZZER_IDLE) {
              length = sizeof(noteDurations1) / sizeof(int);
              buzzer.playMelody(melody1, noteDurations1, length); // playing
            }

            break;
          }
          else if (ansewer == 0) {

            if (buzzer.getState() == BUZZER_IDLE) {
              length = sizeof(noteDurations1) / sizeof(int);
              buzzer.playMelody(melody1, noteDurations1, length); // playing
            }

            break;
          }
          else {

            if (buzzer.getState() == BUZZER_IDLE) {
              length = sizeof(noteDurations2) / sizeof(int);
              buzzer.playMelody(melody2, noteDurations2, length); // playing
            }
            break;
          }

        }
      }
    }



    ////////////////////////////////////////////////////////////////////////////////////////////

    void STATUS_BUTTON() {
      if (button.getState() == 1) {
        TIMER_S12 = 0;
        if (Status_key == 0) {
          Status_key = 1;
          Start_Key_Time = millis();


          //if (buzzer.getState() == BUZZER_IDLE) {
          //length = sizeof(noteDurations1) / sizeof(int);
          //buzzer.playMelody(melody1, noteDurations1, length); // playing
          //}

          //Serial.println("The button is released");
          //RALAY_ACTION.beep(900000);
          //RESET_SIM800L_ACTION.beep(100);
        }
        Time = millis();
        if ((Time >= Start_Key_Time + (timeset1 * 1000)) && (Status_key == 1)) {

          if (buzzer.getState() == BUZZER_IDLE) {
            length = sizeof(noteDurations2) / sizeof(int);
            buzzer.playMelody(melody2, noteDurations2, length); // playing
          }
          Status_key = 2;
        }
        if ((Time >= Start_Key_Time + (timeset2 * 1000)) && (Status_key == 2)) {
          if (buzzer.getState() == BUZZER_IDLE) {
            length = sizeof(noteDurations3) / sizeof(int);
            buzzer.playMelody(melody3, noteDurations3, length); // playing
          }
          Status_key = 3;
        }
        if ((Time >= Start_Key_Time + (timeset3 * 1000)) && (Status_key == 3)) {
          if (buzzer.getState() == BUZZER_IDLE) {
            length = sizeof(noteDurations4) / sizeof(int);
            buzzer.playMelody(melody4, noteDurations4, length); // playing
          }
          Status_key = 4;
        }
        if ((Time >= Start_Key_Time + (timeset4 * 1000)) && (Status_key == 4)) {
          if (buzzer.getState() == BUZZER_IDLE) {
            length = sizeof(noteDurations5) / sizeof(int);
            buzzer.playMelody(melody5, noteDurations5, length); // playing
          }
          Status_key = 5;
        }
      }
      if (button.isPressed()) {

        if (Status_key == 1) {
          TIMER_S12 = 30;
          milisetphone = millis() + 600000;  ///10 min
          //Serial.println("1");
        }
        else if (Status_key == 2) {
          //Serial.println("2");
          SET_SENSOR();
          mySwitch.resetAvailable();
        }
        else if (Status_key == 3) {
          //Serial.println("3");
          SET_REMOTE_ON();
          mySwitch.resetAvailable();
        }
        else if (Status_key == 4) {
          //Serial.println("4");
          SET_REMOTE_OFF();
          mySwitch.resetAvailable();
        }
        else {
          //Serial.println("5");
          CELEAR_MEMORY();
          //EEPROM_GET_ALL_DATA();
        }
        //Serial.println("The button is pressed");
        //Serial.println(Status_key);
        Status_key = 0;
      }
    }
    //////////////////////////////////////////////////////////////////////////////////////////////////////

    void RF_MODULE() {

      if (mySwitch.available()) {
        if (mySwitch.getReceivedProtocol() == 1) {
          SWITCH_DATA = 0;
          SWITCH_DATA = mySwitch.getReceivedValue();


          if (NUMBER_ZONE == 0 && Turn_Device == 1) { //ZONE
            for (byte i = 0; i < 9; i++) {
              if ( Data_ZONE[i] == SWITCH_DATA && Turn_ZONE[4 + i]) {
                NUMBER_ZONE = i + 5;
              }
            }
          }



          if (millis() >= NEW_TIME2 + 1000) {
            NEW_TIME2 = millis();

            for (byte i = 0; i < 9; i++) {//REMOT ON
              if ( Data_Remote_On [i] == SWITCH_DATA) {
                int dataout = TURN_ON_DEVICE();

                if (dataout == 1) {
                  NUMBER_ZONE = 0;
                  SMS_CALL_ZONE = 0;
                  SIREN_STOP();
                  BEEP_ACTION();
                  if (buzzer.getState() == BUZZER_IDLE) {
                    length = sizeof(noteDurations2) / sizeof(int);
                    buzzer.playMelody(melody2, noteDurations2, length); // playing
                  }
                  //delay(1000);
                  for (int o = 0; o < 10; o++) {
                    if (Phone_Number[o] != 0) {
                      for (int p = 0; p < 20; p++) {
                        if (SMS_OUT_DATAS[p].flag == 0) {
                          SMS_OUT_DATAS[p].flag = 1;
                          SMS_OUT_DATAS[p].SMS_PHONE = Phone_Number[o];
                          String datastr = "Device activated!, by remote : " + String(i + 1) + "\n";
                          //if (CALL_STATUS == 0) {
                            datastr = datastr + SIM800L_CHEACK_TIME();
                         // }
                          strcpy(SMS_OUT_DATAS[p].SMS_TEXT, datastr.c_str());
                          SMS_OUT_DATAS[p].ESP_TIME = millis();
                          break;
                        }
                      }
                    }
                  }
                }
                if (dataout == -2) {
                  NUMBER_ZONE = 0;
                  SMS_CALL_ZONE = 0;
                  SIREN_STOP();
                  BEEP_ACTION();
                  if (buzzer.getState() == BUZZER_IDLE) {
                    length = sizeof(noteDurations3) / sizeof(int);
                    buzzer.playMelody(melody3, noteDurations3, length); // playing
                  }
                }
              }
            }


            for (byte i = 0; i < 9; i++) {//REMOT OFF
              if ( Data_Remote_Off [i] == SWITCH_DATA) {
                int dataout = TURN_OFF_DEVICE();

                if (dataout == 1) {
                  NUMBER_ZONE = 0;
                  SMS_CALL_ZONE = 0;
                  SIREN_STOP();
                  BEEP_ACTION();
                  if (buzzer.getState() == BUZZER_IDLE) {
                    length = sizeof(noteDurations2) / sizeof(int);
                    buzzer.playMelody(melody2, noteDurations2, length); // playing
                  }
                  // delay(1000);
                  for (int e = 0; e < 10; e++) {
                    if (Phone_Number[e] != 0) {
                      for (int f = 0; f < 20; f++) {
                        if (SMS_OUT_DATAS[f].flag == 0) {
                          SMS_OUT_DATAS[f].flag = 1;
                          SMS_OUT_DATAS[f].SMS_PHONE = Phone_Number[e];
                          String datastr = "Device deactivated!, by remote : " + String(i + 1) + "\n";
                          //if (CALL_STATUS == 0) {
                            datastr = datastr + SIM800L_CHEACK_TIME();
                          //}
                          strcpy(SMS_OUT_DATAS[f].SMS_TEXT, datastr.c_str());
                          SMS_OUT_DATAS[f].ESP_TIME = millis();
                          break;
                        }
                      }
                    }
                  }
                }
                if (dataout == -2) {
                  NUMBER_ZONE = 0;
                  SMS_CALL_ZONE = 0;
                  SIREN_STOP();
                  BEEP_ACTION();
                  if (buzzer.getState() == BUZZER_IDLE) {
                    length = sizeof(noteDurations3) / sizeof(int);
                    buzzer.playMelody(melody3, noteDurations3, length); // playing
                  }
                }
              }
            }


          }
        }
        mySwitch.resetAvailable();
      }

    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////

    void SIREN_PROCESS() {


      if (NUMBER_ZONE != 0) {

        if (SMS_CALL_ZONE == 0) {
          SMS_CALL_ZONE = NUMBER_ZONE;
          TIMER_SMS_CALL_ZONE = millis() + 300000 ; //5 min
        }



        if (RALAY_ACTION.getState() == BUZZER_IDLE) {

          SIREN_ACTION(Time_Siren);

        }
        //Serial.println(NUMBER_ZONE);
        if (Turn_Device == 0 || RALAY_ACTION.getState() != BUZZER_IDLE) {
          NUMBER_ZONE = 0;
        }
      }

    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////




    void SMS_WARNING() {
      if (SMS_CALL_ZONE >= 1) {
        for (int o = 0; o < 10; o++) {
          if (Phone_Number[o] != 0) {
            for (int p1 = 0; p1 < 20; p1++) {
              if (CALL_OUT_DATAS[p1].flag == 0) {
                CALL_OUT_DATAS[p1].flag = 1;
                CALL_OUT_DATAS[p1].CALL_NUMBER = SMS_CALL_ZONE;
                CALL_OUT_DATAS[p1].CALL_PHONE = Phone_Number[o];
                CALL_OUT_DATAS[p1].ESP_TIME = millis();
                break;
              }
            }
            for (int p2 = 19; p2 >= 0; p2--) {
              if (CALL_OUT_DATAS[p2].flag == 0) {
                CALL_OUT_DATAS[p2].flag = 1;
                CALL_OUT_DATAS[p2].CALL_NUMBER = SMS_CALL_ZONE;
                CALL_OUT_DATAS[p2].CALL_PHONE = Phone_Number[o];
                CALL_OUT_DATAS[p2].ESP_TIME = millis();
                break;
              }
            }
          }
        }
        for (int o = 0; o < 10; o++) {
          if (Phone_Number[o] != 0) {
            for (int p = 0; p < 20; p++) {
              if (SMS_OUT_DATAS[p].flag == 0) {
                SMS_OUT_DATAS[p].flag = 1;
                SMS_OUT_DATAS[p].SMS_PHONE = Phone_Number[o];
                String datastr = "Motion detection warning!, by zone : " + String(SMS_CALL_ZONE) + "\n";
                //if (CALL_STATUS == 0) {
                  datastr = datastr + SIM800L_CHEACK_TIME();
                //}
                strcpy(SMS_OUT_DATAS[p].SMS_TEXT, datastr.c_str());
                SMS_OUT_DATAS[p].ESP_TIME = millis();
                break;
              }
            }
          }
        }
        SMS_CALL_ZONE = -1;
      }
      if (SMS_CALL_ZONE == -1) {
        if (TIMER_SMS_CALL_ZONE < millis()) {
          SMS_CALL_ZONE = 0;
          if (Turn_Siren == LOW) {
            NUMBER_ZONE = 0;
          }
        }
      }
    }

    void setup() {

      WiFi.mode(WIFI_OFF);

      mySwitch.enableReceive(RF_Receiver_Pin);

      button.setDebounceTime(100);

      ZONE1_isPressed.setDebounceTime(20);
      ZONE2_isPressed.setDebounceTime(20);
      ZONE3_isPressed.setDebounceTime(20);
      ZONE4_isPressed.setDebounceTime(20);


      EEPROM_GET_ALL_DATA();

      if (Turn_Time_Reset == 1) {
        TIMER_S11 = 301;
      }




    }




    void loop() {
      LOOPER();
      STATUS_POWER();
      STATUS_STATIC_ZONE();
      STATUS_BUTTON();
      RF_MODULE();
      SIREN_PROCESS();
      SMS_WARNING();
    }

} rf_task;
