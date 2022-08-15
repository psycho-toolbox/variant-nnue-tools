#pragma once

#include <filesystem>
#include <ios>



namespace Stockfish::Tools::Sfen
{
  template<typename StreamType, std::ios_base::openmode O>
  class IOStreamBase
  {
    protected:
      StreamType m_stream;

      explicit IOStreamBase(const std::filesystem::path & path)
      : m_stream(path, IOStreamBase::get_openmode())
      {}
      virtual ~IOStreamBase() {}

      static inline constexpr std::ios_base::openmode get_openmode() noexcept
      { return std::ios_base::binary | O; }
  };
}
