/* mbed Microcontroller Library
 * Copyright (c) 2022 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "Bitcoin.h"
#include "Hash.h"
#include "Conversion.h"
#include <stdint.h>
#include <mbed.h>
#include "platform/mbed_thread.h"

void demo_hash_function(){
	String message = "Hello world!"; // message to hash
	unsigned char hash[64] = { 0 }; // hash
	int hashLen = 0;
	printf(message.c_str());
	printf("\n\r");
	printf("Should be: c0535e4be2b79ffd93291305436bf889314e4a3faec05ecffcbb7df31ad9e51a\n\r");
	printf("SHA-256:   ");
	// sha-256
	hashLen = sha256(message, hash);
	String result = toHex(hash, hashLen); //转为16进制字符串
	printf(result.c_str());
	printf("\n\r");
}

void demo_seed_to_phrase(){
	// Generate a recovery phrase from entropy
	// Fundamentally it is just a convenient way of representing some random number in a human-readable form. It contains a checksum and uses a fixed dictionary so if you make a mistake while typing it the wallet will spot it. Then this recovery phrase together with the password can be converted to a 64-byte seed used for key derivation in [BIP-32]
	// These recovery phrases became standards in the industry and almost every wallet uses them. We will stick to the standard ([BIP-39]
	String entropy = "h3iq7fqj3f7yowu3849uqomfiq3984"; //示例种子
	printf(entropy.c_str());
	printf("\n\r");
	// generating 12 words (first parameter, 24 by default)
	String phrase = generateMnemonic(12, entropy); // 将种子变成12个助记词
	printf("Generate a recovery phrase from entropy:\n\r");
	printf(phrase.c_str());
	printf("\n\r");
}

void demo_mnemonic_to_key(){
	// Derive root key from mnemonic and password
	// derive master private key from the recovery seed
	String mnemonic = "arch volcano urge cradle turn labor skin secret squeeze denial jacket vintage fix glad lemon";
	String password = "my secret password";
	HDPrivateKey hd(mnemonic, password); // 根据助记词和默认密码生成私钥
	printf("Mnemonic: %s \n\r", mnemonic.c_str());
	printf("Password: %s \n\r", password.c_str());
	printf("Root private key: %s \n\r", hd.xprv().c_str());
}

void demo_key_to_address(){
	// generate first 5 receiving addresses from public keys
	HDPublicKey hd("vpub5Yrg2UmoGPvDxBavP5BUmdByVpZMxnKf2EcaMRXNVNBxQMLwjK4BbfdPS5qotmByvnmUtPVAUMsfsP9RJrmRDWk6t3uP285Lq5iFsrfkoKu");
	// deriving first 5 public keys and printing their addresses
	HDPublicKey pub;
	printf("public key: %s \n\r", hd.xpub().c_str());
	printf("first receiving 5 addresses:\n\r");
	for(int i=0; i<5; i++){
		// deriving in a different manner
		printf("child %d:", i+1);
		pub = hd.child(0).child(i); //通过公钥生成地址
		printf(pub.address().c_str());
		printf("\n\r");
	}
}

void beep(){
    PwmOut wave(D6);
    wave = 1;
    thread_sleep_for(300);
    wave = 0;
    thread_sleep_for(300);
    wave = 1;
    thread_sleep_for(300);
    wave = 0;
    thread_sleep_for(600);
}

DigitalIn switch_white(D5);
DigitalIn switch_red(D4);
DigitalOut led_white(D10);
DigitalOut led_red(D11);

int main()
{
    printf("Hello, Mbed!\n\r");
	int choice = 0;
	int choice_old = 0;
	while(1){
		if (switch_white == 1) {
			led_white = 1;
		} else {
			led_white = 0;
		}
		if (switch_red == 1) {
			led_red = 1;
		} else {
			led_red = 0;
		}
		choice = switch_red*2+switch_white; // 开关二进制转数字
		if (choice != choice_old) {
			printf("=================================\n\r");
			beep();
			switch (choice) {
			case 0:
				printf("Demo Bitcoin hash Operation on wallet\n\r");
				demo_hash_function();
				break;
			case 1:
				printf("Demo Bitcoin derive phase from seed on wallet\n\r");
				demo_seed_to_phrase();
				break;
			case 2:
				printf("Demo Bitcoin derive private key from mnemonic on wallet\n\r");
				demo_mnemonic_to_key();
				break;
			case 3:
				printf("Demo Bitcoin derive 5 addresses from public key on wallet\n\r");
				demo_key_to_address();
				break;
			default:
				break;
			}	
			choice_old = choice;
			printf("\n\r");
		}
		thread_sleep_for(1000);
	}
	return 0;
}