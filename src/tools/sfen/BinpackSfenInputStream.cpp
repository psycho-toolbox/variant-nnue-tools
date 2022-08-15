#include "BinpackSfenInputStream.hpp"



namespace Stockfish::Tools::Sfen
{
  BinpackSfenInputStream::BinpackSfenInputStream(const std::filesystem::path & path)
  : InputStreamBase<binpack::CompressedTrainingDataEntryReader>(path)
  {}

  std::optional<PackedSfenValue> BinpackSfenInputStream::next()
  {
    static_assert(sizeof(binpack::nodchip::PackedSfenValue) == sizeof(PackedSfenValue));

    if (!this->m_stream.hasNext()) return std::nullopt;

    auto training_data_entry = this->m_stream.next();
    auto v = binpack::trainingDataEntryToPackedSfenValue(training_data_entry);
    PackedSfenValue psv;
    // same layout, different types. One is from generic library.
    std::memcpy(&psv, &v, sizeof(PackedSfenValue));

    return psv;
  }
}
