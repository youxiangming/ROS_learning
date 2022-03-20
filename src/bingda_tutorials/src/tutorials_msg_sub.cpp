#include "ros/ros.h"
#include "bingda_tutorials/Student.h"

/**
 * This tutorial demonstrates simple receipt of messages over the ROS system.
 */
void chatterCallback(const bingda_tutorials::Student::ConstPtr& msg)
{
  ROS_INFO("Student Name is %s %s;Age is %d ;Socer is %d.", msg->first_name.c_str(),msg->last_name.c_str() ,msg->age,msg->score);
  // ROS_INFO("Student Name is %s.", msg.first_name);
  // msg->
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "tutorials_msg_sub");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("student_info", 1000, chatterCallback);

  ros::spin();

  return 0;
}