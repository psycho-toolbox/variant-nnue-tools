#pragma once

#include "StreamBase.hpp"

#include "../packed_sfen.h"

#include <filesystem>



namespace Stockfish::Tools::Sfen
{
  class OutputStreamInterface
  {
    public:
      virtual ~OutputStreamInterface() = default;

      virtual void write(const PSVector & sfens) = 0;
  };

  template<typename StreamType>
  class OutputStreamBase
  : public IOStreamBase<StreamType, std::ios_base::out | std::ios_base::app>
  , public OutputStreamInterface
  {
    protected:
      explicit OutputStreamBase(const std::filesystem::path & path)
      : IOStreamBase<StreamType, std::ios_base::out | std::ios_base::app>(this->get_output_name(path))
      {}
      virtual ~OutputStreamBase() = default;

      inline const std::filesystem::path get_output_name(const std::filesystem::path & path) const
      {
        if(path.extension() == this->get_extension()) return path;
        else return path.parent_path() / (path.stem().concat(this->get_extension()));
      }

      virtual const std::string_view & get_extension() const = 0;
  };
}
