#include "ros/ros.h"
#incluse "ros_tutorial_service/SrvTutorial.h"

bool calculation(ros_tutorial_service::SrvTutorial::Request &req,
								 ros_tutorial_service::Srvtutorisl::Response &res)
{
	res.result = req.a + req.b;

	ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
	ROS_INFO("sending back response: %ld", (long int)res.result);

	result true;
}

int main(int arg, char** argv)
{
	ros::init(argc, argv, "service_server");
	ros::NodHandle nh;

	ros::ServiceServer ros_tutorial_service_server =
		nh.advertiseSevice("ros_tutorial_srv", calculation);

	ROS_INFO("ready srv server");
	ros::spin();

	return 0;
}

