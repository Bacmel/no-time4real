# TP3 Real Time : OROCOS & ROS

*Practical Work on **OROCOS** and **ROS**.*

*Statement : [*main-tp3-1.pdf*](main-tp3-1.pdf) (in french)*

## 2) OROCOS : Develop a motor controller

### Question 2.1

*Draw of a Controller for Orientation Control*

![Alt text](pictures/sadt.png?raw=true "SADT Controller")

with :

- current orientation (*mesure*) ;
- desired orientation (*des*) ;
- control voltage (cmd).

### Questions 2.2 & 2.3

To create a package we first need to create a workspace.
To do that we first need to source
```sh
source /opt/ros/melodic/setup.bash
```
Then we create our workspace
```sh
mkdir -p TR_ws/src
cd TR_ws/src
```
We initialise our workspace
```sh
catkin_init_workspace
```
We build it : from here all commands are done in the first layer of our workspace (in TR_ws)
```sh
cd .. 
catkin_make
```
And finally we add our workspace in orocos by sourcing the devel, this command need to be done after each 'catkin_make' 
```sh
source devel/setup.bash
```
Now we can create our package 'MyTask' in the folder src of our workspace with the command
```sh
orocreate-catkin-pkg MyTask component
```
A *.cpp and *.hpp file are generated automaticly when creating our package, they already have the minimal skeleton. A constructor and 5 basical functions are already present in them.

- updateHook
- startHook
- configureHook
- stopHook
- cleanupHook

After building the component we need now to load it in the deployer in order to use it.For that we need to use the command
```sh
deployer-gnulinux
```
Once we are in the deployer we can use the commands below
```cpp
import("MyTask") //add MyTask in the list of components
displayComponentTypes() //To see if MyTask was added as a component
loadComponent("task","MyTask") //create a component task of type MyTask
task.configure() //Use the function configureHook() on task
```

### Question 2.4

For this question we want to write in the orocos logs every time we use the basic functions. It is very easy we just need to include <rtt/RTT.hpp> and add this line in each function
```cpp
log(Info) << "Text" <<endlog();
```
After building, loading and writing in the deployer we can go check the log file present in the first layer of our workspace, we can read our prints at the end of thee file.

### Question 2.5

Inside the *MyTask-component.hpp*, we add the library for the ports and define the ports and attribut in public :

```cpp
#include <rtt/Port.h>
...
public:
    // Define ports and attribut
    inputPort<double> mesure;
    outputPort<double> cmd;
    double des;
```

Inside the constructor in *MyTask-component.cpp*, we add all the ports and attribut to the component :

```cpp
...
Mytask(string name) : TaskContext(name) {
    ...
    // Add ports and attribut to the component
    this->ports()->addPort("mesure", mesure).doc("Input Port for mesure");
    this->ports()->addPort("cmd", cmd).doc("Output Port for command");
    this->addAttribut("des", des);
```

### Question 2.6

In order to make different components in the same file :

- We define all the components class in the same **cpp** and **hpp** files ;
- We add at the end of the **cpp** file `ORO_LIST_COMPONENT_TYPE(NAME_COMPONENT)`, with the name of the component, for each of them.

Now we can use them in the deployer with the command below 
```cpp
import("MyTask") //add MyTask in the list of components
loadComponent("task","MyTask") //create a component task of type MyTask
loadComponent("task2","MyTask2") //create a component task2 of type MyTask2
task.configure() //Use the function configureHook() on task
task.configure() //Use the function configureHook() on task2
```

### Question 2.7

We can of course automatize the process above by writing all the commands that we wrote in the deployer in a script that we called start.ops. To load our components and execute our code we only need to type in the terminal 
```
deployer-gnulinux -s path/to/script/star.ops
```
Our path/to/script = src/MyTask/src

### Question 2.8

*Now we work on **MyTask_controller.cpp** and **MyTask_controller.hpp** and **startC.ops**.

The first component we define is the **Controller**. It has :

- A `public InputPort<double>` e_mes ;
- A `public OutputPort<double>` cmd ;
- A `public double` des ;
- And all the constants and variable to implement a **PID**.

Inside the *updateHook* is define the **PID** function :
```cpp
 void Controller::updateHook(){
  ...
  while (e_mes.read(in)){
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
    cmd.write(out);
    ...
```

The second component we define is the **Moteur**. It has :

- A `public InputPort<double>` e_cmd ;
- A `public OutputPort<double>` pos ;
- And all the constants and variable to implement a **DCM**.

Inside the *updateHook* is define the **DCM** function :
```cpp
void Moteur::updateHook(){
  ...
  while (e_cmd.read(in)){
    std::cout<< "cmd="<<in.data<<std::endl;
    ni = a11*i+a12*v+b1*in.data;
    nv = a21*i+a22*v+b2*in.data;
    p.data += nv*Te;
    i = ni;
    v = nv;
    out.data=p.data;
    pos.write(out);
    std::cout<< "position="<<p<<std::endl;
  }
  ...
```
To run the code we need to load the **startC.ops** script in the deployer

### Question 2.9

In order to read the messages in ROS we need to use std_mgs::Float64 type for our input and output ports. Moreover we need to add some dependencies in our **package.xml** 
```
  <build_depend>rtt_ros</build_depend>
  <build_depend>std_msgs</build_depend>
  <build_depend>ocl</build_depend>

  <run_depend>rtt_ros</run_depend>
  <run_depend>std_msgs</run_depend>
  <build_depend>ocl</build_depend>
```
and to add our packages in **CmakeList.txt** file
```
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs)
```
We import the needed packages in our deployer by writting them in the **.ops** file
```
import("rtt_ros")
import("rtt_std_msgs")
import("rtt_roscomm")
import("rtt_rosnode")
```
We finally streamall the data we want on specific topics.
```
//topics 
stream("moteur.pos", ros.comm.topic("/position"))
stream("controleur.cmd", ros.comm.topic("/commande"))
```

## Related Documents

- [The Orocos Component Builder's Manual](https://www.orocos.org/stable/documentation/rtt/v2.x/doc-xml/orocos-components-manual.html)
- [TikZ Examples](https://texample.net/tikz/examples/)
