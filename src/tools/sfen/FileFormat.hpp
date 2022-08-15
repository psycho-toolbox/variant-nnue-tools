#pragma once

#include <algorithm>
#include <array>
#include <cstdint>
#include <string_view>



namespace Stockfish::Tools::Sfen
{
  class FileFormat
  {
    public:
      using  Enum = std::uint_fast8_t;
      static constexpr Enum Bin = 0;
      static constexpr Enum Binpack = 1;

      static inline const std::string_view & to_string(const Enum & t)
      { return m_output_type_name[t]; }

      static inline Enum to_enum(const std::string_view & s)
      {
         auto it = std::find(m_output_type_name.cbegin(), m_output_type_name.cend(), s);
         return it - m_output_type_name.cbegin();
      }

    private:
      static constexpr std::array<std::string_view, 2>
      m_output_type_name =
      {
        ".bin",
        ".binpack"
      };
  };
}
