#include <OneWire.h>

#include <DallasTemperature.h>

#include <LiquidCrystal.h>

#define DS18B20 3 //DEFINE O PINO DO SENSOR DS18B20
const int PINO_RELE1 = 13; // INFORMA PINO DO RELE 1
const int PINO_RELE2 = 8; // INFORMA PINO DO RELE 2
LiquidCrystal lcd(12, 11, 7, 6, 5, 4); //PINOS UTILIZADOS PARA A CONEXÃO DO DISPLAY
OneWire ourWire(DS18B20);//CONFIGURA UMA INSTÂNCIA ONEWIRE PARA SE COMUNICAR COM DS18B20
DallasTemperature sensors(&ourWire); //PASSA A TEMPERATURA PARA O DallasTemperature



void setup() {
  delay(1000); //INTERVALO DE 1000 MILISSEGUNDOS
 Serial.begin(9600); // Inicia a porta serial
 Serial.println("Medindo temperatura"); // Imprime a mensagem inicial 
 lcd.begin(16, 2); // INICIA O LCD
  delay(500);
    lcd.setCursor(2,0);
    lcd.print("ANALISANDO");
    lcd.setCursor(4,1);
    lcd.print("TEMPERATURA");
    
    delay(3000);
    
sensors.begin(); // INICIA O SENSOR DS18B20
lcd.clear();

pinMode (PINO_RELE1, OUTPUT); // VENTILADOR
pinMode (PINO_RELE2, OUTPUT); // EXAUSTOR

}

void loop() {
lcd.setCursor(0,0);//SETA O CURSOR PARA INICIAR AS ESCRITAS NO LCD
lcd.print(sensors.getTempCByIndex(0)); //valor da temp1
lcd.write(223);//IMPRIME NO DISPLAY LCD O SÍMBOLO 'º'
lcd.print("C");
lcd.setCursor(9,0);//SETA O CURSOR PARA ESCREVER A PALAVRA CELSIUS NA SEGUNDA LINHA E COLUNA 9 DO DISPLAY
lcd.print("EXTERNA");//IMPRIME O TEXTO NO LCD
sensors.requestTemperatures();//REQUISITA A TEMPERATURA DO SENSOR
lcd.setCursor(0,1);//SETA O CURSOR PARA INICIAR AS ESCRITAS NA SEGUNDA LINHA DO LCD
lcd.print(sensors.getTempCByIndex(1));//IMPRIME NO LCD O VALOR DA TEMPERATURA2 
lcd.write(223);//IMPRIME NO DISPLAY LCD O SÍMBOLO 'º'
lcd.print("C");
lcd.setCursor(9,1);//SETA O CURSOR PARA ESCREVER A PALAVRA CELSIUS NA SEGUNDA LINHA E COLUNA 9 DO DISPLAY
lcd.print("INTERNA");//IMPRIME O TEXTO NO LCD
delay(1000);//INTERVALO DE 500 MILISSEGUNDOS
// SENSOR EXTERNO ARMA VENTILADOR (AMARELO)
if (sensors.getTempCByIndex(0) <=27){
  digitalWrite(PINO_RELE1, HIGH);
}
else {
  digitalWrite(PINO_RELE1, LOW);
}
// SENSOR INTERNO ARMA EXAUSTOR (VERMELHO)
if (sensors.getTempCByIndex(1) >=28){
  digitalWrite(PINO_RELE2, HIGH);
}
else {
  digitalWrite(PINO_RELE2, LOW); 
}
delay(1000);

}
