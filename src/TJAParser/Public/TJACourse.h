#pragma once
#include "TJAUtility.h"
#include <vector>
#include <string>

using namespace std;
class TJACourse 
{
    public:
        TJACourse(){}
        ~TJACourse(){}

        //Metadata
        map_difficulty course_dif;
        vector<int> balloon;
        int score_init;
        int score_diff;

        //Map Data
        vector<string> map_data;





};