# bitcoin-wallet
simple bitcoin wallet demo based on STM32/mbed

This project introduces the main functions of a Bitcoin HD wallet on STM32 based on uBitcoin. HD wallet is a tool for managing private keys, mainly including generating and storing private keys and addresses. This project implements the operations of hash algorithm, derive phase from seed, derive private key from mnemonic and derive 5 addresses from public key on mbed. At the same time, this project also shows how to use mbed to connect the windows 10 operating system to realize the serial output of computer screen printing, and use the buttons, buzzer and LED lights to demonstrate different HD wallet core functions.

# Installation
## serial connection on windows 10
To realize the serial output of computer screen printing on windows 10 operating system, Python, Cmake, Ninja, and GNU Arm Embedded Version 9 are downloaded and installed on the computer. One of the simplest programs (by connecting mbed to the computer, and printing “hello world” on the computer after running) was used to debug to prove that the serial port output has been successful.

## install uBitcoin
Download library from [uBitcoin] (https://github.com/micro-bitcoin/uBitcoin)

# Implementation
It was about the code part, including the function of the hash algorithm, the function of a series of operations such as private key conversion, and the function of the buzzer. After the "Bitcoin.h", "Hash.h", "Conversion.h", <stdint.h> were included in the main program, some functions to run them were also completed. In running the hash function, a normal text (hello world) was converted to a hexadecimal string by the sha256 and toHex functions. The example seed was then converted into 12 mnemonic words by the generateMnemonic function. Afterwards, the mnemonic and default password were generated to the private key by the HDPrivateKey hd function. The public key was then converted to a bitcoin address using the hd function. Finally, the buzzer was defined by the PwmOut function.
Next, connect the elements to the mbed pin.

# Result
For result, this project implements HD wallet’s function including the operations of hash algorithm, derive phase from seed, derive private key from mnemonic and derive 5 addresses from public key on mbed. Each time a function is run, the buzzer will sound to indicate completion, and the corresponding LED will light up when the button is pressed at the same time.

## derive phase from seed
![image](https://user-images.githubusercontent.com/109030200/178688825-05cc7556-10e3-4409-9627-cbcd733db371.png)
![image](https://user-images.githubusercontent.com/109030200/178688861-85d8c122-2106-4f87-9a5f-420ebeb48093.png)

## derive 5 addresses from public key
![image](https://user-images.githubusercontent.com/109030200/178689001-7561a929-3431-41a1-83fe-ea3a469746d7.png)
![image](https://user-images.githubusercontent.com/109030200/178689018-ef01dc8d-4157-4ac7-90fa-eca25f9a85a1.png)

## derive private key from mnemonic
![image](https://user-images.githubusercontent.com/109030200/178689122-513527fa-8d01-4ed1-b51b-5e54e2985e2d.png)
![image](https://user-images.githubusercontent.com/109030200/178689140-b22b87af-8d44-424e-a35d-747a75ecd40c.png)

## operations of hash algorithm
![image](https://user-images.githubusercontent.com/109030200/178689251-317c0bdb-0cbf-4b66-8477-ac2dcecfd3fa.png)
![image](https://user-images.githubusercontent.com/109030200/178689290-1b742b20-ab9a-4557-86c1-d60743dc5cba.png)

