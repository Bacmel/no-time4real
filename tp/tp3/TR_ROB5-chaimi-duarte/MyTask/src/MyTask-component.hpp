#ifndef OROCOS_MYTASK_COMPONENT_HPP
#define OROCOS_MYTASK_COMPONENT_HPP

#include <rtt/RTT.hpp>
#include <rtt/Port.hpp>

class MyTask : public RTT::TaskContext{
  private:
  // Input port
  RTT::InputPort<double> mes;
  // Output ports
  RTT::OutputPort<double> cmd;

  public:
    double des;
    MyTask(std::string const& name);
    bool configureHook();
    bool startHook();
    void updateHook();
    void stopHook();
    void cleanupHook();
};

class MyTask2 : public RTT::TaskContext{
private:
  // Input port
  RTT::InputPort<double> mes;
  // Output ports
  RTT::OutputPort<double> cmd;

public:
  double des;
  MyTask2(std::string const& name);
  bool configureHook();
  bool startHook();
  void updateHook();
  void stopHook();
  void cleanupHook();
};
#endif
