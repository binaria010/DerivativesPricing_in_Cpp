// The only difference with SimpleMC3.h is that this includes Vanilla2.h instead of Vanilla.h

#include <Vanilla2.h>
#pragma once

double SimpleMonteCarlo3(const VanillaOption& TheOption, double Spot,
                        double Vol,
                        double r,
                        unsigned long NumberOfPaths
                        );