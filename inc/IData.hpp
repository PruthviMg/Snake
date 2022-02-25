#ifndef IDATA_HPP
#define IDATA_HPP

enum class eDIRECTION
{
    UP = 1,
    DOWN,
    LEFT,
    RIGHT,
    QUIT,
    UNKNOWN
};

namespace Control
{
    constexpr auto UP = 'w';
    constexpr auto DOWN = 's';
    constexpr auto LEFT = 'a';
    constexpr auto RIGHT = 'd';
    constexpr auto QUIT = 'q';
};

    // namespace Control
    // {
    //     constexpr auto UP = static_cast<char>(72);
    //     constexpr auto DOWN = static_cast<char>(80);
    //     constexpr auto LEFT = static_cast<char>(75);
    //     constexpr auto RIGHT = static_cast<char>(77);
    //     constexpr auto QUIT = 'q';
    // };

#endif