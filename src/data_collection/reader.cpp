#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Float64.h"
#include "std_msgs/Int32.h"
#include <fstream>
#include <string>
#include <iostream>
#include <chrono>

using namespace std::chrono;

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  // auto start = high_resolution_clock::now();
  ROS_INFO("I heard: [%s]", msg->data.c_str());
  // auto stop = high_resolution_clock::now();
  // auto duration = duration_cast<microseconds>(stop - start);
  // std::ofstream out("output.csv", std::ios::out | std::ios::app);
  // out << msg->data.c_str()<< ',' << duration.count() << std::endl;
  // out.close();
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener");
  ros::NodeHandle n;
  ros::Rate loop_rate(1);
  auto exStart = high_resolution_clock::now();
  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
  while(ros::ok()){
    // auto dd = high_resolution_clock::now() - exStart;
    std::cout << (high_resolution_clock::now() - exStart).count() << std::endl;
    exStart = high_resolution_clock::now();
    ros::spinOnce();
    loop_rate.sleep();
  }
  
//   ros::spinOnce();
  std::cout << " This exists";
  return 0;
}


// controller_costmap_ros_
