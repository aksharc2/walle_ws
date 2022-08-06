#ifndef GET_EXECUTION_TIME
#define GET_EXECUTION_TIME

#include <ros/ros.h>
#include <fstream>
#include <string>
#include <iostream>
#include <chrono>

using namespace std::chrono;

namespace exeTime
{
    class execution_Time
    {
    public:
        // void execution_time(duration<double>& exDiff, const std::string file_name){
        //     std::ofstream out(file_name, std::ios::out | std::ios::app);
        //     // duration<double> exDiff;
        //     out << ros::Time::now() << ',' << exDiff.count() << std::endl;
        //     out.close();
        // }

        void execution_time(duration<double>& exDiff, const std::string file_name){

            std::fstream fout;

            fout.open(file_name, std::ios::out | std::ios::app);
            // duration<double> exDiff;
            fout << ros::Time::now() << ',' << exDiff.count() << std::endl;
            ROS_INFO("I heard runtime %.6f seconds", exDiff.count());
            ROS_INFO("%s", file_name.c_str());
            // out.close();
        }





    };
}
#endif  // GET_EXECUTION_TIME
