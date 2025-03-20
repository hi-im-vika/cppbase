/**
 * CBase.cpp - base class for C++ projects
 * 2025-03-20
 * vika <https://github.com/hi-im-vika>
 */

#include "../include/CBase.hpp"

CBase::~CBase() = default;

void CBase::run() {
    // start update thread
    std::thread thread_for_updating(update_thread, this);
    thread_for_updating.detach();
    // draw UI in main thread
    do draw();
    while (!_do_exit);
    // handle exit
    if (thread_for_updating.joinable()) thread_for_updating.join();
}

void CBase::update_thread(CBase *who_called_me) {
    while (!(who_called_me->_do_exit)) {
        who_called_me->_perf_update_start = std::chrono::steady_clock::now();
        who_called_me->update();
        who_called_me->_perf_update = (int) std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::steady_clock::now() - who_called_me->_perf_update_start).count();
    }
}