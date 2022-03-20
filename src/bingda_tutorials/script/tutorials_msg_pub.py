#!/usr/bin/env python
# license removed for brevity
import rospy
from bingda_tutorials.msg import Student

def talker():
    pub = rospy.Publisher('student_info', Student, queue_size=10)
    rospy.init_node('tutorials_msg_pub', anonymous=True)
    rate = rospy.Rate(10) # 10hz
    while not rospy.is_shutdown():
        hello_str = "hello world %s" % rospy.get_time()
        student = Student()
        student.first_name = 'BingDa'
        student.last_name = 'Robot'
        student.age = 2
        student.score = 100
        rospy.loginfo('pub a student msg')
        pub.publish(student)
        rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass