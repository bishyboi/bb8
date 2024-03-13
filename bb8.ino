#define FORWARD 'F'
#define BACKWARD 'B'
#define LEFT 'L'
#define RIGHT 'R'
#define CIRCLE 'C'
#define CROSS 'X'
#define TRIANGLE 'T'
#define SQUARE 'S'
#define START 'A'
#define PAUSE 'P'

#define MOTOR_MAX 255
#define MOTOR_NORMAL 155
// Motor Pin[] Format: Negative, Positive, PWM
const int motor_L_pins[] = {7, 8, 9};
const int motor_R_pins[] = {10, 11, 12};
const int LED = 13;

bool motors_on = false;
int motors_speed = 155;

void power_motor(int motor_pins[3], bool on, int pwm = 255, bool rev = false)
{
    if (on)
    {
        if (!rev)
        {
            digitalWrite(motor_pins[0], 1);
            digitalWrite(motor_pins[1], 0);
            analogWrite(motor_pins[2], pwm);
        }
        else
        {
            digitalWrite(motor_pins[0], 0);
            digitalWrite(motor_pins[1], 1);
            analogWrite(motor_pins[2], pwm);
        }
    }
    else
    {
        digitalWrite(motor_pins[0], 0);
        digitalWrite(motor_pins[1], 0);
        analogWrite(motor_pins[2], 0);
    }
}

void executeCommand(char command)
{
    switch (command)
    {
    case FORWARD:
        power_motor(motor_L_pins, motors_on, motors_speed);
        power_motor(motor_R_pins, motors_on, motors_speed);
        break;

    case BACKWARD:
        power_motor(motor_L_pins, motors_on, motors_speed, true);
        power_motor(motor_R_pins, motors_on, motors_speed, true);
        break;

    case LEFT:
        power_motor(motor_L_pins, motors_on, motors_speed, true);
        power_motor(motor_R_pins, motors_on, motors_speed);
        break;

    case RIGHT:
        power_motor(motor_L_pins, motors_on, motors_speed);
        power_motor(motor_R_pins, motors_on, motors_speed, true);
        break;

    case CIRCLE:
        motors_speed = MOTOR_NORMAL;
        break;

    case CROSS:
        motors_speed = MOTOR_MAX;
        break;

    case TRIANGLE:
        break;
    case SQUARE:
        break;
    case START:
        motors_on = true;
        digitalWrite(LED, HIGH);
        break;

    case PAUSE:
        motors_on = false;
        digitalWrite(LED, LOW);
        break;

    default:
        // Invalid command
        break;
    }
}

void setup()
{
    for (int pin : motor_L_pins)
        pinMode(pin, OUTPUT);

    for (int pin : motor_R_pins)
        pinMode(pin, OUTPUT);

    pinMode(LED, OUTPUT);
}

void loop()
{
    if (Serial.available())
        char command = Serial.read();
        Serial.println(command);
        executeCommand(command);
}
