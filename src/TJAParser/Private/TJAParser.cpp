#include "../Public/TJAParser.h"
//#pragma execution_character_set( "utf-8" )
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
    }

    // Now you have your Shift-JIS encoded file contents in 'lines'

    // Remember to close the file when done
    file.close();

    // You can access the lines as needed
    for (const std::wstring& s : lines) {
        std::wcout << s << std::endl;
    }

    return out;
}