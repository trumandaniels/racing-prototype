/*
Author: Truman Daniels
Class: CS302
Program 2
Due 2/20/2023

Description: prototype file for all program data structures & vehicle objects
*/

#pragma once

#include <ostream>
#include <iostream>
#include <cstring>
#include <array>
#include <memory>
#include "exceptions.h"

using namespace std;

class Vehicle
{
    public:
        Vehicle();
        Vehicle(char * a_name, float a_base_mph, float a_curve_modifier, float a_off_road_modifier, float a_variance);
        ~Vehicle();
        Vehicle(const Vehicle&);

        friend bool operator!=(const Vehicle & obj1, const Vehicle & obj2);
        friend bool operator>(const Vehicle & obj1, const Vehicle & obj2); //which one has higher base mph
        friend float operator+(const Vehicle & obj1, const Vehicle & obj2); //averages mph
        friend ostream & operator <<(ostream& out, const Vehicle &obj);
        Vehicle &operator=(const Vehicle &);

        void display() const;
        
        char * get_name();
        float get_base_mph();
        float get_curve_modifier();
        float get_off_road_modifier();
        float get_variance();
        
    protected:
        char * name;
        int name_len;
        float base_mph;
        float curve_modifier;
        float off_road_modifier;
        float variance;
};

class Supercar: public Vehicle
{
    public:
        Supercar();
        Supercar(char * a_name, char * a_color, float a_base_mph, float a_curve_modifier, float a_off_road_modifier, float a_variance);
        ~Supercar();
        Supercar(const Supercar&);

        friend ostream & operator <<(ostream& out, const Supercar &obj);
        Supercar &operator=(const Supercar &);
    
        void display() const;

    protected:
        char * color;
        int color_len;        
};


class Motorcycle: public Vehicle
{
    public:
        Motorcycle();
        Motorcycle(char * a_name, string street_cred, float a_base_mph, float a_curve_modifier, float a_off_road_modifier, float a_variance);
        friend ostream & operator <<(ostream& out, const Motorcycle &obj);
        Motorcycle &operator=(const Motorcycle &);

    private:
        string street_cred;
};

class ATV: public Vehicle
{
    public:
        ATV();
        ATV(char * a_name, string a_fun_factor, float a_base_mph, float a_curve_modifier, float a_off_road_modifier, float a_variance);
        friend ostream & operator <<(ostream& out, const ATV &obj);
        ATV &operator=(const ATV &);

    private:
        string fun_factor;
};

template <typename T>
class TrackSegmentNode
{
    public:
        typedef TrackSegmentNode<T> * node_ptr_type;
        TrackSegmentNode<T>();
        TrackSegmentNode<T>(int a_seg_length, float a_curve_ratio, float a_off_road_ratio);
        ~TrackSegmentNode<T>(); 
        TrackSegmentNode<T>(const TrackSegmentNode<T>&);

        //GETTERS AND SETTERS
        TrackSegmentNode<T> *& get_next();
        TrackSegmentNode<T> *& get_prev();
        bool has_next() const;
        bool has_prev() const;
        void set_next(node_ptr_type node_thats_next);
        void set_prev(node_ptr_type node_thats_prev);
        
        int get_length() const;
        float get_curve_ratio() const;
        float get_off_road_ratio() const;
        

        float time_racer_through_segment(T& a_racer) const;
        void display() const;

        //declared here because I couldn't get this to work in template file
        friend ostream & operator <<(ostream& out, const TrackSegmentNode<T> &obj)
        {
            out << obj.length_miles << '\t' << obj.curve_ratio <<'\t'
                << obj.off_road_ratio; // no the job of the data type to format well, no endl
            return out;
        };

    private:
        node_ptr_type next;
        node_ptr_type prev;
        int length_miles;
        float curve_ratio; //between 0 and 1
        float off_road_ratio; //between 0 and 1
};


template <class T>
class Track
{
    public:
        typedef TrackSegmentNode<T> node_type;
        typedef node_type * node_ptr;
        Track<T>();
        ~Track<T>();

        void add_seg(int a_seg_length, float a_curve_ratio, float a_off_road_ratio);
        void del_all_nodes();

        float time_racer_through_track(T& a_racer, int num_loops);        

    protected:
        node_ptr start;
        void add_helper(int a_seg_length, float a_curve_ratio, float a_off_road_ratio, node_ptr& curr);
        void del_all_nodes_helper(node_ptr & curr_head);
};


template <class T>
class Race: public Track<T>
{
    public:
        void add_racer(const T car_to_race, int index);
        void run(int num_loops);
        bool check_racer_dup() const;
        Race& operator+=(const T car_to_race)
        {
            if (racer_array.at(0) == nullptr)
            {
                this->add_racer(car_to_race, 0);
            }
            else
            {
                this->add_racer(car_to_race, 1);
            }
        };

    private:
        array<T, 2> racer_array;
};

#include "structures.tpp"

