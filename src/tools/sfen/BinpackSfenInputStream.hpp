#pragma once

#include "InputStreamBase.hpp"

#include "../../extra/nnue_data_binpack_format.h"



namespace Stockfish::Tools::Sfen
{
  class BinpackSfenInputStream
  : public InputStreamBase<binpack::CompressedTrainingDataEntryReader>
  {
    public:
      explicit BinpackSfenInputStream(const std::filesystem::path & path);

      virtual std::optional<PackedSfenValue> next() override final;
  };
}
