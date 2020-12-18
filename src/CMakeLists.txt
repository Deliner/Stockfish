# Sets the minimum version of CMake required to build your native library.
# This ensures that a certain set of CMake features is available to
# your build.

cmake_minimum_required(VERSION 3.4.1)

# Specifies a library name, specifies whether the library is STATIC or
# SHARED, and provides relative paths to the source code. You can
# define multiple libraries by adding multiple add.library() commands,
# and CMake builds them for you. When you build your app, Gradle
# automatically packages shared libraries with your APK.

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -DNNUE_EMBEDDING_OFF -DUSE_PTHREADS -g  ")
set(CMAKE_CXX_STANDARD 17)
set(StockfishSources 
		"benchmark.cpp"
		"movegen.cpp"
		"pawns.cpp"
		"thread.cpp"
		"uci.cpp"
		"engine.cpp"
		"psqt.cpp"
		"bitbase.cpp"
		"endgame.cpp"
		"material.cpp"
		"movepick.cpp"
		"position.cpp"
		"timeman.cpp"
		"tune.cpp"
		"ucioption.cpp"
		"bitboard.cpp"
		"evaluate.cpp"
		"misc.cpp"
		"search.cpp"
		"tt.cpp"
		"syzygy/tbprobe.cpp"
		"nnue/evaluate_nnue.cpp"
		"nnue/features/half_kp.cpp" main.cpp)


add_executable(check ${StockfishSources})

target_link_libraries(check pthread)