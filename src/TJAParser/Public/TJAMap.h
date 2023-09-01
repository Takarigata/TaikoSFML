#pragma once
#include <vector>
#include <string>
#include "TJACourse.h"

using namespace std;
class TJAMap 
{
    public:
        TJAMap(){}
        ~TJAMap(){}

        vector<TJACourse> map_courses;

        //Metadata
        string map_title;
        string map_subtitle;
        int bpm;
        string wave;
        float offset;
        float demo_start;
        string genre;
        int scoremode;
        string maker;
        string lyrics;
        float song_vol;
        float se_vol;
        int side;
        int life;
        string game;
        float head_scroll;
        string bg_movie;
        float movie_offset;
        string taiko_web_skin;

};