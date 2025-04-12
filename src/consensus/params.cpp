// Copyright (c) 2025 The Dwarfchain developers


#include <consensus/params.h>

namespace Consensus {

// Initialize the new parameters for the Mith block reward rules
Params::Params() {
    nInitialBlockReward = 128 * COIN;
    nBlockRewardHalvingInterval = 420000;
    nFinalBlockReward = 16 * COIN;

    // Initialize the new parameters for the Argon2iD algorithm
    nArgon2iDMemory = 1024 * 1024; // 1GB
    nArgon2iDParallelism = 1;
    nArgon2iDIterations = 4000;

    // Initialize the new parameters for the ASERT mechanism
    nASERTTargetBlockTime = 5 * 60; // 5 minutes
    nASERTHalfLife = 288 * 60 * 60; // 1 day
}

} // namespace Consensus
