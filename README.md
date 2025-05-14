# Loops

Een interactieve, bewegingsgestuurde vlieggame met een Arduino UNO en een MPU6050, gecombineerd met een Processing-sketch voor de gameplay en real‐time LED-feedback via een custom controller-behuizing.

## Inhoud

- [Introductie](#introductie)
- [Doel](#doel)
- [Materialen](#materialen)
- [Bedrading](#bedrading)
- [Projectstructuur](#projectstructuur)
- [Installatie & Bibliotheken](#installatie--bibliotheken)
- [Gebruik](#gebruik)  
  - [Bewegingsinput](#bewegingsinput)  
  - [Seriële communicatie](#seriële-communicatie)  
  - [LED- en knop-feedback](#led--en-knop-feedback)  
- [Controller-behuizing](#controller-behuizing)
- [Verbeteringen](#verbeteringen)
- [Conclusie](#conclusie)
- [Licentie](#licentie)

## Introductie

Dit project maakt gebruik van een MPU6050 motion sensor op een Arduino UNO om hellingshoek en beweging van een handcontroller te meten. De verkregen data stuurt de Arduino via de seriële poort naar een Processing-sketch, waarin een vliegtuig in een 3D-wereld bestuurd wordt.

Afhankelijk van acties in de game én van streaks (3 events binnen een bepaald tijdsvenster) licht de Arduino rode of blauwe LEDs op als visuele feedback.

## Doel

- De MPU6050 gebruiken om beweging en oriëntatie van een controller te meten en deze in te zetten als besturing voor een vliegsimulator.
- In-game events (door ringen vliegen, targets raken) naar de Arduino sturen om LEDs te bedienen:  
  - **Rode LED** knippert bij een ringpassage of ring-streak.  
  - **Blauwe LED** knippert bij een target-hit of target-streak.  
- Een triggerknop op de handgreep gebruiken voor schieten.  
- Een startknop gebruiken om het spel te starten.

## Materialen

- Arduino UNO  
- MPU6050 (gyroscoop + accelerometer module)  
- Rode LED + 220 Ω weerstand  
- Blauwe LED + 150 Ω weerstand  
- Drukknop (Shoot) + interne pull-up  
- Drukknop (Start) + interne pull-up  
- 3D-geprinte controller-behuizing met handgreep en trigger-slot  
- Optioneel breadboard en bedrading  
- USB-kabel

## Bedrading

De schema’s staan in de map `imgs`:

- `imgs/schema.png` — basisbekabeling:  
  - I2C: **A4 (SDA)** → MPU6050 SDA, **A5 (SCL)** → MPU6050 SCL  
  - **8** → Rode LED via 220 Ω → GND  
  - **10** → Blauwe LED via 150 Ω → GND  
  - **7** → SHOOT-knop → GND (INPUT_PULLUP)  
  - **1** → START-knop → GND (INPUT_PULLUP)  
- `imgs/geschakeld_schema.jpg` — gedetailleerde schakeling  


## Installatie & Bibliotheken

1. **Arduino IDE**: installeer via de Library Manager:  
   - `Wire`  
   - `I2Cdev`  
   - `MPU6050`  
2. **Processing**: gebruik de standaard `processing.serial` library.  
3. Clone deze repository en open:  
   - `src/arduino/Loops.ino` in de Arduino IDE.  
   - `src/processing/LoopsGame.pde` in Processing.

## Gebruik

### Bewegingsinput

- De Arduino leest elke 10 ms gyro- en accelerometerdata van de MPU6050.  
- Pitch en roll worden gecombineerd via een complementair filter (α = 0.98) voor stabiele besturing.  
- De berekende hoeken (in graden) worden verzonden naar Processing als `pitch,roll`.

### Seriële communicatie

- **Arduino → Processing**:
  ```cpp
  Serial.print(pitch, 2);
  Serial.print(",");
  Serial.println(roll, 2);

## LED- en knop-feedback

- In de Arduino-`loop()` worden inkomende commando’s gelezen:  
  - **Ring-event** (`R,n`) → `handleEvent(redLedPin, …)`  
  - **Target-event** (`T,n`) → `handleEvent(blueLedPin, …)`  
- `handleEvent()` verzorgt:  
  - Een korte LED-flash (300 ms)  
  - Tellen van events voor streaks (3 events binnen 5000 ms)  
  - Bij een streak een extra snelle flash-sequentie  
- De shoot- en startknoppen zijn geconfigureerd als `INPUT_PULLUP`;  
  bij indrukken wordt respectievelijk `SHOOT` of `START` verzonden.

## Controller-behuizing

- De behuizing is 3D-geprint en huisvest Arduino, MPU6050, LEDs en knoppen.  
- De triggerknop voor schieten zit ergonomisch in de handgreep verwerkt.  
- Alle bedrading en componenten zijn netjes weggewerkt, met toegang tot de USB-poort.

## Verbeteringen
 
- Extra knoppen voor menu en instellingen  
- Geluidsfeedback via een buzzer  
- Draadloze verbinding (Bluetooth of Wi-Fi)

## Conclusie

Loops combineert real-time sensorinput met een Processing-game voor een meeslepende vliegervaring. De geïntegreerde LED- en knop-feedback in een custom controller maken het geheel interactief en spannend.

## Licentie

Dit project is gelicentieerd onder de Apache License 2.0 – zie het `LICENSE` bestand voor details.  


- `imgs/arduino.png` — pinout Arduino UNO  

![Bedradingsschema](imgs/schema.png)

## Projectstructuur

