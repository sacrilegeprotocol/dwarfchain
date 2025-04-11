#ifndef BITCOIN_SCRIPT_STANDARD_H
#define BITCOIN_SCRIPT_STANDARD_H

#include <script/script.h>
#include <uint256.h>
#include <util/strencodings.h>

#include <string>
#include <variant>

enum class CoinType {
    MITH,
    RING
};

class CScript
{
public:
    std::vector<unsigned char> script;
    CoinType coinType;

    CScript() : coinType(CoinType::MITH) {}
    CScript(const std::vector<unsigned char>& scriptIn, CoinType coinTypeIn) : script(scriptIn), coinType(coinTypeIn) {}

    template<typename Stream>
    void Serialize(Stream &s) const {
        ::Serialize(s, script);
        ::Serialize(s, VARINT(static_cast<uint8_t>(coinType)));
    }

    template<typename Stream>
    void Unserialize(Stream &s) {
        ::Unserialize(s, script);
        uint8_t coinTypeCode;
        ::Unserialize(s, VARINT(coinTypeCode));
		coinType = static_cast<CoinType>(coinTypeCode);
    }
};

#endif // BITCOIN_SCRIPT_STANDARD_H
