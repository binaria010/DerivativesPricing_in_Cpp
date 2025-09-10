/* This is the header file for the MonteCarlo routine including the 
statistics gatherer of chapter 5 (Joshi's book), this is the equivalent
to SimpleMC7.h of the book
*/
#pragma once
#include <Vanilla2.h>
#include <Parameters.h>
#include <MCStatistics_raw.h>

void SimpleMonteCarlo5(const VanillaOption& TheOption,
            double Spot, const Parameters& Vol, 
            const Parameters& r,
            unsigned long NumberOfPaths,
            StatisticsMC& gatherer);



