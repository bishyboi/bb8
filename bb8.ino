// Motor Pin[] Format: Negative, Positive, PWM
const int motor_L_pins[] = {7,8,9};
const int motor_R_pins[] = {10,11,12};

void power_motor(int motor_pins[3], bool on, int pwm = 255, bool rev = false)
{
  if(on)
  {
    if (!rev)
    {
      digitalWrite(motor_pins[0], 1);
      digitalWrite(motor_pins[1], 0);
      analogWrite(motor_pins[2], pwm);
    }else{
      digitalWrite(motor_pins[0], 0);
      digitalWrite(motor_pins[1], 1);
      analogWrite(motor_pins[2], pwm);
    }
  }
  else{
    digitalWrite(motor_pins[0], 0);
    digitalWrite(motor_pins[1], 0);
    analogWrite(motor_pins[2], 0);
  }
}

void setup() {
  for(int pin: motor_L_pins)
    pinMode(pin, OUTPUT);
  
  for(int pin: motor_R_pins)
    pinMode(pin, OUTPUT);
}

void loop() {
  power_motor(motor_L_pins, true);
  power_motor(motor_R_pins, true);
}
