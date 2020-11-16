#ifndef OROCOS_MYTASK_CONTROLLER_HPP
#define OROCOS_MYTASK_CONTROLLER_HPP

#include <rtt/RTT.hpp>
#include <rtt/Port.hpp>
#include <rtt/Attribute.hpp>
#include <rtt/Logger.hpp>
#include <rtt/TaskContext.hpp>
#include <rtt/Component.hpp>
#include <iostream>
#include <std_msgs/Float64.h>

class Controller : public RTT::TaskContext{
  private:
  // constante
  double Kp;
  double Ki;
  double max;
  double Kd;
  // variable
  double err_tot;
  double err_pre;
  std_msgs::Float64 out;
  std_msgs::Float64 in;

  public:
    double des;
    // Input port
    RTT::InputPort<std_msgs::Float64> e_mes;
    // Output ports
    RTT::OutputPort<std_msgs::Float64> cmd;
    Controller(std::string const& name);
    bool configureHook();
    bool startHook();
    void updateHook();
    void stopHook();
    void cleanupHook();
};

class Moteur : public RTT::TaskContext{
private:
  // constante electrique
  double Ke;
  double R;
  double L;
  // constante mecanique
  double Kc;
  double J;
  double f;
  // constante big
  double A;
  double a11, a12, a21, a22, b1, b2;
  // attribut
  double i;
  double v;
  std_msgs::Float64 p;
  std_msgs::Float64 out;
  std_msgs::Float64 in;
public:
  RTT::InputPort<std_msgs::Float64> e_cmd;
  // Output ports
  RTT::OutputPort<std_msgs::Float64> pos;
  Moteur(std::string const& name);
  bool configureHook();
  bool startHook();
  void updateHook();
  void stopHook();
  void cleanupHook();
};
#endif
