#include <webots/Robot.hpp>
#include <webots/Motor.hpp>
#include <webots/DistanceSensor.hpp>
#include <webots/PositionSensor.hpp>
#include <iostream>

#define TIME_STEP 16
#define MAX_SPEED 1.25

using namespace webots;
using namespace std;

/*void controlSliderJoint(Robot *robot, Motor *up_down_motor, PositionSensor *vertical_position, float targetPosition, double targetVelocity) {
  // Set the position sensor to enable
  vertical_position->enable(TIME_STEP);

  // Loop until the target position is reached
  while (robot->step(TIME_STEP) != -1) {
    float vertical_ps = vertical_position->getValue();
    cout << "position " << vertical_ps << endl;

    // Move the slider joint motor based on the target position and velocity
    if (vertical_ps < targetPosition) {
      up_down_motor->setVelocity(targetVelocity);
      cout << "moving velocity " << -targetVelocity << endl;
    } else if (vertical_ps > targetPosition) {
      up_down_motor->setVelocity(-targetVelocity);
      cout << "moving velocity " << targetVelocity << endl;
    } else {
      up_down_motor->setVelocity(0.0);
      cout << "position reached" << endl;
      break;
    }
  }
}*/

int main(int argc, char **argv) {
  Robot *robot = new Robot();
  Motor *up_down_motor = robot->getMotor("up_down_motor");
  PositionSensor *vertical_position = robot->getPositionSensor("ps_up_down");
  vertical_position->enable(TIME_STEP);

  // Set the motor to velocity control mode
  up_down_motor->setPosition(INFINITY);
  up_down_motor->setVelocity(0.0);

  // Control the slider joint motor to reach the target position
  //controlSliderJoint(robot, up_down_motor, vertical_position, 0.4, 1.0);
while (robot->step(TIME_STEP) != -1){
  up_down_motor -> setVelocity(0.01);
    }
  // Cleanup
  delete robot;
  return 0;
}
