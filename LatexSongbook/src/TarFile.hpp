#ifndef TARFILE_HPP
#define TARFILE_HPP

#include <QString>

#define TAR_HEADER_SIZE 512

enum TarHeaderOffset
{
    NAME = 0,
    MODE = 100,
    UID = 108,
    GID = 116,
    SIZE = 124,
    MTIME = 136,
    CHKSUM = 148,
    TYPEFLAG = 156,
    LINKNAME = 157,
    MAGIC = 257,
    VERSION = 263,
    UNAME = 265,
    GNAME = 297,
    DEVMAJOR = 329,
    DEVMINOR = 337,
    PREFIX = 345
};

enum TarHeaderSize
{
    NAME_SIZE = 100,
    MODE_SIZE = 8,
    UID_SIZE = 8,
    GID_SIZE = 8,
    SIZE_SIZE = 12,
    MTIME_SIZE = 12,
    CHKSUM_SIZE = 8,
    TYPEFLAG_SIZE = 1,
    LINKNAME_SIZE = 100,
    MAGIC_SIZE = 6,
    VERSION_SIZE = 2,
    UNAME_SIZE = 32,
    GNAME_SIZE = 32,
    DEVMAJOR_SIZE = 8,
    DEVMINOR_SIZE = 8,
    PREFIX_SIZE = 155,
    PADDING_SIZE = 12
};

typedef QByteArray TarHeader;
typedef QByteArray TarContent;

/*struct TarHeader
{
    char name[100];
    char mode[8];
    char uid[8];
    char gid[8];
    char size[12];
    char mtime[12];
    char chksum[8];
    char typeflag;
    char linkname[100];
    char magic[6];
    char version[2];
    char uname[32];
    char gname[32];
    char devmajor[8];
    char devminor[8];
    char prefix[155];
    char padding[12];
};*/

class TarFile
{
public:
    explicit TarFile();

    TarHeader header();
    TarContent content();

    void setHeader(std::size_t offset, const QByteArray& data);
    void setContent(const TarContent& content);

public: /* static */
    static TarFile fromFile(const QString& fileName);

private:
    void calculateChecksum_();

    TarHeader header_;
    TarContent content_;
};

#endif // TARFILE_HPP
