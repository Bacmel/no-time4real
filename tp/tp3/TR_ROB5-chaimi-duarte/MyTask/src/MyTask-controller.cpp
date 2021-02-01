#include "MyTask-controller.hpp"


using namespace std;
using namespace RTT;
using namespace Orocos;


Controller::Controller(std::string const& name) : TaskContext(name),Kp(0.4),Ki(0.4),max(100),Kd(0.2),err_tot(0.0),err_pre(0.0),e_mes("e_mes"),cmd("cmd"),des(1.57){

  std::cout << "Controller constructed !" <<std::endl;
  this->ports()->addEventPort( "e_mes",e_mes ).doc( "Event Mesure" );
  this->ports()->addPort( "cmd", cmd ).doc( "Commande" );
  this->addAttribute( "des", des);

 }

 bool Controller::configureHook(){
  std::cout << "Controller configured !" <<std::endl;
  log(Info) << "configure Hook !" <<endlog();

  return this->setPeriod(0.01);
 }

 bool Controller::startHook(){
  std::cout << "Controller started !" <<std::endl;
  log(Info) << "start Hook!" <<endlog();
  return true;
 }

 void Controller::updateHook(){
  double e;
  double Te = this->getPeriod();
  double de;
  std_msgs::Float64 out;
  std_msgs::Float64 in;

  if(e_mes.read(in)){
    std::cout<< "mes="<<in.data <<std::endl;
    e = des-in.data;
    err_tot += e*Te;
    if(err_tot > max) {
      err_tot = max;
    }else if(err_tot < max){
      err_tot = -max;

    }
    de = (e-err_pre)/Te;
    out.data = Kp*e+Ki*err_tot+Kd*de;
    err_pre=e;
  }
  cmd.write(out);
 }

 void Controller::stopHook() {
  std::cout << "Controller executes stopping !" <<std::endl;
  log(Info) << "stop Hook !" <<endlog();
 }

 void Controller::cleanupHook() {
  std::cout << "Controller cleaning up !" <<std::endl;
  log(Info) << "cleanup Hook !" <<endlog();
 }



Moteur::Moteur(std::string const& name) : TaskContext(name),Ke(1/(182*(3.14/30))),R(2.03),L(0), Kc(52.5*0.001),J(72.3*0.0000001),f(0.0), i(0.0),v(0.0),e_cmd("e_cmd"),pos("pos"){

  std::cout << "Moteur constructed !" <<std::endl;
  double Te = this->getPeriod();
  // Big Constants (Calculs once)
  A = (Ke*Kc+(f+J/Te)*(R+L/Te));
  a11 = ((f+J/Te)*L/Te)/A;
  a12 = (-Ke*J/Te)/A;
  a21 = (Kc*L/Te)/A;
  a22 = ((R+L/Te)*J/Te)/A;
  b1 = (f+J/Te)/A;
  b2 = Kc/A;
  this->ports()->addEventPort("e_cmd", e_cmd ).doc( "Event Commande" );
  this->ports()->addPort( "pos", pos ).doc( "Position" );

 }

bool Moteur::configureHook(){
  std::cout << "Moteur configured !" <<std::endl;
  log(Info) << "Configure Hook !" <<endlog();
  return this->setPeriod(0.01);
 }

bool Moteur::startHook(){
  std::cout << "Moteur started !" <<std::endl;
  log(Info) << "start Hook!" <<endlog();
  // Check validity of (all) Ports:
  return true;
 }

void Moteur::updateHook(){
  double ni;
  double nv;
  double Te= this->getPeriod();
  std_msgs::Float64 out;
  std_msgs::Float64 in;
  if (e_cmd.read(in)){
    std::cout<< "cmd="<<in.data<<std::endl;
    ni = a11*i+a12*v+b1*in.data;
    nv = a21*i+a22*v+b2*in.data;
    p.data += nv*Te;
    i = ni;
    v = nv;
  }
  out.data=p.data;
  pos.write(out);
  std::cout<< "position="<<p<<std::endl;
}

void Moteur::stopHook() {
  std::cout << "Moteur executes stopping !" <<std::endl;
  log(Info) << "stop Hook !" <<endlog();
 }

void Moteur::cleanupHook() {
  std::cout << "Moteur cleaning up !" <<std::endl;
  log(Info) << "cleanup Hook !" <<endlog();
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
//ORO_CREATE_COMPONENT_LIBRARY()
ORO_LIST_COMPONENT_TYPE(Controller)
ORO_LIST_COMPONENT_TYPE(Moteur)
