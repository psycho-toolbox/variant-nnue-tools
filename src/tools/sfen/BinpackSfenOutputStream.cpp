#include "BinpackSfenOutputStream.hpp"



namespace Stockfish::Tools::Sfen
{
  BinpackSfenOutputStream::BinpackSfenOutputStream(const std::filesystem::path & path)
  : OutputStreamBase<binpack::CompressedTrainingDataEntryWriter>(path)
  {}

  const std::string_view & BinpackSfenOutputStream::get_extension() const
  {
    return FileFormat::to_string(FileFormat::Binpack);
  }

  void BinpackSfenOutputStream::write(const PSVector & sfens)
  {
    static_assert(sizeof(binpack::nodchip::PackedSfenValue) == sizeof(PackedSfenValue));

    // The library uses a type that's different but layout-compatibile.
    binpack::nodchip::PackedSfenValue psv;

    for(auto & sfen : sfens)
    {
      std::memcpy(&psv, &sfen, sizeof(binpack::nodchip::PackedSfenValue));
      this->m_stream.addTrainingDataEntry(binpack::packedSfenValueToTrainingDataEntry(psv));
    }
  }
}
