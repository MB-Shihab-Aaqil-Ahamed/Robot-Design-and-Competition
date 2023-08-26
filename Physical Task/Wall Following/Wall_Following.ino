left_motor_forward=4,
left_motor_backward=8,
right_motor_forward=2,
right_motor_backward=12,
left_motor_pwm=10,
right_motor_pwm=6;

float Kp = 30;
float Kd = 10;
float Ki = 0; 
double error = 0;
double setDistance=5;
double previousError=0;

#define trigPin 5
#define echoPin 3

int dangerThresh = 5; //threshold for obstacles (in cm)
int leftDistance, rightDistance; //distances on either side

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(left_motor_forward,OUTPUT);
  pinMode(left_motor_backward,OUTPUT);
  pinMode(right_motor_forward,OUTPUT);
  pinMode(right_motor_backward,OUTPUT);
  panMotor.attach(9); //attach motors to proper pins
  panMotor.write(90); //set PING))) pan to center
  delay(1000);
}

void loop(){
  currentDistance = read_SONAR();

  //PID
  error=0;
   error = setDistance - currentDistance;

   P = error;
   I = I + error;
   D = error - previousError;

  previousError = error;

  speedAdjust = Kp*P + Ki*I + Kd*D;

  LMotorSpeed = MotorBaseSpeed + speedAdjust;
  RMotorSpeed = MotorBaseSpeed - speedAdjust;
  
  if (LMotorSpeed<0)  {LMotorSpeed = 0;}
  if (RMotorSpeed<0)  {RMotorSpeed = 0;}
  if (LMotorSpeed>MaxSpeed) {LMotorSpeed = MaxSpeed;}
  if (RMotorSpeed>MaxSpeed) {RMotorSpeed = MaxSpeed;}  
  set_speed();
  }


int read_SONAR(){
  distance2=sonar_2.ping_cm();
  distance3=sonar_3.ping_cm();
  return (distance2+distance3)/2;
  }


int read_FRONT_SONAR(){
  distance1=sonar_1.ping_cm(); //front distance
  return (distance1);
  }

void forward()
{
  digitalWrite(left_motor_forward,1);
  digitalWrite(right_motor_forward,1);
  digitalWrite(left_motor_backward,0);
  digitalWrite(right_motor_backward,0);
  analogWrite(left_motor_pwm,150);
  analogWrite(right_motor_pwm,150);
  delay(1000);
  Stop();
}
void backward()
{
  digitalWrite(left_motor_backward,1);
  digitalWrite(right_motor_backward,1);
  digitalWrite(left_motor_forward,0);
  digitalWrite(right_motor_forward,0);
  analogWrite(left_motor_pwm,150);
  analogWrite(right_motor_pwm,150);
  delay(1000);
  Stop();
}
void right_turn()  //hard right turn
{
  digitalWrite(left_motor_forward,1);
  digitalWrite(right_motor_forward,0);
  digitalWrite(left_motor_backward,0);
  digitalWrite(right_motor_backward,1);
  analogWrite(left_motor_pwm,200);   
  analogWrite(right_motor_pwm,100);
  delay(500);
  Stop();
}
void left_turn()    //hard left turn
{
  digitalWrite(left_motor_forward,0);
  digitalWrite(right_motor_forward,1);
  digitalWrite(left_motor_backward,1);
  digitalWrite(right_motor_backward,0);
  analogWrite(left_motor_pwm,100);
  analogWrite(right_motor_pwm,200);
  delay(500);
  Stop();
}
void Stop()
{
  analogWrite(left_motor_pwm,0);
  analogWrite(right_motor_pwm,0);
}

long distance_calculation()
{
  long duration, distance;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  return distance;
}

void compareDistance()
{
  if (leftDistance>rightDistance) //if left is less obstructed 
  {
    left_turn();
    delay(500); 
  }
  else //if right is less obstructed
  {
    right_turn();
    delay(500);
  }
}
