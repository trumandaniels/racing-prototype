/*
Author: Truman Daniels
Class: CS302
Program 2
Due 2/20/2023

Description: implementation file for the data structures (Track Nodes, Track, Races) implementations
*/

#pragma once
#include <iostream>
#include "exceptions.h"

using namespace std;


template <class T>
TrackSegmentNode<T>::TrackSegmentNode(): next(nullptr), prev(nullptr), length_miles(0), curve_ratio(0), off_road_ratio(0)
{
}

template <class T>
TrackSegmentNode<T>::TrackSegmentNode(int a_seg_length, float a_curve_ratio, float a_off_road_ratio): next(nullptr), prev(nullptr), length_miles(a_seg_length), curve_ratio(a_curve_ratio), off_road_ratio(a_off_road_ratio)
{
    if (curve_ratio > 1 || off_road_ratio > 1)
    {
        throw  IllegalTrack("Ratios must be at most 1");
    }
    if (curve_ratio < 0 || off_road_ratio < 0)
    {
        throw  IllegalTrack("Ratios cannot be negative");
    }
    if (length_miles < 0)
    {
        throw  IllegalTrack("Track cannot be negative in length");
    }
}

template <class T>
TrackSegmentNode<T>::~TrackSegmentNode() 
{
}

template <class T>
void TrackSegmentNode<T>::set_next(node_ptr_type node_thats_next)
{
    this->next = node_thats_next;
}

template <class T>
void TrackSegmentNode<T>::set_prev(node_ptr_type node_thats_prev)
{
    this->prev = node_thats_prev;
}

template <class T>
int TrackSegmentNode<T>::get_length() const
{
    return length_miles;
}

template <class T>
float TrackSegmentNode<T>::get_curve_ratio() const
{
    return curve_ratio;
}

template <class T>
float TrackSegmentNode<T>::get_off_road_ratio() const
{
    return off_road_ratio;
}

template <class T>
TrackSegmentNode<T> *& TrackSegmentNode<T>::get_next()
{
    return this->next;
}

template <class T>
TrackSegmentNode<T> *& TrackSegmentNode<T>::get_prev()
{
    return this->prev;
}

template <class T>
bool TrackSegmentNode<T>::has_next() const
{
    if (this->next == nullptr)
    {
        return false;
    }
    else
    {
        return true;
    }
}

template <class T>
bool TrackSegmentNode<T>::has_prev() const
{
    if (this->prev == nullptr)
    {
        return false;
    }
    else
    {
        return true;
    }
}

template <class T>
void TrackSegmentNode<T>::display() const
{
    cout << "Track Segment: " 
    << "Total Miles " << length_miles 
    << ", Curve Ratio " << curve_ratio 
    << ", Off Road Ratio " << off_road_ratio << endl;
}

template <class T>
float TrackSegmentNode<T>::time_racer_through_segment(T& a_racer) const
/*
Description: Times a Racer through a single segment
Logic: Curve ratio describes entire course, off road shares with "normal" road
Variance logic not implemented yet"
*/
{
    float time, miles_per_minute, normal_dist, off_road_dist; 
    
    miles_per_minute = a_racer.get_base_mph()/60;

    off_road_dist = this->length_miles * off_road_ratio;
    normal_dist = this->length_miles - off_road_dist;

    time = (1-curve_ratio*a_racer.get_curve_modifier())*(normal_dist/miles_per_minute + off_road_dist/(miles_per_minute*a_racer.get_off_road_modifier()));

    //a_racer.variance();
    //time = += variance    

    return time;
}



template <class T>
Track<T>::Track(): start(nullptr)
{
}

template <class T>
void Track<T>::add_seg(int a_seg_length, float a_curve_ratio, float a_off_road_ratio)
/*
Description: public recursive function that adds a segment to the track DLL
*/
{
    //if list is empty
    if (start == nullptr)
    {
        node_ptr new_node = new TrackSegmentNode<T>(a_seg_length, a_curve_ratio, a_off_road_ratio);
        start = new_node;
        start->set_next(nullptr);
        start->set_prev(nullptr);
    }
    
    //add to end of the list
    else 
    {
        return add_helper(a_seg_length, a_curve_ratio, a_off_road_ratio, start);
    }
}

template <class T>
void Track<T>::add_helper(int a_seg_length, float a_curve_ratio, float a_off_road_ratio, node_ptr & curr)
/*
Description: private recursive function that adds a segment to the track DLL
*/
{
    //if there's another element in front
    if (curr->has_next() == true)
    {
        return add_helper(a_seg_length, a_curve_ratio, a_off_road_ratio, curr->get_next());
    }
    //we've reached end of list
    else
    {
        node_ptr new_node = new TrackSegmentNode<T>(a_seg_length, a_curve_ratio, a_off_road_ratio);
        curr->set_next(new_node);
        new_node->set_next(nullptr);
        new_node->set_prev(curr);
    }
}

template <class T>
void Track<T>::del_all_nodes()
/*
Description: public recursive function that deletes all segments in the track DLL
(Used in the destructor)
*/
{
    if (start == nullptr)
    {
        throw NoData("No segments in Track to delete");
    }
    else
    {
        del_all_nodes_helper(start);
        start = nullptr;
    }
}

template <class T>
void Track<T>::del_all_nodes_helper(node_ptr & curr_head)
/*
Description: private recursive function that deletes all segments in the track DLL
*/
{
    if (curr_head->has_next())
    {
        del_all_nodes_helper(curr_head->get_next()); 
    }
    delete curr_head;
}

template <class T>
Track<T>::~Track() 
{
    if (this->start != nullptr)
    {
        this->del_all_nodes();
    }
}

template <class T>
float Track<T>::time_racer_through_track(T& a_racer, int num_loops)
/*
Description: times a single racer through the entire course
*/
{
    if (start==nullptr)
    {
        throw NoData("There are no segments in the track to race.");
    }

    float total_time;
    node_ptr curr;
    int num_loops_done = 0;

    curr = this->start;

    for (int i=0; i<num_loops; i++)
    {
        //forward pass
        curr = this->start;
        
        while (curr->has_next()==true)
        {
            total_time += curr->time_racer_through_segment(a_racer);
            curr = curr->get_next();
        }

        //backwards pass
        while(curr->has_prev()==true)
        {
            total_time += curr->time_racer_through_segment(a_racer);
            curr = curr->get_prev();
        }
    }
    return total_time;
}



template <class T>
void Race<T>::add_racer(const T car_to_race, int index)
/*
Description: adds a single racer to the track
at a specified index (in the array, either 0 or 1 for two person array)
*/
{
    racer_array.at(index) = car_to_race;
}

template <class T>
bool Race<T>::check_racer_dup() const
/*
Description: checks if racers are duplicate cars,
note: will only work if n=2
*/
{
    if (!(racer_array.at(0) != racer_array.at(1)))
    {
        //duplicate
        return true;
    }
    else
    {   
        //no duplicate
        return false;
    }
}

template <class T>
void Race<T>::run(int num_loops)
/*
Description: Times both racers, and displays winner
*/
{
    cout << "Track - Num Loops: " << num_loops << endl;
    cout << "Vehicle " << racer_array.at(0).get_name() << " took " << this->time_racer_through_track(racer_array.at(0), num_loops) << " minutes." << endl;
    cout << "Vehicle " << racer_array.at(1).get_name() << " took " << this->time_racer_through_track(racer_array.at(1), num_loops) << " minutes." << endl;
}

