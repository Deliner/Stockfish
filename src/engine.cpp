#include "engine.h"

#include <memory>

StockfishEngine *StockfishEngine::engine = nullptr;
const char *StockfishEngine::StartFEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";


StockfishEngine::StockfishEngine(StockfishEngine::Callback *callback) {
    name[0] = (char *) (malloc(sizeof(char) * (strlen(ENGINE_NAME)+1)));
    strcpy(name[0], ENGINE_NAME);
    this->callback = callback;

    CommandLine::init(1, name);
    UCI::init(Options);
    Tune::init();
    PSQT::init();
    Bitboards::init();
    Position::init();
    Bitbases::init();
    Endgames::init();
    Threads.set(8);
    Eval::init_NNUE();

    states = std::make_unique<std::deque<StateInfo>>(1);
    pos.set(StartFEN, false, &states->back(), Threads.main());
}

StockfishEngine::~StockfishEngine() {
    free(name[0]);
    Threads.set(0);
}

void StockfishEngine::send_command(std::string cmd) {
    UCI::send_command(cmd, pos, states);
}

void StockfishEngine::calc_finished(std::string answer) {
    engine->callback->on_answer(answer);
}

StockfishEngine *StockfishEngine::get_instance(StockfishEngine::Callback *callback) {
    if (engine == nullptr) {
        engine = new StockfishEngine(callback);
    }
    return engine;
}
