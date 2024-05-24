/* Projeto Curto Circuito – ESP32, Button Blynk */
/*-------- Bibliotecas ----------- */
#define BLYNK_TEMPLATE_ID "TMPL29oLUz-0Y"
#define BLYNK_TEMPLATE_NAME "Rio Renovado"
#define BLYNK_AUTH_TOKEN "a1evsh53Ahqdy9be6-_WRLN6uprhzNB5"

#define BLYNK_PRINT Serial /* Blynk Serial Print */
#include <WiFi.h> /* Wi-Fi */
#include <WiFiClient.h> /* Wi-Fi client */
#include <BlynkSimpleEsp32.h> /* Blynk-ESP32 */
/*-------- Token de Autenticação ----------- */
char auth[] = "a1evsh53Ahqdy9be6-_WRLN6uprhzNB5";
/*-------- Configurações de Wi-Fi ----------- */
char ssid[] = "Lu";
char pass[] = "maia1234";
/*-------- Pino Virtual ----------- */
BLYNK_CONNECTED()
{         /* Se conectar com Blynk */
 
  Blynk.syncVirtual(V12);    /* Sincroniza com o pino V2 */
 
  
}

const int vermelho = 2;
const int amarelo = 5;
const int verde = 4;
int deteccoes = 0;

void setup()
{
    Serial.begin(9600);
    pinMode(12, INPUT_PULLUP);
    pinMode(verde, OUTPUT);
    pinMode(vermelho, OUTPUT);
    pinMode(amarelo, OUTPUT);
    Blynk.begin(auth, ssid, pass);
}

void loop() 
{
    Blynk.run();

    delay(1000); 

    if (digitalRead(12) == HIGH) { // Se o sensor for ativado
        deteccoes++; // Incrementa o contador de deteccoes
    }

    if (deteccoes >= 10)
    {
        digitalWrite(verde, HIGH);
        Blynk.virtualWrite(V12, deteccoes);
        delay(1000);

    }
    

    if (deteccoes >= 15)
    {
        digitalWrite(amarelo, HIGH);
        digitalWrite(verde, LOW);
        Blynk.virtualWrite(V12, deteccoes);
        delay(1000);
        
    }

  

    if (deteccoes >= 20)
    { digitalWrite(vermelho, HIGH);
    digitalWrite(amarelo, LOW);}
        Blynk.virtualWrite(V12, deteccoes);
        delay(1000);
         digitalWrite(vermelho, LOW);
}
        
 


