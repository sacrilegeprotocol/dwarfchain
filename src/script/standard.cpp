#include <script/standard.h>

CScript::CScript() : coinType(CoinType::MITH) {}

CScript::CScript(const std::vector<unsigned char>& scriptIn, CoinType coinTypeIn) : script(scriptIn), coinType(coinTypeIn) {}

template<typename Stream>
void CScript::Serialize(Stream &s) const {
    ::Serialize(s, script);
    ::Serialize(s, VARINT(static_cast<uint8_t>(coinType)));
}

template<typename Stream>
void CScript::Unserialize(Stream &s) {
    ::Unserialize(s, script);
    uint8_t coinTypeCode;
    ::Unserialize(s, VARINT(coinTypeCode));
    coinType = static_cast<CoinType>(coinTypeCode);
}
