#ifndef __LIBSYS_FILE_H__
#define __LIBSYS_FILE_H__

#include <Gorm/Foundation.hpp>

// POSIX like file API.

typedef Skoch::Int32 file_t;

bool fclose(file_t handle);
file_t fopen(const char* filename);
Skoch::SSizeT fread(file_t, char* buffer, unsigned long int sz, int where);
Skoch::SSizeT fwrite(file_t, const char* buffer, unsigned long int sz, int where);

enum FILE_WHERE {
    FILE_AT_BEGIN,
    FILE_AT_END,
    FILE_AT_CUR_POS,
};

namespace LibSystem {
    class GFile final {
    public:
        GFile(const char* filename) : m_Fh(fopen(filename)) {}
        ~GFile() { if (m_Fh != -1) fclose(m_Fh); }

        GFile& operator=(const GFile&) = default;
        GFile(const GFile&) = default;

    public:
        Skoch::SSizeT write(const char* buffer, unsigned long int sz) { return fwrite(m_Fh, buffer, sz, m_Where); }
        Skoch::SSizeT read(char* buffer, unsigned long int sz) { return fread(m_Fh, buffer, sz, m_Where); }
        void seek(const Skoch::SSizeT& where) { m_Where = where; }

    private:
        file_t m_Fh;
        Skoch::SSize m_Where;

    };
}

#endif // !__LIBSYS_FILE_H__
