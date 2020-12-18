/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2020 The Stockfish developers (see AUTHORS file)

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef STOCKFISH_ENGINE_H
#define STOCKFISH_ENGINE_H

#include <iostream>

#include "bitboard.h"
#include "endgame.h"
#include "position.h"
#include "search.h"
#include "thread.h"
#include "tt.h"
#include "uci.h"
#include "syzygy/tbprobe.h"

#define ENGINE_NAME "stockfish"

namespace PSQT {
    void init();
}

class StockfishEngine {
public:
    class Callback;

    ~StockfishEngine();
    static const char* StartFEN;
private:
    char *name[1] = {nullptr};
    Position pos = Position();
    StateListPtr states;
    Callback *callback;

    static StockfishEngine *engine;

public:
    void send_command(std::string);
    static void calc_finished(std::string);
    static StockfishEngine *get_instance(Callback *callback);

private:
    StockfishEngine(Callback *callback);
};

class StockfishEngine::Callback {
public:
    virtual void on_answer(std::string answer) = 0;
};

#endif