#include "MyTask-component.hpp"
#include <rtt/Component.hpp>
#include <iostream>

using namespace std;
using namespace RTT;
using namespace Orocos;


  MyTask::MyTask(std::string const& name) : TaskContext(name){
  std::cout << "MyTask constructed !" <<std::endl;
  this->ports()->addPort( "mes", mes ).doc( "Mesure" );
  this->ports()->addPort( "cmd", cmd ).doc( "Commande" );
  this->addAttribute( "des", des);
 }

  bool MyTask::configureHook(){
  std::cout << "MyTask configured !" <<std::endl;
  log(Info) << "configure Hook !" <<endlog();
  return this->setPeriod(1);
 }

  bool MyTask::startHook(){
  std::cout << "MyTask started !" <<std::endl;
  log(Info) << "start Hook!" <<endlog();
  return true;
 }

  void MyTask::updateHook(){
  std::cout << "MyTask executes updateHook !" <<std::endl;
  log(Info) << "update Hook !" <<endlog();
 }

  void MyTask::stopHook() {
  std::cout << "MyTask executes stopping !" <<std::endl;
  log(Info) << "stop Hook !" <<endlog();
 }

  void MyTask::cleanupHook() {
  std::cout << "MyTask cleaning up !" <<std::endl;
  log(Info) << "cleanup Hook !" <<endlog();
 }



  MyTask2::MyTask2(std::string const& name) : TaskContext(name){
  std::cout << "MyTask2 constructed !" <<std::endl;
  this->ports()->addPort( "mes", mes ).doc( "Mesure" );
  this->ports()->addPort( "cmd", cmd ).doc( "Commande" );
  this->addAttribute( "des", des);
 }

  bool MyTask2::configureHook(){
  std::cout << "MyTask2 configured !" <<std::endl;
  log(Info) << "configure2 Hook !" <<endlog();
  return this->setPeriod(1);
 }

  bool MyTask2::startHook(){
  std::cout << "MyTask2 started !" <<std::endl;
  log(Info) << "start2 Hook!" <<endlog();
  return true;
 }

  void MyTask2::updateHook(){
  std::cout << "MyTask2 executes updateHook !" <<std::endl;
  log(Info) << "update2 Hook !" <<endlog();
 }

  void MyTask2::stopHook() {
  std::cout << "MyTask2 executes stopping !" <<std::endl;
  log(Info) << "stop2 Hook !" <<endlog();
 }

  void MyTask2::cleanupHook() {
  std::cout << "MyTask2 cleaning up !" <<std::endl;
  log(Info) << "cleanup2 Hook !" <<endlog();
 }


/*
 * Using this macro, only one component may live
 * in one library *and* you may *not* link this library
 * with another component library. Use
 * ORO_CREATE_COMPONENT_TYPE()
 * ORO_LIST_COMPONENT_TYPE(MyTask)
 * In case you want to link with another library that
 * already contains components.
 *
 * If you have put your component class
 * in a namespace, don't forget to add it here too:
 */
ORO_CREATE_COMPONENT_LIBRARY()
ORO_LIST_COMPONENT_TYPE(MyTask)
ORO_LIST_COMPONENT_TYPE(MyTask2)
