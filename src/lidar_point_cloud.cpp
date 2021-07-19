#include "ros/ros.h"
#include "sensor_msgs/PointCloud2.h"
#include <stdio.h>
#include <vector>

// std_msgs/Header header
//   uint32 seq
//   time stamp
//   string frame_id
// uint32 height
// uint32 width
// sensor_msgs/PointField[] fields
//   uint8 INT8=1
//   uint8 UINT8=2
//   uint8 INT16=3
//   uint8 UINT16=4
//   uint8 INT32=5
//   uint8 UINT32=6
//   uint8 FLOAT32=7
//   uint8 FLOAT64=8
//   string name
//   uint32 offset
//   uint8 datatype
//   uint32 count
// bool is_bigendian
// uint32 point_step
// uint32 row_step
// uint8[] data
// bool is_dense

void msgCallback(const sensor_msgs::PointCloud2::ConstPtr&msg) //const: 상수
{
	int height = msg -> height;
	int width = msg -> width;

	int point_step = msg -> point_step;
	int row_step = msg -> row_step;

	int data_0 = msg -> data[0];
	int data_1 = msg -> data[1];
	int data_2 = msg -> data[2];

	int data_size = msg -> data.size();

	ROS_INFO("height : %d", height);
	ROS_INFO("width : %d", width);

	ROS_INFO("point_step : %d", point_step);
	ROS_INFO("row_step : %d", row_step);

	ROS_INFO("data_0 : %d", data_0);
	ROS_INFO("data_1 : %d", data_1);
	ROS_INFO("data_2 : %d", data_2);
	
	ROS_INFO("data_v size: %d", data_size);
}

int main(int argc, char **argv)
{
 	ros::init(argc, argv, "lidar_pointcloud");
	ros::NodeHandle nh;
 	ros::Subscriber sub = nh.subscribe("/camera/depth/color/points", 100, msgCallback);
 	ros::spin(); // 어떤 값이 들어오기 전까지 대기
 	return 0;
}
