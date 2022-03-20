/*
    该例程将发布/person_info话题，自定义消息类型为learning_topic::Person
    //在文件夹learning_topic中新建一个命名为msg的文件夹，存放消息类文件,方便管理
    //创建.msg文件 touch Person.msg
    //打开该文件，输入以下信息后保存
    string name
    uint8 sex
    uint8 age

    uint8 unknown = 0
    uint8 male = 1
    uint8 female = 2
    //这里写的并不是cpp，也不是python。但他在编译过程中会由ros自动编译成cpp或python
    需要在package.xml
    cmakelist文件中配置


    为了方便代码提示以及避免误抛异常，需要先配置 vscode，
    将前面生成的 head 文件路径配置进 c_cpp_properties.json 的 includepath属性:
 */

#include<ros/ros.h>
#include<learning_topic/Person.h>

int main(int argc,char  **argv)
{
    //ROS 节点初始化
    ros::init(argc,argv,"person_publisher");

    //创建节点句柄
    ros::NodeHandle n;

    //创建一个Publisher,发布名为/person_info的topic, 消息类型为learning_topic::Person ,队列长度为10
    ros::Publisher person_info_pub=n.advertise<learning_topic::Person>("person_info",10) ;

    //设置循环频率
    ros::Rate loop_rate(10);
    
    int count=0;
    while (ros::ok)
    {
        //初始化learning_topic::Person类型的消息
       learning_topic::Person person_msg;
        person_msg.name= " Tom";
        person_msg.age=18;
        person_msg.sex=learning_topic::Person::male;

        //发布消息
        person_info_pub.publish(person_msg);
        ROS_INFO("Publisher Person Info:name:%s age:%d sex:%d",person_msg.name.c_str(),person_msg.age,person_msg.sex);

        //按照循环频率延时
        loop_rate.sleep();
    }
    return 0;
    
}
