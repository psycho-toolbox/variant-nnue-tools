#pragma once

#include "FileFormat.hpp"
#include "OutputStreamBase.hpp"

#include "../../extra/nnue_data_binpack_format.h"



namespace Stockfish::Tools::Sfen
{
  class BinpackSfenOutputStream
  : public OutputStreamBase<binpack::CompressedTrainingDataEntryWriter>
  {
    public:
      explicit BinpackSfenOutputStream(const std::filesystem::path & path);

      virtual const std::string_view & get_extension() const override final;

      virtual void write(const PSVector & sfens) override final;
  };
}
