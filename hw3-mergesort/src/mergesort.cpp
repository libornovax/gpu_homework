//
// Libor Novak
// 12/13/2016
//
// GPU class, HW3
// Implementation of a bitonic merge sort with CUDA
//

#include <iostream>
#include <chrono>
#include "settings.h"
#include "utils.h"
#include "cpu/CPUSort.h"


int main (int argc, char* argv[])
{
    std::cout << "-- SEQUENCE LENGTH: " << SEQUENCE_LENGTH << std::endl;

    std::vector<float> seq = utils::generateRandomSequence();

    std::vector<float> seq_cpu(seq.begin(), seq.end());
    std::vector<float> seq_gpu(seq.begin(), seq.end());

//    std::cout << "Original sequence: " << std::endl;
//    utils::printSequence(seq);


#ifdef MEASURE_TIME
    auto start1 = std::chrono::high_resolution_clock::now();
#endif
    // Sort data on CPU
    CPUSort::sortSequence(seq_cpu);
#ifdef MEASURE_TIME
    auto end1 = std::chrono::high_resolution_clock::now();
    std::cout << "CPU time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end1-start1).count() << " ms" << std::endl;
#endif

//    std::cout << "CPU sorted sequence: " << std::endl;
//    utils::printSequence(seq_cpu);


    if (utils::compareSequences(seq_cpu, seq_gpu))
    {
        std::cout << "-- YAY! GPU sorting is correct!" << std::endl;
    }
    else
    {
        std::cout << "ERROR: Sequences are not the same!" << std::endl;
    }


    return EXIT_SUCCESS;
}
