/*
Author: Truman Daniels
Class: CS302
Program 2
Due 2/20/2023

Description: prototype defined exceptions classes 
*/

#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;


class NotThatManySegments : public runtime_error
{
    public:
        NotThatManySegments(const char* what): runtime_error(what) {}
};

class NoData : public runtime_error
{
    public:
        NoData(const char* what): runtime_error(what) {}
};

class IllegalTrack : public runtime_error
{
    public:
        IllegalTrack(const char* what): runtime_error(what) {}
};

class IllegalCar : public runtime_error
{
    public:
        IllegalCar(const char* what): runtime_error(what) {}
};
