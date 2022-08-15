#pragma once

#include "InputStreamBase.hpp"

#include <fstream>



namespace Stockfish::Tools::Sfen
{
  class BinSfenInputStream
  : public InputStreamBase<std::fstream>
  {
    public:
      explicit BinSfenInputStream(const std::filesystem::path & path);

      virtual std::optional<PackedSfenValue> next() override final;
  };

  // Specialized version of eof() for std::fstream.
  template<>
  inline bool InputStreamBase<std::fstream>::eof() const noexcept
  { return this->m_stream.eof(); }
}
