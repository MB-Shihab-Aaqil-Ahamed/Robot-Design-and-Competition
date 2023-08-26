#include <webots/Robot.hpp>
#include <webots/Motor.hpp>
#include <webots/DistanceSensor.hpp>

#define TIME_STEP 16
#define MAX_SPEED 0.0005

using namespace webots;

int main(int argc, char **argv) {
  Robot *robot = new Robot();
  
  Motor *wheels[4];
  const char *wheel_names[4] = {"Motor_1", "Motor_2", "Motor_1", "Motor_2"};
  for (int i = 0; i < 4; i++) {
    wheels[i] = robot->getMotor(wheel_names[i]);
    wheels[i]->setPosition(INFINITY);
    wheels[i]->setVelocity(0.0);
  }
 
  Motor *linear_horizontal = robot->getMotor("linear_horizontal");
  //Motor *linear_vertical = robot->getMotor("linear_vertical");
  linear_horizontal->setPosition(INFINITY);
  //linear_vertical->setPosition(INFINITY);
  
  DistanceSensor *sensors[5];
  const char *sensor_names[5] = {"ds_left_most", "ds_left", "ds_mid", "ds_right", "ds_right_most"};
  for (int i = 0; i < 5; i++) {
    sensors[i] = robot->getDistanceSensor(sensor_names[i]);
    sensors[i]->enable(TIME_STEP);
  }
  
  double kp = 1.7;
  double ki = 0;
  double kd = 1.5;
  double last_error = 0;
  double P = 0;
  double I = 0;
  double D = 0;
  double error = 0;
  double left_speed = MAX_SPEED;
  double right_speed = MAX_SPEED;
  
  while (robot->step(TIME_STEP) != -1) {
    double sensor_values[5];
    for (int i = 0; i < 5; i++) {
      sensor_values[i] = sensors[i]->getValue();
    }
    
    error = (sensor_values[0] - sensor_values[4]) / 400.0 
          + (sensor_values[1] - sensor_values[3]) / 200.0 
          + sensor_values[2] / 50.0;
    
    P = kp * error;
    I += ki * error;
    D = kd * (error - last_error);
    last_error = error;
    
    double pid_value = P + I + D;
    left_speed = MAX_SPEED - pid_value;
    right_speed = MAX_SPEED + pid_value;
    
    for (int i = 0; i < 2; i++) {
      wheels[i]->setVelocity(left_speed);
      wheels[i+2]->setVelocity(right_speed);
    }
  }
  
  delete robot;
  return 0;
}