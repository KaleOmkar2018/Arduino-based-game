uint16_t i=0;//16 bit 
uint8_t a1,a2;
void setup()
{
  analogReference(EXTERNAL);                
  Serial.begin(1200);              //baud rate=1200
  pinMode(12, INPUT_PULLUP);        //dig pin no 12 =input(pin 18)
}

void loop()
{
  
  i=analogRead(A0);                    ///read analog value =10bit
  //Serial.write(i<<3 | 2);
  
  //Serial.write((i>>2 & 248<<0) | (digitalRead(12) & 7));
  a1=((i<<3) | (2<<0));
  a2=(((i>>2) & (248<<0)) | (digitalRead(12) & 7));
  Serial.write(a1);  
  Serial.write(a2);
  Serial.write(abs(a1-a2));
  
  i=analogRead(A1);
  //Serial.write(i<<3 | 3);
  //Serial.write((i>>2 & 248<<0) | (digitalRead(12) & 7));
  
  a1=((i<<3) | (3<<0));
  a2=(((i>>2) & (248<<0)) | (digitalRead(12) & 7));
  Serial.write(a1);  
  Serial.write(a2);
  Serial.write(abs(a1-a2));
  
  delay(5);  
}