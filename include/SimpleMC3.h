#include <Vanilla.h>
#pragma once

double SimpleMonteCarlo3(const VanillaOption& TheOption, double Spot,
                        double Vol,
                        double r,
                        unsigned long NumberOfPaths
                        );