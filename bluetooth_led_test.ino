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

void setup()
{
    Serial.begin(9600);
    pinMode(13, OUTPUT);
}

void loop()
{
    if (Serial.available())
    {
        char command = Serial.read();
        Serial.println(command);
        executeCommand(command);
    }
}

void executeCommand(char command)
{
    switch (command)
    {
    case FORWARD:
    
        break;
    case BACKWARD:
            break;
    case LEFT:
            break;
    case RIGHT:
            break;
    case CIRCLE:
            digitalWrite(13, 0);
            break;
    case CROSS:
            digitalWrite(13,1);
            break;
    case TRIANGLE:
            break;
    case SQUARE:
            break;
    case START:
            break;
    case PAUSE:
            break;
    default:
    // Invalid command
            break;
    }
}