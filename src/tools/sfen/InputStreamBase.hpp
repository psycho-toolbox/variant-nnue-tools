#pragma once

#include "StreamBase.hpp"

#include "../packed_sfen.h"

#include <filesystem>
#include <optional>



namespace Stockfish::Tools::Sfen
{
  class InputStreamInterface
  {
    public:
      virtual ~InputStreamInterface() = default;

      virtual bool eof() const noexcept = 0;

      virtual std::optional<PackedSfenValue> next() = 0;
  };

  template<typename StreamType>
  class InputStreamBase
  : public IOStreamBase<StreamType, std::ios_base::in>
  , public InputStreamInterface
  {
    public:
      virtual inline bool eof() const noexcept override final
      { return !this->m_stream.hasNext(); }

    protected:
      explicit InputStreamBase(const std::filesystem::path & path)
      : IOStreamBase<StreamType, std::ios_base::in>(path)
      {}
      virtual ~InputStreamBase() = default;
  };
}
