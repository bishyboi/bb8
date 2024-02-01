#define CH1 3
#define CH2 5
#define CH3 6
#define CH4 9

int readChannel(int channelInput, int minLimit, int maxLimit, int defaultValue){
  int ch = pulseIn(channelInput, HIGH, 30000);
  return ch;
  if (ch < 100) return defaultValue;
  return map(ch, 600, 1600, minLimit, maxLimit);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(CH1, INPUT);
  pinMode(CH2, INPUT);
  pinMode(CH3, INPUT);
  pinMode(CH4, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensor1 = readChannel(CH1, -100, 100, 0);
  int sensor2 = readChannel(CH2, -100, 100, 0);
  int sensor3 = readChannel(CH3, -100, 100, 0);
  int sensor4 = readChannel(CH4, -100, 100, 0);


  Serial.print(" | Ch1: ");
  Serial.print(sensor1);
  Serial.print(" | Ch2: ");
  Serial.print(sensor2);
  Serial.print(" | Ch3: ");
  Serial.print(sensor3);
  Serial.print(" | Ch4: ");
  Serial.print(sensor4);
  Serial.println();

  delay(50);
}
