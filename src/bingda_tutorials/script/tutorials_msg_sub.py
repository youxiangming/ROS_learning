#!/usr/bin/env python
import rospy
from bingda_tutorials.msg import Student

def callback(data):
    rospy.loginfo("Student Name is %s %s;Age is %d ;Socer is %d.", data.first_name,data.last_name ,data.age,data.score)
    
def listener():
    rospy.init_node('tutorials_msg_sub', anonymous=False)
    rospy.Subscriber("student_info", Student, callback)
    rospy.spin()

if __name__ == '__main__':
    listener()