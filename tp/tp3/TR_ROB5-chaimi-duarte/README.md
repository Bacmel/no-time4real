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
mkdir -p TR-ws/src
cd TR-ws/src
```
We initialise our workspace
```sh
catkin_init_workspace
```
We build it
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

- We define all the component class in the same **cpp** and **hpp** files ;
- We add at the end of the **cpp** file `ORO_LIST_COMPONENT_TYPE(NAME_COMPONENT)`, with the name of the component, for each of them.

### Question 2.7



### Question 2.8

*Now we work on **MyTask_controller.cpp** and **MyTask_controller.hpp**.*

The first component we define is the **Controleur**. It has :

- A `public InputPort<double>` mesure ;
- A `public OutputPort<double>` cmd ;
- A `public double` des ;
- And all the constants and variable to implement a **PID**.

Inside the *updateHook* is define the **PID** function :
```cpp
// Copy from code
```

The second component we define is the **Moteur**. It has :

- A `public InputPort<double>` cmd ;
- A `public OutputPort<double>` position ;
- And all the constants and variable to implement a **DCM**.

Inside the *updateHook* is define the **PID** function :
```cpp
// Copy from code
```

### Question 2.9


## Related Documents

- [The Orocos Component Builder's Manual](https://www.orocos.org/stable/documentation/rtt/v2.x/doc-xml/orocos-components-manual.html)
- [TikZ Examples](https://texample.net/tikz/examples/)