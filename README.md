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
- `imgs/arduino.png` — pinout Arduino UNO  

![Bedradingsschema](imgs/schema.png)

## Projectstructuur

