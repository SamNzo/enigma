# Enigma
C++ implementation of Enigma.

The Enigma machine is a cipher device developed and used in the early- to mid-20th century. It was employed extensively by Nazi Germany during World War II, in all branches of the German military.

```
                     __                                   
                    |  \                                  
  ______   _______   \$$  ______   ______ ____    ______  
 /      \ |       \ |  \ /      \ |      \    \  |      \ 
|  $$$$$$\| $$$$$$$\| $$|  $$$$$$\| $$$$$$\$$$$\  \$$$$$$\
| $$    $$| $$  | $$| $$| $$  | $$| $$ | $$ | $$ /      $$
| $$$$$$$$| $$  | $$| $$| $$__| $$| $$ | $$ | $$|  $$$$$$$
 \$$     \| $$  | $$| $$ \$$    $$| $$ | $$ | $$ \$$    $$
  \$$$$$$$ \$$   \$$ \$$ _\$$$$$$$ \$$  \$$  \$$  \$$$$$$$
                        |  \__| $$                        
                         \$$    $$                        
                          \$$$$$$                         
```

# Installation

Clone repository:
```
git clone https://github.com/SamNzo/enigma.git
```

Build enigma:
```
cd enigma
chmod +x make.sh
./make.sh
```

The enigma binary is then in the ``build`` directory.

# Usage
The simplest way to use it is:

```
./enigma --message <your message>
```

If no information is provided about the rotors, reflector and plugboard the default configuration is:

|  Reflector  |      Left rotor      |  Middle rotor |  Right rotor |
|:-----------:|:--------------------:|:-------------:|:------------:|
|      B      |         I AA         |     II A A    |    III A A   |

You can customize it by choosing up to 4 rotors, 1 reflector and 1 plugboard. 

For each rotor you can choose a wiring, ring setting and starting position:

```
./enigma --left-rotor I A A --middle-rotor II A A --right-rotor III A A --reflector B --message <your message>
```

To know which rotors wiring are available: ``./enigma -h rotor``

To know which reflectors wiring are available: ``./enigma -h reflector``

To get more information about the plugboard: ``./enigma -h plugboard``

For more information: ``./enigma -h``

## Example
To encode the message ``ENIGMA`` using 3 rotors (II, V, VIII) with respective ring settings WAR, starting positions SUN and plugboard A-F, D-G, R-M:

```
./enigma --left-rotor II W S --middle-rotor V A U --right-rotor VIII R N --plugboard AF DG RM --message ENIGMA
```

**Note:** since Enigma is self-reciprocal, to decode the message simply use the configuration used to encode it on the ciphered message

# Machine overview
The Enigma machine, used extensively during World War II, was a remarkable encryption device. It consisted of a keyboard, a set of rotating wheels called rotors, a reflector, and a display panel. When a letter was pressed on the keyboard, an electrical signal passed through the rotors, which had intricate internal wiring. Each rotor had a different wiring configuration, causing the input signal to be scrambled in a complex manner. The rotors rotated with each key press, altering the wiring connections and ensuring that a letter was not always encoded by the same character. After passing through the rotors, the signal was reflected back through the wiring, further scrambling the message. The encrypted letter was then displayed on the panel. 

<p align="center">
  <img src="https://github.com/SamNzo/enigma/blob/main/img/enigma.jpg?raw=true" width=280 height=280>
</p>

To decrypt the message, the receiver had to know the exact settings used by the sender, including the initial rotor positions and wiring configurations. The Enigma machine's encryption was considered highly secure at the time, but it was eventually cracked by codebreakers, notably mathematician Alan Turing, leading to a crucial breakthrough in cryptography. 

# Ressources
These ressources are helpful to understand how the machine works.

I recommend watching these Numberphile videos in which they explain how the machine works, how it was used during the war and cracked:

https://www.youtube.com/watch?v=G2_Q9FoD-oQ

https://www.youtube.com/watch?v=d2NWPG2gB_A

https://www.youtube.com/watch?v=kj_7Jc1mS9k

Another great video with a 3D machine for visualization:

https://www.youtube.com/watch?v=ybkkiGtJmkM

If you'd rather read:

https://www.cryptomuseum.com/crypto/enigma/working.htm

https://en.wikipedia.org/wiki/Enigma_machine

Rotors internal wiring, notches, etc. are described here:

https://en.wikipedia.org/wiki/Enigma_rotor_details

If you want to play with a virtual Enigma machine:

https://enigma.virtualcolossus.co.uk/VirtualEnigma/

If you'd rather play by hand, Mike Koss made this great paper simulator:

https://mckoss.com/posts/paper-enigma/

