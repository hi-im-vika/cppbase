/**
 * CBase.hpp - library header
 * 2025-03-20
 * vika <https://github.com/hi-im-vika>
 */

#pragma once

#include <thread>

/**
 * @brief A class designed to be inherited from to provide functions common to all
 * @author vika
 */
class CBase {
public:

    /**
     * @brief Constructor for CBase
     */
    CBase() = default;

    /**
     * @brief Destructor for CBase
     */
    ~CBase();

    /**
     * @brief Pure virtual function for updating app logic
     */
    virtual void update() = 0;

    /**
     * @brief Pure virtual function for updating UI
     */
    virtual void draw() = 0;

    /**
     * @brief Runs the update and draw functions.
     */
    void run();

    /**
     * @brief Thread for updating app logic
     * @param who_called_me Pointer to CBase object of interest
     */
    static void update_thread(CBase *who_called_me);

protected:
    std::chrono::steady_clock::time_point _perf_update_start;       ///< Start time for measuring performance.
    std::chrono::steady_clock::time_point _perf_draw_start;         ///< Start time for measuring performance.
    int _perf_update = 1;       ///< Measured update time in milliseconds.
    int _perf_draw = 1;         ///< Measured draw time in milliseconds.
    bool _do_exit = false;      ///< Flag to exit program.
};