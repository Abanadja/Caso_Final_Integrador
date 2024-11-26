//
// Created by alexa on 25/11/2024.
//

#include <iostream>
#include <string>
#include <fstream>

struct ColorConsole
{
    static constexpr auto fg_blue = "\033[34m";
    static constexpr auto bg_white = "\033[47m";
};

struct ConsoleBox
{
    void new_text() {/*...*/}
    void set_text(const std::string &text) { std::cout << text << std::endl; }
};

ConsoleBox *consoleBox = new ConsoleBox; // suponemos que ya está inicializado

void load_script(const char* filename, bool show_script = false)
{
    std::string script;
    std::ifstream file_stream(filename, std::ios::binary);
    if (!file_stream)
    {
        std::cerr << "Error de apertura de " << filename << std::endl;
        return;
    }

    try
    {
        std::string line;
        while (std::getline(file_stream, line))
        {
            script += line + '\n';
        }

        if (show_script)
        {
            std::cout << ColorConsole::fg_blue << ColorConsole::bg_white;
            std::cout << script << std::endl;
        }
        consoleBox->new_text();
        consoleBox->set_text(script);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error durante la lectura del archivo: " << e.what() << std::endl;
    }
}

void load_script()
{
    char filename[500];
    std::cout << "Archivo: ";
    std::cin.getline(filename, 500);
    load_script(filename, true);
}