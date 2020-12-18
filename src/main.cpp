//
// Created by deliner on 18.12.2020.
//

#include "engine.h"
#include "thread.h"
class Writer : public StockfishEngine::Callback {
public:
    Writer() = default;

    void on_answer(std::string answer) {
        std::cout << answer << std::endl;
    }


};


int main() {
    auto writer = new Writer();
    auto engine = StockfishEngine::get_instance(writer);
    std::string cmd;
    while (std::getline(std::cin, cmd)){
        engine->send_command(cmd);
    }
}