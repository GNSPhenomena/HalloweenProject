//declear pins
const int trigPin=9, echoPin=10, redPin=3, greenPin=5, bluePin=6, speakerPin=8;
//declear varibles
int redIntensity, greenIntensity, blueIntensity;
long duration, distance, d;

void setup()
{ 
  //initial
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void showRGB(int color)
{  
  if(color == 0)  writeRGBValue(0, 0, 0);
  else if (color <= 255)  writeRGBValue(255-color, color, 0;
  else if (color <= 511)  writeRGBValue(0, 255-(color-256), color-256);
  else if (color <= 768)  writeRGBValue(color-512, 0, 255-(color-512));
  else  writeRGBValue(255, 255, 255);
}

void writeRGBValue(int redV, int blueV, int greenV)
{
  analogWrite(redPin, redV);
    analogWrite(bluePin, blueV);
    analogWrite(greenPin, greenV);
}

void ultrasonicValue()
{
  digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.1;
    Serial.print("Distance: ");
    Serial.println(distance);
}

void loop() {
  //conditions
  if(distance < 50) 
  {
    showRGB(800);
    delay(10);
    //tone(speakerPin,distance*35);
  }
  else if(distance > 120)
  {
    showRGB(0);
    delay(10);
    //tone(speakerPin,-1);
  }
  else
  {
    showRGB((distance-50)*12);
    delay(10);
    //tone(speakerPin,distance*35);
  }
}