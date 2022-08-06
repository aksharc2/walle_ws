#include "ros/ros.h"
#include "std_msgs/String.h"
// #include <fstream>
#include <string>
#include <iostream>
#include <chrono>
#include <gettime.h>

using namespace exeTime;

static const std::string fileName = "globalPlaner.csv";
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  execution_Time obj;
  auto exStart = std::chrono::high_resolution_clock::now();
  ROS_INFO("I heard: [%s]", msg->data.c_str());
  auto exEnd = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> exDiff = exEnd - exStart;  // global plan execution time
  obj.execution_time(exDiff, fileName);
}

int main(int argc, char **argv)
{
  execution_Time obj;
  ros::init(argc, argv, "listener");
  ros::NodeHandle n;
  ros::Rate loop_rate(50);
  // auto exStart = high_resolution_clock::now();
  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
  // while(ros::ok()){
  //   // auto dd = high_resolution_clock::now() - exStart;
  //   // std::cout << (high_resolution_clock::now() - exStart).count() << std::endl;
  //   // exStart = high_resolution_clock::now()
  //   ros::spinOnce();
  //   loop_rate.sleep();
  // }
  
  ros::spin();
  std::cout << " This exists";
  return 0;
}
