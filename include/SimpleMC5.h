// header for the modified SimpleMC4 where now the arguments Vol and r are not doubles but classes

#include <Vanilla2.h>
#include <Parameters.h>
#include <PieceWiseConstParameters.h>
#pragma once

double SimpleMonteCarlo4(const VanillaOption& TheOption, 
                        double Spot,
                        const Parameters& Vol,
                        const Parameters& r,
                        unsigned long NumberOfPaths);