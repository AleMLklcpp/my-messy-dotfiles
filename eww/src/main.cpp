#include <iostream>
#include <thread>
#include <vector>

#define buffersize 32

std::string read_stdin(std::string command) {
    std::string result = "";
    char buffer[buffersize];
    FILE* pipe = popen(command.c_str(), "r");

    while (fgets(buffer, buffersize, pipe) != NULL) result += buffer;

    pclose(pipe);

    return result;
}

int main() {
    std::cout << "ver0.2" << std::endl;
    bool open=false;
    std::vector<std::string> windows = {"sliders_side", "stats_side"};
    std::string open_str="/home/aleml/eww/target/release/eww open ", close_str="/home/aleml/eww/target/release/eww close ";

    while (true) {
        if (read_stdin("if bspc query -T -d focused | grep -q 'client'; then\n echo 0\n else\n echo 1\n fi")=="1\n") {
            if (!open) {
                for (int i=0; i<windows.size(); ++i) {
                    system((open_str + windows[i] + " >> /dev/null").c_str());
                }
                open=true;
            }
        } else {
            if (open) {
                for (int i=0; i<windows.size(); ++i) {
                    system((close_str + windows[i] + " >> /dev/null").c_str());
                }
                open=false;
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
    }
}
