#ifndef CONSTS_H_INCLUDED
#define CONSTS_H_INCLUDED

namespace consts {

    const int dimensions = 3; // 3 dimensions means its a 3x3 cube
    const int langs = 2;
    const std::string solved[6][dimensions] =   {
                                                {"BBB", "BBB", "BBB"}, //white
                                                {"RRR", "RRR", "RRR"}, //red
                                                {"VVV", "VVV", "VVV"}, //green
                                                {"NNN", "NNN", "NNN"}, //orange (magenta)
                                                {"AAA", "AAA", "AAA"}, //blue
                                                {"MMM", "MMM", "MMM"}  //yellow
                                                };
    // you should be able to make a smaller or bigger cube by changing the dimensions and this state (it wont work correctly because of how I made the movements and will crash if its smaller than 3x3) (probably some of the worst code ive ever written but works for 3x3)
    const std::string languageNames[langs] = {"ESPANOL", "ENGLISH"};
    const std::string clearLine = "                                     ";

}

#endif // CONSTS_H_INCLUDED
