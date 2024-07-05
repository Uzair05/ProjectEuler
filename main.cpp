#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>

int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[]) {
    std::string s =
        "731671765313306249192251196744265747423553491949349698352031277450632623957831801698480186"
        "947885184385861560789112949495459501737958331952853208805511125406987471585238630507156932"
        "909632952274430435576689664895044524452316173185640309871112172238311362229893423380308135"
        "336276614282806444486645238749303589072962904915604407723907138105158593079608667017242712"
        "188399879790879227492190169972088809377665727333001053367881220235421809751254540594752243"
        "525849077116705560136048395864467063244157221553975369781797784617406495514929086256932197"
        "846862248283972241375657056057490261407972968652414535100474821663704844031998900088952434"
        "506585412275886668811642717147992444292823086346567481391912316282458617866458359124566529"
        "476545682848912883142607690042242190226710556263211111093705442175069416589604080719840385"
        "096245544436298123098787992724428490918884580156166097919133875499200524063689912560717606"
        "058861164671094050775410022569831552000559357297257163626956188267042825248360082325753042"
        "0752963450";

    unsigned long long res{0};
    for (size_t i{0}; i < (s.length() - 12); i++) {
        const std::string s_sub{s.substr(i, 13)};
        if (!std::any_of(s_sub.cbegin(), s_sub.cend(), [](const char& c) { return c == '0'; })) {
            unsigned long long res_ = std::accumulate(
                s_sub.cbegin(), s_sub.cend(), 1ull, [](unsigned long long acc, const char& c) {
                    return acc * static_cast<long long unsigned>((int)(c - '0'));
                });
            if (res_ > res) {
                res = res_;
            }
        }
    }

    std::cout << res << std::endl;

    return 0;
}