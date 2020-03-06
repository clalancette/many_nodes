#ifndef MANY_NODES__SIMPLE_NODE_HPP
#define MANY_NODES__SIMPLE_NODE_HPP

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

namespace many_nodes {
class SimpleNode final : public rclcpp::Node
{
 public:
  explicit SimpleNode(const rclcpp::NodeOptions & options);
  ~SimpleNode();

 private:
  void testCallback(const std_msgs::msg::String::SharedPtr msg);

  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_;
};

}

#endif  // MANY_NODES__SIMPLE_NODE_HPP
