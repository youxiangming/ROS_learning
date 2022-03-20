/*

   Topic通信方式例程，一方发布数据，一方接收数据
  发布方与接收方需要订阅和发布相同的话题
    
    实现Topic通信方式的流程：
    1. 初始化ROS节点 ：命名（唯一）
    2. 创建一个ROS节点对象并实例化（c++）
    3. 创建并实例化 publisher 对象 ，包括发布的话题名(话题名需要和订阅者的名字一样)和话题的消息类型
    4. 按照一定频率循环发布消息

    ROS_INFO的用法：
     2.ROS_INFO(“s%”, msg.data.c_str()),输出一个字符串变量
    3.ROS_INFO(“I heard: [s%]”, msg.data.c_str()),输出一个字符串变量，这里的中括号不是必须的，输出时会直接显示这个中括号
    4.ROS_INFO(“I heard: [s%]”, msg->data.c_str()),输出一个指针变量
    5.ROS_INFO(“Publish Person Info: name:%s age:%d sex:%d", person_msg.name.c_str(), person_msg.age, person_msg.sex)，按数据类型输出
 */


#include<ros/ros.h>
#include<std_msgs/String.h>
#include<sstream>


int main(int argc, char **argv)
{
    //设置编码,用于终端显示正常
    setlocale(LC_ALL,"");
    //1. ROS 节点初始化
    // 参数1和参数2 后期为节点传值会使用
    // 参数3 是节点名称，是一个标识符，需要保证运行后，在 ROS 网络拓扑中唯一
    ros::init(argc,argv,"info_publisher");

    //2. 创建节点句柄(实例化Node节点对象)
    ros::NodeHandle n;//该类封装了 ROS 中的一些常用功能

    //3.实例化 发布者 对象
    //泛型: 发布话题的消息类型(std_msgs::String)可以自行定义，见古月的person_info
    //参数1: 要发布到的话题
    //参数2: 队列中最大保存的消息数，超出此阀值时，先进的先销毁(时间早的先销毁)
    ros::Publisher pub=n.advertise<std_msgs::String>("chatter",10);

    //4.组织被发布的数据，并编写逻辑发布数据
    //数据(动态组织)
    std_msgs::String msg;//msg是一个函数
    // msg.data = "你好啊！！！";
    std::string msg_front = "Hello 你好！"; //消息前缀（类型为字符串）
    int count = 0; //消息计数器

    //逻辑(一秒10次)
    ros::Rate r(1);

    //节点不死
    while (ros::ok())
    {
        //使用 stringstream 拼接字符串与编号
        std::stringstream ss;
        
        //把msg_front count按照顺序复制到ss字符对象中
        ss << msg_front << count; 
        msg.data = ss.str();
        //发布消息
        pub.publish(msg);
        //加入调试，打印发送的消息
        ROS_INFO("发送的消息:%s",msg.data.c_str()); 

        //根据前面制定的发送贫频率自动休眠 休眠时间 = 1/频率；
        r.sleep();
        count++;//循环结束前，让 count 自增
        //暂无应用
        ros::spinOnce();
    }


    return 0;
}
