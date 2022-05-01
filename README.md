# Parking-System
## Question
Design a low-level parking system using C++
### Assumptions
1. It is a multilevel parking system with 4 levels (Ground Floor, Basement 1, Basement 2, Basement 3)
2. The parking system has spaces for 3 different types of vehicles (light, standard, heavy)
3. Capacity: light - 100; standard - 220; heavy - 80
4. A vehicle of one type can only be parked in its respective spot
5. Parking of vehicles start from ground floor

## Working
The parking system is implemented using a class called 'parking'
The class contains 4 private members: light, standard, heavy, and total.
Each of these members represent the number of vehicles of that type currently parked in the parking lot.
There are 4 public member functions:
1. `void parking::parkVehicle(int type)`
This function parks a vehicle. It first checks if a spot for that vehicle type is available or not. If it is available, the vehicle is parked in it and the value of respective variable is incrememted by one.
If parking space is not available, vehicle cannot be parked and the message is diaplayed.

2. `int parking::available(int type)`
This function checks whether a parking spot for a particular vehicle type is available or not and returns 1 or 0 depending on the result.

3. `void parking::removeVehicle(int type)`
This function removes a vehicle from the parking lot. It first checks if such a vehicle is present or not. If it is present, the variable for that vehicle is decremented by one. It no such vehicle is present, a suitable message is displayed.

4. `void parking::Number_of_empty_spots()`
This function displays the number of parking spaces left for each type of vehicle.

The main function asks the user what task needs to be done and calls the appropriate function. User can exit by pressing 0
