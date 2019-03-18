#include "ros/ros.h"
#include "ros_tutorial_service/SrvTutorial.h"
#include <cstdlib>

int main(int argc, char** argv)
{
	ros::init(argc, argv, "service_client");

	if(argc != 3)
	{
		ROS_INFO(
				"cmd : rosrun ros_tutorial_service service_client arg0 arg1");
		ROS_INFO("arg0: double number, arg1: double number");
		return 0;
	}

	ros::NodeHandle nh;

	ros::ServiceClient ros_tutorial_service_client =
		nh.serviceClient<ros_tutorial_service::SrvTutorial>(
			"ros_tutorial_srv");

	ros_tutorial_service::SrvTutorial srv;

	srv.request.a = atoll(argv[1]);
	srv.request.b = atoll(argv[2]);

	if(ros_tutorial_service_client.call(srv))
	{
		ROS_INFO("send srv, srv.Request.a and b: %ld, %ld",
				(long int)srv.request.a, (long int)srv.request.b);
		ROS_INFO("receive srv, srv Response.result: %ld",
				(long int)srv.response.result);
	}
	else
	{
		ROS_ERROR("Failed to call service ros_tutorial_srv");
		return 1;
	}

	return 0;
}
