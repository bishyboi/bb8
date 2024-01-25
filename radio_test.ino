//Define the channels of the analog inputs of the reciever.

int ch1 = 0;

int ch2 = 0;

int ch3 = 1;

int ch4 = 0;

int ch5 = 1;

int ch6 = 1;

//Define the pulsein functions.

int PWM_CH1=0;

int PWM_CH2=0;

int PWM_CH3=0;

int PWM_CH4=0;

int PWM_CH5=0;

int PWM_CH6=0;

//Define the values for mapping the inputs for the tank.

int CH1_VAL=0;

int CH2_VAL=0;

int CH3_VAL=0;

int CH4_VAL=0;

int CH5_VAL=0;

int CH6_VAL=0;

void setup() {

//Define the inputs and engage the serial monitor in the setup.

pinMode(ch1,INPUT);

pinMode(ch2,INPUT);

pinMode(ch3,INPUT);

pinMode(ch4,INPUT);

pinMode(ch5,INPUT);

pinMode(ch6,INPUT);

Serial.begin(115200);

}

void loop() {

//Read the PWM pulse.

PWM_CH1 = pulseIn (ch1,HIGH);

PWM_CH2 = pulseIn (ch2,HIGH);

PWM_CH3 = pulseIn (ch3,HIGH);

PWM_CH4 = pulseIn (ch4,HIGH);

PWM_CH5 = pulseIn (ch5,HIGH);

PWM_CH6 = pulseIn (ch6,HIGH);

//map the values.

CH1_VAL = map(PWM_CH1, 1000, 1990, 0, 255);

CH2_VAL = map(PWM_CH2, 1000, 1990, 0, 255);

CH3_VAL = map(PWM_CH3, 1000, 1990, 0, 255);

CH4_VAL = map(PWM_CH4, 1000, 1990, 0, 255);

//format the digital switched inputs.

if(PWM_CH5>1300){

CH5_VAL=0;

}

else{

CH5_VAL=1000;

}

if(PWM_CH6<1100){

CH6_VAL=1000;

}

if(PWM_CH6>1300){

CH6_VAL=500;

}

if(PWM_CH6>1600){

CH6_VAL=0;

}

//Read the pulses on the serial monitor, with a bit of formating.

Serial.print(" Channel 1 = ");

Serial.print(CH1_VAL);

Serial.print(" Channel 2 = ");

Serial.print(CH2_VAL);

Serial.print(" Channel 3 = ");

Serial.print(CH3_VAL);

Serial.print(" Channel 4 = ");

Serial.print(CH4_VAL);

Serial.print(" Channel 5 = ");

Serial.print(CH5_VAL);

Serial.print(" Channel 6 = ");

Serial.println(CH6_VAL);

}