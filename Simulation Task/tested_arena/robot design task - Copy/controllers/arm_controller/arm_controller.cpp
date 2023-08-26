/// File:          test_robot.cpp
// Date:
// Description:
// Author:
// Modifications:

// You may need to add webots include files such as
// <webots/DistanceSensor.hpp>, <webots/Motor.hpp>, etc.
// and/or to add some other includes
#include <webots/Robot.hpp>
#include <webots/Motor.hpp>
#include <webots/DistanceSensor.hpp>
#include <webots/PositionSensor.hpp>
#include <iostream>

#define TIME_STEP 16
#define MAX_SPEED 1.25

// All the webots classes are defined in the "webots" namespace
using namespace webots;
using namespace std;
// This is the main program of your controller.
// It creates an instance of your Robot instance, launches its
// function(s) and destroys it at the end of the execution.
// Note that only one instance of Robot should be created in
// a controller program.
// The arguments of the main function can be specified by the
// "controllerArgs" field of the Robot node

/*void controlSliderJoint(Robot *robot,Motor *up_down_motor,PositionSensor *vertical_position,float targetPosition, double targetVelocity) {
 

  // Get the slider joint motor and set the position and velocity mode
  while (robot->step(TIME_STEP) != -1) {
   float vertical_ps = vertical_position -> getValue();
   std::cout<<"position value: "<< vertical_ps<<std::endl;
   
   if (vertical_ps < targetPosition){
   std::cout<<"moving velocity "<<targetVelocity<< std::endl;
   up_down_motor -> setVelocity(-targetVelocity);
   }
  
  else if (vertical_ps < targetPosition){
   std::cout<<"moving velocity "<<-targetVelocity<< std::endl;
   up_down_motor -> setVelocity( targetVelocity);
   }
  }
  }*/
int main(int argc, char **argv) {
  // create the Robot instance.
  Robot *robot = new Robot();
  
  Motor *up_down_Motor = robot->getMotor("up_down_motor");
  
  up_down_Motor -> setPosition(INFINITY);
  
  while (robot->step(TIME_STEP) != -1) {
  up_down_Motor -> setVelocity(1.0);
  }
  
  //PositionSensor *vertical_position = robot->getPositionSensor("ps_up_down");
 // vertical_position->enable(TIME_STEP);


  
  // You should insert a getDevice-like function in order to get the
  // instance of a device of the robot. Something like:
  //  Motor *motor = robot->getMotor("motorname");
  //  DistanceSensor *ds = robot->getDistanceSensor("dsname");
//controlSliderJoint(robot,up_down_Motor,vertical_position, 0.4, 0.2);

  return 0;
  // Enter here exit cleanup code.

  delete robot;
  return 0;
}
