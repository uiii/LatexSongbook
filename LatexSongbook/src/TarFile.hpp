#ifndef TARFILE_HPP
#define TARFILE_HPP

#include <QString>
#include <QDateTime>

#define TAR_HEADER_SIZE 512
#define TAR_BLOCK_SIZE 512

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
    MAGIC_SIZE = 8,
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

class TarFile
{
public:
    explicit TarFile(const QString& name, const TarContent& content = TarContent());

    const QString& name();
    std::size_t size();

    TarHeader header();
    TarContent content();

    void setContent(const TarContent& content);

public: /* static */
    static TarFile fromHeader(const TarHeader& header);
    static TarFile fromFile(const QString& fileName);

private:
    TarFile();
    void setHeader_(std::size_t offset, const QByteArray& data);
    void calculateChecksum_();

    TarHeader header_;
    TarContent content_;
};

#endif // TARFILE_HPP
