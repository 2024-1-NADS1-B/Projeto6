#define BLYNK_TEMPLATE_ID "TMPL29oLUz-0Y"
#define BLYNK_TEMPLATE_NAME "Rio Renovado"

#include <ESP8266WiFi.h> //Biblioteca para uso do WiFi do ESP8266
#include <BlynkSimpleEsp8266.h> //Biblioteca para uso do ESP8266 no Blynk

char auth[] = "65g8jbjwMiBgXSMlcgqyPXwrU458kQEg"; //Auth token do projeto
char ssid[] = "Lu"; //Nome da rede Wi-Fi
char pass[] = "maia1234"; //Senha da rede Wi-Fi


void setup(){
  Serial.begin(115200); //Inicialização da comunicação serial
  Blynk.begin(auth, ssid, pass); //Inicializa o blynk passando como parâmetro o auth token, o nome da rede Wi-Fi e a senha
 
}

void loop(){
  Blynk.run(); //Chama a função Blynk.run()
  int infra = analogRead(A0);
  Blynk.virtualWrite(V1, infra);
  Serial.println(infra);
}