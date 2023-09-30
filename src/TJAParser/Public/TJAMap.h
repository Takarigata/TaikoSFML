#pragma once
#include <vector>
#include <string>
#include "TJACourse.h"


struct note_timing  
{
    float note_time;
    note_type current_note_type;
    int note_count;

};


using namespace std;
class TJAMap 
{
    public:
        TJAMap(){}
        ~TJAMap(){}

        vector<std::wstring> raw_map_data;

        void parse_raw_mapdata();

        void parse_diff(map_difficulty diff_to_parse);

        vector<TJACourse*> map_courses;
        
        vector<note_timing> current_note_vector;



        //Metadata
        wstring map_title;
        wstring map_subtitle;
        float bpm;
        wstring wave;
        float offset;
        float demo_start;
        wstring genre;
        int scoremode;
        wstring maker;
        wstring lyrics;
        float song_vol;
        float se_vol;
        int side;
        int life;
        wstring game;
        float head_scroll;
        wstring bg_movie;
        float movie_offset;
        wstring taiko_web_skin;

};