#pragma once

#include "FileFormat.hpp"
#include "OutputStreamBase.hpp"

#include <fstream>


namespace Stockfish::Tools::Sfen
{
  class BinSfenOutputStream
  : public OutputStreamBase<std::fstream>
  {
    public:
      explicit BinSfenOutputStream(const std::filesystem::path & path);

      virtual const std::string_view & get_extension() const override final;

      virtual void write(const PSVector & sfens) override final;
  };
}
