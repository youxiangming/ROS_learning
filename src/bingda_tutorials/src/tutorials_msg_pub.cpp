#include "ros/ros.h"
#include "bingda_tutorials/Student.h"

#include <sstream>

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{
  /**
   * The ros::init() function needs to see argc and argv so that it can perform
   * any ROS arguments and name remapping that were provided at the command line.
   * For programmatic remappings you can use a different version of init() which takes
   * remappings directly, but for most command-line programs, passing argc and argv is
   * the easiest way to do it.  The third argument to init() is the name of the node.
   *
   * You must call one of the versions of ros::init() before using any other
   * part of the ROS system.
   */
  ros::init(argc, argv, "tutorials_msg_pub");

  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<bingda_tutorials::Student>("student_info", 1000);

  ros::Rate loop_rate(10);

  uint8_t count = 0;
  while (ros::ok())
  {

    bingda_tutorials::Student student;

    std::stringstream ss;
    ss << "hello world " << count;
    student.first_name = "BingDa";
    student.last_name = "Robot";
    student.age = count;
    student.score = 100;

    ROS_INFO("Counte %d", count);


    chatter_pub.publish(student);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}