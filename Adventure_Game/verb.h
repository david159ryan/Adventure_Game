#ifndef VERB
#define VERB

#include <map>
#include <string>

enum Verb {
    NONE,
    PUSH,
    PULL,
    PICKUP,
    USE,
    USETARGET,
    OPEN,
    OPENTARGET,
    CLOSE,
    LICK,
    LOOKAT,
    TALKTO
};

static std::map<std::string, Verb> VerbMap = {
    {"none", NONE},
    {"push", PUSH},
    {"pull", PULL},
    {"pickup", PICKUP},
    {"use", USE},
    {"usetarget", USETARGET},
    {"open", OPEN},
    {"opentarget", OPENTARGET},
    {"close", CLOSE},
    {"lick", LICK},
    {"lookat", LOOKAT},
    {"talkto", TALKTO}
};
#endif // VERB

