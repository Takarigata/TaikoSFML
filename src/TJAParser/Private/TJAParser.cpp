#include "../Public/TJAParser.h"

TJAMap* TJAParser::ParseTJAMap(std::string& file_path)
{
    
    TJAMap* out = new TJAMap();
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t, 0x10FFFF, std::consume_header>> converter;
    std::wstring widePath = converter.from_bytes(file_path);
    std::wifstream file(widePath);
     std::locale utf8_locale(std::locale(), new std::codecvt_utf8_utf16<wchar_t, 0x10FFFF, std::consume_header>);
     file.imbue(utf8_locale);

    if (!file.is_open()) {
        std::cerr << "Failed to open the file!" << std::endl;
        return out;
    }

    // Create a vector to store the lines
    std::vector<std::wstring> lines;

    // Read the file line by line
    std::wstring line;
    while (std::getline(file, line)) {
        lines.push_back(line);
        out->raw_map_data.push_back(line);
    }

    // Now you have your Shift-JIS encoded file contents in 'lines'

    // Remember to close the file when done
    file.close();

    out->parse_raw_mapdata();
    return out;
}

map_difficulty TJAParser::parse_wstring_diff(std::wstring in_diff)
{
    if(in_diff == L"Easy" || in_diff == L"0")
    {
        return map_difficulty::easy;
    }

    if(in_diff == L"Normal" || in_diff == L"1")
    {
        return map_difficulty::normal;
    }

    if(in_diff == L"Hard" || in_diff == L"2")
    {
        return map_difficulty::hard;
    }

    if(in_diff == L"Oni" || in_diff == L"3")
    {
        return map_difficulty::oni;
    }

    if(in_diff == L"Edit" || in_diff == L"4" || in_diff == L"Ura")
    {
        return map_difficulty::tower;
    }
    return map_difficulty::undefined;
}