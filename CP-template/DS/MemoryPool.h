#ifndef __OY_MEMORYPOOL__
#define __OY_MEMORYPOOL__

#include <cstdint>
#include <functional>

namespace OY {
    template <typename T, int batch>
    class MemoryPool {
        private:
        static inline std::vector<T *> pool;
        static inline std::vector<T *> gc;

        static inline T *cursor = nullptr;
        static inline T *end = nullptr;

        static void reserve(int count = batch) {
            pool.push_back((T *)malloc(count * sizeof(T)));
            cursor = pool.back();
            end = cursor + count;
        }
public:
        static void *operator new(size_t) {
            if (gc.size()) {
                auto it = gc.back();
                gc.pop_back();
                return it;
            } else if (cursor == end)
                reserve();
            return cursor++;
        }

        static void operator delete(void *it) { gc.push_back((T *)it); }
    };
}

#endif