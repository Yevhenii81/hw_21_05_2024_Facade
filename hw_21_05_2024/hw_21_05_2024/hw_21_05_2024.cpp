#include <iostream>
using namespace std;

class Lighting
{
    int level = 0;
public:
    void TurnOn()
    {
        cout << "Light is on\n";
    }

    void TurnOff()
    {
        level = 0;
        cout << "Light is off\n";
    }

    void Customization(int levelLight)
    {
        level = levelLight;
    }
};

class ClimateControl
{
    double temperature = 20;
public:
    void SetTemperature(double temperature)
    {
        this->temperature = temperature;
    }

    void TurnOnConditioner()
    {
        cout << "Conditioner is on\n";
    }

    void TurnOffConditioner()
    {
        cout << "Conditioner is off\n";
    }
};

class SecutirySystem
{
    string password = " ";
public:
    void SetPassword(string password)
    {
        this->password = password;
    }

    void Condition(string password)
    {
        if (this->password != password)
        {
            cout << "Error\n";
        }
        else
        {
            cout << "Welcome!\n";
        }
    }

    void CloseWindows()
    {
        cout << "Windows are clossed\n";
    }

    void CloseDoor()
    {
        cout << "Door is closed\n";
    }
};

class Multimedia
{
    double volume = 0;
public:
    void SetVolume(double volume)
    {
        this->volume = volume;
    }

    void TurnOnTv()
    {
        cout << "TV is on\n";
    }

    void TurnOffTV()
    {
        cout << "TV is off\n";
    }
};

class SmartHouse
{
    Lighting* lighting;
    ClimateControl* control;
    SecutirySystem* security;
    Multimedia* multimedia;
public:
    SmartHouse(string password)
    {
        lighting = new Lighting;
        control = new ClimateControl;
        security = new SecutirySystem;
        multimedia = new Multimedia;
        security->SetPassword(password);
    }

    void GoodMorning() {
        lighting->Customization(25);
        lighting->TurnOn();
        security->CloseWindows();
        control->SetTemperature(22);
        control->TurnOnConditioner();
        multimedia->SetVolume(25);
        multimedia->TurnOnTv();
    }

    void GoodNight() {
        multimedia->TurnOffTV();
        control->SetTemperature(19);
        control->TurnOnConditioner();
        security->CloseDoor();
        security->CloseWindows();
        lighting->TurnOff();
    }

    void LeavingHome() {
        multimedia->TurnOffTV();
        security->CloseDoor();
        security->CloseWindows();
        lighting->TurnOff();
        control->SetTemperature(22);
        control->TurnOnConditioner();
    }

    void ComeHome(string password) {
        security->Condition(password);
        multimedia->TurnOnTv();
        multimedia->SetVolume(50);
        lighting->Customization(76);
        lighting->TurnOn();
        security->CloseDoor();
    }
};

int main()
{
    SmartHouse house("111111");
    house.ComeHome("111111");
    cout << "\\\\\\\\\\\\\\\\";
    house.GoodNight();
}