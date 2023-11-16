/*
Author: Truman Daniels
Class: CS302
Program 2
Due 2/20/2023

Description: file to test the program/use features
*/

#include "racing.h"

#include <ostream>
#include <iostream>
#include <cstring>

using namespace std;

int main()
/*
Description:
Runs program with a neat interface
*/
{   
    int user_input;
    bool quit = false;
    
    while (quit == false)
    {
        cout << "What would you like to do?" << endl;
        cout << "1. Run Race" << endl;
        cout << "2. Quit" << endl;
        cin >> user_input;
        switch (user_input) 
        {
            case 1 : //race
                {   
                    cout << "What Type of Vehicle?" << endl;
                    cout << "1. Supercar" << endl;
                    cout << "2. Motorcycle" << endl;
                    cout << "3. ATV" << endl;
                    cin >> user_input;
                    switch (user_input) 
                    {
                        case 1 :
                            {
                                Race<Supercar> my_race;
                                //add two cars to track
                                for(int i=0; i<2; i++)
                                {
                                    cout << "Pick a supercar " << i << endl;
                                    cout << "1. Lamborghini Murcielago" << endl;
                                    cout << "2. Ferrari Testarossa" << endl;
                                    cout << "3. Nissan Skyline R32" << endl;
                                    cout << "4. Make New" << endl;
                                    cin >> user_input;
                                    switch (user_input) 
                                    {
                                        case 1 : 
                                        {
                                            Supercar my_super("Lamborghini Murcielago", "Green", 180, 0.9, 0.15, 0.2);
                                            my_race.add_racer(my_super, i);
                                            break;
                                        }
                                        case 2 : 
                                        {
                                            Supercar my_super("Ferrari Testarossa", "Red", 165, 0.8, 0.2, 0.2);
                                            my_race.add_racer(my_super, i);
                                            break;
                                        }
                                        case 3 : 
                                        {
                                            Supercar my_super("Nissan Skyline R32", "Red", 195, 0.75, 0.15, 0.2);
                                            my_race.add_racer(my_super, i);
                                            break;
                                        }
                                        case 4 : 
                                        {
                                            char in_name[250], in_color[250]; 
                                            float in_mph, in_or_mod, in_curve_mod;
                                            cout << "Give your supercar a name" << endl;
                                            cin >> in_name;
                                            cout << "Give your supercar a color" << endl;
                                            cin >> in_color;
                                            cout << "Top speed? (Miles Per Hour)" << endl;
                                            cin >> in_mph;
                                            cout << "Curve modifier? (Between 0-1)" << endl;
                                            cin >> in_curve_mod;
                                            cout << "Off Road modifier? (Between 0-1)" << endl;
                                            cin >> in_or_mod;
                                            Supercar my_super(in_name, in_color, in_mph, in_curve_mod, in_or_mod, 0.2);
                                            my_race.add_racer(my_super, i);
                                            break;
                                        }
                                    }
                                }
                                cout << "Course Type?" << endl;
                                cout << "1. Straight" << endl;
                                cout << "2. Off Road" << endl;
                                cout << "3. Curvy" << endl;
                                cin >> user_input;
                                switch (user_input) 
                                {
                                    case 1 :
                                    {
                                        my_race.add_seg(10, 0.05, 0);
                                        my_race.add_seg(10, 0, 0);
                                        my_race.add_seg(10, 0.05, 0);
                                        break;
                                    }
                                    case 2 :
                                    {
                                        my_race.add_seg(10, 0.25, 0.5);
                                        my_race.add_seg(10, 0.2, 0.5);
                                        my_race.add_seg(10, 0.25, 0.5);
                                        break;
                                    }
                                    case 3 :
                                    {
                                        my_race.add_seg(10, 0.7, 0.1);
                                        my_race.add_seg(10, 0.5, 0.1);
                                        my_race.add_seg(10, 0.7, 0.1);
                                        break;
                                    }
                                }
                                cout << "How many loops?" << endl;
                                cin >> user_input;

                                my_race.run(user_input);
                                break;
                            }
                        case 2 :
                            {
                                Race<Motorcycle> my_race;
                                //add two cars to track
                                for(int i=0; i<2; i++)
                                {
                                    cout << "Pick a motorcycle " << i << endl;
                                    cout << "1. Harley Davidson Low Rider" << endl;
                                    cout << "2. Yamaha R6" << endl;
                                    cout << "3. Honda CB750" << endl;
                                    cout << "4. Make New" << endl;
                                    cin >> user_input;
                                    switch (user_input) 
                                    {
                                        case 1 : 
                                        {
                                            Motorcycle my_super("Harley Davidson Low Rider", "Very Street", 80, 0.3, 0.3, 0.2);
                                            my_race.add_racer(my_super, i);
                                            break;
                                        }
                                        case 2 : 
                                        {
                                            Motorcycle my_super("Yamaha R6", "Piano Street", 165, 0.6, 0.15, 0.2);
                                            my_race.add_racer(my_super, i);
                                            break;
                                        }
                                        case 3 : 
                                        {
                                            Motorcycle my_super("Honda CB750", "Sweet Noise", 65, 0.75, 0.3, 0.2);
                                            my_race.add_racer(my_super, i);
                                            break;
                                        }
                                        case 4 : 
                                        {
                                            char in_name[250], in_streetcred[250]; 
                                            float in_mph, in_or_mod, in_curve_mod;
                                            cout << "Give your motorcycle a name" << endl;
                                            cin >> in_name;
                                            cout << "Give your motorcycle a street cred" << endl;
                                            cin >> in_streetcred;
                                            cout << "Top speed? (Miles Per Hour)" << endl;
                                            cin >> in_mph;
                                            cout << "Curve modifier? (Between 0-1)" << endl;
                                            cin >> in_curve_mod;
                                            cout << "Off Road modifier? (Between 0-1)" << endl;
                                            cin >> in_or_mod;
                                            Motorcycle my_super(in_name, in_streetcred, in_mph, in_curve_mod, in_or_mod, 0.2);
                                            my_race.add_racer(my_super, i);
                                            break;
                                        }
                                    }
                                }
                                cout << "Course Type?" << endl;
                                cout << "1. Straight" << endl;
                                cout << "2. Off Road" << endl;
                                cout << "3. Curvy" << endl;
                                cin >> user_input;
                                switch (user_input) 
                                {
                                    case 1 :
                                    {
                                        my_race.add_seg(10, 0.05, 0);
                                        my_race.add_seg(10, 0, 0);
                                        my_race.add_seg(10, 0.05, 0);
                                        break;
                                    }
                                    case 2 :
                                    {
                                        my_race.add_seg(10, 0.25, 0.5);
                                        my_race.add_seg(10, 0.2, 0.5);
                                        my_race.add_seg(10, 0.25, 0.5);
                                        break;
                                    }
                                    case 3 :
                                    {
                                        my_race.add_seg(10, 0.7, 0.1);
                                        my_race.add_seg(10, 0.5, 0.1);
                                        my_race.add_seg(10, 0.7, 0.1);
                                        break;
                                    }
                                }
                                cout << "How many loops?" << endl;
                                cin >> user_input;

                                my_race.run(user_input);
                                break;
                            }
                        case 3 :
                            {
                                Race<ATV> my_race;
                                //add two cars to track
                                for(int i=0; i<2; i++)
                                {
                                    cout << "Pick an ATV" << i << endl;
                                    cout << "1. Yamaha Raptor" << endl;
                                    cout << "2. Honda TRX250X" << endl;
                                    cout << "3. Souped Up Golfer" << endl;
                                    cout << "4. Make New" << endl;
                                    cin >> user_input;
                                    switch (user_input) 
                                    {
                                        case 1 : 
                                        {
                                            ATV my_super("Yamaha Raptor", "High", 85, 0.65, 0.85, 0.2);
                                            my_race.add_racer(my_super, i);
                                            break;
                                        }
                                        case 2 : 
                                        {
                                            ATV my_super("Honda TRX250X", "Medium", 75, 0.6, 0.9, 0.2);
                                            my_race.add_racer(my_super, i);
                                            break;
                                        }
                                        case 3 : 
                                        {
                                            ATV my_super("Souped Up Golfer", "Low", 35, 0.5, 0.35, 0.2);
                                            my_race.add_racer(my_super, i);
                                            break;
                                        }
                                        case 4 : 
                                        {
                                            char in_name[250], in_fun_fact[250]; 
                                            float in_mph, in_or_mod, in_curve_mod;
                                            cout << "Give your ATV a name" << endl;
                                            cin >> in_name;
                                            cout << "Give your ATV a fun factor" << endl;
                                            cin >> in_fun_fact;
                                            cout << "Top speed? (Miles Per Hour)" << endl;
                                            cin >> in_mph;
                                            cout << "Curve modifier? (Between 0-1)" << endl;
                                            cin >> in_curve_mod;
                                            cout << "Off Road modifier? (Between 0-1)" << endl;
                                            cin >> in_or_mod;
                                            ATV my_super(in_name, in_fun_fact, in_mph, in_curve_mod, in_or_mod, 0.2);
                                            my_race.add_racer(my_super, i);
                                            break;
                                        }
                                    }
                                }
                                cout << "Course Type?" << endl;
                                cout << "1. Straight" << endl;
                                cout << "2. Off Road" << endl;
                                cout << "3. Curvy" << endl;
                                cin >> user_input;
                                switch (user_input) 
                                {
                                    case 1 :
                                    {
                                        my_race.add_seg(10, 0.05, 0);
                                        my_race.add_seg(10, 0, 0);
                                        my_race.add_seg(10, 0.05, 0);
                                        break;
                                    }
                                    case 2 :
                                    {
                                        my_race.add_seg(10, 0.25, 0.5);
                                        my_race.add_seg(10, 0.2, 0.5);
                                        my_race.add_seg(10, 0.25, 0.5);
                                        break;
                                    }
                                    case 3 :
                                    {
                                        my_race.add_seg(10, 0.7, 0.1);
                                        my_race.add_seg(10, 0.5, 0.1);
                                        my_race.add_seg(10, 0.7, 0.1);
                                        break;
                                    }
                                }
                                cout << "How many loops?" << endl;
                                cin >> user_input;

                                my_race.run(user_input);
                                break;
                            }
                        default:
                            {
                            cout << "Not a recognized input, please try again" << endl;
                            break;
                            }
                    }
                break;
                }
            case 2 :
                {
                quit = true;
                break;
                }
            default:
                {
                cout << "Not a recognized input, please try again" << endl;
                break;
                }
        }
    }

    return 0;
};
