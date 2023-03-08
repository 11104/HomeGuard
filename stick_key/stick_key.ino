#include <Arduino.h>
#include "M5StickCPlus.h"
#include <WiFiClientSecure.h>
/*
When this code write to M5Stick, remove GND pin from M5Stick.
Then Err won't occurred
*/
const char* ssid     = "";//<-wifi ssid
const char* password = "";//<- wifi password
const char* host     = "notify-api.line.me";
const char* token    = "";//<- LineNotice Token

#define LED_PIN 10
#define DOOR_PIN 26
#define KEY_PIN 0
#define KEY_TIME 3

boolean line_notify(String msg) {
  WiFiClientSecure client;
  client.setInsecure();
  if(!client.connect(host, 443)) {
    Serial.println("connect error!");
    return false;
  }
  String query = String("message=") + msg;
  String request = String("")
              + "POST /api/notify HTTP/1.1\r\n"
              + "Host: " + host + "\r\n"
              + "Authorization: Bearer " + token + "\r\n"
              + "Content-Length: " + String(query.length()) +  "\r\n"
              + "Content-Type: application/x-www-form-urlencoded\r\n\r\n"
              + query + "\r\n";
  client.print(request);
  return true;
}

void setup() {
    M5.begin();
    M5.Lcd.setRotation(3);
    pinMode(DOOR_PIN, INPUT_PULLUP);
    pinMode(KEY_PIN, INPUT_PULLUP);
    pinMode(LED_PIN,OUTPUT);
    M5.Lcd.fillScreen(BLACK);
    //wifi
    M5.Lcd.printf("WIFI START:%s ", ssid);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        M5.Lcd.print(".");
    }
    M5.Lcd.println(" - READY");
}

void loop(){
    M5.update();
    if(digitalRead(KEY_PIN)==1){
        digitalWrite(LED_PIN, HIGH);
        M5.Lcd.fillScreen(GREEN);
        M5.Lcd.setCursor(10,40);
        M5.Lcd.setTextColor(BLACK);
        M5.Lcd.setTextSize(5);
        M5.Lcd.print("Unlock");
    }else{
        digitalWrite(LED_PIN, LOW);
        M5.Lcd.fillScreen(BLACK);
        M5.Lcd.setCursor(10,40);
        M5.Lcd.setTextColor(WHITE);
        M5.Lcd.setTextSize(5);
        M5.Lcd.print("Locked");
    }
    if(digitalRead(DOOR_PIN)==1){
        M5.Lcd.fillScreen(BLUE);
        M5.Lcd.setTextColor(BLACK);
        M5.Lcd.setTextSize(5);
        M5.Lcd.setCursor(10,40);
        M5.Lcd.printf("Open");
        while(1){
            if(digitalRead(DOOR_PIN)==0){
                /*
                M5.Lcd.fillScreen(GREEN);
                M5.Lcd.setCursor(10,40);
                M5.Lcd.setTextColor(BLACK);
                M5.Lcd.setTextSize(5);
                M5.Lcd.print("Closed");
                */
                break;
            }
        }
        int seccount=0;
        while(seccount<KEY_TIME){
            if(digitalRead(KEY_PIN)==0){
                digitalWrite(LED_PIN, LOW);
                M5.Lcd.fillRect(0,0,320,120,BLACK);
                M5.Lcd.setCursor(10,40);
                M5.Lcd.setTextColor(WHITE);
                M5.Lcd.setTextSize(5);
                M5.Lcd.print("Locked");
                break;
            }
            delay(1000);
            seccount++;
        }
        if(digitalRead(KEY_PIN)==1){
            M5.Lcd.fillScreen(RED);
            M5.Lcd.setTextColor(BLACK);
            M5.Lcd.setTextSize(5);
            M5.Lcd.setCursor(10,40);
            M5.Lcd.printf("Unlock!!!");
            //line api
            String msg = "戸締まり忘れ検知!";
            line_notify(msg);
            while(1){
                digitalWrite(LED_PIN, HIGH);
                M5.Beep.beep();
                delay(500);
                digitalWrite(LED_PIN, LOW);
                M5.Beep.mute();
                delay(500);
                if(digitalRead(KEY_PIN)==0){
                    break;
                }
            }
        }
    }
    delay(1000);
}