/*
Author: Truman Daniels
Class: CS302
Program 2
Due 2/20/2023

Description: implementation file for the Vehicle implementations
*/

#include "racing.h"
#include "exceptions.h"

#include <ostream>
#include <iostream>
#include <cstring>

using namespace std;


Vehicle::Vehicle(): name(nullptr), name_len(0), base_mph(0), curve_modifier(1), off_road_modifier(1), variance(0)
{
}


Vehicle::Vehicle(char * a_name, float a_base_mph, float a_curve_modifier, float a_off_road_modifier, float a_variance): name(a_name), name_len(0), 
base_mph(a_base_mph), curve_modifier(a_curve_modifier), off_road_modifier(a_off_road_modifier), variance(a_variance)
{   
    if (curve_modifier <= 0 || off_road_modifier <= 0)
    {
        throw IllegalCar("Modifiers must be > 0");
    }

    name = nullptr;
    name_len = strlen(a_name);
    name = new char[name_len+1];
    strcpy(name, a_name);

    // need to go in and do exception detection, e.g. if null
    if (name_len == 0)
    {
        throw NoData("Vehicle is missing a name.");
    }
}

Vehicle::Vehicle(const Vehicle &obj) //copy constructor
{
    this->name = nullptr;
    this->name_len = obj.name_len;
    this->name = new char[obj.name_len+1];
    strcpy(this->name, obj.name);

    this->base_mph = obj.base_mph;
    this->curve_modifier = obj.curve_modifier;
    this->off_road_modifier = obj.off_road_modifier;
}   

Vehicle::~Vehicle()
{
    if (name)
    {
        delete [] name;
    }
}

char * Vehicle::get_name()
{
    return this->name;
}

float Vehicle::get_base_mph()
{
    return this->base_mph;
}

float Vehicle::get_curve_modifier()
{
    return this->curve_modifier;
}

float Vehicle::get_off_road_modifier()
{
    return this->off_road_modifier;
}

float Vehicle::get_variance()
{
    return this->variance;
}

ostream & operator <<(ostream& out, const Vehicle &obj)
{
    out << obj.name << '\t' << obj.base_mph <<'\t'
        << obj.curve_modifier  <<'\t' << obj.off_road_modifier; // no the job of the data type to format well, no endl
    return out;
}

Vehicle & Vehicle::operator=(const Vehicle & rs)
{
    //check self assignment
    if (this == &rs)  
    {
        return *this;
    }
    if (name)
    {
        delete [] name;
    }
    this->name = new char [rs.name_len +1];
    strcpy(this->name, rs.name);
    this->name_len = rs.name_len;
    this->base_mph = rs.base_mph;
    this->curve_modifier = rs.curve_modifier;
    this->off_road_modifier = rs.off_road_modifier;
    return *this;
}

bool operator!=(const Vehicle & obj1, const Vehicle & obj2)
/*
Comparision only checks name and base_mph
*/
{
    bool temp;
    temp = obj1.name==obj2.name && obj1.base_mph==obj2.base_mph;
    return !temp;
}

bool operator>(const Vehicle & obj1, const Vehicle & obj2)
/*
Comparision only applies to base_mph
*/
{
    bool temp;
    temp = obj1.base_mph>obj2.base_mph;
    return temp;
}

float operator+(const Vehicle & obj1, const Vehicle & obj2)
/*
Returns average of base_mph of vehcile objects
*/
{
    float avg;
    avg = (obj1.base_mph + obj2.base_mph)/2;
    return avg;
}

Supercar::Supercar(): Vehicle(), color(nullptr), color_len(0)
{
}


Supercar::Supercar(char * a_name, char * a_color, float a_base_mph, float a_curve_modifier, float a_off_road_modifier, float a_variance): Vehicle(a_name, a_base_mph, a_curve_modifier, a_off_road_modifier, a_variance), 
color(nullptr), color_len(0)
{   
    color = nullptr;
    color_len = strlen(a_color);
    color = new char[color_len+1];
    strcpy(color, a_color);
}

Supercar::Supercar(const Supercar &obj) //copy constructor
{
    this->name = nullptr;
    this->name_len = obj.name_len;
    this->name = new char[obj.name_len+1];
    strcpy(this->name, obj.name);

    this->color = nullptr;
    this->color_len = obj.color_len;
    this->color = new char[obj.color_len+1];
    strcpy(this->color, obj.color);

    this->base_mph = obj.base_mph;
    this->curve_modifier = obj.curve_modifier;
    this->off_road_modifier = obj.off_road_modifier;
}


Supercar::~Supercar()
{
    if (color)
    {
        delete [] color;
    }
}

ostream & operator <<(ostream& out, const Supercar &obj)
{
    out << obj.name << '\t' << obj.color << '\t' << obj.base_mph <<'\t'
        << obj.curve_modifier  <<'\t' << obj.off_road_modifier; // no the job of the data type to format well, no endl
    return out;
}

Supercar & Supercar::operator=(const Supercar & rs)
{
    //check self assignment
    if (this == &rs)  
    {
        return *this;
    }
    if (name)
    {
        delete [] name;
    }
    this->name = new char [rs.name_len +1];
    strcpy(this->name, rs.name);
    this->name_len = rs.name_len;

    if (color)
    {
        delete [] color;
    }
    color = new char [rs.color_len+1];
    strcpy(color, rs.color);
    color_len = rs.color_len;

    this->base_mph = rs.base_mph;
    this->curve_modifier = rs.curve_modifier;
    this->off_road_modifier = rs.off_road_modifier;

    return *this;
}

Motorcycle::Motorcycle(): Vehicle(), street_cred("")
{
}

Motorcycle::Motorcycle(char * a_name, string a_street_cred, float a_base_mph, float a_curve_modifier, float a_off_road_modifier, float a_variance): Vehicle(a_name, a_base_mph, a_curve_modifier, a_off_road_modifier, a_variance), street_cred(a_street_cred)
{
}

Motorcycle & Motorcycle::operator=(const Motorcycle & rs)
{
    //check self assignment
    if (this == &rs)  
    {
        return *this;
    }
    if (name)
    {
        delete [] name;
    }
    this->name = new char [rs.name_len +1];
    strcpy(this->name, rs.name);
    this->name_len = rs.name_len;

    this->street_cred = rs.street_cred;
    this->base_mph = rs.base_mph;
    this->curve_modifier = rs.curve_modifier;
    this->off_road_modifier = rs.off_road_modifier;

    return *this;
}

ostream & operator <<(ostream& out, const Motorcycle &obj)
{
    out << obj.name << '\t' << obj.street_cred << '\t' << obj.base_mph <<'\t'
        << obj.curve_modifier  <<'\t' << obj.off_road_modifier; // no the job of the data type to format well, no endl
    return out;
}


ATV::ATV(): Vehicle(), fun_factor("")
{
}

ATV::ATV(char * a_name, string a_fun_factor, float a_base_mph, float a_curve_modifier, float a_off_road_modifier, float a_variance): Vehicle(a_name, a_base_mph, a_curve_modifier, a_off_road_modifier, a_variance), fun_factor(a_fun_factor)
{
}

ATV & ATV::operator=(const ATV & rs)
{
    //check self assignment
    if (this == &rs)  
    {
        return *this;
    }
    if (name)
    {
        delete [] name;
    }
    this->name = new char [rs.name_len +1];
    strcpy(this->name, rs.name);
    this->name_len = rs.name_len;

    this->fun_factor = rs.fun_factor;
    this->base_mph = rs.base_mph;
    this->curve_modifier = rs.curve_modifier;
    this->off_road_modifier = rs.off_road_modifier;

    return *this;
}

ostream & operator <<(ostream& out, const ATV &obj)
{
    out << obj.name << '\t' << obj.fun_factor << '\t' << obj.base_mph <<'\t'
        << obj.curve_modifier  <<'\t' << obj.off_road_modifier; // no the job of the data type to format well, no endl
    return out;
}
