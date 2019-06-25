# Feedback Controller for a Cassie Robot

This repository uses the Simulator and Realtime Simulink models from Agility Robotics. It contains a MATLAB/Simulink implementation of a basic feedback controller for the bipedal robot Cassie. The controller utilizes virtual constraints and gait libraries and it has been tested on Cassie Blue, Cassie Maize, and Cassie Cal on various terrains including indoor, outdoor environments, and terrains covered with snow, or grass. What you might expect from this basic controller can be found in the following videos:
 
- Cassie Blue and Associated Press. https://youtu.be/h6hnfCo4a00. Accessed: 2018-09-12.                   
- Cassie Blue at the UM Dental School. https://youtu.be/jhQMq6vpnAo. Accessed: 2018-09-12.                
- Cassie Blue Hones Her Segway Riding Skills. https://youtu.be/0gauVSUJzd0. Accessed: 2018-09-12.      
- Cassie Blue Plays in the Sand. https://youtu.be/VoD7hbssu-M. Accessed: 2018-09-12.       
- Cassie Blue Summary Video. https://youtu.be/UhXly-5tEkc. Accessed: 2018-09-14.      
- Cassie Blue Walks Through Fire. https://youtu.be/cGb3bE6ZwrQ. Accessed: 2018-09-12.       
- Cassie Maize Walks With a Gantry. https://youtu.be/oYjAS9AoxHI. Accessed: 2018-12-06.         
- Feedback Control on Cassie Cal using the control described in https://arxiv.org/abs/1809.07279 https://youtu.be/LUxr1u760so Accessed 2019-01-16

The details of the controller’s design and implementation are explained in: “Feedback Control of a Cassie Bipedal Robot: Walking, Standing, and Riding a Segway " (arxiv.org/abs/1809.07279). Please cite this paper and the GitHub site if you use the open-source code (the BibTeX entry is located at the bottom of the README).
 

## Running the controller in Simulink simulation:
0. Use MATLAB 2017b. If you use MATLAB 2018, you need to modify the solver from auto to ode45
1. Download this repository and execute the script "start_up.m" to add all functions needed to the MATLAB searchable path.
2. Open “\Controllers\Flatground\FG_Simulator.slx” and run the simulation. This will automatically open Matlab's mechanics explorer and show animations after compiling.
3. Optional：before doing the parameter tuning on your physical robot, you could play with the control parameters in the simulation. You can open "Controllers\Flatground\utils\+PreFunctions\ParamInit.m” and adjust the parameters there to see how they affect the robot’s closed-loop motion in simulation.
  
## Preparations for the online tuning:

While the Cassie robots are quite similar to one another, they have been modified throughout their production run. Hence, some tuning for your robot may be required. In order to achieve more robust performance during walking and standing, please follow the instructions below for the parameter tuning process.

1. Set up the development PC according to the instructions in the following link: https://github.com/agilityrobotics/agility-cassie-doc/wiki/Setting-Up-Development-PC.
2. Follow the instructions on the Agility Robotics’ Website (https://github.com/agilityrobotics/agility-cassie-doc/wiki/Creating-Standalone-Application) to make a USB standalone controller using the Simulink RealTime model (FG_RealTime_2.slx) located at “\Controllers\Flatground\ ... “. We recommend using 'Microsoft Visual C++ 2015 Professional' as the default compiler to ensure a proper build.
3. Carefully tether the robot to a gantry or safety cable. Plug in the standalone USB controller, perform the startup procedure and then the homing procedure. Suspend the robot so that hips are approximately 1 meter high while keeping Cassie's feet on the ground. Make sure the SB switch on the radio controller is in the middle position (standing controller) and then enable the power by turning on the SA switch (move it up). The motor torques will ramp up gradually over a 10 second window. If Cassie does not stand up as expected, try to gradually adjust the left slider (LS) on the radio controller to tune the desired leg length until Cassie can balance itself. The following assumes that balancing is achieved. Else, go back and check your calibration and/or the motor commutation. The Center of Mass of your robot should definitely be within the support polygon of the downloaded controller.
4. Plug in the Ethernet cable and then open Simulink Real-Time explorer by typing slrtexplr in the MATLAB command window.
5. Run the script (addTargetPC.m) stored in the Shortcuts folder to add CassieV3 to the targets.
6. Right-click CassieV3 and then select connect. The indicator will turn green if the connection has been established successfully.
7. Click the File-open-instrument Panel and select the file (InstrumentPanel1.slrtip) located at “Controllers\Flatground\utils\3\...”. Then run the instrument panel by clicking the run button on the upper-left corner. All of the default values for the tunable gains will pop up automatically.

## Radio Function Description

Walk Controller

| Command | Description |
|:-:|:-:|
| LV | Move in Longitudinal direction |
| LH | Move in Lateral direction |
| RH | Change yaw angle (turnning) |
| S1 | Adjust drifting in Longitudinal direction |
| SA | Emergency Stop |
| SB | Switch Controller, (-1, 0) standing, (+1) walking|

Stand Controller

| Command | Description |
|:-:|:-:|
| RV | Torso pitch |
| RH | Move torso in lateral direction |
| S2 | Adjust COM position |
| LS | Adjust Leg length |
| SA | Emergency Stop |
| SB | Switch Controller, (-1, 0) standing, (+1) walking|


## Tuning the standing controller on Cassie’s hardware to improve disturbance rejection:
1. The estimated Center of Mass position in the controller may be inaccurate due to variation in the Cassie robots. To adjust the estimated Center of Mass, adjust the parameter stand_offset in the instrument panel until the readings in Channels 6 and 7 become 0. Increasing the stand_offset will decrease the readings in Channels 6 and 7. It is recommended to change the offset in increments of 0.01 or 0.005. 
2. Go to the right side of the panel and find the section called PD gain on joints (stand)
3. You can tune the proportional gain (Kp) and derivative gain (Kd) for each joint by left-clicking the corresponding box and typing the desired values. The typed value will be sent to the hardware immediately after you move the cursor out of the box by left-clicking anywhere else on the panel.
4. Initially,  push the robot gently. If the pelvis falls forward or backward very easily, try to increase the values of Kp and Kd for each joint. If the toes tilt up or down very often, try reducing the proportional gain for the toe joints. 
5. If the motors are vibrating, try reducing the values of the derivative gains. 
 
## Tuning the walking controller on Cassie hardware:
1. With the robot still attached to a safety cable, you can transition from the standing controller to the walking controller by setting the SB switch up. The robot will start to step in place.
2. If the robot is drifting to one side or turning to one direction, try to tune the values in the offset section: reduce the value of sagittal_offset if the robot is stepping backwards; reduce the value of lateral_offset if it is drifting to the right side; and increase the turning_offset if Cassie is turning to the left.
3. Next, adjust the PD gains in the oot placement section to stabilize the walking speed. If Cassie oscillates back and forth in the sagittal plane, reduce the value of Kp and increase the value of Kd in the Kfs row. If Cassie cannot reject disturbances in the lateral direction,  increase the value of Kd in the Kfl row. Occasionally, if the PD gains for the lateral foot placement are too aggressive, the swing leg may interfere with the stance leg when moving inwards. You might gradually reduce the value abduction_inward_gain to avoid such situations.
4. During walking, if Cassie's feet hammer on the ground very hard, try to gradually increase the value knee_compensation in the compensation section.
 
## Tuning walking standing switch controllers on Cassie robot:
1. In order to switch from standing to stepping, Cassie will always shift its center of mass position to the left side and then lifts its right leg first. Try to tune the value of shift_distance in the walking standing switch section to achieve more robust switching behavior. If the robot falls to the right side very often after its first step, try to increase shift_distance. If the robot leans to the left sides, try to decrease shift_distance instead.
2. When switching to the stance controller from walking, several more values should be properly adjusted. These include the four values listed in the walking standing switch section. When the switching command is sent out, Cassie will not stop stepping immediately. The robot will keep walking for one or two steps depending on when the switch command is received. During this period of time, Cassie will adjust its stance and swing leg abduction angles and prepare for standing. If Cassie oscillates after switching to the standing controller, try to tune the value of final_sw_abduction and final_st_abduction to adjust the distance between the two feet during stance to reduce the oscillation.
 
After all the parameters have been properly adjusted, save all the changes to the "Controllers\Flatground\utils\+PreFunctions\ParamInit.m" script. Then build the standalone USB controller again following the procedures given in the preparation section. These values should be loaded automatically to the updated standalone controller.
 


## Related literature:
* Feedback Control of a Cassie Bipedal Robot: Walking, Standing, and Riding a Segway, by Yukai Gong, Ross Hartley, Xingye Da, Ayonga Hereid, Omar Harib, Jiunn-Kai Huang, and Jessy W. Grizzle. arxiv.org/abs/1809.07279
```
@misc{1809.07279,
Author = {Yukai Gong and Ross Hartley and Xingye Da and Ayonga Hereid and Omar Harib and Jiunn-Kai Huang and Jessy Grizzle},
Title = {Feedback Control of a Cassie Bipedal Robot: Walking, Standing, and Riding a Segway},
Year = {2018},
Eprint = {arXiv:1809.07279},
}
```

* The official Agility Robotics Cassie documentation and software release repository.

https://github.com/agilityrobotics/agility-cassie-doc

