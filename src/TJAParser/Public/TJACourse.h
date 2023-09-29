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
        map_difficulty course_dif = map_difficulty::undefined;
        int level;
        vector<int> balloon;
        int score_init;
        int score_diff;

        //Map Data
        vector<wstring> map_data;





};