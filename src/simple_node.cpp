#include <functional>

#include <rclcpp/rclcpp.hpp>
#include <rclcpp_components/register_node_macro.hpp>
#include <std_msgs/msg/string.hpp>

#include "many_nodes/simple_node.hpp"

namespace many_nodes {

SimpleNode::SimpleNode(const rclcpp::NodeOptions & options) : rclcpp::Node("simple_node", options)
{
  sub_ = this->create_subscription<std_msgs::msg::String>(
    "test", rclcpp::QoS(10), std::bind(&SimpleNode::testCallback, this, std::placeholders::_1));
}

void SimpleNode::testCallback(const std_msgs::msg::String::SharedPtr msg)
{
  RCLCPP_INFO(get_logger(), "Got msg: %s", msg->data);
}

SimpleNode::~SimpleNode()
{
}

}  // namespace many_nodes

RCLCPP_COMPONENTS_REGISTER_NODE(many_nodes::SimpleNode)
