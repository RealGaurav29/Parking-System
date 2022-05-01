#include<iostream>
using namespace std;

class parking
{
    private:
    int heavy;
    int standard;
    int light;
    int total;
    int floor_status[4];

    public:
    parking();
    void parkVehicle(int type);
    void removeVehicle(int type);
    int available(int type);   //type = 1 for light, 2 for standard, 3 for heavy
    void Number_of_empty_spots();
};

int main()
{
    parking p;
    int choice;
    cout << "\nMultilevel Parking System\n------------------------------------------";

    do
    {
        cout << "\n1. Park a vehicle";
        cout << "\n2. Remove a vehicle";
        cout << "\n3. Enquire number of empty spots";
        cout << "\n0. Exit";
        cout << "\nChoose: ";
        cin >> choice;

        switch(choice)
        {
            int type;
            case 1: cout << "\nWhat type of vehicle you want to park:-";
                    cout << "\n1 -> Light (2-wheelers and 3-wheelers)";
                    cout << "\n2 -> Standard (cars)";
                    cout << "\n3 -> Heavy (Trucks, buses, etc)";
                    cout << "\nEnter: ";
                    cin >> type;
                    p.parkVehicle(type);
                    break;
            case 2: cout << "\nWhat type of vehicle you want to remove:-";
                    cout << "\n1 -> Light (2-wheelers and 3-wheelers)";
                    cout << "\n2 -> Standard (cars)";
                    cout << "\n3 -> Heavy (Trucks, buses, etc)";
                    cout << "\nEnter: ";
                    cin >> type;
                    p.removeVehicle(type);
                    break;
            case 3: p.Number_of_empty_spots();
                    break;
            case 0: break;
            default: cout << "\nInvalid Input. Choose Again";
        }
    } while(choice != 0);
    
    return 0;
}

parking::parking()
{
    heavy = 0;
    standard = 0;
    light = 0;
    total = 0;
    for(int i = 0; i < 4; i++)
        floor_status[i] = 0;  
}

int parking::available(int type)
{
    if(type == 1)
    {
        if(light < 100)
            return 1;
        return 0;
    }
    else if(type == 2)
    {
        if(standard < 220)
            return 1;
        return 0;
    }
    else if(type == 3)
    {
        if(heavy < 80)
            return 1;
        return 0;
    }
    else
    {
        cout << "\nInvalid type of vehicle";
        return 0;
    }
}

void parking::parkVehicle(int type)
{
    int status;
    status = available(type);
    if(status == 1)
    {
        int which_floor = total/10;
        if(which_floor == 0)
            cout << "\nVehicle parked on Ground Floor\n";
        else if(which_floor == 1)
            cout << "\nVehicle parked in Basement 1\n";
        else if(which_floor == 2)
            cout << "\nVehicle parked in Basement 2\n";
        else
            cout << "\nVehicle parked in Basement 3\n";
        total++;
        if(type == 1)
            light++;
        else if(type == 2)
            standard++;
        else if(type == 3)
            heavy++;
    }
    else
    {
        if(type == 1)
            cout << "\nNo more parking space left for light vehicles\n";
        else if(type == 2)
            cout << "\nNo more parking space left for standard cars\n";
        else if(type == 3)
            cout << "\nNo more parking space left for heavy vehicles\n";
    }
}

void parking::removeVehicle(int type)
{
    if(type == 1)
    {
        if(light > 0)
        {    
            cout << "\nLight Vehicle removed\n";
            light--;
        }
        else
            cout << "\nNo light vehicle in parking lot\n";
    }
    if(type == 2)
    {
        if(standard > 0)
        {
            cout << "\nStandard Vehicle removed\n";
            standard--;
        }
        else
            cout << "\nNo standard vehicle in parking lot\n";
    }
    if(type == 3)
    {
        if(heavy > 0)
        {    
            cout << "\nHeavy Vehicle removed\n";
            heavy--;
        }
        else
            cout << "\nNo heavy vehicle in parking lot\n";
    }
}

void parking::Number_of_empty_spots()
{
    cout << "\nNo. of light vehicle spaces left: " << 100 - light;
    cout << "\nNo. of standard vehicle spaces left: " << 220 - standard;
    cout << "\nNo. of heavy vehicle spaces left: " << 80 - heavy << endl;
}