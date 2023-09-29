#include "../Public/TJAMap.h"
#include "../Public/TJAParser.h"


vector<wstring> explode(const wstring& str, const char& ch) {
    wstring next;
    vector<wstring> result;

    // For each character in the string
    for (wstring::const_iterator it = str.begin(); it != str.end(); it++) {
        // If we've hit the terminal character
        if (*it == ch) {
            // If we have some characters accumulated
            if (!next.empty()) {
                // Add them to the result vector
                result.push_back(next);
                next.clear();
            }
        } else {
            // Accumulate the next character into the sequence
            next += *it;
        }
    }
    if (!next.empty())
         result.push_back(next);
    return result;
}


void TJAMap::parse_raw_mapdata()
{
    bool is_parsing_a_course = false;
    bool is_parsing_course_data = false;
    TJACourse* current_course = nullptr;
    for(auto line : raw_map_data)
    {
        int pos = -1;
        pos = line.find(L"COURSE:");
        if(pos != -1)
        {
            is_parsing_a_course = true;
        }

        if(!is_parsing_a_course)
        {
            pos = line.find(L"TITLE:");
            if(pos != -1 && map_title.length() <= 0)
            {
                printf("--------------------\n");
                printf("POSITION = %d \n", pos);
                wprintf(L"Data =  %s \n", line.erase(0, 6).c_str());
                map_title = line.c_str();
                wprintf(L"Title =  %s \n", map_title.c_str());
            }

            pos = line.find(L"SUBTITLE:");
            if(pos != -1 && map_subtitle.length() <= 0)
            {
                printf("--------------------\n");
                printf("POSITION = %d \n", pos);
                wprintf(L"Data =  %s \n", line.erase(0, 9).c_str());
                map_subtitle = line.c_str();
                wprintf(L"SUBTITLE =  %s \n", map_title.c_str());
            }

            pos = line.find(L"BPM:");
            if(pos != -1 && bpm <= 0)
            {
                printf("--------------------\n");
                float map_bpm = (float) _wtof(line.erase(0, 4).c_str());
                printf("POSITION = %d \n", pos);
                wprintf(L"Data =  %s \n", line.c_str());

                wprintf(L"BPM =  %f \n", map_bpm);
                bpm = map_bpm;
            }

            pos = line.find(L"WAVE:");
            if(pos != -1 && wave.length() <= 0)
            {
                printf("--------------------\n");
                printf("POSITION = %d \n", pos);
                wprintf(L"Data =  %s \n", line.erase(0, 5).c_str());
                wave = line.c_str();
                wprintf(L"WAVE =  %s \n", wave.c_str());
            }

            pos = line.find(L"OFFSET:");
            if(pos != -1 && offset < 0)
            {
                printf("--------------------\n");
                line.erase(0, 7);
                float map_offset =  (float) _wtof(line.c_str());
                printf("POSITION = %d \n", pos);
                wprintf(L"Data =  %s \n", line.c_str());

                wprintf(L"OFFSET =  %f \n", map_offset);
                offset = map_offset;
            }

            pos = line.find(L"GENRE:");
            if(pos != -1 && genre.length() <= 0)
            {
                printf("--------------------\n");
                printf("POSITION = %d \n", pos);
                wprintf(L"Data =  %s \n", line.erase(0, 6).c_str());
                genre = line.c_str();
                wprintf(L"GENRE =  %s \n", genre.c_str());
            }

            pos = line.find(L"SCOREMODE:");
            if(pos != -1 && scoremode < 0)
            {
                printf("--------------------\n");
                int map_scoremode = (int) _wtof(line.erase(0, 10).c_str());
                printf("POSITION = %d \n", pos);
                wprintf(L"Data =  %s \n", line.c_str());

                wprintf(L"SCOREMODE =  %d \n", map_scoremode);
                scoremode = map_scoremode;
            }

            pos = line.find(L"MAKER:");
            if(pos != -1 && maker.length() <= 0)
            {
                printf("--------------------\n");
                printf("POSITION = %d \n", pos);
                wprintf(L"Data =  %s \n", line.erase(0, 6).c_str());
                maker = line.c_str();
                wprintf(L"MAKER =  %s \n", maker.c_str());
            }

            pos = line.find(L"LYRICS:");
            if(pos != -1 && lyrics.length() <= 0)
            {
                printf("--------------------\n");
                printf("POSITION = %d \n", pos);
                wprintf(L"Data =  %s \n", line.erase(0, 7).c_str());
                lyrics = line.c_str();
                wprintf(L"LYRICS =  %s \n", lyrics.c_str());
            }

            pos = line.find(L"SONGVOL:");
            if(pos != -1 && song_vol < 0)
            {
                printf("--------------------\n");
                line.erase(0, 8);
                float current_song_vol = (float) _wtof(line.c_str());
                printf("POSITION = %d \n", pos);
                wprintf(L"Data =  %s \n", line.c_str());

                wprintf(L"SONGVOL =  %f \n", song_vol);
                song_vol = current_song_vol;
            }

            pos = line.find(L"SEVOL:");
            if(pos != -1 && se_vol < 0)
            {
                printf("--------------------\n");
                line.erase(0, 8);
                float current_se_vol =  (float) _wtof(line.c_str());
                printf("POSITION = %d \n", pos);
                wprintf(L"Data =  %s \n", line.c_str());

                wprintf(L"SONGVOL =  %f \n", se_vol);
                se_vol = current_se_vol;
            }
        }
        else
        {
            if(current_course == nullptr)
            {
                current_course = new TJACourse();
            }

            if(!is_parsing_course_data)
            {
                pos = line.find(L"COURSE:");
                if(pos != -1 && current_course->course_dif == map_difficulty::undefined)
                {
                    printf("--------------------\n");
                    printf("POSITION = %d \n", pos);
                    wprintf(L"Data =  %s \n", line.erase(0, 7).c_str());
                    current_course->course_dif = TJAParser::instance().parse_wstring_diff(line.c_str());
                    wprintf(L"COURSE =  %d \n", current_course->course_dif);
                }

                pos = line.find(L"LEVEL:");
                if(pos != -1 && current_course->level < 0)
                {
                    printf("--------------------\n");
                    int course_level = (int) _wtof(line.erase(0, 10).c_str());
                    printf("POSITION = %d \n", pos);
                    wprintf(L"Data =  %s \n", line.c_str());

                    wprintf(L"LEVEL =  %d \n", course_level);
                    current_course->level = course_level;
                }

                pos = line.find(L"BALLOON:");
                if(pos != -1 && current_course->balloon.size() <= 0)
                {
                    printf("--------------------\n");
                    int course_level = (int) _wtof(line.erase(0, 8).c_str());
                    printf("POSITION = %d \n", pos);
                    wprintf(L"Data =  %s \n", line.c_str());
                    vector<wstring> result = explode(line, ',');

                    for(auto str : result)
                    {
                        int current_balloon_level = (int) _wtof(str.c_str());
                        wprintf(L"DELIMITER %s \n", str.c_str());
                        current_course->balloon.push_back(current_balloon_level);
                    }
                    wprintf(L"BALLOON =  %d \n", course_level);
                }

                pos = line.find(L"SCOREINIT:");
                if(pos != -1 && current_course->score_init < 0)
                {
                    printf("--------------------\n");
                    int course_score_init = (int) _wtof(line.erase(0, 10).c_str());
                    printf("POSITION = %d \n", pos);
                    wprintf(L"Data =  %s \n", line.c_str());

                    wprintf(L"SCOREINIT =  %d \n", course_score_init);
                    current_course->score_init = course_score_init;
                }

                pos = line.find(L"SCOREDIFF:");
                if(pos != -1 && current_course->score_diff < 0)
                {
                    printf("--------------------\n");
                    int course_score_diff = (int) _wtof(line.erase(0, 10).c_str());
                    printf("POSITION = %d \n", pos);
                    wprintf(L"Data =  %s \n", line.c_str());

                    wprintf(L"SCOREDIFF =  %d \n", course_score_diff);
                    current_course->score_diff = course_score_diff;
                }
            }
            
            if(line == L"#START")
            {
                is_parsing_course_data = true;
            }
            if(line == L"#END")
            {
                printf("END Course \n");
                is_parsing_course_data = false;
                is_parsing_a_course = false;
                current_course->map_data.push_back(line.c_str());
                map_courses.push_back(current_course);
                current_course = nullptr;
                
            }

            if(is_parsing_course_data)
            {
                //wprintf(L"Data =  %s \n", line.c_str());
                current_course->map_data.push_back(line.c_str());
            }
        }
    }
}


