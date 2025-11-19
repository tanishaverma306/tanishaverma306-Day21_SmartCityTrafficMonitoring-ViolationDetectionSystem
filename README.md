Highway Vehicle Monitoring System (C Program)
This project is a beginner-friendly C program that monitors up to 30 vehicles passing through a highway checkpoint. It uses only numeric data, 1D arrays, loops, and functions, following all restrictions such as no strings, no structs, no pointers, and no user-defined types.
Features
Input and validate:
4-digit Vehicle ID
Positive Speed
Lane number (1–4)
Detect speed violations (speed > 80 km/h)
Detect lane violations using:
VehicleID % 4 != lane
Find:
Highest and lowest speed
Vehicle with most severe lane violation
Traffic density analysis using a laneCount array
Generates a complete tabular report
Requirements
Only <stdio.h> allowed
No advanced data types
Use of loops, conditions, arrays, and functions is mandatory
Functions Implemented
void inputData(...)
int countSpeedViolations(...)
int countLaneViolations(...)
int busiestLane(...)
int leastBusyLane(...)
void displayReport(...)
How It Works
The program stores vehicle IDs, speeds, and lane numbers in separate arrays.
It processes the data using simple loops and conditions to identify violations, count lane traffic, and determine speed statistics.
Finally, it prints a clear report for all vehicles.
Output
The final report includes:
VehID   Speed   Lane   SpeedV   LaneV
Along with overall statistics for the checkpoint.
Purpose
This project helps beginners practice:
Array handling
Input validation
Modular programming with functions
Logical problem solving
