#include "BinSfenInputStream.hpp"
#include "BinSfenOutputStream.hpp"
#include "BinpackSfenInputStream.hpp"
#include "BinpackSfenOutputStream.hpp"
#include "FileFormat.hpp"



namespace Stockfish::Tools::Sfen
{
  inline std::unique_ptr<InputStreamInterface> open_input_file(const std::string & filename)
  {
    std::filesystem::path path(filename);

    switch(FileFormat::to_enum(path.extension().string()))
    {
      case FileFormat::Bin:
        return std::make_unique<BinSfenInputStream>(path);
      case FileFormat::Binpack:
        return std::make_unique<BinpackSfenInputStream>(path);
      default:
        return nullptr;
    }
  }

  inline std::unique_ptr<OutputStreamInterface> create_output_file(const std::string & filename, FileFormat::Enum format)
  {
    switch(format)
    {
      case FileFormat::Bin:
        return std::make_unique<BinSfenOutputStream>(filename);
      case FileFormat::Binpack:
        return std::make_unique<BinpackSfenOutputStream>(filename);
      default:
      {
        // It should not be occur.
        assert(false);
        return nullptr;
      }
    }
  }

  inline std::unique_ptr<OutputStreamInterface> create_output_file(const std::string & filename)
  {
    std::filesystem::path path(filename);

    return create_output_file(path, FileFormat::to_enum(path.extension().string()));
  }
}
