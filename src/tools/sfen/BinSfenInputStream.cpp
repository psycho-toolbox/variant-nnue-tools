#include "BinSfenInputStream.hpp"



namespace Stockfish::Tools::Sfen
{
  BinSfenInputStream::BinSfenInputStream(const std::filesystem::path & path)
  : InputStreamBase<std::fstream>(path)
  {}

  std::optional<PackedSfenValue> BinSfenInputStream::next()
  {
    PackedSfenValue psv;

    if(this->m_stream.read(reinterpret_cast<char*>(&psv), sizeof(PackedSfenValue)))
      return psv;
    else
      return std::nullopt;
  }
}
