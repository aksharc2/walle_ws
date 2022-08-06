#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include <unistd.h>

// unsigned int microseconds;


int main(int argc, char **argv)
{

  ros::init(argc, argv, "talker");
  ros::NodeHandle n;
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
  ros::Rate loop_rate(0.5);
//   ros::Rate loop_rate2(300);
  int count = 0;
  while (ros::ok())
  {
    std_msgs::String msg;
    std::stringstream ss;
    ss << "hello world " << count;
    // loop_rate2.sleep();
    msg.data = ss.str();
    ROS_INFO("%s", msg.data.c_str());

    usleep(1200000);

    if (count == 20){ 
        usleep(3000000);
    }


    chatter_pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
    ++count;
  }


  return 0;
}
