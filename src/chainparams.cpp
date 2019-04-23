// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2019 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "assert.h"

#include "chainparams.h"
#include "main.h"
#include "util.h"

#include <boost/assign/list_of.hpp>

using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

//
// Main network
//

// Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress> &vSeedsOut, const SeedSpec6 *data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7*24*60*60;
    for (unsigned int i = 0; i < count; i++)
    {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

class CMainParams : public CChainParams {
public:
    CMainParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
		pchMessageStart[0] = 0xb4;
		pchMessageStart[1] = 0x97;
		pchMessageStart[2] = 0x87;
		pchMessageStart[3] = 0xda;
        vAlertPubKey = ParseHex("047f403f027027ab13d9a17d453bbe9e33920f1efd0a37e43c0f52d3e2f53e84662d21e628d9be61c8a4085b17a5b8fa5a3a7cadf63c03cb33399d9e0645ba0ee8");
        nDefaultPort = 48223;
        nRPCPort = 48221;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 20);

        // Build the genesis block. Note that the output of the genesis coinbase cannot
        // be spent as it did not originally exist in the database.
       

        const char* pszTimestamp = "Wednesday, April 17, 2019 6:55:47 CBLCoin Pos Masternode";
        std::vector<CTxIn> vin;
        vin.resize(1);
        vin[0].scriptSig = CScript() << 0 << CBigNum(42) << vector<unsigned char>((const unsigned char *)pszTimestamp, (const unsigned char *)pszTimestamp + strlen(pszTimestamp));
        std::vector<CTxOut> vout;
        vout.resize(1);
        vout[0].SetEmpty();
        CTransaction txNew(1, 1520363196, vin, vout, 0);
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = 1555527347;
        genesis.nBits    = 0x1e0ffff0;
        genesis.nNonce   = 1994581;

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x000009da943d8b53ca4df143ce4874d873ebf3ad48acdf198fcb99a79c7ca7dc"));
        assert(genesis.hashMerkleRoot == uint256("0xac23ddcb4d9b3330d4d2add45631df6f297d438db68edbc581d2a96cb3777880"));


        vSeeds.push_back(CDNSSeedData("144.217.224.88", "144.217.224.88")); // Single node address
        vSeeds.push_back(CDNSSeedData("node1.cblcoin.net", "node1.cblcoin.net"));
	    vSeeds.push_back(CDNSSeedData("node2.cblcoin.net", "node2.cblcoin.net"));
        
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,28); // CBLCoin addresses start with 'C'
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,18); // CBLCoinscript addresses start with 8 
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1,179);
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x88)(0xB2)(0x1E).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x88)(0xAD)(0xE4).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        nLastPOWBlock = 1000;
    }

    virtual const CBlock &GenesisBlock() const { return genesis; }
    virtual Network NetworkID() const { return CChainParams::MAIN; }

    virtual const vector<CAddress> &FixedSeeds() const
    {
        return vFixedSeeds;
    }

  protected:
    CBlock genesis;
    vector<CAddress> vFixedSeeds;
};
static CMainParams mainParams;

//
// Testnet
//

class CTestNetParams : public CMainParams
{
  public:
    CTestNetParams()
    {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
		pchMessageStart[0] = 0xd5;
		pchMessageStart[1] = 0xee;
		pchMessageStart[2] = 0xf5;
		pchMessageStart[3] = 0xcd;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 16);
        vAlertPubKey = ParseHex("042287ee0d61ee0aa1cbb052806262d3541061a51bde796db3d1b33dd524d1df2088c9aba23b8f3b7db5c7dfdbd2f63c691bd67a480b7825b92dd114e2ac5350bc");
        nDefaultPort = 48224;
        nRPCPort = 48222;
        strDataDir = "testnet";

        // Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nTime    = 1555527390;
        genesis.nBits    = 0x1e0ffff0;
        genesis.nNonce   = 11980;

  	    hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x0000d03b5b927f3cb3739decf3b9cd2b2c2db2af3fa66a1f3e5a78d50a9177bd"));
        assert(genesis.hashMerkleRoot == uint256("0xac23ddcb4d9b3330d4d2add45631df6f297d438db68edbc581d2a96cb3777880"));
	   

        vFixedSeeds.clear();
        vSeeds.clear();

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,64);  //keys start with 'S' or 'T'
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,20);  //keys start with  '9'
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,239); //keys start with Bitcoin defaults)
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x35)(0x87)(0xCF).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x35)(0x83)(0x94).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        nLastPOWBlock = 10000;
    }
    virtual Network NetworkID() const { return CChainParams::TESTNET; }
};
static CTestNetParams testNetParams;

static CChainParams *pCurrentParams = &mainParams;

const CChainParams &Params()
{
    return *pCurrentParams;
}

void SelectParams(CChainParams::Network network)
{
    switch (network)
    {
    case CChainParams::MAIN:
        pCurrentParams = &mainParams;
        break;
    case CChainParams::TESTNET:
        pCurrentParams = &testNetParams;
        break;
    default:
        assert(false && "Unimplemented network");
        return;
    }
}

bool SelectParamsFromCommandLine()
{

    bool fTestNet = GetBoolArg("-testnet", false);

    if (fTestNet)
    {
        SelectParams(CChainParams::TESTNET);
    }
    else
    {
        SelectParams(CChainParams::MAIN);
    }
    return true;
}
