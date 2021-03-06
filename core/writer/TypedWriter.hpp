#pragma once

#include <vector>

#include "../base/types.h"
#include "../remote_process/IProcess.h"

namespace pkn
{
    class TypedWriter
    {
    public:
        TypedWriter(IProcessWriter *writable_process) : _writable_process(writable_process) {}
        virtual ~TypedWriter() = default;
    public:
    public:
        // custom read rptr_t as type
        template <typename T>
        bool write(erptr_t remote_address, const T &data) const
        {
            return _writable_process->write_unsafe(remote_address, sizeof(T), &data);
        }

        //template <typename T>
        //inline std::vector<T> read_sequence(const T *remote_address, size_t number) const
        //{
        //    std::vector<T> items(number);
        //    if (number == 0)
        //        return items;
        //    _writable_process->write_unsafe((rptr_t)remote_address, sizeof(T) * number, &items[0]);
        //    return items;
        //}
    private:
        IProcessWriter * _writable_process;
    };
}

