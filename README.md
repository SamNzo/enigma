# Enigma
C++ implementation of enigma cryptography machine

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

# Usage
The simplest way to use it is:

```
./enigma --message <your message>
```

If no information is provided about the rotors, reflector and plugboard the default configuration is

|  Reflector  |      Left rotor      |  Middle rotor |  Right rotor |
|:-----------:|:--------------------:|:-------------:|:------------:|
|      B      |         I AA         |     II A A    |    III A A   |

You can customize it by choosing up to 4 rotors, 1 reflector and 1 plugboard. 

For each rotor you can chose a wiring, ring setting and starting position:

```
./enigma --left-rotor I A A --middle-rotor II A A --right-rotor III A A --reflector B --message <your message>
```

To know which rotors wiring are available: ``./enigma -h rotor``

To know which reflectors wiring are available: ``./enigma -h reflector``

For more information: ``./enigma -h``

If you want to use a specific machine (Wehrmacht, Kriegsmarine):

```
./enigma --wehrmacht --message <your message>
```

For more information about available machines: ``./enigma -h machines``

## Example
To encode the message ``ENIGMA`` using 3 rotors (II, V, VIII) with respective ring settings WAR, starting positions SUN and plugboard A-F, D-G, R-M:

```
./enigma --left-rotor II W S --middle-rotor V A U --right-rotor VIII R N --plugboard AF DG RM --message ENIGMA
```


# Machine overview

# Ressources 📚
These ressource are helpful to understand how the machine works.

I recommend watching these Numberphile videos in which they explain how the machine works, how it was used during the war and decrypted:

https://www.youtube.com/watch?v=G2_Q9FoD-oQ

https://www.youtube.com/watch?v=d2NWPG2gB_A

https://www.youtube.com/watch?v=kj_7Jc1mS9k

Another great video with a 3D machine for visualization:

https://www.youtube.com/watch?v=ybkkiGtJmkM

If you'd rather read:

https://www.cryptomuseum.com/crypto/enigma/working.htm

https://fr.wikipedia.org/wiki/Enigma_(machine)

Rotors internal wiring, notches, etc. are described here:

https://en.wikipedia.org/wiki/Enigma_rotor_details

If you want to play with a virtual Enigma machine:

https://enigma.virtualcolossus.co.uk/VirtualEnigma/

If you'd rather play by hand, Mike Koss made this great paper simulator:

https://mckoss.com/posts/paper-enigma/

