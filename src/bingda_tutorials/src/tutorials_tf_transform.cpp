#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <tf/transform_datatypes.h>


int main(int argc, char** argv){
    ros::init(argc, argv, "robot_tf_publisher");
    ros::NodeHandle n;
    ros::Rate r(10);
    tf::TransformBroadcaster broadcaster;
    float angle = 0.0;
    float x = 0.0;
    float y = 0.0;
    float z = 0.0;
    ROS_INFO("Start TF Transform");
    while(n.ok()){

        x = cos(angle)*0.3;
        y = sin(angle)*0.3;
        z = 0.2;
        broadcaster.sendTransform(
            tf::StampedTransform(
                tf::Transform(tf::createQuaternionFromRPY(0.0,0.0,angle), tf::Vector3(x, y, z)),
                ros::Time::now(),"tf1", "tf3"));

        broadcaster.sendTransform(
            tf::StampedTransform(
                tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(x, y, z*2)),
                ros::Time::now(),"tf1", "tf4"));

        r.sleep();
        angle += 0.01;
    }
}