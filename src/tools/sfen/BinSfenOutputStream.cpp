#include "BinSfenOutputStream.hpp"



namespace Stockfish::Tools::Sfen
{
  BinSfenOutputStream::BinSfenOutputStream(const std::filesystem::path & path)
  : OutputStreamBase<std::fstream>(path)
  {}

  const std::string_view & BinSfenOutputStream::get_extension() const
  {
    return FileFormat::to_string(FileFormat::Bin);
  }

  void BinSfenOutputStream::write(const PSVector & sfens)
  {
    this->m_stream.write
    (
      reinterpret_cast<const char*>(sfens.data()),
      sizeof(PackedSfenValue) * sfens.size()
    );
  }
}
