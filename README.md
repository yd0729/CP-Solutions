# Soultions

This repo contains my solutions for competitive programming problems.

## 题解

全部题目的**简明**题解，按照题号倒序排列．

⭐️ 是我认为很有价值的题目．

- LeetCode
    - [LC](./LC.md)
    - LCP
- PTA
    - PAT
        - [PAT Advanced Practice](./PAT%20Advanced%20Practice.md)

## 与算法无关的无聊技巧

### Fast IO

```cpp
static const auto _ = []() {
    ios::sync_with_stdio(false);

    cin.tie(nullptr);

    cin.iword(1 << 10);
    cout.iword(1 << 10);

    return 0;
}();
```

1. `sync_with_stdio(false)` 关闭 C++ 标准流和相应的 C 标准流之间的同步．
2. `cin` 默认绑定 `cout` ，导致每次 `cin` 之前 `cout` 都会 `flush()` ．
3. `cout` 默认绑定的就是 `nullptr` ．
4. `iword` 在有需要时扩容内部存储，从而减少系统调用，应该能实现和 `fread` 一样的效率，下面是 libcxx 源码．

   ```cpp
   long&
    ios_base::iword(int index)
    {
        size_t req_size = static_cast<size_t>(index)+1;
        if (req_size > __iarray_cap_)
        {
            size_t newcap = __ios_new_cap<long>(req_size, __iarray_cap_);
            long* iarray = static_cast<long*>(realloc(__iarray_, newcap * sizeof(long)));
            if (iarray == 0)
            {
                setstate(badbit);
                static long error;
                error = 0;
                return error;
            }
            __iarray_ = iarray;
            for (long* p = __iarray_ + __iarray_size_; p < __iarray_ + newcap; ++p)
                *p = 0;
            __iarray_cap_ = newcap;
        }
        __iarray_size_ = max<size_t>(__iarray_size_, req_size);
        return __iarray_[index];
    }
    ```
