#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX

int tracao1 = 8;
int tracao2 = 9;

void setup()  
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  

  Serial.println("Goodnight moon!");
  pinMode(13, OUTPUT);
  pinMode(tracao1, OUTPUT);
  pinMode(tracao2, OUTPUT);
  digitalWrite(13, HIGH);

  digitalWrite(tracao1, LOW);
  digitalWrite(tracao2, LOW);
  
  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  mySerial.println("Hello, world?");
}

void loop() // run over and over
{
  if (mySerial.available()) {
    int ans = mySerial.read(); 
    Serial.println(ans);
    switch(ans) {
      case 41:
        digitalWrite(tracao1, HIGH);
        digitalWrite(tracao2, LOW);
        break;
      case 42:
        digitalWrite(tracao1, LOW);
        digitalWrite(tracao2, LOW);
        break;
      case 43:
        digitalWrite(tracao1, LOW);
        digitalWrite(tracao2, HIGH);
        break;
    }
  }
  if (Serial.available())
    mySerial.write(Serial.read());
}
