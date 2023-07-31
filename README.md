# Home-Security-System-Based-on-SIM800

Home security system based on SIM800 is a security system that uses a SIM card to send and receive text messages. It is designed to detect any unauthorized entry into a home and alert the homeowner via text message and call to their mobile phone. The system made up of a control panel (main board), sensors, and sirens. 

The sensors can be placed on doors, windows, and other areas around the home to detect any movement or disturbance. When the sensors are triggered, the control panel sends a few calls and text messages to the homeowner's phone, notifying them of the disturbance. This type of home alarm system is often preferred by those who want to be alerted of any security breaches immediately, even if they are not at home. 

Additionally, this type of system can be controlled remotely via text message, allowing the homeowner to turn the system on or off, and to check its status from anywhere at any time.

### This project has been tested more than 4000 hours...

<div align="center"><a href="#"><img src="Images/11.jpg"  width="1600"></a><br></div>
<div align="center"><a href="#"><img src="Images/FGFHH.jpg"  width="1600"></a><br></div>

<br/>

## Features

-  ZONE:
    -  4 wired zones
    -  10 wireless zones for connecting wireless sensors

-  Remote controller:
    -  Learning 10 remote controllers
      
-  Caller memory:
    -  10 mobile phone number storage memory
      
-  Battery charger:
    -  internal charging and battery protection circuit

 -  Internal siren circuit:
    -  45 watt internal siren circuit

 -  External antenna socket:
    -  SMA socket to connect the SIM800 antenna

 -  IOT:
    -  Internet connection via Wi-Fi

 -  SMS:
    -  Control(on, off, settings) via SMS
      
<br/>
<div align="center"><a href="#"><img src="Images/3.jpg"  width="1600"></a><br></div>

## Instruction


### SMS Instruction

|    Description   | Instruction |
| ----------- | ----------- |
| Save and status mobile number      | In        |
| Delete mobile number     | In        |
| Activate the device      | In        |
| Disable the device      | In        |
| Activate the alarm      | In        |
| Disable the alarm    | In        |
| Activate  the notification beep     | In        |
| Disable the notification beep     | In        |
| Enable zones      | In        |
| Disable zones  | In         |
| Alarm time   | In         |
| Send USSD code | In     |
| Set the device time | In     |
| Status of the device | In     |
| Status of zones | In     |
| Reset the device | In     |

### SMS Instruction

|    Description   | Instruction |
| ----------- | ----------- |
| Save mobile number      |<Unique code; mobile number> for example :  ```RIJ111111111111111;09191111111```        |
| status mobile number      |<Unique code> for example :  ```RIJ111111111111111```        |
| Delete mobile number     | <Special code; mobile number saved> for example :  ```RIJ111111111111111;09191111111```         |
| Activate the device      |  ```RIJ ON```        |
| Disable the device      |  ```RIJ OFF```        |
| Activate the alarm      | ```RIJ SIREN ON```        |
| Disable the alarm    | ```RIJ SIREN OFF```        |
| Activate  the notification beep     | ```RIJ BEEP ON```        |
| Disable the notification beep     | ```RIJ BEEP OFF```        |
| Enable zones      | <RIJ ZONE "Number" ON> for example :  ```RIJ ZONE 1 ON```        |
| Disable zones  | <RIJ ZONE "Number" OFF> for example :  ```RIJ ZONE 1 OFF```        |
| Alarm time   | <RIJ SIREN "Minutes"> for example :  ```RIJ SIREN 15```         |
| Send USSD code | <RIJ UCODE:"Code"> for example :  ```RIJ UCODE:*11111*11111#```     |
| Set the device time | <RIJ SET TIME: "Time"+18> for example :  ```RIJ SET TIME:22/05/09,23:59:59+18```     |
| Status of the device | <Special code; mobile number> for example :  ```RIJ111111111111111;09191111111```     |
| Status of zones | <Special code; mobile number> for example :  ```RIJ111111111111111;09191111111```     |
| Reset the device | <Special code; mobile number> for example :  ```RIJ111111111111111;09191111111```     |

### For detailed information ```Src/main.cpp```

## License
[MIT License](LICENSE)

Free Hardware!
