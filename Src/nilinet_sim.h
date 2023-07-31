class SIMTask : public Task {
  protected:




    String SIM800L_1A(unsigned long endtime = 0) {

      unsigned long  starttime = millis();
      unsigned long  timer = 0;
      bool outdata = 0;
      String StringReturn = "EROR\r" ;
      //char a[20540]="";
      //char DATA[] = "AT+CFUN=1\r\n";
      //mySerial.println(sizeof(DATA) );
      //mySerial.write(0X1A);
      if (TIMER_S12 >= 60) {
        Serial.write(0X1A);
      }
      // Serial.println(DATA);
      while (1)  {
        if (TIMER_S12 < 60) { //fffffffffffffffffffffffffffff
          STATUS_ERROR ++;
          StringReturn = "ERROR\r" ;
          break;
        }
        if ( StringReturn == "ERROR\r") {
          //mySerial.write("ERROR\r");
          STATUS_ERROR ++;
          break;
        }
        if ( StringReturn == "OK\r" ) {
          //mySerial.write("OK\r");
          break;
        }
        if (timer > starttime + endtime) {
          //mySerial.write("TIMER\r");
          STATUS_ERROR ++;
          StringReturn = "ERROR\r" ;
          break;
        }
        timer = millis();
        if (Serial.available() > 0) {
          StringReturn = Serial.readStringUntil('\n');
        }
        delay(1);
        //ESP.wdtFeed();
      }
      delay(100);
      return StringReturn;
    }




    String SIM800L_SEND(char DATA[],  unsigned long endtime = 0) {

      unsigned long  starttime = millis();
      unsigned long  timer = 0;
      bool outdata = 0;
      String StringReturn = "EROR\r" ;
      //char a[20540]="";
      //char DATA[] = "AT+CFUN=1\r\n";
      //mySerial.println(sizeof(DATA) );
      //mySerial.write(DATA);
      if (TIMER_S12 >= 60) {
        Serial.write(DATA);
      }
      // Serial.println(DATA);
      while (1)  {
        if (TIMER_S12 < 60) { //fffffffffffffffffffffffffffffffffffff
          STATUS_ERROR ++;
          StringReturn = "ERROR\r" ;
          break;
        }

        if ( StringReturn == "ERROR\r") {
          //mySerial.write("ERROR\r");
          STATUS_ERROR ++;
          break;
        }
        if ( StringReturn == "OK\r" ) {
          //mySerial.write("OK\r");
          break;
        }
        if (timer > starttime + endtime) {
          //mySerial.write("TIMER\r");
          STATUS_ERROR ++;
          StringReturn = "ERROR\r" ;
          break;
        }
        timer = millis();
        if (Serial.available() > 0) {
          StringReturn = Serial.readStringUntil('\n');
        }
        delay(1);
        //ESP.wdtFeed();
      }
      delay(100);
      return StringReturn;
    }





    bool SIM800L_CHEACK_CCALR() {
      unsigned long  starttime = millis();
      unsigned long  timer = 0;
      String StringReturn = "EROR\r" ;
      bool outdata = 0;
      if (TIMER_S12 >= 60) {
        Serial.write("AT+CCALR?\r\n");
      }
      while (1)  {
        if (TIMER_S12 < 60) {  //fffffffffffffffffffffffffffffffff
          STATUS_ERROR ++;
          outdata = 0;
          break;
        }

        if ( StringReturn == "ERROR\r") {
          STATUS_ERROR ++;
          outdata = 0;
          break;
        }
        if ( StringReturn == "+CCALR: 1\r" ) {
          outdata = 1;
          break;
        }
        if (timer > starttime + 5000) {
          STATUS_ERROR ++;
          outdata = 0;
          break;
        }
        timer = millis();
        if (Serial.available() > 0) {
          StringReturn = Serial.readStringUntil('\n');
          //Serial.println("SIM800L_CHEACK_CCALR:");
          //Serial.println(StringReturn);
        }
        delay(1);
        //ESP.wdtFeed();
      }
      delay(500);
      //Serial.println("SIM800L_CHEACK_CCALR:");
      //Serial.println(outdata);
      return outdata;
    }






    int SIM800L_CHEACK_CREG() {
      unsigned long  starttime = millis();
      unsigned long  timer = 0;
      String StringReturn = "EROR\r" ;
      int outdata = 0;
      if (TIMER_S12 >= 60) {
        Serial.write("AT+CREG?\r\n");
      }
      while (1)  {



        if (TIMER_S12 < 60) { //ffffffffffffffffffffffffffffffffffffffffffffff
          STATUS_ERROR ++;
          outdata = 0;
          break;
        }



        if ( StringReturn == "ERROR\r") {
          STATUS_ERROR ++;
          outdata = 0;
          break;
        }
        if ( StringReturn == "+CREG: 0,1\r" ) {
          outdata = 1;
          break;
        }
        if ( StringReturn == "+CREG: 0,5\r" ) {
          outdata = 1;
          break;
        }
        if ( StringReturn == "+CREG: 0,2\r" ) {
          outdata = 2;
          break;
        }

        if (timer > starttime + 5000) {
          STATUS_ERROR ++;
          outdata = 0;
          break;
        }
        timer = millis();
        if (Serial.available() > 0) {
          StringReturn = Serial.readStringUntil('\n');
          //Serial.println("SIM800L_CHEACK_CREG:");
          //Serial.println(StringReturn);
        }
        delay(1);
        //ESP.wdtFeed();
      }
      //Serial.println("SIM800L_CHEACK_CREG:");
      //Serial.println(outdata);
      delay(1000);
      return outdata;
    }








    //    String SIM800L_CHEACK_TIME() {
    //      unsigned long  starttime = millis();
    //      unsigned long  timer = 0;
    //      String StringReturn = "" ;
    //      Serial.write("AT+CCLK?\r\n");
    //      while (1)  {
    //        if ( StringReturn == "ERROR\r") {
    //          STATUS_ERROR ++;
    //          StringReturn = "";
    //          break;
    //        }
    //        if ( StringReturn.indexOf("+CCLK: \"")  == 0 ) {
    //          StringReturn = StringReturn.substring(8, 25);
    //          break;
    //        }
    //
    //        if (timer > starttime + 5000) {
    //          STATUS_ERROR ++;
    //          break;
    //        }
    //        timer = millis();
    //        if (Serial.available() > 0) {
    //          StringReturn = Serial.readStringUntil('\n');
    //        }
    //      }
    //      return StringReturn;
    //    }




    String SIM800L_CHEACK_SIGNALL_POWER() {
      unsigned long  starttime = millis();
      unsigned long  timer = 0;
      String StringReturn = "" ;
      if (TIMER_S12 >= 60) {
        Serial.write("AT+CSQ\r\n");
      }
      while (1)  {


        if (TIMER_S12 < 60) { //fffffffffffffffffffffffffffffffffffffffffffffffffffff
          STATUS_ERROR ++;
          break;
        }


        if ( StringReturn == "ERROR\r") {
          STATUS_ERROR ++;
          StringReturn = "";
          break;
        }
        if ( StringReturn.indexOf("+CSQ: ")  == 0 ) {
          StringReturn = StringReturn.substring(6, StringReturn.length() - 1);
          break;
        }

        if (timer > starttime + 5000) {
          STATUS_ERROR ++;
          break;
        }
        timer = millis();
        if (Serial.available() > 0) {
          StringReturn = Serial.readStringUntil('\n');
        }
        delay(1);
      }
      delay(500);
      return StringReturn;
    }


    String SIM800L_USSD(String DATA) {
      unsigned long  starttime = millis();
      unsigned long  timer = 0;
      String StringReturn = "" ;

      char Buf[50];
      String TimeSTR = "AT+CUSD=1,\"" + DATA + "\"\r\n";

      TimeSTR.toCharArray(Buf, 50);
      //mySerial.write(Buf);
      if (SIM800L_SEND("AT+CUSD=1\r\n", 200) == "OK\r") {
        Serial.write(Buf);
        while (1)  {

          if (TIMER_S12 < 60) {  //ffffffffffffffffffffffffffffffffffffff
            STATUS_ERROR ++;
            StringReturn = "Unspecified error";
            break;
          }

          if ( StringReturn == "ERROR\r") {
            STATUS_ERROR ++;
            StringReturn = "Unspecified error";
            break;
          }
          if ( StringReturn.indexOf("+CUSD: ")  == 0 ) {
            StringReturn = StringReturn;
            break;
          }

          if (timer > starttime + 60000) {
            STATUS_ERROR ++;
            StringReturn = "Time over error";
            break;
          }
          timer = millis();
          if (Serial.available() > 0) {
            StringReturn = Serial.readStringUntil('\n');
          }
          delay(1);
        }
      }
      else {
        StringReturn = "Unspecified error";
      }
      delay(1000);
      return StringReturn;
    }


    int SIM800L_DEFALT() {
      SIM800L_SEND("AT\r\n", 1000) ;
      delay(100);
      SIM800L_SEND("AT\r\n", 1000) ;
      delay(100);
      SIM800L_SEND("AT\r\n", 1000) ;
      delay(100);
      char trueans = 0;
      if (SIM800L_SEND("ATE0\r\n", 1000) == "OK\r") //N ECHO
        trueans++;
      delay(100);
      if (SIM800L_SEND("AT\r\n", 1000) == "OK\r") // OK
        trueans++;
      delay(100);
      if (SIM800L_SEND("AT+CMGF=1\r\n", 1000) == "OK\r") //HALAT MATNI
        trueans++;
      delay(100);
      if (SIM800L_SEND("AT+CLIP=1\r\n", 1000) == "OK\r") //NAMAYESH SHOMARE
        trueans++;
      delay(100);
      if (SIM800L_SEND("AT+CNMI=2,2,0,1,0\r\n", 1000) == "OK\r") //DARYAFT PAYAM
        trueans++;
      delay(100);
      if (SIM800L_SEND("AT+DDET=1\r\n", 1000) == "OK\r") //AADAD NAMAESH DADE SHAVAD
        trueans++;
      delay(100);
      if (SIM800L_SEND("AT+GSMBUSY=1\r\n", 1000) == "OK\r") //TAMASHAYE VOROODI BASTE
        trueans++;
      delay(100);
      if (SIM800L_SEND("AT+CMGDA=\"DEL ALL\"\r\n", 1000) == "OK\r") //PACK KON PAYAMHARO
        trueans++;
      delay(100);
      if (SIM800L_SEND("AT+CREG=0\r\n", 1000) == "OK\r") //DEFALT
        trueans++;
      delay(100);
      if (SIM800L_SEND("AT+CSCS=\"IRA\"\r\n", 1000) == "OK\r") //ENGLISI
        trueans++;
      delay(100);
      if (SIM800L_SEND("AT+CSMP=49,167,0,0\r\n", 1000) == "OK\r") //MARBOOT BE PAYAM
        trueans++;
      delay(100);
      if (SIM800L_SEND("AT+CLCC=1\r\n", 1000) == "OK\r") //JOZYAT TAMAS
        trueans++;
      delay(100);
      if (SIM800L_SEND("AT+CUSD=1\r\n", 1000) == "OK\r") //A USSD
        trueans++;
      delay(100);
      if (SIM800L_SEND("AT+CLTS=1\r\n", 1000) == "OK\r") // SAVE
        trueans++;
      delay(100);

      if (SIM800L_SEND("AT&W\r\n", 2000) == "OK\r") // SAVE
        trueans++;
      delay(100);
      return trueans;
    }











    bool SIM800L_PPWER_OFF() {
      unsigned long  starttime = millis();
      unsigned long  timer = 0;
      String StringReturn = "EROR\r" ;
      bool outdata = 0;
      Serial.write("AT+CPOWD=1\r\n");
      while (1)  {
        if ( StringReturn == "ERROR\r") {
          STATUS_ERROR ++;
          outdata = 0;
          break;
        }
        if ( StringReturn.indexOf("NORMAL POWER DOWN")  == 0 ) {
          outdata = 1;
          break;
        }
        if (timer > starttime + 5000) {
          STATUS_ERROR ++;
          outdata = 0;
          break;
        }
        timer = millis();
        if (Serial.available() > 0) {
          StringReturn = Serial.readStringUntil('\n');
        }
        delay(1);
      }
      delay(500);
      return outdata;
    }







    int SIM800L_SOFTRESET() {
      char trueans = 0;


      SIM800L_SEND("AT\r\n", 500) ;
      delay(500);
      SIM800L_SEND("AT\r\n", 500) ;
      delay(500);
      SIM800L_SEND("AT\r\n", 500) ;
      delay(500);
      if (SIM800L_SEND("AT+CFUN=0\r\n", 7000) == "OK\r") {
        trueans++;
      }
      delay(15000);
      if (SIM800L_SEND("AT+CFUN=1\r\n", 7000) == "OK\r") {
        trueans++;
      }
      delay(20000);
      return trueans;
    }















    bool SIM800L_SRESTART() {
      busy = 1;
      if (SIM800L_SOFTRESET() >= 0) {
        if (SIM800L_DEFALT() >= 15) {
          delay(1000);
          busy = 0;
          return true;
        }
        else {
          busy = 0;
          delay(1000);
          return false;
        }
      }
      else {
        busy = 0;
        delay(1000);
        return false;
      }
      busy = 0;
    }









    bool SIM800L_HRESTART() {
      ///hardware reset
      busy = 1;
      SIM800L_PPWER_OFF();
      delay(3000);
      RESET_SIM800L_ACTION.beep(100);
      delay(20000);
      if (SIM800L_DEFALT() >= 15) {
        delay(1000);
        busy = 0;
        return true;
      }
      else {
        delay(1000);
        busy = 0;
        return false;
      }
      busy = 0;
    }






    bool SIM800L_HPOWER() {
      ///hardware reset
      busy = 1;
      SIM800L_PPWER_OFF();
      delay(3000);
      POWER_SIM800L_ACTION.beep(10000);
      delay(30000);
      if (SIM800L_DEFALT() >= 15) {
        delay(1000);
        busy = 0;
        return true;
      }
      else {
        delay(1000);
        busy = 0;
        return false;
      }
      busy = 0;
    }








    void SMS_DETECTION() {
      if (Serial.available() > 0) {
        //mySerial.println("DDDDDD");
        //String_SMS_DATA_IN1 = "";
        //  String_SMS_DATA_IN2 = "";


        if (SMS_IN_I == 0) {
          String_SMS_DATA_IN1 = Serial.readStringUntil('\n');
          if (String_SMS_DATA_IN1 != "" && String_SMS_DATA_IN1 != "\n" && String_SMS_DATA_IN1 != "\r\n" && String_SMS_DATA_IN1 != "\r\r\n" && String_SMS_DATA_IN1 != "\r" && String_SMS_DATA_IN1 != "\r\r"  ) {




            if ( String_SMS_DATA_IN1.substring(0, 5) == "+CDS:" ) {
              timer_derivery_sms = millis();
            }




            SMS_IN_I ++;


            //mySerial.println( "2 --> " + String(CALL_STATUS));
            if (CALL_STATUS >= 1) {
              //mySerial.println( "2 --> " + String_SMS_DATA_IN1.substring(7, 16) );
              if ( String_SMS_DATA_IN1.substring(7, 16) == "1,0,0,0,0" ) {
                //mySerial.println("1,0,0,0,0");
                Serial.write("AT+VTS=\"*,#,*,#,*,#,*,#\",1\r\n");
                //SIM800L_SEND("AT+VTS=*\r\n", 500);
                CALL_OUT_DATAS[CALL_STATUS - 1].flag = 0;
                CALL_ANS_STATUS = 1;
                call_resp_timer = millis();
                //Serial.write("AT+CLDTMF=100,\"1,2,3,4,5,6,7,8,9,0,*,#,A,B,C,D\"\r\n");
              }



              if ( String_SMS_DATA_IN1.substring(7, 16) == "1,0,3,0,0" )  {
                //mySerial.println("1,0,3,0,0");

                CALL_Ring_STATUS = 1;
              }


              if ( String_SMS_DATA_IN1.substring(7, 16) == "1,0,6,0,0" ) {
                //mySerial.println("1,0,6,0,0");
                if (CALL_Ring_STATUS == 1 || CALL_Ring_STATUS2 >= 5 ) {
                  CALL_OUT_DATAS[CALL_STATUS - 1].flag = 0;
                  CALL_Ring_STATUS2 = 0;
                  //SIM800L_HPOWER();
                }
                else if (CALL_Ring_STATUS == 0 && CALL_Ring_STATUS2 == 2) {
                  CALL_Ring_STATUS2 ++;
                  SIM800L_SRESTART();
                  //SIM800L_HRESTART();
                }
                else if (CALL_Ring_STATUS == 0 && CALL_Ring_STATUS2 == 3) {
                  CALL_Ring_STATUS2 ++;
                  SIM800L_HRESTART();
                  //SIM800L_HPOWER();
                }
                else if (CALL_Ring_STATUS == 0 && CALL_Ring_STATUS2 == 4) {
                  CALL_Ring_STATUS2 ++;
                  //SIM800L_HRESTART();
                  SIM800L_HPOWER();
                }
                else {
                  CALL_Ring_STATUS2 ++;
                }
                CALL_ANS_STATUS = 0;
                CALL_STATUS = 0;
                CALL_Ring_STATUS = 0;
                //Serial.write("ATH\r\n");
              }
              if ( String_SMS_DATA_IN1.substring(0, 5) == "error" ) {
                CALL_ANS_STATUS = 0;
                CALL_STATUS = 0;
              }
            }




            String_SMS_DATA_IN1.toLowerCase();

            if (String_SMS_DATA_IN1.indexOf(": \"+989") >= 4) {
              if (String_SMS_DATA_IN2.indexOf("rij") == 0 ) {
                SMS_DATA_NUMBER_NEW ++;
              }
            }
            if (String_SMS_DATA_IN2.indexOf(": \"+989") >= 4) {
              if (String_SMS_DATA_IN1.indexOf("rij") == 0 ) {
                SMS_DATA_NUMBER_NEW ++;
              }
            }

            //mySerial.println("0 : " + String_SMS_DATA_IN1);
          }
        }





        else if (SMS_IN_I == 1) {
          String_SMS_DATA_IN2 = Serial.readStringUntil('\n');
          if (String_SMS_DATA_IN2 != "" && String_SMS_DATA_IN2 != "\n" && String_SMS_DATA_IN2 != "\r\n" && String_SMS_DATA_IN2 != "\r\r\n" && String_SMS_DATA_IN2 != "\r" && String_SMS_DATA_IN2 != "\r\r"  ) {



            if ( String_SMS_DATA_IN2.substring(0, 5) == "+CDS:" ) {
              timer_derivery_sms = millis();
            }



            SMS_IN_I ++;

            //mySerial.println( "1 --> " + String(CALL_STATUS));
            if (CALL_STATUS >= 1) {
              //mySerial.println( "1 --> " + String_SMS_DATA_IN2.substring(7, 16));
              if ( String_SMS_DATA_IN2.substring(7, 16) == "1,0,0,0,0" )  {
                //mySerial.println("1,0,0,0,0");
                Serial.write("AT+VTS=\"*,#,*,#,*,#,*,#\",1\r\n");
                CALL_OUT_DATAS[CALL_STATUS - 1].flag = 0;
                CALL_ANS_STATUS = 1;
                call_resp_timer = millis();
                //Serial.write("AT+CLDTMF=100,\"1,2,3,4,5,6,7,8,9,0,*,#,A,B,C,D\"\r\n");
              }

              if ( String_SMS_DATA_IN2.substring(7, 16) == "1,0,3,0,0" )  {
                //mySerial.println("1,0,3,0,0");

                CALL_Ring_STATUS = 1;
              }

              if ( String_SMS_DATA_IN2.substring(7, 16) == "1,0,6,0,0" )  {
                //mySerial.println("1,0,6,0,0");
                if (CALL_Ring_STATUS == 1 || CALL_Ring_STATUS2 >= 5 ) {
                  CALL_OUT_DATAS[CALL_STATUS - 1].flag = 0;
                  CALL_Ring_STATUS2 = 0;
                  //SIM800L_HPOWER();
                }
                else if (CALL_Ring_STATUS == 0 && CALL_Ring_STATUS2 == 2) {
                  CALL_Ring_STATUS2 ++;
                  SIM800L_SRESTART();
                  //SIM800L_HRESTART();
                }
                else if (CALL_Ring_STATUS == 0 && CALL_Ring_STATUS2 == 3) {
                  CALL_Ring_STATUS2 ++;
                  SIM800L_HRESTART();
                  //SIM800L_HPOWER();
                }

                else if (CALL_Ring_STATUS == 0 && CALL_Ring_STATUS2 == 4) {
                  CALL_Ring_STATUS2 ++;
                  //SIM800L_HRESTART();
                  SIM800L_HPOWER();
                }

                else {
                  CALL_Ring_STATUS2 ++;
                }
                CALL_ANS_STATUS = 0;
                CALL_STATUS = 0;
                CALL_Ring_STATUS = 0;
                //Serial.write("ATH\r\n");
              }
              if ( String_SMS_DATA_IN2.substring(0, 5) == "error" ) {
                CALL_ANS_STATUS = 0;
                CALL_STATUS = 0;
              }
            }

            String_SMS_DATA_IN2.toLowerCase();



            if (String_SMS_DATA_IN1.indexOf(": \"+989") >= 4) {
              if (String_SMS_DATA_IN2.indexOf("rij") == 0 ) {
                SMS_DATA_NUMBER_NEW ++;
              }
            }
            if (String_SMS_DATA_IN2.indexOf(": \"+989") >= 4) {
              if (String_SMS_DATA_IN1.indexOf("rij") == 0 ) {
                SMS_DATA_NUMBER_NEW ++;
              }
            }

            //mySerial.println("1 : " + String_SMS_DATA_IN2);
          }
        }
        else {

        }
        //mySerial.println(String_SMS_DATA_IN1);



        //mySerial.println(String_SMS_DATA_IN2);


        if (SMS_IN_I >= 2) {
          SMS_IN_I = 0;
        }


      }
      //////////////////////////////////////////////////////////////////////////////////////////////////////

      if (SMS_DATA_NUMBER_NEW != SMS_DATA_NUMBER_LAST) {

        String_SMS_DATA_IN3 = "";
        INT_SMS_DATA_IN4 = 0;

        SMS_DATA_NUMBER_LAST = SMS_DATA_NUMBER_NEW;

        for (int i = 0; i < 48; i++) {


          if (String_SMS_DATA_IN1.indexOf( SMS_INSTRACTION_IN_String[i]) == 0) {
            //mySerial.println("ok 1");
            //mySerial.println(String_SMS_DATA_IN2);
            SMS_IN_J = String_SMS_DATA_IN2.indexOf(": \"+989");

            if (SMS_IN_J >= 4) {

              //mySerial.println("ok 2");
              //mySerial.println(String_SMS_DATA_IN2);

              String_SMS_DATA_IN3 = String_SMS_DATA_IN2.substring(SMS_IN_J + 7, SMS_IN_J + 16);
              //mySerial.println("phone per5 :");
              //mySerial.println(String_SMS_DATA_IN3);
              INT_SMS_DATA_IN4 = String_SMS_DATA_IN3.toInt();
              //mySerial.println("phone per6 :");
              //mySerial.println(INT_SMS_DATA_IN4);


              for (int j = 0; j < 10; j++) {


                if ((INT_SMS_DATA_IN4 == Phone_Number[j] ) || i == 1) {
                  // mySerial.println("ok number");

                  //mySerial.println("ok 3");
                  for (int k = 0; k < 10; k++) {
                    if (SMS_IN_DATAS[k].flag == 0 ) {
                      //mySerial.println("ok 4");
                      SMS_IN_DATAS[k].flag  = 1;
                      SMS_IN_DATAS[k].SMS_NUMBER  = i;
                      SMS_IN_DATAS[k].COMAND_SMS_PHONE  = INT_SMS_DATA_IN4;

                      //mySerial.println("phone per7 :");
                      //mySerial.println(SMS_IN_DATAS[k].COMAND_SMS_PHONE);


                      if (i == 1) {
                        //mySerial.println("ok 5");

                        if (String_SMS_DATA_IN1.length() == 31) {
                          //mySerial.println("ok 5.1");
                          //mySerial.println(String_SMS_DATA_IN1.substring(23, 25) );
                          if (String_SMS_DATA_IN1.substring(19, 21) == "09") {
                            //mySerial.println("ok 5.3");
                            strcpy(SMS_IN_DATAS[k].COMAND_DATA, String_SMS_DATA_IN1.substring(19, 30).c_str());
                          }
                          else {
                            strcpy(SMS_IN_DATAS[k].COMAND_DATA, "ERROR");
                          }
                        }
                        else {
                          strcpy(SMS_IN_DATAS[k].COMAND_DATA, "ERROR");
                        }

                      }




                      else if (i == 2) {
                        //mySerial.println("ok 6");
                        if (String_SMS_DATA_IN1.length() == 34) {
                          //mySerial.println("ok 6.1");
                          if (String_SMS_DATA_IN1.substring(15, 16) == "/") {
                            // mySerial.println("ok 6.2");
                            if (String_SMS_DATA_IN1.substring(30, 33) == "+18" || String_SMS_DATA_IN1.substring(30, 33) == "+14") {
                              // mySerial.println("ok 6.3");
                              strcpy(SMS_IN_DATAS[k].COMAND_DATA, String_SMS_DATA_IN1.substring(13, 33).c_str());
                            }
                            else {
                              strcpy(SMS_IN_DATAS[k].COMAND_DATA, "ERROR");
                            }
                          }
                          else {
                            strcpy(SMS_IN_DATAS[k].COMAND_DATA, "ERROR");
                          }
                        }
                        else {
                          strcpy(SMS_IN_DATAS[k].COMAND_DATA , "ERROR");
                        }
                      }


                      else if (i == 3) {
                        //mySerial.println("ok 7");
                        if (String_SMS_DATA_IN1.length() >= 13) {
                          //mySerial.println("ok 7.1");
                          if (String_SMS_DATA_IN1.substring(10, 11) == "*") {
                            //mySerial.println("ok 7.2");
                            if (String_SMS_DATA_IN1.substring(String_SMS_DATA_IN1.length() - 2, String_SMS_DATA_IN1.length() - 1) == "#") {
                              //mySerial.println("ok 7.3");
                              strcpy(SMS_IN_DATAS[k].COMAND_DATA, String_SMS_DATA_IN1.substring(10, String_SMS_DATA_IN1.length() - 1).c_str());
                            }

                            else {
                              strcpy(SMS_IN_DATAS[k].COMAND_DATA , "ERROR");
                            }
                          }
                          else {
                            strcpy(SMS_IN_DATAS[k].COMAND_DATA , "ERROR");
                          }
                        }
                        else {
                          strcpy(SMS_IN_DATAS[k].COMAND_DATA , "ERROR");
                        }
                      }



                      else {
                        //mySerial.println("ok 8");
                        strcpy(SMS_IN_DATAS[k].COMAND_DATA , "");
                      }


                      SMS_IN_DATAS[k].ESP_TIME  = millis();
                      //mySerial.println(SMS_IN_DATAS[k].SMS_NUMBER);
                      break;
                    }
                  }
                  break;
                }
              }


              break;
            }
            String_SMS_DATA_IN1 = "";
            String_SMS_DATA_IN2 = "";
            break;
          }


          else if (String_SMS_DATA_IN2.indexOf( SMS_INSTRACTION_IN_String[i]) == 0) {


            //mySerial.println("ok char");
            //mySerial.println("ok 1");
            // mySerial.println(String_SMS_DATA_IN1);
            SMS_IN_J = String_SMS_DATA_IN1.indexOf(": \"+989");
            if (SMS_IN_J >= 4) {

              //mySerial.println("ok 2");
              //mySerial.println(String_SMS_DATA_IN1);
              String_SMS_DATA_IN3 = String_SMS_DATA_IN1.substring(SMS_IN_J + 7, SMS_IN_J + 16);


              //mySerial.println("phone per5 :");
              //mySerial.println(String_SMS_DATA_IN3);


              //mySerial.println(String_SMS_DATA_IN3);
              INT_SMS_DATA_IN4 = String_SMS_DATA_IN3.toInt();

              //mySerial.println("phone per6 :");
              //mySerial.println(INT_SMS_DATA_IN4);

              // mySerial.println(String(INT_SMS_DATA_IN4));

              for (int j = 0; j < 10; j++) {
                if (INT_SMS_DATA_IN4 == Phone_Number[j]  || i == 1) {

                  //mySerial.println("ok 3");




                  for (int k = 0; k < 10; k++) {
                    if (SMS_IN_DATAS[k].flag == 0 ) {
                      SMS_IN_DATAS[k].flag  = 1;
                      SMS_IN_DATAS[k].SMS_NUMBER  = i;
                      SMS_IN_DATAS[k].COMAND_SMS_PHONE  = INT_SMS_DATA_IN4;

                      //mySerial.println("ok 4");


                      //mySerial.println("phone per7 :");
                      //mySerial.println(SMS_IN_DATAS[k].COMAND_SMS_PHONE);





                      if (i == 1) {
                        //mySerial.println("ok 5");
                        if (String_SMS_DATA_IN2.length() == 31) {
                          //mySerial.println("ok 5.1");
                          //mySerial.println(String_SMS_DATA_IN2.substring(23, 25) );
                          if (String_SMS_DATA_IN2.substring(19, 21) == "09") {
                            //mySerial.println("ok 5.2");
                            strcpy(SMS_IN_DATAS[k].COMAND_DATA , String_SMS_DATA_IN2.substring(19, 30).c_str());
                          }
                          else {
                            //mySerial.println("ok 5.3");
                            strcpy(SMS_IN_DATAS[k].COMAND_DATA , "ERROR");
                          }
                        }
                        else {
                          //mySerial.println("ok 5.4");
                          strcpy(SMS_IN_DATAS[k].COMAND_DATA , "ERROR");
                        }

                      }




                      else if (i == 2) {
                        // mySerial.println("ok 6");
                        if (String_SMS_DATA_IN2.length() == 34) {
                          //mySerial.println("ok 6.1");

                          if (String_SMS_DATA_IN2.substring(15, 16) == "/") {
                            //mySerial.println("ok 6.2");

                            if (String_SMS_DATA_IN2.substring(30, 33) == "+18" || String_SMS_DATA_IN2.substring(30, 33) == "+14") {
                              //mySerial.println("ok 6.3");

                              strcpy(SMS_IN_DATAS[k].COMAND_DATA , String_SMS_DATA_IN2.substring(13, 33).c_str());
                            }
                            else {
                              strcpy(SMS_IN_DATAS[k].COMAND_DATA , "ERROR");
                            }
                          }
                          else {
                            strcpy(SMS_IN_DATAS[k].COMAND_DATA , "ERROR");
                          }
                        }
                        else {
                          strcpy(SMS_IN_DATAS[k].COMAND_DATA , "ERROR");
                        }
                      }


                      else if (i == 3) {
                        //mySerial.println("ok 7");
                        if (String_SMS_DATA_IN2.length() >= 13) {
                          // mySerial.println("ok 7.1");
                          if (String_SMS_DATA_IN2.substring(10, 11) == "*") {
                            //mySerial.println("ok 7.2");
                            if (String_SMS_DATA_IN2.substring(String_SMS_DATA_IN2.length() - 2, String_SMS_DATA_IN2.length() - 1) == "#") {
                              // mySerial.println("ok 7.3");
                              strcpy(SMS_IN_DATAS[k].COMAND_DATA , String_SMS_DATA_IN2.substring(10, String_SMS_DATA_IN2.length() - 1).c_str());
                            }

                            else {
                              //mySerial.println("ok 7.4");
                              strcpy(SMS_IN_DATAS[k].COMAND_DATA , "ERROR");
                            }
                          }
                          else {
                            // mySerial.println("ok 7.5");
                            strcpy(SMS_IN_DATAS[k].COMAND_DATA , "ERROR");
                          }
                        }
                        else {
                          // mySerial.println("ok 7.6");
                          strcpy(SMS_IN_DATAS[k].COMAND_DATA , "ERROR");
                        }
                      }



                      else {
                        // mySerial.println("ok 8");
                        strcpy(SMS_IN_DATAS[k].COMAND_DATA , "");
                      }




                      SMS_IN_DATAS[k].ESP_TIME  = millis();
                      //mySerial.println(SMS_IN_DATAS[k].SMS_NUMBER);
                      break;
                    }
                  }
                  break;
                }
              }

              break;
            }
            String_SMS_DATA_IN1 = "";
            String_SMS_DATA_IN2 = "";
            break;
          }



          else {

          }
        }
      }

    }




    bool SIM800L_SETTIME(String DATA) {
      char Buf[40];
      String TimeSTR = "AT+CCLK=\"" + DATA.substring(0, 20) + "\"\r\n";
      TimeSTR.toCharArray(Buf, 40);
      if (SIM800L_SEND(Buf, 3000) == "OK\r") {
        return 1;
      }
      return 0;
    }





    void SMS_DECODE() {

      if (TIMER_S3 >= 2) {
        TIMER_S3 = 0;



        for (int k = 0; k < 10; k++) {
          if (SMS_IN_DATAS[k].flag == 1 ) {

            int DATA_NUMBER_DCODE  = SMS_IN_DATAS[k].SMS_NUMBER ;
            int DATA_NUMBER_DCODE_ZONE  = 0;
            String data1 = "";
            int data2 = 0;
            bool data3 = 0;

            int qqbbuser = 0;

            for (int q = 0; q < 10; q++) {
              if (Phone_Number[q] == SMS_IN_DATAS[k].COMAND_SMS_PHONE) {
                qqbbuser =  q + 1;
                break;
              }
            }

            if (DATA_NUMBER_DCODE == 0) { //  "nilinet865210036125408\r",     SIM800L_CHEACK_TIME()

              for (int p = 0; p < 20; p++) {
                if (SMS_OUT_DATAS[p].flag == 0) {
                  SMS_OUT_DATAS[p].flag = 1;
                  SMS_OUT_DATAS[p].SMS_PHONE = SMS_IN_DATAS[k].COMAND_SMS_PHONE;

                  for (int o = 0; o < 10; o++) {
                    if ( Phone_Number[o] != 0) {
                      if (Phone_Number[o] < 10) {
                        data1 = data1 + "User " + String(o + 1) + ") " + "0900000000" + String(  Phone_Number[o] ) + "\n";
                      }
                      else if (Phone_Number[o] < 100) {
                        data1 = data1 + "User " + String(o + 1) + ") " + "090000000" + String(  Phone_Number[o] ) + "\n";
                      }
                      else if (Phone_Number[o] < 1000) {
                        data1 = data1 + "User " + String(o + 1) + ") " + "09000000" + String(  Phone_Number[o] ) + "\n";
                      }
                      else if (Phone_Number[o] < 10000) {
                        data1 = data1 + "User " + String(o + 1) + ") " + "0900000" + String(  Phone_Number[o] ) + "\n";
                      }
                      else if (Phone_Number[o] < 100000) {
                        data1 = data1 + "User " + String(o + 1) + ") " + "090000" + String(  Phone_Number[o] ) + "\n";
                      }
                      else if (Phone_Number[o] < 1000000) {
                        data1 = data1 + "User " + String(o + 1) + ") " + "09000" + String(  Phone_Number[o] ) + "\n";
                      }
                      else if (Phone_Number[o] < 10000000) {
                        data1 = data1 + "User " + String(o + 1) + ") " + "0900" + String(  Phone_Number[o] ) + "\n";
                      }
                      else if (Phone_Number[o] < 100000000) {
                        data1 = data1 + "User " + String(o + 1) + ") " + "090" + String(  Phone_Number[o] ) + "\n";
                      }
                      else {
                        data1 = data1 + "User " + String(o + 1) + ") " + "09" + String(  Phone_Number[o] ) + "\n";
                      }
                    }
                  }
                  if (CALL_STATUS == 0) {
                    data1 = data1 +  SIM800L_CHEACK_TIME();
                  }
                  strcpy(SMS_OUT_DATAS[p].SMS_TEXT, data1.c_str());
                  SMS_OUT_DATAS[p].ESP_TIME = SMS_IN_DATAS[k].ESP_TIME;
                  break;
                }
              }
            }
            else if (DATA_NUMBER_DCODE == 1) { // "nilinet865210036125408;",

              if (millis() < milisetphone) {
                for (int p = 0; p < 20; p++) {
                  if (SMS_OUT_DATAS[p].flag == 0) {
                    SMS_OUT_DATAS[p].flag = 1;
                    SMS_OUT_DATAS[p].SMS_PHONE = SMS_IN_DATAS[k].COMAND_SMS_PHONE;
                    data2 = PHONE_NUMBER_DATA(atoi(&SMS_IN_DATAS[k].COMAND_DATA[2]));
                    if (data2 >= 1 ) {
                      String datastr110 = "Mobile number saved for user: " + String(data2);
                      strcpy(SMS_OUT_DATAS[p].SMS_TEXT, datastr110.c_str());
                      TIMER_S13 = 17970;
                    }
                    else if (data2 == -3) {
                      strcpy(SMS_OUT_DATAS[p].SMS_TEXT, "Mobile number deleted!");
                    }
                    else if (data2 == -1) {
                      strcpy(SMS_OUT_DATAS[p].SMS_TEXT, "Error!, Mobile number memory is full!");
                    }
                    else {
                      strcpy(SMS_OUT_DATAS[p].SMS_TEXT, "Error!");
                    }
                    SMS_OUT_DATAS[p].ESP_TIME = SMS_IN_DATAS[k].ESP_TIME;
                    break;
                  }
                }
              }
              else {
                for (int p2 = 0; p2 < 20; p2++) {
                  if (SMS_OUT_DATAS[p2].flag == 0) {
                    SMS_OUT_DATAS[p2].flag = 1;
                    SMS_OUT_DATAS[p2].SMS_PHONE = SMS_IN_DATAS[k].COMAND_SMS_PHONE;
                    strcpy(SMS_OUT_DATAS[p2].SMS_TEXT, "Error!, Press the settings button, Before sending the message!");
                    SMS_OUT_DATAS[p2].ESP_TIME = SMS_IN_DATAS[k].ESP_TIME;
                    break;
                  }
                }
              }


            }
            else if (DATA_NUMBER_DCODE == 2 && CALL_STATUS == 0) { //  "nilinet set time:"
              for (int p = 0; p < 20; p++) {
                if (SMS_OUT_DATAS[p].flag == 0) {

                  SMS_OUT_DATAS[p].flag = 1;
                  SMS_OUT_DATAS[p].SMS_PHONE = SMS_IN_DATAS[k].COMAND_SMS_PHONE;

                  if ( SIM800L_SETTIME(String(SMS_IN_DATAS[k].COMAND_DATA))) {
                    strcpy(SMS_OUT_DATAS[p].SMS_TEXT, "Time saved!");
                    TIMER_S13 = 17970;
                  }
                  else {
                    strcpy(SMS_OUT_DATAS[p].SMS_TEXT, "Error!");
                  }
                  SMS_OUT_DATAS[p].ESP_TIME = SMS_IN_DATAS[k].ESP_TIME;
                  break;
                }
              }
            }
            else if (DATA_NUMBER_DCODE == 3 && CALL_STATUS == 0) { // "nilinet ucode:"////////////////////////////////////////////////////////////////////////////



              for (int p = 0; p < 20; p++) {
                if (SMS_OUT_DATAS[p].flag == 0) {
                  SMS_OUT_DATAS[p].flag = 1;
                  SMS_OUT_DATAS[p].SMS_PHONE = SMS_IN_DATAS[k].COMAND_SMS_PHONE;
                  data1 = SIM800L_USSD(String(SMS_IN_DATAS[k].COMAND_DATA));
                  strcpy(SMS_OUT_DATAS[p].SMS_TEXT, data1.c_str());
                  SMS_OUT_DATAS[p].ESP_TIME = SMS_IN_DATAS[k].ESP_TIME;
                  break;
                }
              }

            }



            else if (DATA_NUMBER_DCODE == 6) { // "nilinet status\r"

              for (int p = 0; p < 20; p++) {
                if (SMS_OUT_DATAS[p].flag == 0) {


                  data1 = "Device: ";
                  if (Turn_Device) {
                    data1 = data1 + "On\n";
                  }
                  else {
                    data1 = data1 + "Off\n";
                  }

                  data1 = data1 + "Siren: ";
                  if (Turn_Siren) {
                    data1 = data1 + "On\n";
                  }
                  else {
                    data1 = data1 + "Off\n";
                  }

                  data1 = data1 + "Beep: ";
                  if (Turn_Beep) {
                    data1 = data1 + "On\n";
                  }
                  else {
                    data1 = data1 + "Off\n";
                  }

                  data1 = data1 + "Siren time: " + String(Time_Siren) + "\n";

                  data1 = data1 + "Signal power: " + SIM800L_CHEACK_SIGNALL_POWER() + "\n";
                  if (CALL_STATUS == 0) {
                    data1 = data1 + SIM800L_CHEACK_TIME();
                  }
                  SMS_OUT_DATAS[p].flag = 1;
                  SMS_OUT_DATAS[p].SMS_PHONE = SMS_IN_DATAS[k].COMAND_SMS_PHONE;


                  //mySerial.println("phone per3 :");
                  //mySerial.println(SMS_IN_DATAS[k].COMAND_SMS_PHONE);
                  //mySerial.println("phone per4 :");
                  //mySerial.println(SMS_OUT_DATAS[p].SMS_PHONE);
                  strcpy(SMS_OUT_DATAS[p].SMS_TEXT, data1.c_str());
                  SMS_OUT_DATAS[p].ESP_TIME = SMS_IN_DATAS[k].ESP_TIME;
                  break;
                }
              }

            }

            else if (DATA_NUMBER_DCODE == 13) { // "nilinet status zone\r"


              for (int p = 0; p < 20; p++) {
                if (SMS_OUT_DATAS[p].flag == 0) {

                  for (int o = 0; o < 14; o++) {
                    data1 = data1 + "Zone " + String(o + 1) + " : ";
                    if (Turn_ZONE[o]) {
                      data1 = data1 + "On";
                    }
                    else {
                      data1 = data1 + "Off";
                    }
                    if ( o > 3) {
                      data1 = data1 + " ( " + String(Data_ZONE[o - 4]) + " )";
                    }
                    data1 = data1 + "\n";
                  }
                  if (CALL_STATUS == 0) {
                    data1 = data1 + SIM800L_CHEACK_TIME();
                  }

                  SMS_OUT_DATAS[p].flag = 1;
                  SMS_OUT_DATAS[p].SMS_PHONE = SMS_IN_DATAS[k].COMAND_SMS_PHONE;
                  strcpy(SMS_OUT_DATAS[p].SMS_TEXT, data1.c_str());
                  SMS_OUT_DATAS[p].ESP_TIME = SMS_IN_DATAS[k].ESP_TIME;
                  break;
                }
              }

            }

            else if (DATA_NUMBER_DCODE == 7) { // "nilinet reset\r",
              RESTART();
            }


            else if (DATA_NUMBER_DCODE == 12) { // "nilinet clear\r"
              // note use in vertion
            }

            else if (DATA_NUMBER_DCODE == 4) { //  "nilinet on\r"
              data2 = TURN_ON_DEVICE();



              for (int o = 0; o < 10; o++) {
                if (Phone_Number[o] != 0) {
                  for (int p = 0; p < 20; p++) {
                    if (SMS_OUT_DATAS[p].flag == 0) {
                      SMS_OUT_DATAS[p].flag = 1;
                      SMS_OUT_DATAS[p].SMS_PHONE = Phone_Number[o];
                      if (data2  == 1) {
                        if (buzzer.getState() == BUZZER_IDLE) {
                          length = sizeof(noteDurations2) / sizeof(int);
                          buzzer.playMelody(melody2, noteDurations2, length); // playing
                        }
                        NUMBER_ZONE = 0;
                        SMS_CALL_ZONE = 0;
                        SIREN_STOP();

                        BEEP_ACTION();
                        data1 = "Device activated!, by User : " + String(qqbbuser) + "\n";
                        if (CALL_STATUS == 0) {
                          data1 = data1 + SIM800L_CHEACK_TIME();
                        }
                        strcpy(SMS_OUT_DATAS[p].SMS_TEXT, data1.c_str());
                      }
                      else  if (data2 == -2) {
                        if (buzzer.getState() == BUZZER_IDLE) {
                          length = sizeof(noteDurations3) / sizeof(int);
                          buzzer.playMelody(melody3, noteDurations3, length); // playing
                        }
                        NUMBER_ZONE = 0;
                        SMS_CALL_ZONE = 0;
                        SIREN_STOP();
                        BEEP_ACTION();
                        data1 = "Device activated again!, by User : " + String(qqbbuser) + "\n";
                        if (CALL_STATUS == 0) {
                          data1 = data1 + SIM800L_CHEACK_TIME();
                        }
                        strcpy(SMS_OUT_DATAS[p].SMS_TEXT, data1.c_str());
                      }
                      else {
                        data1 = "Error!, Unspecified error, by User : " + String(qqbbuser) + "\n";
                        if (CALL_STATUS == 0) {
                          data1 = data1 + SIM800L_CHEACK_TIME();
                        }
                        strcpy(SMS_OUT_DATAS[p].SMS_TEXT, "Error!");
                      }
                      SMS_OUT_DATAS[p].ESP_TIME = SMS_IN_DATAS[k].ESP_TIME;
                      break;
                    }
                  }
                }
              }
            }
            else if (DATA_NUMBER_DCODE == 5) { // "nilinet off\r"
              data2 = TURN_OFF_DEVICE();
              for (int o = 0; o < 10; o++) {
                if (Phone_Number[o] != 0) {
                  for (int p = 0; p < 20; p++) {
                    if (SMS_OUT_DATAS[p].flag == 0) {
                      SMS_OUT_DATAS[p].flag = 1;
                      SMS_OUT_DATAS[p].SMS_PHONE = Phone_Number[o];
                      if (data2  == 1) {
                        if (buzzer.getState() == BUZZER_IDLE) {
                          length = sizeof(noteDurations2) / sizeof(int);
                          buzzer.playMelody(melody2, noteDurations2, length); // playing
                        }
                        NUMBER_ZONE = 0;
                        SMS_CALL_ZONE = 0;
                        SIREN_STOP();
                        BEEP_ACTION();
                        data1 = "Device deactivated!, by User : " + String(qqbbuser) + "\n";
                        if (CALL_STATUS == 0) {
                          data1 = data1 + SIM800L_CHEACK_TIME();
                        }
                        strcpy(SMS_OUT_DATAS[p].SMS_TEXT, data1.c_str());
                      }
                      else  if (data2 == -2) {

                        if (buzzer.getState() == BUZZER_IDLE) {
                          length = sizeof(noteDurations3) / sizeof(int);
                          buzzer.playMelody(melody3, noteDurations3, length); // playing
                        }
                        NUMBER_ZONE = 0;
                        SMS_CALL_ZONE = 0;
                        SIREN_STOP();
                        BEEP_ACTION();
                        data1 = "Device deactivated again!, by User : " + String(qqbbuser) + "\n";
                        if (CALL_STATUS == 0) {
                          data1 = data1 + SIM800L_CHEACK_TIME();
                        }
                        strcpy(SMS_OUT_DATAS[p].SMS_TEXT, data1.c_str());
                      }
                      else {
                        data1 = "Error!, Unspecified error, by User : " + String(qqbbuser) + "\n";
                        if (CALL_STATUS == 0) {
                          data1 = data1 + SIM800L_CHEACK_TIME();
                        }
                        strcpy(SMS_OUT_DATAS[p].SMS_TEXT, "Error!");
                      }
                      SMS_OUT_DATAS[p].ESP_TIME = SMS_IN_DATAS[k].ESP_TIME;
                      break;
                    }
                  }
                }
              }
            }

            else if (DATA_NUMBER_DCODE == 8) { // "nilinet siren on\r"



              data2 = TURN_ON_SIREN();
              for (int o = 0; o < 10; o++) {
                if (Phone_Number[o] != 0) {
                  for (int p = 0; p < 20; p++) {
                    if (SMS_OUT_DATAS[p].flag == 0) {
                      SMS_OUT_DATAS[p].flag = 1;
                      SMS_OUT_DATAS[p].SMS_PHONE = Phone_Number[o];
                      if (data2  == 1) {
                        SIREN_STOP();
                        BEEP_ACTION();
                        data1 = "Siren activated!, by User : " + String(qqbbuser) + "\n";
                        if (CALL_STATUS == 0) {
                          data1 = data1 + SIM800L_CHEACK_TIME();
                        }
                        strcpy(SMS_OUT_DATAS[p].SMS_TEXT, data1.c_str());
                      }
                      else  if (data2 == -2) {
                        SIREN_STOP();
                        BEEP_ACTION();
                        data1 = "Siren activated again!, by User : " + String(qqbbuser) + "\n";
                        if (CALL_STATUS == 0) {
                          data1 = data1 + SIM800L_CHEACK_TIME();
                        }
                        strcpy(SMS_OUT_DATAS[p].SMS_TEXT, data1.c_str());
                      }
                      else {
                        data1 = "Error!, Unspecified error, by User : " + String(qqbbuser) + "\n";
                        if (CALL_STATUS == 0) {
                          data1 = data1 + SIM800L_CHEACK_TIME();
                        }
                        strcpy(SMS_OUT_DATAS[p].SMS_TEXT, "Error!");
                      }
                      SMS_OUT_DATAS[p].ESP_TIME = SMS_IN_DATAS[k].ESP_TIME;
                      break;
                    }
                  }
                }
              }

            }
            else if (DATA_NUMBER_DCODE == 9) { // "nilinet siren off\r"



              data2 = TURN_OFF_SIREN();
              for (int o = 0; o < 10; o++) {
                if (Phone_Number[o] != 0) {
                  for (int p = 0; p < 20; p++) {
                    if (SMS_OUT_DATAS[p].flag == 0) {
                      SMS_OUT_DATAS[p].flag = 1;
                      SMS_OUT_DATAS[p].SMS_PHONE = Phone_Number[o];
                      if (data2  == 1) {
                        SIREN_STOP();
                        BEEP_ACTION();
                        data1 = "Siren deactivated!, by User : " + String(qqbbuser) + "\n";
                        if (CALL_STATUS == 0) {
                          data1 = data1 + SIM800L_CHEACK_TIME();
                        }
                        strcpy(SMS_OUT_DATAS[p].SMS_TEXT, data1.c_str());
                      }
                      else  if (data2 == -2) {
                        SIREN_STOP();
                        BEEP_ACTION();
                        data1 = "Siren deactivated again!, by User : " + String(qqbbuser) + "\n";
                        if (CALL_STATUS == 0) {
                          data1 = data1 + SIM800L_CHEACK_TIME();
                        }
                        strcpy(SMS_OUT_DATAS[p].SMS_TEXT, data1.c_str());
                      }
                      else {
                        data1 = "Error!, Unspecified error, by User : " + String(qqbbuser) + "\n";
                        if (CALL_STATUS == 0) {
                          data1 = data1 + SIM800L_CHEACK_TIME();
                        }
                        strcpy(SMS_OUT_DATAS[p].SMS_TEXT, "Error!");
                      }
                      SMS_OUT_DATAS[p].ESP_TIME = SMS_IN_DATAS[k].ESP_TIME;
                      break;
                    }
                  }
                }
              }


            }
            else if (DATA_NUMBER_DCODE == 10) { // "nilinet beep on\r"




              data2 = TURN_ON_BEEP();
              for (int o = 0; o < 10; o++) {
                if (Phone_Number[o] != 0) {
                  for (int p = 0; p < 20; p++) {
                    if (SMS_OUT_DATAS[p].flag == 0) {
                      SMS_OUT_DATAS[p].flag = 1;
                      SMS_OUT_DATAS[p].SMS_PHONE = Phone_Number[o];
                      if (data2  == 1) {
                        data1 = "Beep activated!, by User : " + String(qqbbuser) + "\n";
                        if (CALL_STATUS == 0) {
                          data1 = data1 + SIM800L_CHEACK_TIME();
                        }
                        strcpy(SMS_OUT_DATAS[p].SMS_TEXT, data1.c_str());
                      }
                      else  if (data2 == -2) {
                        data1 = "Beep activated again!, by User : " + String(qqbbuser) + "\n";
                        if (CALL_STATUS == 0) {
                          data1 = data1 + SIM800L_CHEACK_TIME();
                        }
                        strcpy(SMS_OUT_DATAS[p].SMS_TEXT, data1.c_str());
                      }
                      else {
                        data1 = "Error!, Unspecified error, by User : " + String(qqbbuser) + "\n";
                        if (CALL_STATUS == 0) {
                          data1 = data1 + SIM800L_CHEACK_TIME();
                        }
                        strcpy(SMS_OUT_DATAS[p].SMS_TEXT, "Error!");
                      }
                      SMS_OUT_DATAS[p].ESP_TIME = SMS_IN_DATAS[k].ESP_TIME;
                      break;
                    }
                  }
                }
              }




            }
            else if (DATA_NUMBER_DCODE == 11) { // "nilinet beep off\r"



              data2 = TURN_OFF_BEEP();
              for (int o = 0; o < 10; o++) {
                if (Phone_Number[o] != 0) {
                  for (int p = 0; p < 20; p++) {
                    if (SMS_OUT_DATAS[p].flag == 0) {
                      SMS_OUT_DATAS[p].flag = 1;
                      SMS_OUT_DATAS[p].SMS_PHONE = Phone_Number[o];
                      if (data2  == 1) {
                        data1 = "Beep deactivated!, by User : " + String(qqbbuser) + "\n";
                        if (CALL_STATUS == 0) {
                          data1 = data1 + SIM800L_CHEACK_TIME();
                        }
                        strcpy(SMS_OUT_DATAS[p].SMS_TEXT, data1.c_str());
                      }
                      else  if (data2 == -2) {
                        data1 = "Beep deactivated again!, by User : " + String(qqbbuser) + "\n";
                        if (CALL_STATUS == 0) {
                          data1 = data1 + SIM800L_CHEACK_TIME();
                        }
                        strcpy(SMS_OUT_DATAS[p].SMS_TEXT, data1.c_str());
                      }
                      else {
                        data1 = "Error!, Unspecified error, by User : " + String(qqbbuser) + "\n";
                        if (CALL_STATUS == 0) {
                          data1 = data1 + SIM800L_CHEACK_TIME();
                        }
                        strcpy(SMS_OUT_DATAS[p].SMS_TEXT, "Error!");
                      }
                      SMS_OUT_DATAS[p].ESP_TIME = SMS_IN_DATAS[k].ESP_TIME;
                      break;
                    }
                  }
                }
              }


            }

            else if (DATA_NUMBER_DCODE == 14) { // "nilinet siren 1\r"


              data2 = SET_TIME_SIREN(1);
              for (int o = 0; o < 10; o++) {
                if (Phone_Number[o] != 0) {
                  for (int p = 0; p < 20; p++) {
                    if (SMS_OUT_DATAS[p].flag == 0) {
                      SMS_OUT_DATAS[p].flag = 1;
                      SMS_OUT_DATAS[p].SMS_PHONE = Phone_Number[o];
                      if (data2  == 1) {
                        data1 = "One minute selected!, by User : " + String(qqbbuser) + "\n";
                        if (CALL_STATUS == 0) {
                          data1 = data1 + SIM800L_CHEACK_TIME();
                        }
                        strcpy(SMS_OUT_DATAS[p].SMS_TEXT, data1.c_str());
                      }
                      else  if (data2 == -2) {
                        data1 = "One minute selected again!, by User : " + String(qqbbuser) + "\n";
                        if (CALL_STATUS == 0) {
                          data1 = data1 + SIM800L_CHEACK_TIME();
                        }
                        strcpy(SMS_OUT_DATAS[p].SMS_TEXT, data1.c_str());
                      }
                      else {
                        data1 = "Error!, Unspecified error, by User : " + String(qqbbuser) + "\n";
                        if (CALL_STATUS == 0) {
                          data1 = data1 + SIM800L_CHEACK_TIME();
                        }
                        strcpy(SMS_OUT_DATAS[p].SMS_TEXT, "Error!");
                      }
                      SMS_OUT_DATAS[p].ESP_TIME = SMS_IN_DATAS[k].ESP_TIME;
                      break;
                    }
                  }
                }
              }

            }
            else if (DATA_NUMBER_DCODE == 15) { //  "nilinet siren 3\r"


              data2 = SET_TIME_SIREN(3);
              for (int o = 0; o < 10; o++) {
                if (Phone_Number[o] != 0) {
                  for (int p = 0; p < 20; p++) {
                    if (SMS_OUT_DATAS[p].flag == 0) {
                      SMS_OUT_DATAS[p].flag = 1;
                      SMS_OUT_DATAS[p].SMS_PHONE = Phone_Number[o];
                      if (data2  == 1) {
                        data1 = "Three minutes selected!, by User : " + String(qqbbuser) + "\n";
                        if (CALL_STATUS == 0) {
                          data1 = data1 + SIM800L_CHEACK_TIME();
                        }
                        strcpy(SMS_OUT_DATAS[p].SMS_TEXT, data1.c_str());
                      }
                      else  if (data2 == -2) {
                        data1 = "Three minutes selected again!, by User : " + String(qqbbuser) + "\n";
                        if (CALL_STATUS == 0) {
                          data1 = data1 + SIM800L_CHEACK_TIME();
                        }
                        strcpy(SMS_OUT_DATAS[p].SMS_TEXT, data1.c_str());
                      }
                      else {
                        data1 = "Error!, Unspecified error, by User : " + String(qqbbuser) + "\n";
                        if (CALL_STATUS == 0) {
                          data1 = data1 + SIM800L_CHEACK_TIME();
                        }
                        strcpy(SMS_OUT_DATAS[p].SMS_TEXT, "Error!");
                      }
                      SMS_OUT_DATAS[p].ESP_TIME = SMS_IN_DATAS[k].ESP_TIME;
                      break;
                    }
                  }
                }
              }


            }
            else if (DATA_NUMBER_DCODE == 16) { // "nilinet siren 5\r"

              data2 = SET_TIME_SIREN(5);
              for (int o = 0; o < 10; o++) {
                if (Phone_Number[o] != 0) {
                  for (int p = 0; p < 20; p++) {
                    if (SMS_OUT_DATAS[p].flag == 0) {
                      SMS_OUT_DATAS[p].flag = 1;
                      SMS_OUT_DATAS[p].SMS_PHONE = Phone_Number[o];
                      if (data2  == 1) {
                        data1 = "Five minutes selected!, by User : " + String(qqbbuser) + "\n";
                        if (CALL_STATUS == 0) {
                          data1 = data1 + SIM800L_CHEACK_TIME();
                        }
                        strcpy(SMS_OUT_DATAS[p].SMS_TEXT, data1.c_str());
                      }
                      else  if (data2 == -2) {
                        data1 = "Five minutes selected again!, by User : " + String(qqbbuser) + "\n";
                        if (CALL_STATUS == 0) {
                          data1 = data1 + SIM800L_CHEACK_TIME();
                        }
                        strcpy(SMS_OUT_DATAS[p].SMS_TEXT, data1.c_str());
                      }
                      else {
                        data1 = "Error!, Unspecified error, by User : " + String(qqbbuser) + "\n";
                        if (CALL_STATUS == 0) {
                          data1 = data1 + SIM800L_CHEACK_TIME();
                        }
                        strcpy(SMS_OUT_DATAS[p].SMS_TEXT, "Error!");
                      }
                      SMS_OUT_DATAS[p].ESP_TIME = SMS_IN_DATAS[k].ESP_TIME;
                      break;
                    }
                  }
                }
              }




            }
            else if (DATA_NUMBER_DCODE == 17) { // "nilinet siren 7\r"



              data2 = SET_TIME_SIREN(7);
              for (int o = 0; o < 10; o++) {
                if (Phone_Number[o] != 0) {
                  for (int p = 0; p < 20; p++) {
                    if (SMS_OUT_DATAS[p].flag == 0) {
                      SMS_OUT_DATAS[p].flag = 1;
                      SMS_OUT_DATAS[p].SMS_PHONE = Phone_Number[o];
                      if (data2  == 1) {
                        data1 = "Seven minutes selected!, by User : " + String(qqbbuser) + "\n";
                        if (CALL_STATUS == 0) {
                          data1 = data1 + SIM800L_CHEACK_TIME();
                        }
                        strcpy(SMS_OUT_DATAS[p].SMS_TEXT, data1.c_str());
                      }
                      else  if (data2 == -2) {
                        data1 = "Seven minutes selected again!, by User : " + String(qqbbuser) + "\n";
                        if (CALL_STATUS == 0) {
                          data1 = data1 + SIM800L_CHEACK_TIME();
                        }
                        strcpy(SMS_OUT_DATAS[p].SMS_TEXT, data1.c_str());
                      }
                      else {
                        data1 = "Error!, Unspecified error, by User : " + String(qqbbuser) + "\n";
                        if (CALL_STATUS == 0) {
                          data1 = data1 + SIM800L_CHEACK_TIME();
                        }
                        strcpy(SMS_OUT_DATAS[p].SMS_TEXT, "Error!");
                      }
                      SMS_OUT_DATAS[p].ESP_TIME = SMS_IN_DATAS[k].ESP_TIME;
                      break;
                    }
                  }
                }
              }


            }
            else if (DATA_NUMBER_DCODE == 18) { // "nilinet siren 10\r"



              data2 = SET_TIME_SIREN(10);
              for (int o = 0; o < 10; o++) {
                if (Phone_Number[o] != 0) {
                  for (int p = 0; p < 20; p++) {
                    if (SMS_OUT_DATAS[p].flag == 0) {
                      SMS_OUT_DATAS[p].flag = 1;
                      SMS_OUT_DATAS[p].SMS_PHONE = Phone_Number[o];
                      if (data2  == 1) {
                        data1 = "Ten minutes selected!, by User : " + String(qqbbuser) + "\n";
                        if (CALL_STATUS == 0) {
                          data1 = data1 + SIM800L_CHEACK_TIME();
                        }
                        strcpy(SMS_OUT_DATAS[p].SMS_TEXT, data1.c_str());
                      }
                      else  if (data2 == -2) {
                        data1 = "Ten minutes selected again!, by User : " + String(qqbbuser) + "\n";
                        if (CALL_STATUS == 0) {
                          data1 = data1 + SIM800L_CHEACK_TIME();
                        }
                        strcpy(SMS_OUT_DATAS[p].SMS_TEXT, data1.c_str());
                      }
                      else {
                        data1 = "Error!, Unspecified error, by User : " + String(qqbbuser) + "\n";
                        if (CALL_STATUS == 0) {
                          data1 = data1 + SIM800L_CHEACK_TIME();
                        }
                        strcpy(SMS_OUT_DATAS[p].SMS_TEXT, "Error!");
                      }
                      SMS_OUT_DATAS[p].ESP_TIME = SMS_IN_DATAS[k].ESP_TIME;
                      break;
                    }
                  }
                }
              }

            }
            else if (DATA_NUMBER_DCODE == 19) { // "nilinet siren 15\r"




              data2 = SET_TIME_SIREN(15);
              for (int o = 0; o < 10; o++) {
                if (Phone_Number[o] != 0) {
                  for (int p = 0; p < 20; p++) {
                    if (SMS_OUT_DATAS[p].flag == 0) {
                      SMS_OUT_DATAS[p].flag = 1;
                      SMS_OUT_DATAS[p].SMS_PHONE = Phone_Number[o];
                      if (data2  == 1) {
                        data1 = "Fifteen minutes selected!, by User : " + String(qqbbuser) + "\n";
                        if (CALL_STATUS == 0) {
                          data1 = data1 + SIM800L_CHEACK_TIME();
                        }
                        strcpy(SMS_OUT_DATAS[p].SMS_TEXT, data1.c_str());
                      }
                      else  if (data2 == -2) {
                        data1 = "Fifteen minutes selected again!, by User : " + String(qqbbuser) + "\n";
                        if (CALL_STATUS == 0) {
                          data1 = data1 + SIM800L_CHEACK_TIME();
                        }
                        strcpy(SMS_OUT_DATAS[p].SMS_TEXT, data1.c_str());
                      }
                      else {
                        data1 = "Error!, Unspecified error, by User : " + String(qqbbuser) + "\n";
                        if (CALL_STATUS == 0) {
                          data1 = data1 + SIM800L_CHEACK_TIME();
                        }
                        strcpy(SMS_OUT_DATAS[p].SMS_TEXT, "Error!");
                      }
                      SMS_OUT_DATAS[p].ESP_TIME = SMS_IN_DATAS[k].ESP_TIME;
                      break;
                    }
                  }
                }
              }


            }
            else if (DATA_NUMBER_DCODE >= 20 && DATA_NUMBER_DCODE <= 33 ) { // "nilinet zone  on\r"

              DATA_NUMBER_DCODE_ZONE  = DATA_NUMBER_DCODE - 19;




              data2 = TURN_ON_ZONE(DATA_NUMBER_DCODE_ZONE);
              for (int o = 0; o < 10; o++) {
                if (Phone_Number[o] != 0) {
                  for (int p = 0; p < 20; p++) {
                    if (SMS_OUT_DATAS[p].flag == 0) {
                      SMS_OUT_DATAS[p].flag = 1;
                      SMS_OUT_DATAS[p].SMS_PHONE = Phone_Number[o];
                      if (data2  == 1) {
                        data1 =  "Zone " +  String( DATA_NUMBER_DCODE_ZONE)  + " activated!, by User : " + String(qqbbuser) + "\n";
                        if (CALL_STATUS == 0) {
                          data1 = data1 + SIM800L_CHEACK_TIME();
                        }
                        strcpy(SMS_OUT_DATAS[p].SMS_TEXT, data1.c_str());
                      }
                      else  if (data2 == -2) {
                        data1 =  "Zone " +  String( DATA_NUMBER_DCODE_ZONE)  + " activated again!, by User : " + String(qqbbuser) + "\n";
                        if (CALL_STATUS == 0) {
                          data1 = data1 + SIM800L_CHEACK_TIME();
                        }
                        strcpy(SMS_OUT_DATAS[p].SMS_TEXT, data1.c_str());
                      }
                      else {
                        data1 = "Error!, Unspecified error, by User : " + String(qqbbuser) + "\n";
                        if (CALL_STATUS == 0) {
                          data1 = data1 + SIM800L_CHEACK_TIME();
                        }
                        strcpy(SMS_OUT_DATAS[p].SMS_TEXT, "Error!");
                      }
                      SMS_OUT_DATAS[p].ESP_TIME = SMS_IN_DATAS[k].ESP_TIME;
                      break;
                    }
                  }
                }
              }





            }
            else if (DATA_NUMBER_DCODE >= 34 && DATA_NUMBER_DCODE <= 47 ) { // "nilinet zone  off\r"

              DATA_NUMBER_DCODE_ZONE  = DATA_NUMBER_DCODE - 33;







              data2 = TURN_OFF_ZONE(DATA_NUMBER_DCODE_ZONE);
              for (int o = 0; o < 10; o++) {
                if (Phone_Number[o] != 0) {
                  for (int p = 0; p < 20; p++) {
                    if (SMS_OUT_DATAS[p].flag == 0) {
                      SMS_OUT_DATAS[p].flag = 1;
                      SMS_OUT_DATAS[p].SMS_PHONE = Phone_Number[o];
                      if (data2  == 1) {
                        data1 = "Zone " +  String( DATA_NUMBER_DCODE_ZONE)  + " deactivated!, by User : " + String(qqbbuser) + "\n";
                        if (CALL_STATUS == 0) {
                          data1 = data1 + SIM800L_CHEACK_TIME();
                        }
                        strcpy(SMS_OUT_DATAS[p].SMS_TEXT, data1.c_str());
                      }
                      else  if (data2 == -2) {
                        data1 =  "Zone " +  String( DATA_NUMBER_DCODE_ZONE)  + " deactivated again!, by User : " + String(qqbbuser) + "\n";
                        if (CALL_STATUS == 0) {
                          data1 = data1 + SIM800L_CHEACK_TIME();
                        }
                        strcpy(SMS_OUT_DATAS[p].SMS_TEXT, data1.c_str());
                      }
                      else {
                        data1 = "Error!, Unspecified error, by User : " + String(qqbbuser) + "\n";
                        if (CALL_STATUS == 0) {
                          data1 = data1 + SIM800L_CHEACK_TIME();
                        }
                        strcpy(SMS_OUT_DATAS[p].SMS_TEXT, "Error!");
                      }
                      SMS_OUT_DATAS[p].ESP_TIME = SMS_IN_DATAS[k].ESP_TIME;
                      break;
                    }
                  }
                }
              }




            }
            else {//

            }

            SMS_IN_DATAS[k].flag  = 0;

          }
        }
      }

    }











    int SIM800L_READY_CHECK() {
      busy = 1;
      int outdata = 0;
      int testdata = SIM800L_CHEACK_CREG();
      if (testdata == 2) {
        outdata = 2;
      }
      else if (testdata == 1) {
        if (SIM800L_CHEACK_CCALR() == 1 && (SIM800L_SEND("AT+CNMI=2,2,0,1,0\r\n", 500) == "OK\r") ) {
          outdata = 1;
        }
        else {
          outdata = 0;
        }

      }
      else {
        outdata = 0;
      }
      busy = 0;
      return outdata;
    }







    void SIM800L_ERORR_CHECK() {

      if (TIMER_S2 >= 5) {//5
        TIMER_S2 = 0;
        if (STATUS_ERROR >= 5 && SIM800L_READY < 6) {
          SIM800L_READY ++;
          TIMER_S1 = 1600;
          STATUS_ERROR = 0;
          if (STATUS_RESET_ERROR == 0) {
            //mySerial.println("error s reset");
            STATUS_RESET_ERROR = 1;
            SIM800L_SRESTART();
            //SIM800L_HRESTART();
          }
          else if (STATUS_RESET_ERROR == 1) {
            //mySerial.println("error s reset");
            STATUS_RESET_ERROR = 2;
            //SIM800L_SRESTART();
            TIMER_S6 = 0;
            SIM800L_HRESTART();
          }
          else {
            TIMER_S7 = 0;
            //mySerial.println("error h reset");
            //SIM800L_HRESTART();
            SIM800L_HPOWER();
          }
        }
        else {
          SecondsCount_s13();
        }
      }
    }













    void SIM800L_TIME_CHECK() {
      if (CALL_STATUS == 0) {
        if (TIMER_S1 >= TIMER_S9) { //1800 DEFALT
          TIMER_S1 = 0;
          TIMER_S6 = TIMER_S6 + 1;
          TIMER_S7 = TIMER_S7 + 1;
          if ( SIM800L_READY < 72) {
            if (SIM800L_READY_CHECK() == 0) {
              SIM800L_READY ++;
              STATUS_ERROR = 0;
              if (STATUS_RESET_TIME == 0) {
                //mySerial.println("loop s reset");
                STATUS_RESET_TIME = 1;
                SIM800L_SRESTART();
                //SIM800L_HRESTART();
                TIMER_S1 = 1200;//1200
                TIMER_S9 = 1800;
              }


              else if (STATUS_RESET_TIME == 1) {
                //mySerial.println("loop s reset");
                TIMER_S6 = 0;
                STATUS_RESET_TIME = 2;
                //SIM800L_SRESTART();
                SIM800L_HRESTART();
                TIMER_S1 = 1200;//1200
                TIMER_S9 = 1800;
              }


              else if (STATUS_RESET_TIME == 2 || STATUS_RESET_TIME == 3 || STATUS_RESET_TIME == 4 || STATUS_RESET_TIME == 5 || STATUS_RESET_TIME == 6 || STATUS_RESET_TIME == 7 || STATUS_RESET_TIME == 8) {
                //mySerial.println("loop h reset");
                TIMER_S7 = 0;
                STATUS_RESET_TIME = STATUS_RESET_TIME + 1;
                //SIM800L_HRESTART();
                SIM800L_HPOWER();
                TIMER_S1 = 0;//1200
                TIMER_S9 = 3600;
              }

              else {
                TIMER_S6 = 0;
                //STATUS_RESET_TIME = 2;
                //SIM800L_SRESTART();
                SIM800L_HRESTART();
                TIMER_S1 = 0;//1200
                TIMER_S9 = 3600;
              }
            }
            else {
              TIMER_S9 = 1800;
              STATUS_RESET_TIME = 0;
              STATUS_RESET_ERROR = 0;
              SIM800L_READY = 0;
              SecondsCount_s13();
            }
            if (TIMER_S6 >= 150) { //3 day
              TIMER_S6 = 0;
              STATUS_ERROR = 0;
              SIM800L_HRESTART();
            }

            if (TIMER_S7 >= 336) { //7 day
              TIMER_S7 = 0;
              STATUS_ERROR = 0;
              //SIM800L_HRESTART();
              SIM800L_HPOWER();
            }


            if ((millis() - timer_send_sms) > 300000) { //300 s
              defrint_send_derivery_sms = timer_send_sms - timer_derivery_sms;
              if (defrint_send_derivery_sms > 120000) { //120s
                TIMER_S8 = TIMER_S8 +  1;
              }
              else {
                TIMER_S8 = 0;
              }
            }
            if (TIMER_S8 >= 5) { //2h
              TIMER_S6 = 0;
              SIM800L_HRESTART();
            }
            if (TIMER_S8 >= 24) { //12h
              timer_send_sms = 0;
              timer_derivery_sms = 0;
              TIMER_S7 = 0;
              TIMER_S8 = 0;
              SIM800L_HPOWER();
            }
          }
        }
      }

    }





    String SIM800L_CHEACK_TIME_ONLINE() {
      unsigned long  starttime = millis();
      unsigned long  timer = 0;
      String StringReturn = "" ;
      String StringReturn1 = "" ;
      String StringReturn2 = "" ;
      String StringReturn3 = "" ;
      String StringReturn4 = "" ;
      String StringReturn5 = "" ;
      String StringReturn6 = "" ;

      int Day_SIM = 0;
      int Month_SIM = 0;
      int Year_SIM = 0;
      int Seconds_SIM = 0;
      int Minutes_SIM = 0;
      int Hour_SIM = 0;

      Serial.write("AT+CCLK?\r\n");
      while (1)  {
        if ( StringReturn == "ERROR\r") {
          STATUS_ERROR ++;
          StringReturn = "";
          break;
        }
        if ( StringReturn.indexOf("+CCLK: \"")  == 0 ) {

          StringReturn1 = StringReturn.substring(8, 10);
          StringReturn2 = StringReturn.substring(11, 13);
          StringReturn3 = StringReturn.substring(14, 16);
          StringReturn4 = StringReturn.substring(17, 19);
          StringReturn5 = StringReturn.substring(20, 22);
          StringReturn6 = StringReturn.substring(23, 25);

          Day_SIM = StringReturn3.toInt();
          Month_SIM = StringReturn2.toInt();
          Year_SIM = StringReturn1.toInt();
          Seconds_SIM = StringReturn6.toInt();
          Minutes_SIM = StringReturn5.toInt();
          Hour_SIM = StringReturn4.toInt();

          if(Day_SIM < 32 && Month_SIM <13 && Year_SIM <100 && Seconds_SIM < 61  && Minutes_SIM < 61   && Hour_SIM < 25){
          rtc.setTime(Seconds_SIM, Minutes_SIM, Hour_SIM, Day_SIM, Month_SIM, 2000 + Year_SIM);
          }

          break;
        }

        if (timer > starttime + 5000) {
          STATUS_ERROR ++;
          break;
        }
        timer = millis();
        if (Serial.available() > 0) {
          StringReturn = Serial.readStringUntil('\n');
        }
        delay(1);
      }
      return StringReturn;
    }






    void SecondsCount() {
      if (millis() > StartMilis + 1000) {
        StartMilis = millis();
        TIMER_S1 ++;
        TIMER_S2 ++;
        TIMER_S3 ++;
        TIMER_S4 ++;
        TIMER_S5 ++;
        TIMER_S10 ++;
        TIMER_S11++;
        TIMER_S13++;
      }
    }


    void SecondsCount_s12() {
      if (millis() > StartMilis_s12 + 1000) {
        StartMilis_s12 = millis();
        TIMER_S12++;
      }
    }

    void SecondsCount_s13() {
      if (TIMER_S13 >= 18000) {
        check_flag_call_bool = 0;
        for (int df = 0; df < 20; df++) {
          if (CALL_OUT_DATAS[df].flag == 1 ) {
            check_flag_call_bool = 1;
            break;
          }
          if (SMS_OUT_DATAS[df].flag == 1 ) {
            check_flag_call_bool = 1;
            break;
          }
        }

        if (busy == 0 && check_flag_call_bool == 0  &&  SIM800L_READY < 20) {
          SIM800L_CHEACK_TIME_ONLINE();
          TIMER_S13 = 0;
        }
        else {
          TIMER_S13 = 17940;
        }
      }
    }

    void CALL_LOOP() {
      if ( SIM800L_READY < 20) {
        if (TIMER_S12 >= 60) {  //eeeeeeeeeeeeeeeeeeee
          if (SMS_STATUS == 0) {
            if (TIMER_S5 >= 3) {
              call_status_timer = millis();
              if (CALL_STATUS == 0 ) {
                CALL_ANS_STATUS = 0;
                //CALL_Ring_STATUS = 0;
                for (int k = 0; k < 20; k++) {
                  if (TIMER_S12 >= 60) { //eeeeeeeeeeeeeeeeeee
                    if (CALL_OUT_DATAS[k].flag == 1 ) {
                      if (SIM800L_SEND("AT\r\n", 500) == "OK\r") {
                        delay (500);
                        if (SIM800L_SEND("AT+VTD=80\r\n", 500) == "OK\r") {
                          delay (500);
                          if (SIM800L_SEND("AT+CLCC=1\r\n", 500) == "OK\r") {
                            delay (500);
                            if (SIM800L_CHEACK_CCALR()) {
                              delay (1500);
                              char Buf[50];
                              String datastringcall = "";
                              if (CALL_OUT_DATAS[k].CALL_PHONE < 10) {
                                datastringcall = "ATD0900000000" +  String( CALL_OUT_DATAS[k].CALL_PHONE)  + ";\r\n";
                              }
                              else if (CALL_OUT_DATAS[k].CALL_PHONE < 100) {
                                datastringcall = "ATD090000000" +  String( CALL_OUT_DATAS[k].CALL_PHONE)  + ";\r\n";
                              }
                              else if (CALL_OUT_DATAS[k].CALL_PHONE < 1000) {
                                datastringcall = "ATD09000000" +  String( CALL_OUT_DATAS[k].CALL_PHONE)  + ";\r\n";
                              }
                              else if (CALL_OUT_DATAS[k].CALL_PHONE < 10000) {
                                datastringcall = "ATD0900000" +  String( CALL_OUT_DATAS[k].CALL_PHONE)  + ";\r\n";
                              }
                              else if (CALL_OUT_DATAS[k].CALL_PHONE < 100000) {
                                datastringcall = "ATD090000" +  String( CALL_OUT_DATAS[k].CALL_PHONE)  + ";\r\n";
                              }
                              else if (CALL_OUT_DATAS[k].CALL_PHONE < 1000000) {
                                datastringcall = "ATD09000" +  String( CALL_OUT_DATAS[k].CALL_PHONE)  + ";\r\n";
                              }
                              else if (CALL_OUT_DATAS[k].CALL_PHONE < 10000000) {
                                datastringcall = "ATD0900" +  String( CALL_OUT_DATAS[k].CALL_PHONE)  + ";\r\n";
                              }
                              else if (CALL_OUT_DATAS[k].CALL_PHONE < 100000000) {
                                datastringcall = "ATD090" +  String( CALL_OUT_DATAS[k].CALL_PHONE)  + ";\r\n";
                              }
                              else {
                                datastringcall = "ATD09" +  String( CALL_OUT_DATAS[k].CALL_PHONE)  + ";\r\n";
                              }
                              datastringcall.toCharArray(Buf, 50);
                              //mySerial.println("phone:");
                              //mySerial.println(Buf);
                              Serial.write(Buf);
                              call_rstart_time = millis();
                              CALL_STATUS = k + 1;
                              TIMER_S5 = 0;
                              break;
                            }
                            else {
                              CALL_STATUS = 0;
                              TIMER_S5 = 0;
                              break;
                            }
                          }
                          else {
                            CALL_STATUS = 0;
                            TIMER_S5 = 0;
                            break;
                          }
                        }
                        else {
                          CALL_STATUS = 0;
                          TIMER_S5 = 0;
                          break;
                        }
                      }
                      else {
                        CALL_STATUS = 0;
                        TIMER_S5 = 0;
                        break;
                      }
                    }
                  }
                }
              }

              if (CALL_STATUS >= 1 && CALL_ANS_STATUS == 0 && ( call_status_timer > call_rstart_time + 60000)) {
                CALL_STATUS = 0;
                TIMER_S5 = 0;
                //Serial.write("ATH\r\n");
                if (CALL_Ring_STATUS2 >= 5 ) {
                  // mySerial.println("sms call");
                  CALL_OUT_DATAS[CALL_STATUS - 1].flag = 0;
                  CALL_Ring_STATUS2 = 0;
                }
                else if (CALL_Ring_STATUS2 == 2) {
                  //mySerial.println("sms s reset");
                  CALL_Ring_STATUS2 ++;
                  SIM800L_SRESTART();
                  //SIM800L_HRESTART();
                }
                else if (CALL_Ring_STATUS2 == 3) {
                  //mySerial.println("sms h reset");
                  CALL_Ring_STATUS2 ++;
                  SIM800L_HRESTART();
                  //SIM800L_HPOWER();
                }
                else if (CALL_Ring_STATUS2 == 4) {
                  //mySerial.println("sms h reset");
                  CALL_Ring_STATUS2 ++;
                  //SIM800L_HRESTART();
                  SIM800L_HPOWER();
                }
                else {
                  CALL_Ring_STATUS2 ++;
                }

              }

              if (CALL_STATUS >= 1 && CALL_ANS_STATUS == 1 && ( call_status_timer > call_resp_timer + 20000)) {
                CALL_OUT_DATAS[CALL_STATUS - 1].flag = 0;
                TIMER_S5 = 0;
                CALL_ANS_STATUS = 0;
                CALL_STATUS = 0;
                Serial.write("ATH\r\n");
              }
              TIMER_S5 = 0;
            }
          }
          else {
            TIMER_S5 = 0;
          }
        }
      }
    }





    void SMS_LOOP() {
      if ( SIM800L_READY < 20) {
        if (TIMER_S12 >= 60) { //eeeeeeeeee

          if (CALL_STATUS == 0) {
            check_flag_call_booll = 0;
            for (int dff = 0; dff < 20; dff++) {
              if (CALL_OUT_DATAS[dff].flag == 1 ) {
                check_flag_call_booll = 1;
                break;
              }
            }
            
            if (check_flag_call_booll == 0) {

              if (TIMER_S4 >= 5) {
                TIMER_S4 = 0;
                for (int k = 0; k < 20; k++) {
                  if (SMS_OUT_DATAS[k].flag == 1 ) {
                    SMS_STATUS = k + 1;
                    char Buf1[50];
                    char Buf2[256];
                    String DataTextSMS = SMS_OUT_DATAS[k].SMS_TEXT;
                    DataTextSMS = DataTextSMS + "\r";


                    String DataNumberSMS = "";
                    timer_send_sms = millis();

                    if (SMS_OUT_DATAS[k].SMS_PHONE < 10) {
                      DataNumberSMS = "AT+CMGS=\"0900000000" + String (SMS_OUT_DATAS[k].SMS_PHONE) + "\"\r\n";
                    }
                    else if (SMS_OUT_DATAS[k].SMS_PHONE < 100) {
                      DataNumberSMS = "AT+CMGS=\"090000000" + String (SMS_OUT_DATAS[k].SMS_PHONE) + "\"\r\n";
                    }
                    else if (SMS_OUT_DATAS[k].SMS_PHONE < 1000) {
                      DataNumberSMS = "AT+CMGS=\"09000000" + String (SMS_OUT_DATAS[k].SMS_PHONE) + "\"\r\n";
                    }
                    else if (SMS_OUT_DATAS[k].SMS_PHONE < 10000) {
                      DataNumberSMS = "AT+CMGS=\"0900000" + String (SMS_OUT_DATAS[k].SMS_PHONE) + "\"\r\n";
                    }
                    else if (SMS_OUT_DATAS[k].SMS_PHONE < 100000) {
                      DataNumberSMS = "AT+CMGS=\"090000" + String (SMS_OUT_DATAS[k].SMS_PHONE) + "\"\r\n";
                    }
                    else if (SMS_OUT_DATAS[k].SMS_PHONE < 1000000) {
                      DataNumberSMS = "AT+CMGS=\"09000" + String (SMS_OUT_DATAS[k].SMS_PHONE) + "\"\r\n";
                    }
                    else if (SMS_OUT_DATAS[k].SMS_PHONE < 10000000) {
                      DataNumberSMS = "AT+CMGS=\"0900" + String (SMS_OUT_DATAS[k].SMS_PHONE) + "\"\r\n";
                    }
                    else if (SMS_OUT_DATAS[k].SMS_PHONE < 100000000) {
                      DataNumberSMS = "AT+CMGS=\"090" + String (SMS_OUT_DATAS[k].SMS_PHONE) + "\"\r\n";
                    }
                    else {
                      DataNumberSMS = "AT+CMGS=\"09" + String (SMS_OUT_DATAS[k].SMS_PHONE) + "\"\r\n";
                    }

                    //mySerial.println("phone per1 :");
                    //mySerial.println(SMS_OUT_DATAS[k].SMS_PHONE);


                    //mySerial.println("phone per2 :");
                    //mySerial.println(DataNumberSMS);

                    if (DataTextSMS.substring(0, 6) != "+CUSD:" ) {
                      if (SIM800L_CHEACK_CCALR()) {

                        delay(200);
                        if  (SIM800L_SEND("AT+CNMI=2,2,0,1,0\r\n", 1000) == "OK\r") {
                          delay(500);
                          if  (SIM800L_SEND("AT+CMGDA=\"DEL ALL\"\r\n", 2000) == "OK\r") {
                            delay(1000);
                            if (SIM800L_SEND("AT+CMGF=1\r\n", 500) == "OK\r") {
                              delay(200);
                              if (SIM800L_SEND("AT+CSCS=\"IRA\"\r\n", 500) == "OK\r") {
                                delay(200);
                                if (SIM800L_SEND("AT+CSMP=49,167,0,0\r\n", 500) == "OK\r") {
                                  delay(1000);
                                  DataNumberSMS.toCharArray(Buf1, 50);
                                  Serial.write(Buf1);
                                  //mySerial.println("phone:");
                                  //mySerial.println(Buf1);
                                  delay(2000);
                                  DataTextSMS.toCharArray(Buf2, 256);
                                  Serial.write(Buf2);
                                  //mySerial.println("text:");
                                  //mySerial.println(Buf2);
                                  delay(2000);
                                  if (SIM800L_1A(10000) == "OK\r") {
                                    timer_send_sms = millis();
                                    SMS_OUT_DATAS[k].flag = 0;
                                    SMS_STATUS2 = 0;
                                    SMS_STATUS = 0;
                                    break;
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                    else {
                      if (SIM800L_CHEACK_CCALR()) {

                        delay(200);
                        if  (SIM800L_SEND("AT+CNMI=2,2,0,1,0\r\n", 1000)  == "OK\r") {
                          delay(200);
                          if  (SIM800L_SEND("AT+CMGDA=\"DEL ALL\"\r\n", 2000) == "OK\r") {
                            delay(1000);
                            if (SIM800L_SEND("AT+CMGF=1\r\n", 500) == "OK\r") {
                              delay(200);
                              if (SIM800L_SEND("AT+CSCS=\"IRA\"\r\n", 500) == "OK\r") {
                                delay(200);
                                if (SIM800L_SEND("AT+CSMP=49,167,0,0\r\n", 500) == "OK\r") {
                                  delay(1000);
                                  DataNumberSMS.toCharArray(Buf1, 50);
                                  Serial.write(Buf1);
                                  //mySerial.println("phone:");
                                  //mySerial.println(Buf1);
                                  delay(2000);
                                  DataTextSMS.toCharArray(Buf2, 256);
                                  Serial.write(Buf2);
                                  //mySerial.println("text:");
                                  //mySerial.println(Buf2);
                                  delay(2000);
                                  if (SIM800L_1A(10000) == "OK\r") {
                                    timer_send_sms = millis();
                                    SMS_OUT_DATAS[k].flag = 0;
                                    SMS_STATUS2 = 0;
                                    SMS_STATUS = 0;
                                    break;
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }



                    if (SMS_STATUS2 >= 5 ) {
                      //mySerial.println("sms delet");
                      SMS_OUT_DATAS[SMS_STATUS - 1].flag = 0;
                      SMS_STATUS2 = 0;
                    }
                    else if (SMS_STATUS2 == 2) {
                      SMS_STATUS2 ++;
                      //mySerial.println("sms s reset");
                      SIM800L_SRESTART();
                      //SIM800L_HRESTART();
                    }
                    else if (SMS_STATUS2 == 3) {
                      SMS_STATUS2 ++;
                      //mySerial.println("sms h reset");
                      SIM800L_HRESTART();
                      //SIM800L_HPOWER();
                    }
                    else if (SMS_STATUS2 == 4) {
                      SMS_STATUS2 ++;
                      //mySerial.println("sms h reset");
                      //SIM800L_HRESTART();
                      SIM800L_HPOWER();
                    }
                    else {
                      SMS_STATUS2 ++;
                    }
                    SMS_STATUS = 0;
                    break;
                  }
                }
                TIMER_S4 = 0;
              }
            }
          }
        }
        else {
          TIMER_S4 = 0;
        }
      }
    }














    void setup() {

      //      Serial.begin(115200);
      //      mySerial.begin(115200);

      delay(3000);
      busy = 1;
      SIM800L_DEFALT() ;
      busy = 0;
      delay(2000);


      if (Turn_Time_Reset == 0) {
        for (int p = 0; p < 10; p++) {
          if (Phone_Number[p] != 0) {
            SMS_OUT_DATAS[p].flag = 1;
            SMS_OUT_DATAS[p].SMS_PHONE = Phone_Number[p];
            strcpy(SMS_OUT_DATAS[p].SMS_TEXT, "System restarted!\nIf not done by you, check the building and device!");
            SMS_OUT_DATAS[p].ESP_TIME = millis();
          }
        }




        for (int o = 0; o < 10; o++) {
          if (Phone_Number[o] != 0) {
            for (int p1 = 0; p1 < 20; p1++) {
              if (CALL_OUT_DATAS[p1].flag == 0) {
                CALL_OUT_DATAS[p1].flag = 1;
                CALL_OUT_DATAS[p1].CALL_NUMBER = 0;
                CALL_OUT_DATAS[p1].CALL_PHONE = Phone_Number[o];
                CALL_OUT_DATAS[p1].ESP_TIME = millis();
                break;
              }
            }
            for (int p2 = 19; p2 >= 0; p2--) {
              if (CALL_OUT_DATAS[p2].flag == 0) {
                CALL_OUT_DATAS[p2].flag = 1;
                CALL_OUT_DATAS[p2].CALL_NUMBER = 0;
                CALL_OUT_DATAS[p2].CALL_PHONE = Phone_Number[o];
                CALL_OUT_DATAS[p2].ESP_TIME = millis();
                break;
              }
            }
          }
        }
      }
      else {
        TIMER_S11 = 301;
        for (int p = 0; p < 10; p++) {
          if (Phone_Number[p] != 0) {
            SMS_OUT_DATAS[p].flag = 1;
            SMS_OUT_DATAS[p].SMS_PHONE = Phone_Number[p];
            strcpy(SMS_OUT_DATAS[p].SMS_TEXT, "System check, the device is online.");
            SMS_OUT_DATAS[p].ESP_TIME = millis();
          }
        }
      }
    }

    void RESET_TIME_LOOP() {
      if (Turn_Time_Reset == 1) {
        TIMER_S11 = 301;
        TURN_TIME_RESET_OFF() ;
      }
      if (TIMER_S10 > 604800  && TIMER_S10 < 608400 ) { //1800 -  1900
        if (CALL_STATUS == 0) {
          TURN_TIME_RESET_ON();
          RESTART();
        }
      }
      if (TIMER_S10 >= 608400) { //1900
        TURN_TIME_RESET_ON();
        RESTART();
      }
    }


    void loop() {
      SecondsCount_s12();
      SecondsCount();
      if (TIMER_S12 >= 60) {
        ////sim

        //RESET_TIME_LOOP();
        SIM800L_ERORR_CHECK();
        SIM800L_TIME_CHECK();
        SMS_DETECTION();
        SMS_DECODE();

        RESET_TIME_LOOP();

        SMS_LOOP();
        CALL_LOOP();
      }
    }

} sim_task;
