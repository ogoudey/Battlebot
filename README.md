# Battlebot
This is a robot built for Tufts Robotics Club's fall Battlebots competition (it won!).

Its name's Jake.

## Building
Some under-specific directions for building this robot follow.

### The Model
Here is the model used to print it.
![Title](image.png)

### Printing
Print all of the (about 20 parts).

### Hardware
No complete list of specific hardware here. But they must be ordered.

### Assembly
Here a rough diagram suggesting one general way to assemble the parts. Most required screws are the same type.
```mermaid

graph TD
    A{Frames};
    A1[Frame Right];
    A2[Frame Left];
    A3[Frame Front];
    A4[Frame Back];

    B{Vertical Components};
    B1[Vertical Back-right];
    B2[Vertical Back-left];
    B3[Vertical Front-right];
    B4[Vertical Front-left];
    B5[Vertical Front-center];

    C{Attic};
    C1[Attic];
    C2[Attic Front];

    D1[Upper Chassis];
    D2[Lower Chassis];

    E{Wheel and Motor Assembly};
    E1[Wheel Motor Holder Right];
    E2[Wheel Motor Holder Left];
    E3[Free Wheel Right];
    E4[Free Wheel Left];

    F{Wheel Hub Components};
    F1[Free Wheel Hub];
    F2[Free Wheel Hub];
    F3[Wheel Hub];
    F4[Wheel Hub];

    %% Frames
    A --> A1;
    A --> A2;
    A --> A3;
    A --> A4;

    %% Vertical Components
    B --> B1;
    B --> B2;
    B --> B3;
    B --> B4;
    B --> B5;

    %% Attic Assembly
    C --> C1;
    C --> C2;

    %% Wheel and Motor Assembly
    E --> E1;
    E --> E2;
    E --> E3;
    E --> E4;

    %% Wheel Hub Components
    F --> F1;
    F --> F2;
    F --> F3;
    F --> F4;

    B --> A;

    B --> C;

    B --> D1;


    A --> E;
    E --> F;
    A --> D2;

```
Make sure everything is wired up correctly. (Circuit diagram coming soon...)

### Code
All code is in [.ino](code). Upload this code the Arduino.

### Running
If the above extremely vague and incomplete instructions have somehow been followed, turn the transmitter on, turn safety switch off, and you're off!
