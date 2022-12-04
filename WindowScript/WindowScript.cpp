
#include <windows.h>
#include <iostream>

#include <SDL.h>
#include <SDL_Image.h>

SDL_Window *   cWindow;
SDL_Renderer * cRender;

const uint16_t nScreenWidth = NULL;
const uint16_t nScreenHeight = NULL;

size_t _copy_file(const char * _file, FILE *_f, FILE *_fw){
    fopen_s(&_f, _file, "rb" );
    fopen_s(&_fw, "window.config", "wb");
    fseek  (_f, 0, SEEK_END );
    size_t size_of_file = ftell(_f);
    char * buffer       = new char[size_of_file];

    /* fread(the buffer to read into, size of a single element, size of the buffer, the allocated FILE class instance) */
    fread(buffer, sizeof(char), size_of_file, _f);
    std::cout << buffer;

    fseek(_fw, 0, SEEK_SET);
    fwrite(buffer, sizeof(char), size_of_file, _fw);

    return size_of_file;
    delete[] buffer;
}

inline void start(const char * _file, FILE *_f, FILE *_fw){
	const size_t size_of_file = _copy_file(_file, _f, _fw);

    std::cout << "\n\nconfiguration process finished! press ESC to close..." << std::endl;
	while(1){ if(GetAsyncKeyState(VK_ESCAPE & 0x1B)) break; }
}


int main(int s, char * z[]){

    FILE *f;
    FILE *fw;
    const char * file = "window.config";
    start(file, f, fw);

    fclose(f);
    fclose(fw);

    return 0;
}