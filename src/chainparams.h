// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2021 The Bitcoin Core developers
// Copyright (c) 2025 The Dwarfchain  developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_CHAINPARAMS_H
#define BITCOIN_CHAINPARAMS_H

#include <kernel/chainparams.h> // IWYU pragma: export
#include <memory>
#include <string>
#include <vector>

class ArgsManager;

class CChainParams {
public:
    // Factory functions for creating chain parameters
    static std::unique_ptr<const CChainParams> Main();
    static std::unique_ptr<const CChainParams> Dwarfchain(); // Added for dwarfchain network
    static std::unique_ptr<const CChainParams> TestNet();
    static std::unique_ptr<const CChainParams> TestNet4();
    static std::unique_ptr<const CChainParams> SigNet(const SigNetOptions& options);
    static std::unique_ptr<const CChainParams> RegTest(const RegTestOptions& options);

    // Getter methods for chain parameters
    const Consensus::Params& GetConsensus() const { return consensus; }
    const CBlock& GenesisBlock() const { return genesis; }
    const std::string& NetworkIDString() const { return strNetworkID; }
    const std::string& Bech32HRP() const { return bech32_hrp; }
    const std::string& Bech32mHRP() const { return bech32m_hrp; } // Added for Ring's Bech32m prefix
    const std::string& RingBlackHoleAddress() const { return ringBlackHoleAddress; } // Added for Ring's black hole address
    int GetDefaultPort() const { return nDefaultPort; }
    const std::vector<std::string>& DNSSeeds() const { return vSeeds; }

protected:
    Consensus::Params consensus;
    std::string strNetworkID;
    CBlock genesis;
    std::string bech32_hrp;
    std::string bech32m_hrp; // Added for Ring's Bech32m prefix
    std::string ringBlackHoleAddress; // Added for Ring's black hole address
    int nDefaultPort;
    std::vector<std::string> vSeeds;
};

/**
 * Creates and returns a std::unique_ptr<CChainParams> of the chosen chain.
 */
std::unique_ptr<const CChainParams> CreateChainParams(const ArgsManager& args, const ChainType chain);

/**
 * Return the currently selected parameters. This won't change after app
 * startup, except for unit tests.
 */
const CChainParams &Params();

/**
 * Sets the params returned by Params() to those for the given chain type.
 */
void SelectParams(const ChainType chain);

#endif // BITCOIN_CHAINPARAMS_H
