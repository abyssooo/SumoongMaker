#pragma once
#include "Stat.h"
#include <random>
#include <chrono>
#include <thread>

class MiniGame {
public:
    Stat run();

private:
    // true=성공 / false=실패
    bool playCardMatch();             // 1. 카드 맞추기
    bool playCupGuess();              // 2. 컵 맞추기
    bool playCoinFlip();              // 3. 동전 앞뒤
    bool playRockPaperScissors();     // 4. 가위바위보

    Stat calcReward(bool success);

    /* util */
    void clearScreen() const;
    template<typename Rep, typename Period>
    void sleepMs(const std::chrono::duration<Rep, Period>& d) const {
        std::this_thread::sleep_for(d);
    }

    std::mt19937 rng{ std::random_device{}() }; //난수
};
