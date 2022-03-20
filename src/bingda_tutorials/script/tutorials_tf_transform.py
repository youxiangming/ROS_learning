#!/usr/bin/env python
import rospy
import tf
import math

def tf_transform():
    rospy.init_node('tutorials_tf_transform', anonymous=False)
    tf_broadcaster = tf.TransformBroadcaster()
    rate = rospy.Rate(10) # 10hz
    angle = 0.0
    rospy.loginfo('Start TF Transform')
    while not rospy.is_shutdown():
        current_time = rospy.Time.now()
        x = math.cos(angle)*0.3
        y = math.sin(angle)*0.3
        z = 0.2
        quat = tf.transformations.quaternion_from_euler(0,0,angle)
        tf_broadcaster.sendTransform((x,y,z),quat,current_time,'tf3','tf1')
        tf_broadcaster.sendTransform((x,y,z*2),(0,0,0,1),current_time,'tf4','tf1')
        angle += 0.01
        rate.sleep()

if __name__ == '__main__':
    tf_transform()