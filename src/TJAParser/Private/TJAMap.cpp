#include "../Public/TJAMap.h"
#include "../Public/TJAParser.h"

//WIP Parsing is wip for now it can be greatly optimized
vector<wstring> explode(const wstring& str, const char& ch) {
    wstring next;
    vector<wstring> result;

    for (wstring::const_iterator it = str.begin(); it != str.end(); it++) {
        if (*it == ch) {
            if (!next.empty()) {
                result.push_back(next);
                next.clear();
            }
        } else {
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
                current_course->map_data.push_back(line.c_str());
            }
        }
    }
}

float calculate_measure(float part, float beat)
{
    return (part / beat);
}

note_type parse_note_type(wstring in_note)
{
    if(in_note == L"1")
    {
        return note_type::don;
    }

    if(in_note == L"2")
    {
        return note_type::ka;
    }

    if(in_note == L"3")
    {
        return note_type::big_don;
    }

    if(in_note == L"4")
    {
        return note_type::big_ka;
    }
    return note_type::blank;
}
void TJAMap::parse_diff(map_difficulty diff_to_parse)
{
    float part = 4;
    float beat  = 4;
    float globaltime = 0;
    int current_note_count = 0;
    for(auto diff : map_courses)
    {
        if(diff_to_parse == diff->course_dif)
        {
            for(auto tmp_course_data : diff->map_data)
            {
                wstring course_data = tmp_course_data.c_str();


                printf("PARSING NEW LINE  ----------- \n");
                
                if(course_data.find(L'#') == -1 && course_data.find(L',') != -1)
                {
                    //WIP Magic Formula to implement correctly with sub measure and bpm for each note
                    // # Compute the change in fumenOffset (i.e. the duration of the measure)
                    // measureSize = measureTJA['time_sig'][0] / measureTJA['time_sig'][1]
                    // measureLength = measureTJA['pos_end'] - measureTJA['pos_start']
                    // measureRatio = 1.0 if measureTJA['subdivisions'] == 0.0 else (measureLength / measureTJA['subdivisions'])
                    // measureDuration = (4 * 60_000 * measureSize * measureRatio / measureTJA['bpm'])
                    // # The following adjustment accounts for mid-measure BPM changes, where the measure is split into "sub-measures"
                    // # (!!! Discovered by tana :3 !!!)
                    // if measureRatio != 1.0:
                    //     measureDuration -= (4 * 60_000 * ((1 / tja['measures'][idx_m+1]['bpm']) - (1 / measureTJA['bpm'])))
                    //course_data.erase(remove(course_data.begin(), course_data.end(), L','), course_data.end());
                    wprintf(L"SELECTED NOTE Raw Data =  %s \n", course_data.c_str());
                    int postest = course_data.find(L",");
                    course_data = course_data.substr(0, postest).c_str();
                     wprintf(L"SELECTED NOTE  Data =  %s \n", course_data.c_str());
                    float current_measure = 4 * 60000 * calculate_measure(part, beat) * 1 / bpm;
                    globaltime += current_measure;

                    if(course_data.length() > 0)
                    {
                        std::vector<std::wstring> characterArray;
                        for (wchar_t character : course_data) 
                        {
                            std::wstring singleChar(1, character);
                            characterArray.push_back(singleChar);
                        }

                        for(int i = 0; i < characterArray.size() - 1; i++)
                        {
                            wstring character = characterArray[i];
                            if(character == L"1" || character == L"2" || character == L"3" || character == L"4")
                            {
                                note_timing current_note;
                                current_note.note_time = (globaltime + ((current_measure / characterArray.size()) * (i + 1)));
                                current_note.current_note_type = parse_note_type(character);
                                current_note.note_count = current_note_count;
                                current_note_count++;
                                current_note_vector.push_back(current_note);
                            }
                        }
                    }
                    
                    wprintf(L"SELECTED NOTE Data =  %s And LEN = %d  and measure time = %f global = %f\n", course_data.c_str(), course_data.length(), current_measure, globaltime);
                }
                else
                {
                    if(course_data.find(L"#MEASURE") != -1)
                    {
                        course_data.erase(0, 9);
                        vector<wstring> result = explode(course_data, '/');
                        for(auto explo : result)
                        {
                            wprintf(L"RESULT =  %s len = %d \n", explo.c_str(), explo.length());
                        }
                        part = (float) _wtof(result[0].c_str());
                        beat = (float) _wtof(result[1].c_str());
                        wprintf(L"NEW MEASURE =  %f / %f \n", part, beat);
                    }

                    if(course_data.find(L"#BPMCHANGE") != -1)
                    {
                        course_data.erase(0, 11);
                        bpm = (float) _wtof(course_data.c_str());
                        wprintf(L"NEWBPM =  %f \n", bpm);
                        //139000
                        //126 000
                        // 2 min 19
                        // 2 min 03
                    }
                }
            }
        }
    }
    wprintf(L"END TIMER =  %f \n", globaltime);

}


