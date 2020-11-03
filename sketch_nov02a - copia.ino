#include <WiFi.h>
#include "FirebaseESP32.h"

#define ONBOARD_LED  2
const float Trigger = 15;   //Pin digital 2 para el Trigger del sensor
const float Echo = 2;   //Pin digital 3 para el Echo del sensor
int t;
int d;
bool last;


FirebaseData firebaseData;

              //Internet connection
              const char* ssid = "INFINITUM027B";
              const char* password =  "3962030244";
              
              void connectWifi() {
                // Let us connect to WiFi
                WiFi.begin(ssid, password);
                while (WiFi.status() != WL_CONNECTED) {
                  delay(500);
                  Serial.print(".");
                }
                Serial.println(".......");
                Serial.println("WiFi Connected....IP Address:");
                Serial.println(WiFi.localIP());
              }



void setup() {
  pinMode(ONBOARD_LED,OUTPUT);
  connectWifi();
  Serial.begin(9600);//iniciailzamos la comunicación
  pinMode(Trigger, OUTPUT); //pin como salida
  pinMode(Echo, INPUT);  //pin como entrada
  digitalWrite(Trigger, LOW);//Inicializamos el pin con 0
  digitalWrite(ONBOARD_LED, LOW);
  Firebase.begin("https://haboots-86f0b.firebaseio.com/", "d55wKLxhubCdxT7WJpxGu7TCr0b4LPq6PIfXeXOC");
  last = false;
}

void loop()
{
    digitalWrite(ONBOARD_LED, HIGH);
    digitalWrite(Trigger, HIGH);
    delayMicroseconds(10);          //Enviamos un pulso de 10us
    digitalWrite(Trigger, LOW);
    
    t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
    d = t/59; 
    Serial.println(d);
   
   if (d>9 && d<=90) //si la distancia es mayosr
   {
      Firebase.reconnectWiFi(true);
      if(last == true)
      {
               if(Firebase.setInt(firebaseData, "/Alarm", 666))
                {    
                 Serial.println("666 ALARMA ACTIVADA"); //Success
                               
                     
                }else
                {
                 //Failed?, get the error reason from firebaseData
            
                 Serial.print("Error in setInt, ");
                 Serial.println(firebaseData.errorReason());
                }
      }
      last = true;
    }else
    {
    Serial.println("No one here");
    last = false;
    }
      
     
   
  
delay(10);  
}
