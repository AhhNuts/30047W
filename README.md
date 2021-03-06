# 30047W

The 30047W code for the Berkmar Vex team. It is developed and efficent for a simple stacker design. 

## Robot Configuration 
```c++
   [Name]               [Type]        [Port(s)]
   LF                   motor            8               
   LB                   motor            9               
   RF                   motor            3               
   RB                   motor            2                
   Controller1          controller                    
   SUCTION1             motor            10               
   SUCTION2             motor            1               
   TRAY                 motor            4                
   VISIONB              vision           5               
   VISIONA              vision           7         
```
## Game Strategy 
- Make sure the autonomous routine stacks the cubes then decide if the robot should be defensive or offensive depending on the sitation   of the other team(s). The team wants to focus on putting cubes on towers after stacking. The team should be aware of our teammates       situaton and help them if needed. We want to be a team that can play offensive, but also be a support if needed. 
## Pre-Auton 
* Simple GUI Faced interface: First with selecting team color then what auton routine to run.
## Autonomous
* Protected Side 
  - The robot to drive straight and turn 90 degrees to collect and stack a total of four blocks within the protective zone. 
* Unprotected Side
  - The program wires the robot to drive straight and collect four blocks- not including the preload (total five blocks)- and be able to go back to the goal zone and stack the blocks.
## Classes
* PID class
   - Useful to have for calculating the speed based on on the motor rotation so the robot can reach its target destination.
* Button Class
   - Useful to have button toggles and one time action buttons for the robot
## Drive Controls 
* Tray
  - Semi-automatic tray-control that decreases the speed in respect to the increase in position
* Drive Control
  - Uses Arcade Control
* Button Y
  - Uses Vision Sensor to center cubes
* Button X,A,B 
  - Changes the maxspeed of drive x - resets to 100 ; A - 50 ; B - 25
* Button Down
  - Resets Tray Position
## Future Plans
* Add the use of vision sensor to autonomous routine
* Create a useful skill routine
* Add new autonomous routine for a seven block stack on protected side 

## Built With

* [VEXcode V5 Text](https://www.vexrobotics.com/vexcode-download) - Main VEX Robotics IDE

## Authors

* **Calvin Tran** - Head Programmer - [AhhNuts](https://github.com/AhhNuts)

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE) file for details

## Acknowledgments

* Autonomous Routine (Unprotected) from WRCF China Finals with 3219U 


